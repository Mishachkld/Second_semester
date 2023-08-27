//
// Created by Mishach on 01.03.2023.
//
#pragma once
#include "SFML/Window.hpp"


namespace ks {
    class KinematicSolver {
    public:
        KinematicSolver(const int size_x, const int size_y);
        //KinematicSolver(const int size_x, const int size_y, sf::Vector2f a, sf::Vector2f b, sf::Vector2f c);
    private:
        int m_L1 = 0; // длины колен
        int m_L2 = 0;
        double m_x = 0; // координаты среденей точки
        double m_y = 0;
        //sf::Vector2f a, b, c; //первая сторона треугольника
        //int aLen,bLen,cLen; //вторая сторона треугольника
        double A, B;
        double alpha, beta;
        void calculate(double x, double y);
        void  run(int winSizeX, int winSizeY );
    };
} // ks


