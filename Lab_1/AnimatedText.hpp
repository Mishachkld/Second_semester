//
// Created by Mishach on 28.01.2023.

#include <string>
#include <vector>
#include "SFML/AnimationEngine.hpp"

#pragma once

namespace at {

    class AnimatedText {
    public:
        AnimatedText(std::string &text, int time);
        ~AnimatedText();
        void startAnimation();
    private:
        int _time;
        std::string _text;
        std::vector<char> splitText;
        AnimationEngine* engine;

        //Functions
        void split();


    };

} // at

