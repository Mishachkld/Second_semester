#include "block.hpp"
#include <SFML/Graphics.hpp>

namespace cr_lvl {

    Block::Block(X_Y size, my_color color) {
        block = new sf::RectangleShape(sf::Vector2f(size.x, size.y));
        
        //block->setTexture(texture);
        //block->setFillColor(sf::Color(color.r, color.g, color.b));
    };
    void Block::set_texture(std::string text_name) {
        texture.loadFromFile( "../Titles/" ]+ text_name);
        block->setTexture(&texture);
    };

    sf::RectangleShape* Block::return_block(){ return block; };

    Block::~Block() {}
}