#include <SFML/Graphics.hpp>
#include <filesystem>
#include <iostream>
#include <chrono>
#include <thread>
#include <time.h>
#include "block.hpp"


// min + (rand() % static_cast<int>(max - min + 1))

int main()
{
    int start;
    X_Y window_size = { 1920,1080 };
    X_Y block_size = { 50,50 };
    std::vector<cr_lvl::Block> blocks;
    std::vector<my_color> colors;
    std::vector<std::string> files;
    bool flag_grid = false;
    bool flag_stop = true;
    bool mouse_left_togle = false;
    bool mouse_right_togle = false;
    int color = 1;
    X_Y size_block_title = { 300, 50 };

    // Поиск тайтлов
    const std::filesystem::path my_path{ "../Titles" };
    for (auto const& dir_entry : std::filesystem::recursive_directory_iterator{ my_path }){
        if (dir_entry.is_regular_file())
            files.push_back(dir_entry.path().string());
    }
    for (int i = 0; i < files.size(); i++) {
        if (files[i].find_last_of('\\') != std::string::npos)
            start = files[i].find_last_of('\\') + 1;
        else start = 2;
        files[i] = files[i].substr(start, files[i].size() - 1);
    }
    for (int i = 0; i < files.size(); i++) {
        std::cout << files[i] << std::endl;
    }
    
    sf::RenderWindow window(sf::VideoMode(window_size.x, window_size.y), "Life Game", sf::Style::Fullscreen);
    
    colors = { { 255, 255, 255 }, { 255, 255, 0 },{ 255, 0, 255 }, { 0, 255, 255 } ,{ 255, 0, 0 },{ 0, 255, 0 },{ 0, 0, 255 },{ 0, 0, 0 } };
    for (int i = 0; i < files.size(); ++i) {
        blocks.emplace_back(block_size, colors[i]);
        blocks[i].set_texture(files[i]);
    }
    
    window.setFramerateLimit(1200);
    sf::RectangleShape gridx(sf::Vector2f(window_size.x, 2));
    gridx.setFillColor(sf::Color(130,130,130));
    sf::RectangleShape gridy(sf::Vector2f(2, window_size.y));
    gridy.setFillColor(sf::Color(130, 130, 130));


    std::vector<std::vector<int>> blocks_grid;
    blocks_grid.resize((window_size.x-size_block_title.x)/block_size.x+1);

    for (int i = 0; i < blocks_grid.size(); i++) {
        blocks_grid[i].resize((window_size.y - size_block_title.y) / block_size.y+1);
    }

    std::vector<sf::Texture> textures;
    textures.emplace_back();
    textures[0].loadFromFile("green.png");
    blocks[0].return_block()->setTexture(&textures[0], false);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Escape)
                    window.close();
                if (event.key.code == sf::Keyboard::Space)
                    flag_stop = !flag_stop;
                if (event.key.code == sf::Keyboard::G)
                    flag_grid = !flag_grid;
                if (event.key.code == sf::Keyboard::Num1)
                    color = 1;
                if (event.key.code == sf::Keyboard::Num2)
                    color = 2;
                if (event.key.code == sf::Keyboard::Num3)
                    color = 3;
                if (event.key.code == sf::Keyboard::Num4)
                    color = 4;
                if (event.key.code == sf::Keyboard::Num5)
                    color = 5;
                if (event.key.code == sf::Keyboard::Num6)
                    color = 6;
                if (event.key.code == sf::Keyboard::Num7)
                    color = 7;
                if (event.key.code == sf::Keyboard::Num8)
                    color = 8;
                if (event.key.code == sf::Keyboard::Num9)
                    color = 9;
            }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::C)) {
                    for (int i = 0; i < blocks_grid.size(); i++) {
                        for (int j = 0; j < blocks_grid[i].size(); j++) {
                            blocks_grid[i][j] = 0;
                        }
                    }
                }
            }
        // Проверка нажатия мыши
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
            mouse_left_togle = true;
        else
            mouse_left_togle = false;

        if (sf::Mouse::isButtonPressed(sf::Mouse::Right))
            mouse_right_togle = true;
        else
            mouse_right_togle = false;

        // Рисование
        sf::Vector2i position = sf::Mouse::getPosition();
        //std::cout << position.x << std::endl;
        if (position.x > size_block_title.x && position.y > size_block_title.y)
            if (0 <= position.x / block_size.x+1 <= blocks_grid.size() && 0 <= position.y / block_size.y + 1 <= blocks_grid[0].size()) {
                if (mouse_left_togle) {
                    blocks_grid[(position.x-size_block_title.x) / block_size.x][(position.y - size_block_title.y )/ block_size.y] = color;
                }
                if (mouse_right_togle) {
                    blocks_grid[(position.x - size_block_title.x) / block_size.x][(position.y-size_block_title.y) / block_size.y] = 0;
                }
            }
        // Отрисовка
        window.clear(sf::Color(100, 100, 100));//sf::Color(255,255,255));
        for (int i = 0; i < blocks_grid.size(); i++) {
            for (int j = 0; j < blocks_grid[i].size(); j++) {
                for (int k = 1; k < colors.size()+1; k++)
                if (blocks_grid[i][j] == k && blocks.size()>=k) {
                    blocks[k-1].return_block()->setPosition((i * block_size.x + size_block_title.x), j * block_size.y + size_block_title.y);
                    window.draw(*blocks[k - 1].return_block());
                }
            }
        }
        // Сетка
        if (flag_grid)
            for (int i = 0; i < blocks_grid.size(); i++) {
                gridy.setPosition(i * block_size.x, 0);
                window.draw(gridy);
                gridx.setPosition(0, i* block_size.y);
                window.draw(gridx);
            }
        window.display();
    }
    return 0;
}