#include "Blocks/Blocks.hpp"

int main() {
    Block *block = new Block();
    try {
        block->poll();
    } catch (const CustomException e) {
        std::cout << e.what() << std::endl;
    }
    Controller *controller = new Controller();
    controller->readAllBlocks();
    controller->outBlocks();
    return 0;
}
