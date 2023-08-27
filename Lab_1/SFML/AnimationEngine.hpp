//
// Created by Mishach on 03.02.2023.
//
#pragma once
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <chrono>
#include <thread>


namespace at {

    class AnimationEngine {   /// Не забыть про const ссылки и функции
    public:
        AnimationEngine(const std::vector<char> &text, int time);
        ~AnimationEngine();
        void run();  // запуск окна с анимацией
    private:
        std::vector<char> _text;
        std::string _textS;
        float _time;
        int delay;
        std::vector<sf::Text> _litters;  // массив из буковок {a, ab, abv}
        sf::Text fullText;
        std::string fullTextStr;


        //Other
        const unsigned int _sizeWinX = 600;
        const unsigned int _sizeWinY = 200;
        sf::Font font;

        //Function
        void countDelay();
        void splitObjects();
        void setFont();
        void generateObject(sf::RenderWindow &window)  const;
//        void animateByClock();
    };

} // at
