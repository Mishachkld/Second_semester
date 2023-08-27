//
// Created by Mishach on 01.03.2023.
//
#include "KinematicSolver.hpp"
#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"
#include <cmath>

namespace ks {

    KinematicSolver::KinematicSolver(const int size_x,
                                     const int size_y) //sf::Vector2f a, sf::Vector2f b, sf::Vector2f c)
//            : a(a), b(b), c(c)
    {
        run(size_x, size_y);
    }

    void KinematicSolver::run(int winSizeX, int winSizeY) {
        sf::RenderWindow window(sf::VideoMode(winSizeX, winSizeY), "My window");
        calculate(m_x, m_y);  /// переделать
        while (window.isOpen()) {
            sf::Event event;
            while (window.pollEvent(event)) {
                if (event.type == sf::Event::Closed)
                    window.close();
            }
            window.display();
        }
    }

    void KinematicSolver::calculate(double x, double y) {

        /* alpha = pow((cos((bLen * bLen + cLen * cLen - aLen * aLen) / (2 * bLen * cLen))), (-1));
         beta = pow((cos((aLen * aLen + cLen * cLen - bLen * bLen) / (2 * aLen * cLen))), (-1));
         B = M_PI - beta;
         A = alpha + pow(tan((c.x - A) / (c.y - A)), -1);*/  // c - координаты начала шарнира
        // a^2 = b^2 + c^2 - 2*b*c*cos(alpha)
        // alpha = (cos((b^2 + c^2 - a^2)/2*b*c))^(-1)
        // beta = (cos((a^2 + c^2 - b^2)/2*a*c))^(-1)
        // B = PI - beta
        // A = alpha + A', где A' = (tan( (C - A)y/(C-A)x) )^(-1), (C по y и А по y, аналогично и с иксом)


        B = sqrt(pow(x, 2) + pow(y, 2)); // расстояние от начала до заданной точки
        // углы в радианах в первом случае
        alpha = acos(x / B) - acos((pow(m_L1, 2) - pow(m_L2, 2) + (B * B)) / (2 * B * m_L1));
        beta = acos(-1) - acos((pow(m_L1, 2) + pow(m_L2, 2) - (B * B)) / (2 * m_L1 * m_L2));
        // если ср. точка выше нуля берем углы в первом случае, иначе другие
        if (sin(alpha) >= 0) {
            m_x = m_L1 * cos(alpha);            // координаты средней точки
            m_y = m_L1 * sin(alpha);
        } else {
            alpha = acos(x / B) +
                    acos((pow(m_L1, 2) - pow(m_L2, 2) + (B * B)) / (2 * B * m_L1));     // углы во втором случае
            beta = -beta;
            m_x = m_L1 * cos(alpha);            // координаты средней точки
            m_y = m_L1 * sin(alpha);
        }

        alpha = static_cast<float>(alpha * 180 / acos(-1)); // переводим в градусы
        beta = alpha + static_cast<float>(alpha * 180 / acos(-1));
    }
} // ks