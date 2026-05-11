#include "JlTrussC.h"

#include "jlcxx/jlcxx.hpp"

#include "TrussC.h"
using namespace std;
using namespace tc;

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
    return runApp<TestApp>(settings);
}

std::string greet()
{
   return "Hello from JlTrussC C++!!";
}

JLCXX_MODULE define_julia_module(jlcxx::Module& mod)
{
  mod.method("greet", &greet);
  mod.method("runTrusscTestApp", &runTrusscTestApp);
}