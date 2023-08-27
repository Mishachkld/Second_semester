//
// Created by Mishach on 03.02.2023.
//
#include "AnimationEngine.hpp"

namespace at {

    AnimationEngine::AnimationEngine(const std::vector<char> &text, int time) {
        _text = text;
        _time = static_cast<float> (time);
        countDelay();
        setFont();
    }

    AnimationEngine::~AnimationEngine() {}

    void AnimationEngine::run() {
        splitObjects();
        sf::RenderWindow window(sf::VideoMode(_sizeWinX, _sizeWinY), "Text");
        generateObject(window);
        while (window.isOpen()) {
            sf::Event event;
            while (window.pollEvent(event)) {
                if (event.type == sf::Event::Closed)
                    window.close();
            }
        }
    }

    void AnimationEngine::countDelay() {
        delay = static_cast<int>(((_time / static_cast<float> (_text.size())) * 1000));
    }

    void AnimationEngine::splitObjects() {  /// создается массив из буковок текста
        int distance = 24;
        for (int i = 0; i < _text.size(); i++) {
            fullTextStr.push_back(_text[i]);
            sf::Text text(fullTextStr, font, 32);
            _litters.emplace_back(text);
            _litters[i].setPosition(distance, _sizeWinY / 2 - 32);
        }
    }

    void AnimationEngine::setFont() {
        font.loadFromFile("../arialmt.ttf");
    }

    void AnimationEngine::generateObject (sf::RenderWindow &window)   const{
        for (const sf::Text &litter: _litters) {
            window.clear();
            window.draw(litter);
            window.display();
            int timestamp = std::clock();
//            litter.setString(animateByClock(timestamp / 1000 + 1)); // переделать через clock


            std::this_thread::sleep_for(std::chrono::milliseconds(delay));   // костыли / переделать через clock

        }
    }

//    int AnimationEngine::animateByClock(int timestamp) {  // переделать через clock
////        int seconds = timestamp % (duaration + 1);
////        std::string cropped_text = text.substr(0, text.size() * seconds / delay);
//        return cropped_text;
//
//    }
} // at