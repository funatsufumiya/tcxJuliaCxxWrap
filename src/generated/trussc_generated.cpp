
// WARNING: This file is auto-generated!

#define TRUSSC_SHOW_CONSOLE 1
#include "TrussC.h"

#include "trussc_generated.h"

using namespace tc;

// WORKAROUND: to support deprecated functions in lua
#ifndef _MSC_VER
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wdeprecated-declarations"
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdeprecated-declarations"
#endif // #ifndef _MSC_VER

JLCXX_MODULE define_julia_module_trussc_generated(jlcxx::Module& mod){

    // tcMath.h, LINE 987
    mod.method("deg2rad", [](float deg){ return trussc::deg2rad(deg); });
    // tcMath.h, LINE 990
    mod.method("rad2deg", [](float rad){ return trussc::rad2deg(rad); });
    // tcMath.h, LINE 993
    mod.method("clamp", [](float value, float min, float max){ return trussc::clamp(value, min, max); });
    // tcMath.h, LINE 998
    mod.method("remap", [](float value, float inMin, float inMax, float outMin, float outMax){ return trussc::remap(value, inMin, inMax, outMin, outMax); });
    // tcMath.h, LINE 1003
    mod.method("sign", [](float value){ return trussc::sign(value); });
    // tcMath.h, LINE 1006
    mod.method("fract", [](float value){ return trussc::fract(value); });
    // tcMath.h, LINE 1009
    mod.method("sq", [](float value){ return trussc::sq(value); });
    // tcMath.h, LINE 1012
    // tcMath.h, LINE 1026
    // tcMath.h, LINE 1030
    mod.method("dist", [](float x1, float y1, float x2, float y2){ return trussc::dist(x1, y1, x2, y2); });
    mod.method("dist", [](const Vec2 & a, const Vec2 & b){ return trussc::dist(a, b); });
    mod.method("dist", [](const Vec3 & a, const Vec3 & b){ return trussc::dist(a, b); });
    // tcMath.h, LINE 1019
    // tcMath.h, LINE 1027
    // tcMath.h, LINE 1031
    mod.method("distSquared", [](float x1, float y1, float x2, float y2){ return trussc::distSquared(x1, y1, x2, y2); });
    mod.method("distSquared", [](const Vec2 & a, const Vec2 & b){ return trussc::distSquared(a, b); });
    mod.method("distSquared", [](const Vec3 & a, const Vec3 & b){ return trussc::distSquared(a, b); });
    // tcMath.h, LINE 1040
    mod.method("wrap", [](float value, float min, float max){ return trussc::wrap(value, min, max); });
    // tcMath.h, LINE 1051
    mod.method("angleDifference", [](float angle1, float angle2){ return trussc::angleDifference(angle1, angle2); });
    // tcMath.h, LINE 1060
    mod.method("angleDifferenceDeg", [](float deg1, float deg2){ return trussc::angleDifferenceDeg(deg1, deg2); });
    // tcMath.h, LINE 1073
    mod.method("getRandomEngine", [](){ return trussc::internal::getRandomEngine(); });
    // tcMath.h, LINE 1080
    // tcMath.h, LINE 1086
    // tcMath.h, LINE 1092
    mod.method("random", [](){ return trussc::random(); });
    mod.method("random", [](float max){ return trussc::random(max); });
    mod.method("random", [](float min, float max){ return trussc::random(min, max); });
    // tcMath.h, LINE 1098
    // tcMath.h, LINE 1104
    mod.method("randomInt", [](int max){ return trussc::randomInt(max); });
    mod.method("randomInt", [](int min, int max){ return trussc::randomInt(min, max); });
    // tcMath.h, LINE 1110
    mod.method("randomSeed", [](unsigned int seed){  trussc::randomSeed(seed); });
    // tcLog.h, LINE 35
    mod.method("logLevelToString", [](LogLevel level){ return trussc::logLevelToString(level); });
    // tcLog.h, LINE 211
    mod.method("tcSetConsoleLogLevel", [](LogLevel level){  trussc::tcSetConsoleLogLevel(level); });
    // tcLog.h, LINE 215
    mod.method("tcSetFileLogLevel", [](LogLevel level){  trussc::tcSetFileLogLevel(level); });
    // tcLog.h, LINE 219
    mod.method("tcSetLogFile", [](const std::string & path){ return trussc::tcSetLogFile(path); });
    // tcLog.h, LINE 223
    mod.method("tcCloseLogFile", [](){  trussc::tcCloseLogFile(); });
    // tcLog.h, LINE 284
    mod.method("tcLog", [](LogLevel level){ return trussc::tcLog(level); });
    // tcLog.h, LINE 288
    mod.method("logVerbose", [](const std::string & module){ return trussc::logVerbose(module); });
    // tcLog.h, LINE 292
    mod.method("logNotice", [](const std::string & module){ return trussc::logNotice(module); });
    // tcLog.h, LINE 296
    mod.method("logWarning", [](const std::string & module){ return trussc::logWarning(module); });
    // tcLog.h, LINE 300
    mod.method("logError", [](const std::string & module){ return trussc::logError(module); });
    // tcLog.h, LINE 304
    mod.method("logFatal", [](const std::string & module){ return trussc::logFatal(module); });
    // tcLog.h, LINE 311
    mod.method("tcLogVerbose", [](const std::string & module){ return trussc::tcLogVerbose(module); });
    // tcLog.h, LINE 312
    mod.method("tcLogNotice", [](const std::string & module){ return trussc::tcLogNotice(module); });
    // tcLog.h, LINE 313
    mod.method("tcLogWarning", [](const std::string & module){ return trussc::tcLogWarning(module); });
    // tcLog.h, LINE 314
    mod.method("tcLogError", [](const std::string & module){ return trussc::tcLogError(module); });
    // tcLog.h, LINE 315
    mod.method("tcLogFatal", [](const std::string & module){ return trussc::tcLogFatal(module); });
    // TrussC.h, LINE 343
    mod.method("getDpiScale", [](){ return trussc::getDpiScale(); });
    // TrussC.h, LINE 348
    mod.method("getFramebufferWidth", [](){ return trussc::getFramebufferWidth(); });
    // TrussC.h, LINE 352
    mod.method("getFramebufferHeight", [](){ return trussc::getFramebufferHeight(); });
    // TrussC.h, LINE 363
    mod.method("beginFrame", [](){  trussc::beginFrame(); });
    // TrussC.h, LINE 379
    // TrussC.h, LINE 382
    // TrussC.h, LINE 387
    // TrussC.h, LINE 392
    mod.method("clear", [](float r, float g, float b, float a){  trussc::clear(r, g, b, a); });
    mod.method("clear", [](){  trussc::clear(); });
    mod.method("clear", [](float gray, float a){  trussc::clear(gray, a); });
    mod.method("clear", [](const Color & c){  trussc::clear(c); });
    mod.method("clear", [](float r){  trussc::clear(r); } /* NOTE: additional overloads provided by user */);
    mod.method("clear", [](float r, float g, float b){  trussc::clear(r, g, b); } /* NOTE: additional overloads provided by user */);
    // TrussC.h, LINE 397
    mod.method("flushDeferredShaderDraws", [](){  trussc::flushDeferredShaderDraws(); });
    // TrussC.h, LINE 404
    mod.method("ensureSwapchainPass", [](){  trussc::ensureSwapchainPass(); });
    // TrussC.h, LINE 407
    mod.method("present", [](){  trussc::present(); });
    // TrussC.h, LINE 410
    mod.method("isInSwapchainPass", [](){ return trussc::isInSwapchainPass(); });
    // TrussC.h, LINE 413
    mod.method("suspendSwapchainPass", [](){  trussc::suspendSwapchainPass(); });
    // TrussC.h, LINE 416
    mod.method("resumeSwapchainPass", [](){  trussc::resumeSwapchainPass(); });
    // TrussC.h, LINE 423
    // TrussC.h, LINE 428
    // TrussC.h, LINE 433
    mod.method("setColor", [](float r, float g, float b, float a){  trussc::setColor(r, g, b, a); });
    mod.method("setColor", [](float gray, float a){  trussc::setColor(gray, a); });
    mod.method("setColor", [](const Color & c){  trussc::setColor(c); });
    mod.method("setColor", [](float r){  trussc::setColor(r); } /* NOTE: additional overloads provided by user */);
    mod.method("setColor", [](float r, float g, float b){  trussc::setColor(r, g, b); } /* NOTE: additional overloads provided by user */);
    // TrussC.h, LINE 438
    mod.method("getColor", [](){ return trussc::getColor(); });
    // TrussC.h, LINE 443
    mod.method("setColorHSB", [](float h, float s, float b, float a){  trussc::setColorHSB(h, s, b, a); });
    mod.method("setColorHSB", [](float h, float s, float b){  trussc::setColorHSB(h, s, b); } /* NOTE: additional overloads provided by user */);
    // TrussC.h, LINE 448
    mod.method("setColorOKLab", [](float L, float a_lab, float b_lab, float alpha){  trussc::setColorOKLab(L, a_lab, b_lab, alpha); });
    // TrussC.h, LINE 453
    mod.method("setColorOKLCH", [](float L, float C, float H, float alpha){  trussc::setColorOKLCH(L, C, H, alpha); });
    // TrussC.h, LINE 458
    mod.method("fill", [](){  trussc::fill(); });
    // TrussC.h, LINE 463
    mod.method("noFill", [](){  trussc::noFill(); });
    // TrussC.h, LINE 468
    mod.method("setStrokeWeight", [](float weight){  trussc::setStrokeWeight(weight); });
    // TrussC.h, LINE 472
    mod.method("getStrokeWeight", [](){ return trussc::getStrokeWeight(); });
    // TrussC.h, LINE 476
    mod.method("setStrokeCap", [](StrokeCap cap){  trussc::setStrokeCap(cap); });
    // TrussC.h, LINE 480
    mod.method("getStrokeCap", [](){ return trussc::getStrokeCap(); });
    // TrussC.h, LINE 484
    mod.method("setStrokeJoin", [](StrokeJoin join){  trussc::setStrokeJoin(join); });
    // TrussC.h, LINE 488
    mod.method("getStrokeJoin", [](){ return trussc::getStrokeJoin(); });
    // TrussC.h, LINE 511
    // TrussC.h, LINE 517
    mod.method("setScissor", [](float x, float y, float w, float h){  trussc::setScissor(x, y, w, h); });
    mod.method("setScissor", [](int x, int y, int w, int h){  trussc::setScissor(x, y, w, h); });
    // TrussC.h, LINE 522
    mod.method("resetScissor", [](){  trussc::resetScissor(); });
    // TrussC.h, LINE 528
    mod.method("pushScissor", [](float x, float y, float w, float h){  trussc::pushScissor(x, y, w, h); });
    // TrussC.h, LINE 546
    mod.method("popScissor", [](){  trussc::popScissor(); });
    // TrussC.h, LINE 568
    mod.method("pushMatrix", [](){  trussc::pushMatrix(); });
    // TrussC.h, LINE 573
    mod.method("popMatrix", [](){  trussc::popMatrix(); });
    // TrussC.h, LINE 578
    mod.method("pushStyle", [](){  trussc::pushStyle(); });
    // TrussC.h, LINE 583
    mod.method("popStyle", [](){  trussc::popStyle(); });
    // TrussC.h, LINE 588
    mod.method("resetStyle", [](){  trussc::resetStyle(); });
    // TrussC.h, LINE 593
    // TrussC.h, LINE 597
    // TrussC.h, LINE 601
    mod.method("translate", [](Vec3 pos){  trussc::translate(pos); });
    mod.method("translate", [](float x, float y, float z){  trussc::translate(x, y, z); });
    mod.method("translate", [](float x, float y){  trussc::translate(x, y); });
    // TrussC.h, LINE 606
    // TrussC.h, LINE 643
    // TrussC.h, LINE 649
    // TrussC.h, LINE 653
    mod.method("rotate", [](float radians){  trussc::rotate(radians); });
    mod.method("rotate", [](float x, float y, float z){  trussc::rotate(x, y, z); });
    mod.method("rotate", [](const Vec3 & euler){  trussc::rotate(euler); });
    mod.method("rotate", [](const Quaternion & quat){  trussc::rotate(quat); });
    // TrussC.h, LINE 611
    mod.method("rotateX", [](float radians){  trussc::rotateX(radians); });
    // TrussC.h, LINE 616
    mod.method("rotateY", [](float radians){  trussc::rotateY(radians); });
    // TrussC.h, LINE 621
    mod.method("rotateZ", [](float radians){  trussc::rotateZ(radians); });
    // TrussC.h, LINE 626
    // TrussC.h, LINE 658
    // TrussC.h, LINE 664
    mod.method("rotateDeg", [](float degrees){  trussc::rotateDeg(degrees); });
    mod.method("rotateDeg", [](float x, float y, float z){  trussc::rotateDeg(x, y, z); });
    mod.method("rotateDeg", [](const Vec3 & euler){  trussc::rotateDeg(euler); });
    // TrussC.h, LINE 630
    mod.method("rotateXDeg", [](float degrees){  trussc::rotateXDeg(degrees); });
    // TrussC.h, LINE 634
    mod.method("rotateYDeg", [](float degrees){  trussc::rotateYDeg(degrees); });
    // TrussC.h, LINE 638
    mod.method("rotateZDeg", [](float degrees){  trussc::rotateZDeg(degrees); });
    // TrussC.h, LINE 669
    // TrussC.h, LINE 674
    // TrussC.h, LINE 679
    mod.method("scale", [](float s){  trussc::scale(s); });
    mod.method("scale", [](float sx, float sy){  trussc::scale(sx, sy); });
    mod.method("scale", [](float sx, float sy, float sz){  trussc::scale(sx, sy, sz); });
    // TrussC.h, LINE 684
    mod.method("getCurrentMatrix", [](){ return trussc::getCurrentMatrix(); });
    // TrussC.h, LINE 689
    mod.method("resetMatrix", [](){  trussc::resetMatrix(); });
    // TrussC.h, LINE 694
    mod.method("setMatrix", [](const Mat4 & mat){  trussc::setMatrix(mat); });
    // TrussC.h, LINE 704
    mod.method("setBlendMode", [](BlendMode mode){  trussc::setBlendMode(mode); });
    // TrussC.h, LINE 713
    mod.method("getBlendMode", [](){ return trussc::getBlendMode(); });
    // TrussC.h, LINE 718
    mod.method("resetBlendMode", [](){  trussc::resetBlendMode(); });
    // TrussC.h, LINE 723
    mod.method("restoreBlendPipeline", [](){  trussc::restoreBlendPipeline(); });
    // TrussC.h, LINE 736
    mod.method("enable3D", [](){  trussc::enable3D(); });
    // TrussC.h, LINE 745
    mod.method("enable3DPerspective", [](float fovY, float nearZ, float farZ){  trussc::enable3DPerspective(fovY, nearZ, farZ); });
    // TrussC.h, LINE 866
    mod.method("setupScreenFov", [](float fovDeg, float nearDist, float farDist){  trussc::setupScreenFov(fovDeg, nearDist, farDist); });
    // TrussC.h, LINE 873
    mod.method("setupScreenPerspective", [](float fovDeg, float nearDist, float farDist){  trussc::setupScreenPerspective(fovDeg, nearDist, farDist); });
    // TrussC.h, LINE 878
    mod.method("setupScreenOrtho", [](){  trussc::setupScreenOrtho(); });
    // TrussC.h, LINE 884
    mod.method("setDefaultScreenFov", [](float fovDeg){  trussc::setDefaultScreenFov(fovDeg); });
    // TrussC.h, LINE 888
    mod.method("getDefaultScreenFov", [](){ return trussc::getDefaultScreenFov(); });
    // TrussC.h, LINE 893
    mod.method("setNearClip", [](float nearDist){  trussc::setNearClip(nearDist); });
    // TrussC.h, LINE 897
    mod.method("setFarClip", [](float farDist){  trussc::setFarClip(farDist); });
    // TrussC.h, LINE 901
    mod.method("getNearClip", [](){ return trussc::getNearClip(); });
    // TrussC.h, LINE 905
    mod.method("getFarClip", [](){ return trussc::getFarClip(); });
    // TrussC.h, LINE 915
    mod.method("worldToScreen", [](const Vec3 & worldPos){ return trussc::worldToScreen(worldPos); });
    // TrussC.h, LINE 944
    mod.method("screenToWorld", [](const Vec2 & screenPos, float worldZ){ return trussc::screenToWorld(screenPos, worldZ); });
    // TrussC.h, LINE 990
    mod.method("disable3D", [](){  trussc::disable3D(); });
    // TrussC.h, LINE 999
    // TrussC.h, LINE 1003
    // TrussC.h, LINE 1007
    mod.method("drawRect", [](Vec3 pos, Vec2 size){  trussc::drawRect(pos, size); });
    mod.method("drawRect", [](Vec3 pos, float w, float h){  trussc::drawRect(pos, w, h); });
    mod.method("drawRect", [](float x, float y, float w, float h){  trussc::drawRect(x, y, w, h); });
    // TrussC.h, LINE 1012
    // TrussC.h, LINE 1016
    mod.method("drawRectRounded", [](Vec3 pos, Vec2 size, float radius){  trussc::drawRectRounded(pos, size, radius); });
    mod.method("drawRectRounded", [](float x, float y, float w, float h, float radius){  trussc::drawRectRounded(x, y, w, h, radius); });
    // TrussC.h, LINE 1021
    // TrussC.h, LINE 1025
    mod.method("drawRectSquircle", [](Vec3 pos, Vec2 size, float radius){  trussc::drawRectSquircle(pos, size, radius); });
    mod.method("drawRectSquircle", [](float x, float y, float w, float h, float radius){  trussc::drawRectSquircle(x, y, w, h, radius); });
    // TrussC.h, LINE 1030
    // TrussC.h, LINE 1034
    mod.method("drawCircle", [](Vec3 center, float radius){  trussc::drawCircle(center, radius); });
    mod.method("drawCircle", [](float cx, float cy, float radius){  trussc::drawCircle(cx, cy, radius); });
    // TrussC.h, LINE 1039
    // TrussC.h, LINE 1043
    // TrussC.h, LINE 1047
    mod.method("drawEllipse", [](Vec3 center, Vec2 radii){  trussc::drawEllipse(center, radii); });
    mod.method("drawEllipse", [](Vec3 center, float rx, float ry){  trussc::drawEllipse(center, rx, ry); });
    mod.method("drawEllipse", [](float cx, float cy, float rx, float ry){  trussc::drawEllipse(cx, cy, rx, ry); });
    // TrussC.h, LINE 1052
    // TrussC.h, LINE 1056
    // TrussC.h, LINE 1060
    mod.method("drawLine", [](Vec3 p1, Vec3 p2){  trussc::drawLine(p1, p2); });
    mod.method("drawLine", [](float x1, float y1, float x2, float y2){  trussc::drawLine(x1, y1, x2, y2); });
    mod.method("drawLine", [](float x1, float y1, float z1, float x2, float y2, float z2){  trussc::drawLine(x1, y1, z1, x2, y2, z2); });
    // TrussC.h, LINE 1065
    // TrussC.h, LINE 1069
    mod.method("drawTriangle", [](Vec3 p1, Vec3 p2, Vec3 p3){  trussc::drawTriangle(p1, p2, p3); });
    mod.method("drawTriangle", [](float x1, float y1, float x2, float y2, float x3, float y3){  trussc::drawTriangle(x1, y1, x2, y2, x3, y3); });
    // TrussC.h, LINE 1074
    // TrussC.h, LINE 1078
    mod.method("drawPoint", [](Vec3 pos){  trussc::drawPoint(pos); });
    mod.method("drawPoint", [](float x, float y){  trussc::drawPoint(x, y); });
    // TrussC.h, LINE 1083
    mod.method("setCircleResolution", [](int res){  trussc::setCircleResolution(res); });
    // TrussC.h, LINE 1087
    mod.method("getCircleResolution", [](){ return trussc::getCircleResolution(); });
    // TrussC.h, LINE 1092
    mod.method("isFillEnabled", [](){ return trussc::isFillEnabled(); });
    // TrussC.h, LINE 1096
    mod.method("isStrokeEnabled", [](){ return trussc::isStrokeEnabled(); });
    // TrussC.h, LINE 1130
    // TrussC.h, LINE 1134
    // TrussC.h, LINE 1139
    // TrussC.h, LINE 1143
    // TrussC.h, LINE 1148
    // TrussC.h, LINE 1153
    mod.method("drawBitmapString", [](const std::string & text, Vec3 pos, bool screenFixed){  trussc::drawBitmapString(text, pos, screenFixed); });
    mod.method("drawBitmapString", [](const std::string & text, float x, float y, bool screenFixed){  trussc::drawBitmapString(text, x, y, screenFixed); });
    mod.method("drawBitmapString", [](const std::string & text, Vec3 pos, float scale){  trussc::drawBitmapString(text, pos, scale); });
    mod.method("drawBitmapString", [](const std::string & text, float x, float y, float scale){  trussc::drawBitmapString(text, x, y, scale); });
    mod.method("drawBitmapString", [](const std::string & text, Vec3 pos, Direction h, Direction v){  trussc::drawBitmapString(text, pos, h, v); });
    mod.method("drawBitmapString", [](const std::string & text, float x, float y, Direction h, Direction v){  trussc::drawBitmapString(text, x, y, h, v); });
    mod.method("drawBitmapString", [](const std::string& s, float x, float y){  trussc::drawBitmapString(s, x, y); } /* NOTE: additional overloads provided by user */);
    // TrussC.h, LINE 1159
    mod.method("setTextAlign", [](Direction h, Direction v){  trussc::setTextAlign(h, v); });
    // TrussC.h, LINE 1164
    mod.method("getTextAlignH", [](){ return trussc::getTextAlignH(); });
    // TrussC.h, LINE 1168
    mod.method("getTextAlignV", [](){ return trussc::getTextAlignV(); });
    // TrussC.h, LINE 1173
    mod.method("setBitmapLineHeight", [](float h){  trussc::setBitmapLineHeight(h); });
    // TrussC.h, LINE 1178
    mod.method("getBitmapLineHeight", [](){ return trussc::getBitmapLineHeight(); });
    // TrussC.h, LINE 1183
    mod.method("getBitmapFontHeight", [](){ return trussc::getBitmapFontHeight(); });
    // TrussC.h, LINE 1188
    mod.method("getBitmapStringWidth", [](const std::string & text){ return trussc::getBitmapStringWidth(text); });
    // TrussC.h, LINE 1193
    mod.method("getBitmapStringHeight", [](const std::string & text){ return trussc::getBitmapStringHeight(text); });
    // TrussC.h, LINE 1198
    mod.method("getBitmapStringBBox", [](const std::string & text){ return trussc::getBitmapStringBBox(text); });
    // TrussC.h, LINE 1203
    mod.method("drawBitmapStringHighlight", [](const std::string & text, float x, float y, const Color & background, const Color & foreground){  trussc::drawBitmapStringHighlight(text, x, y, background, foreground); });
    mod.method("drawBitmapStringHighlight", [](const std::string& s, float x, float y){  trussc::drawBitmapStringHighlight(s, x, y); } /* NOTE: additional overloads provided by user */);
    // TrussC.h, LINE 1309
    mod.method("setWindowTitle", [](const std::string & title){  trussc::setWindowTitle(title); });
    // TrussC.h, LINE 1349
    mod.method("showCursor", [](){  trussc::showCursor(); });
    // TrussC.h, LINE 1354
    mod.method("hideCursor", [](){  trussc::hideCursor(); });
    // TrussC.h, LINE 1359
    mod.method("setCursor", [](Cursor cursor){  trussc::setCursor(cursor); });
    // TrussC.h, LINE 1364
    mod.method("getCursor", [](){ return trussc::getCursor(); });
    // TrussC.h, LINE 1370
    // TrussC.h, LINE 2526
    mod.method("bindCursorImage", [](Cursor cursor, int width, int height, const unsigned char * pixels, int hotspotX, int hotspotY){  trussc::bindCursorImage(cursor, width, height, pixels, hotspotX, hotspotY); });
    mod.method("bindCursorImage", [](Cursor cursor, const Image & image, int hotspotX, int hotspotY){  trussc::bindCursorImage(cursor, image, hotspotX, hotspotY); });
    // TrussC.h, LINE 1386
    mod.method("unbindCursorImage", [](Cursor cursor){  trussc::unbindCursorImage(cursor); });
    // TrussC.h, LINE 1395
    mod.method("setClipboardString", [](const std::string & text){  trussc::setClipboardString(text); });
    // TrussC.h, LINE 1404
    mod.method("getClipboardString", [](){ return trussc::getClipboardString(); });
    // TrussC.h, LINE 1412
    mod.method("setWindowSize", [](int width, int height){  trussc::setWindowSize(width, height); });
    // TrussC.h, LINE 1424
    mod.method("setFullscreen", [](bool full){  trussc::setFullscreen(full); });
    // TrussC.h, LINE 1431
    mod.method("isFullscreen", [](){ return trussc::isFullscreen(); });
    // TrussC.h, LINE 1436
    mod.method("toggleFullscreen", [](){  trussc::toggleFullscreen(); });
    // TrussC.h, LINE 1466
    mod.method("setOrientation", [](Orientation mask){  trussc::setOrientation(mask); });
    // TrussC.h, LINE 1473
    mod.method("getWindowWidth", [](){ return trussc::getWindowWidth(); });
    // TrussC.h, LINE 1481
    mod.method("getWindowHeight", [](){ return trussc::getWindowHeight(); });
    // TrussC.h, LINE 1489
    mod.method("getWindowSize", [](){ return trussc::getWindowSize(); });
    // TrussC.h, LINE 1494
    mod.method("getAspectRatio", [](){ return trussc::getAspectRatio(); });
    // TrussC.h, LINE 1502
    mod.method("getElapsedTime", [](){ return trussc::getElapsedTime(); });
    // TrussC.h, LINE 1515
    mod.method("getUpdateCount", [](){ return trussc::getUpdateCount(); });
    // TrussC.h, LINE 1520
    mod.method("getDrawCount", [](){ return trussc::getDrawCount(); });
    // TrussC.h, LINE 1525
    mod.method("getFrameCount", [](){ return trussc::getFrameCount(); });
    // TrussC.h, LINE 1529
    mod.method("getDeltaTime", [](){ return trussc::getDeltaTime(); });
    // TrussC.h, LINE 1534
    mod.method("getFrameRate", [](){ return trussc::getFrameRate(); });
    // TrussC.h, LINE 1561
    mod.method("getSokolMemoryBytes", [](){ return trussc::getSokolMemoryBytes(); });
    // TrussC.h, LINE 1564
    mod.method("getSokolMemoryAllocs", [](){ return trussc::getSokolMemoryAllocs(); });
    // TrussC.h, LINE 1569
    mod.method("releaseSglBuffers", [](){  trussc::releaseSglBuffers(); });
    // TrussC.h, LINE 1578
    mod.method("getGlobalMouseX", [](){ return trussc::getGlobalMouseX(); });
    // TrussC.h, LINE 1583
    mod.method("getGlobalMouseY", [](){ return trussc::getGlobalMouseY(); });
    // TrussC.h, LINE 1588
    mod.method("getGlobalPMouseX", [](){ return trussc::getGlobalPMouseX(); });
    // TrussC.h, LINE 1593
    mod.method("getGlobalPMouseY", [](){ return trussc::getGlobalPMouseY(); });
    // TrussC.h, LINE 1598
    mod.method("isMousePressed", [](){ return trussc::isMousePressed(); });
    // TrussC.h, LINE 1603
    mod.method("getMouseButton", [](){ return trussc::getMouseButton(); });
    // TrussC.h, LINE 1608
    mod.method("isKeyPressed", [](int key){ return trussc::isKeyPressed(key); });
    // TrussC.h, LINE 1613
    mod.method("getMouseX", [](){ return trussc::getMouseX(); });
    // TrussC.h, LINE 1614
    mod.method("getMouseY", [](){ return trussc::getMouseY(); });
    // TrussC.h, LINE 1615
    mod.method("getMousePos", [](){ return trussc::getMousePos(); });
    // TrussC.h, LINE 1616
    mod.method("getGlobalMousePos", [](){ return trussc::getGlobalMousePos(); });
    // TrussC.h, LINE 1624
    mod.method("setTouchAsMouse", [](bool enabled){  trussc::setTouchAsMouse(enabled); });
    // TrussC.h, LINE 1625
    mod.method("getTouchAsMouse", [](){ return trussc::getTouchAsMouse(); });
    // TrussC.h, LINE 1632
    mod.method("getBackendName", [](){ return trussc::getBackendName(); });
    // TrussC.h, LINE 1646
    mod.method("getMemoryUsage", [](){ return trussc::getMemoryUsage(); });
    // TrussC.h, LINE 1686
    mod.method("getNodeCount", [](){ return trussc::getNodeCount(); });
    // TrussC.h, LINE 1687
    mod.method("getTextureCount", [](){ return trussc::getTextureCount(); });
    // TrussC.h, LINE 1688
    mod.method("getFboCount", [](){ return trussc::getFboCount(); });
    // TrussC.h, LINE 1712
    mod.method("setFps", [](float fps){  trussc::setFps(fps); });
    // TrussC.h, LINE 1722
    mod.method("setIndependentFps", [](float updateFps, float drawFps){  trussc::setIndependentFps(updateFps, drawFps); });
    // TrussC.h, LINE 1731
    mod.method("getFpsSettings", [](){ return trussc::getFpsSettings(); });
    // TrussC.h, LINE 1751
    mod.method("getFps", [](){ return trussc::getFps(); });
    // TrussC.h, LINE 1757
    mod.method("redraw", [](int count){  trussc::redraw(count); });
    // TrussC.h, LINE 1765
    mod.method("requestExitApp", [](){  trussc::requestExitApp(); });
    // TrussC.h, LINE 1771
    mod.method("exitApp", [](){  trussc::exitApp(); });
    // TrussC.h, LINE 1781
    mod.method("grabScreen", [](Pixels & outPixels){ return trussc::grabScreen(outPixels); });
    // TrussC.h, LINE 1920
    mod.method("registerInspectionTools", [](){  trussc::mcp::registerInspectionTools(); });
    // TrussC.h, LINE 1921
    mod.method("registerDebuggerTools", [](){  trussc::mcp::registerDebuggerTools(); });
    // tcPrimitives.h, LINE 11
    mod.method("createPlane", [](float width, float height, int cols, int rows){ return trussc::createPlane(width, height, cols, rows); });
    // tcPrimitives.h, LINE 47
    // tcPrimitives.h, LINE 102
    mod.method("createBox", [](float width, float height, float depth){ return trussc::createBox(width, height, depth); });
    mod.method("createBox", [](float size){ return trussc::createBox(size); });
    // tcPrimitives.h, LINE 109
    mod.method("createSphere", [](float radius, int resolution){ return trussc::createSphere(radius, resolution); });
    // tcPrimitives.h, LINE 168
    mod.method("createCylinder", [](float radius, float height, int resolution){ return trussc::createCylinder(radius, height, resolution); });
    // tcPrimitives.h, LINE 255
    mod.method("createCone", [](float radius, float height, int resolution){ return trussc::createCone(radius, height, resolution); });
    // tcPrimitives.h, LINE 327
    mod.method("createIcoSphere", [](float radius, int subdivisions){ return trussc::createIcoSphere(radius, subdivisions); });
    // tcPrimitives.h, LINE 430
    mod.method("createTorus", [](float radius, float tubeRadius, int sides, int rings){ return trussc::createTorus(radius, tubeRadius, sides, rings); });
    // TrussC.h, LINE 2570
    // TrussC.h, LINE 2579
    // TrussC.h, LINE 2583
    // TrussC.h, LINE 2590
    // TrussC.h, LINE 2594
    // TrussC.h, LINE 2598
    mod.method("drawBox", [](float w, float h, float d){  trussc::drawBox(w, h, d); });
    mod.method("drawBox", [](float size){  trussc::drawBox(size); });
    mod.method("drawBox", [](Vec3 pos, float w, float h, float d){  trussc::drawBox(pos, w, h, d); });
    mod.method("drawBox", [](float x, float y, float z, float w, float h, float d){  trussc::drawBox(x, y, z, w, h, d); });
    mod.method("drawBox", [](Vec3 pos, float size){  trussc::drawBox(pos, size); });
    mod.method("drawBox", [](float x, float y, float z, float size){  trussc::drawBox(x, y, z, size); });
    // TrussC.h, LINE 2602
    // TrussC.h, LINE 2611
    // TrussC.h, LINE 2618
    mod.method("drawSphere", [](float radius, int resolution){  trussc::drawSphere(radius, resolution); });
    mod.method("drawSphere", [](Vec3 pos, float radius, int resolution){  trussc::drawSphere(pos, radius, resolution); });
    mod.method("drawSphere", [](float x, float y, float z, float radius, int resolution){  trussc::drawSphere(x, y, z, radius, resolution); });
    // TrussC.h, LINE 2622
    // TrussC.h, LINE 2631
    // TrussC.h, LINE 2638
    mod.method("drawCone", [](float radius, float height, int resolution){  trussc::drawCone(radius, height, resolution); });
    mod.method("drawCone", [](Vec3 pos, float radius, float height, int resolution){  trussc::drawCone(pos, radius, height, resolution); });
    mod.method("drawCone", [](float x, float y, float z, float radius, float height, int resolution){  trussc::drawCone(x, y, z, radius, height, resolution); });
    // tc3DGraphics.h, LINE 25
    mod.method("addLight", [](Light & light){  trussc::addLight(light); });
    // tc3DGraphics.h, LINE 37
    mod.method("removeLight", [](Light & light){  trussc::removeLight(light); });
    // tc3DGraphics.h, LINE 46
    mod.method("clearLights", [](){  trussc::clearLights(); });
    // tc3DGraphics.h, LINE 51
    mod.method("getNumLights", [](){ return trussc::getNumLights(); });
    // tc3DGraphics.h, LINE 60
    mod.method("setMaterial", [](Material & material){  trussc::setMaterial(material); });
    // tc3DGraphics.h, LINE 65
    mod.method("clearMaterial", [](){  trussc::clearMaterial(); });
    // tc3DGraphics.h, LINE 76
    mod.method("beginShadowPass", [](Light & light){  trussc::beginShadowPass(light); });
    // tc3DGraphics.h, LINE 85
    mod.method("endShadowPass", [](){  trussc::endShadowPass(); });
    // tc3DGraphics.h, LINE 90
    mod.method("shadowDraw", [](const Mesh & mesh){  trussc::shadowDraw(mesh); });
    // tc3DGraphics.h, LINE 98
    // tc3DGraphics.h, LINE 102
    mod.method("setCameraPosition", [](const Vec3 & pos){  trussc::setCameraPosition(pos); });
    mod.method("setCameraPosition", [](float x, float y, float z){  trussc::setCameraPosition(x, y, z); });
    // tc3DGraphics.h, LINE 106
    mod.method("getCameraPosition", [](){ return trussc::getCameraPosition(); });


}

#ifndef _MSC_VER
#pragma GCC diagnostic pop
#pragma clang diagnostic pop
#endif // #ifndef _MSC_VER
