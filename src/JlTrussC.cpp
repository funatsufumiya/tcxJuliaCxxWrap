#define TRUSSC_SHOW_CONSOLE 1
#include "TrussC.h"

#include "JlTrussC.h"

#include "jlcxx/jlcxx.hpp"

#include "trussc_generated.h"

using namespace std;
using namespace tc;

static void *setupFnPtr = nullptr;
static void *updateFnPtr = nullptr;
static void *drawFnPtr = nullptr;
static void *keyPressedFnPtr = nullptr;
static void *keyReleasedFnPtr = nullptr;

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

void runTrusscTestApp(int width=960, int height=600, const std::string& title="TrussC") {
    WindowSettings settings;
    settings.setSize(width, height);
    settings.setTitle(title);
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

void setKeyPressedFn(jl_value_t *fn){
    keyPressedFnPtr = jl_unbox_voidpointer(fn);
}

void setKeyReleasedFn(jl_value_t *fn){
    keyReleasedFnPtr = jl_unbox_voidpointer(fn);
}

void callFnPtr(void* ptr){
    if(ptr != nullptr){
        typedef void (*CppPtr)();
        CppPtr rePtr = reinterpret_cast<CppPtr>(ptr);
        rePtr();
    }
}

void callKeyFnPtr(void* ptr, int key){
    if(ptr != nullptr){
        typedef void (*CppPtr)(int key);
        CppPtr rePtr = reinterpret_cast<CppPtr>(ptr);
        rePtr(key);
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

void callKeyPressedFn(int key){
    callKeyFnPtr(keyPressedFnPtr, key);
}

void callKeyReleasedFn(int key){
    callKeyFnPtr(keyReleasedFnPtr, key);
}

class MyApp : public App {
    void setup() override {
        callSetupFn();
    }

    void update() override {
        callUpdateFn();
    }

    void draw() override {
        callDrawFn();
    }

    void keyPressed(int key) override {
        callKeyPressedFn(key);
    }

    void keyReleased(int key) override {
        callKeyReleasedFn(key);
    }

    void mousePressed(Vec2 pos, int button) override {

    }
    void mouseReleased(Vec2 pos, int button) override {

    }
    void mouseMoved(Vec2 pos) override {

    }
    void mouseDragged(Vec2 pos, int button) override {

    }
    void mouseScrolled(Vec2 delta) override {

    }
};

void runTrusscApp(int width=960, int height=600, const std::string& title="TrussC") {
    WindowSettings settings;
    settings.setSize(width, height);
    settings.setTitle(title);
    runApp<MyApp>(settings);
}

std::string greet()
{
   return "Hello from JlTrussC C++!!";
}

JLCXX_MODULE define_julia_module(jlcxx::Module& mod)
{
  mod.method("greet", &greet);
  mod.method("runTrusscTestApp", &runTrusscTestApp);
  mod.method("runTrusscTestApp", [](){ runTrusscTestApp(); });
  mod.method("runTrusscTestApp", [](int w, int h){ runTrusscTestApp(w, h); });
  mod.method("runTrusscApp", &runTrusscApp);
  mod.method("runTrusscApp", [](){ runTrusscApp(); });
  mod.method("runTrusscApp", [](int w, int h){ runTrusscApp(w, h); });
  mod.method("setSetupFn", &setSetupFn);
  mod.method("callSetupFn", &callSetupFn);
  mod.method("setUpdateFn", &setUpdateFn);
  mod.method("callUpdateFn", &callUpdateFn);
  mod.method("setDrawFn", &setDrawFn);
  mod.method("callDrawFn", &callDrawFn);
  mod.method("setKeyPressedFn", &setKeyPressedFn);
  mod.method("callKeyPressedFn", &callKeyPressedFn);
  mod.method("setKeyReleasedFn", &setKeyReleasedFn);
  mod.method("callKeyReleasedFn", &callKeyReleasedFn);

  mod.add_type<Vec2>("Vec2")
    .constructor<>()
    .constructor<float, float>()
    .constructor<const Vec2&>();
    // .method("x", &Vec2::x)
    // .method("y", &Vec2::y);

  mod.add_type<Vec3>("Vec3")
    .constructor<>()
    .constructor<float, float, float>()
    .constructor<const Vec3&>();
    // .method("x", &Vec2::x)
    // .method("y", &Vec2::y);

  mod.add_enum<LogLevel>("LogLevel",
    std::vector<const char*>({
        "Verbose",
        "Notice",
        "Warning",
        "Error",
        "Fatal",
        "Silent"
    }),
    std::vector<int>({
        (int)LogLevel::Verbose,
        (int)LogLevel::Notice,
        (int)LogLevel::Warning,
        (int)LogLevel::Error,
        (int)LogLevel::Fatal,
        (int)LogLevel::Silent
    }));

  define_julia_module_trussc_generated(mod);
}
