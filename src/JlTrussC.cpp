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
static void *mousePressedFnPtr = nullptr;
static void *mouseReleasedFnPtr = nullptr;
static void *mouseMovedFnPtr = nullptr;
static void *mouseDraggedFnPtr = nullptr;
static void *mouseScrolledFnPtr = nullptr;
static void *windowResizedFnPtr = nullptr;
static void *filesDroppedFnPtr = nullptr;

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

void setMousePressedFn(jl_value_t *fn){
    mousePressedFnPtr = jl_unbox_voidpointer(fn);
}

void setMouseReleasedFn(jl_value_t *fn){
    mouseReleasedFnPtr = jl_unbox_voidpointer(fn);
}

void setMouseMovedFn(jl_value_t *fn){
    mouseMovedFnPtr = jl_unbox_voidpointer(fn);
}

void setMouseScrolledFn(jl_value_t *fn){
    mouseScrolledFnPtr = jl_unbox_voidpointer(fn);
}

void setMouseDraggedFn(jl_value_t *fn){
    mouseDraggedFnPtr = jl_unbox_voidpointer(fn);
}

void setWindowResizedFn(jl_value_t *fn){
    windowResizedFnPtr = jl_unbox_voidpointer(fn);
}

void setFilesDroppedFn(jl_value_t *fn){
    filesDroppedFnPtr = jl_unbox_voidpointer(fn);
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

void callMouseFnPtr(void* ptr, Vec2 pos, int button){
    if(ptr != nullptr){
        typedef void (*CppPtr)(Vec2& pos, int button);
        CppPtr rePtr = reinterpret_cast<CppPtr>(ptr);
        rePtr(pos, button);
    }
}

void callMouseMovedFnPtr(void* ptr, Vec2 pos){
    if(ptr != nullptr){
        typedef void (*CppPtr)(Vec2& pos);
        CppPtr rePtr = reinterpret_cast<CppPtr>(ptr);
        rePtr(pos);
    }
}

void callWindowResizedFnPtr(void* ptr, int w, int h){
    if(ptr != nullptr){
        typedef void (*CppPtr)(int w, int h);
        CppPtr rePtr = reinterpret_cast<CppPtr>(ptr);
        rePtr(w, h);
    }
}

void callFilesDroppedFnPtr(void* ptr, const vector<string>& files){
    if(ptr != nullptr){
        typedef void (*CppPtr)(vector<string>& files);
        CppPtr rePtr = reinterpret_cast<CppPtr>(ptr);
        rePtr(const_cast<vector<string>&>(files));
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

void callMousePressedFn(Vec2 pos, int button){
    callMouseFnPtr(mousePressedFnPtr, pos, button);
}

void callMouseReleasedFn(Vec2 pos, int button){
    callMouseFnPtr(mouseReleasedFnPtr, pos, button);
}

void callMouseMovedFn(Vec2 pos){
    callMouseMovedFnPtr(mouseMovedFnPtr, pos);
}

void callMouseScrolledFn(Vec2 delta){
    callMouseMovedFnPtr(mouseScrolledFnPtr, delta);
}

void callMouseDraggedFn(Vec2 pos, int button){
    callMouseFnPtr(mouseDraggedFnPtr, pos, button);
}

void callWindowResizedFn(int w, int h){
    callWindowResizedFnPtr(windowResizedFnPtr, w, h);
}

void callFilesDroppedFn(const vector<string>& files){
    callFilesDroppedFnPtr(filesDroppedFnPtr, files);
}

class MyApp : public App {
public:

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
        callMousePressedFn(pos, button);
    }

    void mouseReleased(Vec2 pos, int button) override {
        callMouseReleasedFn(pos, button);
    }

    void mouseMoved(Vec2 pos) override {
        callMouseMovedFn(pos);

    }

    void mouseDragged(Vec2 pos, int button) override {
        callMouseDraggedFn(pos, button);

    }

    void mouseScrolled(Vec2 delta) override {
        callMouseScrolledFn(delta);
    }

    void windowResized(int width, int height) override {
        callWindowResizedFn(width, height);

    }

    void filesDropped(const vector<string>& files) override {
        callFilesDroppedFn(files);
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

namespace jlcxx
{
  template<> struct IsMirroredType<FpsSettings> : std::false_type { };
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
  mod.method("setUpdateFn", &setUpdateFn);
  mod.method("setDrawFn", &setDrawFn);
  mod.method("setKeyPressedFn", &setKeyPressedFn);
  mod.method("setKeyReleasedFn", &setKeyReleasedFn);
  mod.method("setMousePressedFn", &setMousePressedFn);
  mod.method("setMouseReleasedFn", &setMouseReleasedFn);
  mod.method("setMouseMovedFn", &setMouseMovedFn);
  mod.method("setMouseScrolledFn", &setMouseScrolledFn);
  mod.method("setMouseDraggedFn", &setMouseDraggedFn);
  mod.method("setWindowResizedFn", &setWindowResizedFn);
  mod.method("setFilesDroppedFn", &setFilesDroppedFn);

  mod.method("getElapsedTimef", &getElapsedTime);

  mod.add_type<Vec2>("Vec2")
    .constructor<>()
    .constructor<float, float>()
    .constructor<const Vec2&>()
    .method("x", [](Vec2& v){ return v.x; })
    .method("y", [](Vec2& v){ return v.y; })
    .method("x!", [](Vec2& v, float p){ v.x = p; })
    .method("y!", [](Vec2& v, float p){ v.y = p; })
    .method("set", [](Vec2& v, const Vec2& a){ return v.set(a); })
    .method("set", [](Vec2& v, float a, float b){ return v.set(a,b); })
    .method("set!", [](Vec2& v, const Vec2& a){ return v.set(a); })
    .method("set!", [](Vec2& v, float a, float b){ return v.set(a,b); })
    ;

  mod.add_type<Vec3>("Vec3")
    .constructor<>()
    .constructor<float, float, float>()
    .constructor<const Vec3&>()
    .method("x", [](Vec3& v){ return v.x; })
    .method("y", [](Vec3& v){ return v.y; })
    .method("z", [](Vec3& v){ return v.z; })
    .method("x!", [](Vec3& v, float p){ v.x = p; })
    .method("y!", [](Vec3& v, float p){ v.y = p; })
    .method("z!", [](Vec3& v, float p){ v.z = p; })
    .method("set", [](Vec3& v, const Vec3& a){ return v.set(a); })
    .method("set", [](Vec3& v, float a, float b, float c){ return v.set(a,b,c); })
    .method("set!", [](Vec3& v, const Vec3& a){ return v.set(a); })
    .method("set!", [](Vec3& v, float a, float b, float c){ return v.set(a,b,c); })
    ;

  mod.add_type<Vec4>("Vec4")
    .constructor<>()
    .constructor<float, float, float, float>()
    .constructor<const Vec4&>()
    .method("x", [](Vec4& v){ return v.x; })
    .method("y", [](Vec4& v){ return v.y; })
    .method("z", [](Vec4& v){ return v.z; })
    .method("w", [](Vec4& v){ return v.w; })
    .method("x!", [](Vec4& v, float p){ v.x = p; })
    .method("y!", [](Vec4& v, float p){ v.y = p; })
    .method("z!", [](Vec4& v, float p){ v.z = p; })
    .method("w!", [](Vec4& v, float p){ v.w = p; })
    .method("set", [](Vec4& v, const Vec4& a){ return v.set(a); })
    .method("set", [](Vec4& v, float a, float b, float c, float d){ return v.set(a,b,c,d); })
    .method("set!", [](Vec4& v, const Vec4& a){ return v.set(a); })
    .method("set!", [](Vec4& v, float a, float b, float c, float d){ return v.set(a,b,c,d); })
    ;

  mod.add_type<Quaternion>("Quaternion")
    .constructor<>()
    .constructor<float, float, float, float>()
    .constructor<const Quaternion&>()
    .method("w", [](Quaternion& v){ return v.w; })
    .method("x", [](Quaternion& v){ return v.x; })
    .method("y", [](Quaternion& v){ return v.y; })
    .method("z", [](Quaternion& v){ return v.z; })
    .method("w!", [](Quaternion& v, float p){ v.w = p; })
    .method("x!", [](Quaternion& v, float p){ v.x = p; })
    .method("y!", [](Quaternion& v, float p){ v.y = p; })
    .method("z!", [](Quaternion& v, float p){ v.z = p; })
    ;

  mod.add_type<Mat4>("Mat4")
    .constructor<>()
    .constructor<
        float, float, float, float,
        float, float, float, float,
        float, float, float, float,
        float, float, float, float>()
    .constructor<const Mat4&>()
    .method("at", [](Mat4& m, int raw, int col) { return m.at(raw, col); })
    .method("set", [](Mat4& m, int raw, int col, int v){ m.at(raw, col) = v; })
    .method("set!", [](Mat4& m, int raw, int col, int v){ m.at(raw, col) = v; })
    ;

  mod.add_type<Rect>("Rect")
    .constructor<>()
    .constructor<float, float, float, float>()
    .constructor<float, float, float, float, float>()
    .constructor<const Vec2&, float, float>()
    .constructor<const Vec3&, float, float>()
    .constructor<const Rect&>()
    .method("x", [](Rect& v){ return v.x; })
    .method("y", [](Rect& v){ return v.y; })
    .method("width", [](Rect& v){ return v.width; })
    .method("height", [](Rect& v){ return v.height; })
    .method("x!", [](Rect& v, float p){ v.x = p; })
    .method("y!", [](Rect& v, float p){ v.y = p; })
    .method("width!", [](Rect& v, float p){ v.width = p; })
    .method("height!", [](Rect& v, float p){ v.height = p; })
    .method("set", [](Rect& v, const Vec2& a, float c, float d){ return v.set(a,c,d); })
    .method("set", [](Rect& v, float a, float b, float c, float d){ return v.set(a,b,c,d); })
    .method("set!", [](Rect& v, const Vec2& a, float c, float d){ return v.set(a,c,d); })
    .method("set!", [](Rect& v, float a, float b, float c, float d){ return v.set(a,b,c,d); })
    ;

  mod.add_type<Color>("Color")
    .constructor<>()
    .constructor<float>()
    .constructor<float, float>()
    .constructor<float, float, float>()
    .constructor<float, float, float, float>()
    .constructor<const Color&>()
    .method("r", [](Color& v){ return v.r; })
    .method("g", [](Color& v){ return v.g; })
    .method("b", [](Color& v){ return v.b; })
    .method("a", [](Color& v){ return v.a; })
    .method("r!", [](Color& v, float p){ v.r = p; })
    .method("g!", [](Color& v, float p){ v.g = p; })
    .method("b!", [](Color& v, float p){ v.b = p; })
    .method("a!", [](Color& v, float p){ v.a = p; })
    .method("set", [](Color& v, const Color& a){ return v.set(a); })
    .method("set", [](Color& v, float a, float b, float c, float d){ return v.set(a,b,c,d); })
    .method("set", [](Color& v, float a, float b, float c){ return v.set(a,b,c); })
    .method("set", [](Color& v, float a, float b){ return v.set(a,b); })
    .method("set", [](Color& v, float a){ return v.set(a); })
    .method("set!", [](Color& v, const Color& a){ return v.set(a); })
    .method("set!", [](Color& v, float a, float b, float c, float d){ return v.set(a,b,c,d); })
    .method("set!", [](Color& v, float a, float b, float c){ return v.set(a,b,c); })
    .method("set!", [](Color& v, float a, float b){ return v.set(a,b); })
    .method("set!", [](Color& v, float a){ return v.set(a); })
    ;

  mod.add_type<Pixels>("Pixels")
    .constructor<>() // FIXME: move constructor?
    ;

  mod.add_type<Mesh>("Mesh")
    .constructor<>()
    .constructor<const Mesh&>()
    // FIXME: move constructor?
    ;

  mod.add_type<Light>("Light")
    .constructor<>()
    ;

  mod.add_type<Material>("Material")
    .constructor<>()
    ;

  mod.add_type<LogStream>("LogStream");

  mod.add_type<FpsSettings>("FpsSettings");

//   mod.add_type<LogStream>("LogStream")
//     .constructor<LogLevel>()
//     .constructor<LogLevel, const std::string&>()
//     ;

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

  mod.add_enum<BlendMode>("BlendMode",
    std::vector<const char*>({
        "Alpha",
        "Add",
        "Multiply",
        "Screen",
        "Subtract",
        "Disabled"
    }),
    std::vector<int>({
        (int)BlendMode::Alpha,
        (int)BlendMode::Add,
        (int)BlendMode::Multiply,
        (int)BlendMode::Screen,
        (int)BlendMode::Subtract,
        (int)BlendMode::Disabled
    }));

  mod.add_enum<TextureFilter>("TextureFilter",
    std::vector<const char*>({
        "Nearest",
        "Linear"
    }),
    std::vector<int>({
        (int)TextureFilter::Nearest,
        (int)TextureFilter::Linear
    }));

  mod.add_enum<TextureWrap>("TextureWrap",
    std::vector<const char*>({
        "Repeat",
        "ClampToEdge",
        "MirroredRepeat"
    }),
    std::vector<int>({
        (int)TextureWrap::Repeat,
        (int)TextureWrap::ClampToEdge,
        (int)TextureWrap::MirroredRepeat
    }));

  mod.add_enum<StrokeCap>("StrokeCap",
    std::vector<const char*>({
        "Butt",
        "Round",
        "Square"
    }),
    std::vector<int>({
        (int)StrokeCap::Butt,
        (int)StrokeCap::Round,
        (int)StrokeCap::Square
    }));

  mod.add_enum<StrokeJoin>("StrokeJoin",
    std::vector<const char*>({
        "Miter",
        "Round",
        "Bevel"
    }),
    std::vector<int>({
        (int)StrokeJoin::Miter,
        (int)StrokeJoin::Round,
        (int)StrokeJoin::Bevel
    }));

  mod.add_enum<Direction>("Direction",
    std::vector<const char*>({
        "Left",
        "Center",
        "Right",
        "Top",
        "Bottom",
        "Baseline"
    }),
    std::vector<int>({
        (int)Direction::Left,
        (int)Direction::Center,
        (int)Direction::Right,
        (int)Direction::Top,
        (int)Direction::Bottom,
        (int)Direction::Baseline
    }));

  mod.add_enum<Cursor>("Cursor",
    std::vector<const char*>({
        "Default",
        "Arrow",
        "IBeam",
        "Crosshair",
        "Hand",
        "ResizeEW",
        "ResizeNS",
        "ResizeNWSE",
        "ResizeNESW",
        "ResizeAll",
        "NotAllowed",
        "Custom0",
        "Custom1",
        "Custom2",
        "Custom3",
        "Custom4",
        "Custom5",
        "Custom6",
        "Custom7",
        "Custom8",
        "Custom9",
        "Custom10",
        "Custom11",
        "Custom12",
        "Custom13",
        "Custom14",
        "Custom15"
    }),
    std::vector<int>({
        (int)Cursor::Default,
        (int)Cursor::Arrow,
        (int)Cursor::IBeam,
        (int)Cursor::Crosshair,
        (int)Cursor::Hand,
        (int)Cursor::ResizeEW,
        (int)Cursor::ResizeNS,
        (int)Cursor::ResizeNWSE,
        (int)Cursor::ResizeNESW,
        (int)Cursor::ResizeAll,
        (int)Cursor::NotAllowed,
        (int)Cursor::Custom0,
        (int)Cursor::Custom1,
        (int)Cursor::Custom2,
        (int)Cursor::Custom3,
        (int)Cursor::Custom4,
        (int)Cursor::Custom5,
        (int)Cursor::Custom6,
        (int)Cursor::Custom7,
        (int)Cursor::Custom8,
        (int)Cursor::Custom9,
        (int)Cursor::Custom10,
        (int)Cursor::Custom11,
        (int)Cursor::Custom12,
        (int)Cursor::Custom13,
        (int)Cursor::Custom14,
        (int)Cursor::Custom15
    }));

    mod.add_enum<Orientation>("Orientation",
        std::vector<const char*>({
            "Portrait",
            "PortraitUpsideDown",
            "LandscapeLeft",
            "LandscapeRight",
            "Landscape",
            "All",
            "AllButUpsideDown"
        }),
        std::vector<uint32_t>({
            (int)Orientation::Portrait,
            (int)Orientation::PortraitUpsideDown,
            (int)Orientation::LandscapeLeft,
            (int)Orientation::LandscapeRight,
            (int)Orientation::Landscape,
            (int)Orientation::All,
            (int)Orientation::AllButUpsideDown
        }));

  mod.add_type<Image>("Image")
    .constructor<>(); // FIXME: move constructor?

  mod.add_type<Shader>("Shader")
    .constructor<>(); // FIXME: move constructor?

  define_julia_module_trussc_generated(mod);
}
