#include "AnimatedText.hpp"


namespace at {
    AnimatedText::AnimatedText(std::string &text, int time) {
        _text = text;
        _time = time;
        split();
        startAnimation();
    }

    AnimatedText::~AnimatedText() {
        delete engine;
    }

    void AnimatedText::split() {
        for(char i:_text)
            splitText.push_back((i));
    }

    void AnimatedText::startAnimation() {
        engine = new AnimationEngine(splitText, _time);
        engine->run();
    }


} // at