#pragma once

#define TRUSSC_SHOW_CONSOLE 1
#include "TrussC.h"

#include "jlcxx/jlcxx.hpp"
#include "jlcxx/stl.hpp"

template<typename TweenT, typename TweenValue>
void defineTween(jlcxx::Module& mod, std::string name){
    using EaseType = trussc::EaseType;
    using EaseMode = trussc::EaseMode;

    mod.add_type<TweenT>(name)
        .constructor<>()
        .constructor<TweenValue, TweenValue, float>()
        .constructor<TweenValue, TweenValue, float, EaseType>()
        .constructor<TweenValue, TweenValue, float, EaseType, EaseMode>()
        // FIXME: move constructor?
        .method("from", &TweenT::from)
        .method("to", &TweenT::to)
        .method("duration", &TweenT::duration)
        .method("ease", [](TweenT& x, EaseType t) -> TweenT& { return x.ease(t); })
        .method("ease", [](TweenT& x, EaseType t, EaseMode m) -> TweenT& { return x.ease(t, m); })
        .method("ease", [](TweenT& x, EaseType t, EaseType o) -> TweenT& { return x.ease(t, o); })
        .method("loop", &TweenT::loop)
        .method("yoyo", &TweenT::yoyo)
        .method("delay", &TweenT::delay)
        .method("start", &TweenT::start)
        .method("pause", &TweenT::pause)
        .method("resume", &TweenT::resume)
        .method("reset", &TweenT::reset)
        .method("finish", &TweenT::finish)
        .method("getValue", &TweenT::getValue)
        .method("getProgress", &TweenT::getProgress)
        .method("getElapsed", &TweenT::getElapsed)
        .method("getDuration", &TweenT::getDuration)
        .method("isPlaying", &TweenT::isPlaying)
        .method("isComplete", &TweenT::isComplete)
        .method("getStart", &TweenT::getStart)
        .method("getEnd", &TweenT::getEnd)
        .method("getLoopCount", &TweenT::getLoopCount)
        ;
}
