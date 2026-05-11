#define TRUSSC_SHOW_CONSOLE 1
#include "TrussC.h"

#include "JlTrussC.h"

#include "jlcxx/jlcxx.hpp"

using namespace std;
using namespace tc;

static void *setupFnPtr = nullptr;
static void *updateFnPtr = nullptr;
static void *drawFnPtr = nullptr;

class TestApp : public App {
    void draw() override {
        clear(0.12f);

        // Rotating box
        noFill();
        translate(getWindowWidth() / 2, getWindowHeight() / 2);
        rotate(getElapsedTimef() *0.1f, getElapsedTimef() *0.15f, 0);
        drawBox(200.0f);
    }
};

void runTrusscTestApp() {
    WindowSettings settings;
    settings.setSize(960, 600);
    settings.setTitle("TrussC");
    runApp<TestApp>(settings);
}

void setSetupFn(jl_value_t *fn){
    setupFnPtr = jl_unbox_voidpointer(fn);
}

void setUpdateFn(jl_value_t *fn){
    updateFnPtr = jl_unbox_voidpointer(fn);
}

void setDrawFn(jl_value_t *fn){
    drawFnPtr = jl_unbox_voidpointer(fn);
}

void callFnPtr(void* ptr){
    if(ptr != nullptr){
        typedef void (*CppPtr)();
        CppPtr rePtr = reinterpret_cast<CppPtr>(ptr);
        rePtr();
    }
}

void callSetupFn(){
    callFnPtr(setupFnPtr);
}

void callUpdateFn(){
    callFnPtr(updateFnPtr);
}

void callDrawFn(){
    callFnPtr(drawFnPtr);
}

std::string greet()
{
   return "Hello from JlTrussC C++!!";
}

JLCXX_MODULE define_julia_module(jlcxx::Module& mod)
{
  mod.method("greet", &greet);
  mod.method("runTrusscTestApp", &runTrusscTestApp);
  mod.method("setSetupFn", &setSetupFn);
  mod.method("callSetupFn", &callSetupFn);
  mod.method("setUpdateFn", &setUpdateFn);
  mod.method("callUpdateFn", &callUpdateFn);
  mod.method("setDrawFn", &setDrawFn);
  mod.method("callDrawFn", &callDrawFn);
}