//
// Created by Mishach on 21.04.2023.
//
#pragma once

#include <iostream>
#include <utility>
#include <vector>
#include <fstream>

#define NUM_OF_BLOCKS 3
#define QUANTITY_OF_BLOCKS 3





class CustomException : public std::exception {
public:
    const char* what()  const noexcept override{
        return "Abobus exception: just Override, Amigoooooo!";
    }

};

class Block {
public:
    virtual void poll() {
        throw CustomException();
        // Некоторая реализация получения данных, которую вам делать
        // не нужно.
    }
    virtual ~Block() = default;

protected:
    std::string type = "Device name";
};

class ElectricCounterBlock : public Block {
public:
    ElectricCounterBlock(std::string type){
        this->type = std::move(type);
    };


    void poll() override {
        std::cout << "ElectricCounterBlock: " << type << std::endl;
    }


private:
    const std::string TYPES[QUANTITY_OF_BLOCKS] =  {"Merkuri 230", "Nev МТ314", "Energomera CE308"};

};


class DiscreteSignalBlock : public Block {
public:
    DiscreteSignalBlock(std::string type) {
        this->type = std::move(type);
    };

    void poll() override {
        std::cout << "DiscreteSignalBlock: " << type << std::endl;
    }

};

class HeatingControlBlock : public Block {
public:

    HeatingControlBlock(std::string type) {
        this->type = std::move(type);
    };

    void poll() override {
        std::cout << "HeatingControlBlock: " << type << std::endl;
    }
};
/// все управление реализованно через Controller
class Controller {
public:
    ~Controller() {
        for (auto & block : blocks)
            delete block;
    };

    /// вызвает метод poll у каждого объекта типа block
    void outBlocks() {
        for (auto &block: blocks)
            block->poll();
    }

    /// считывает counter число приборов из файла
    void readAllBlocks(int counter) {
        std::ifstream file;
        file.open(PATH);
        std::string block;
        while (getline(file, block) and (counter >= 0)) {
            selectBlock(block);
            counter--;
        }
        file.close();
    }

    /// считывает все приборы из файла
    void readAllBlocks() {
        std::ifstream file;
        file.open(PATH);
        std::string block;
        if (file.is_open())
            while (getline(file, block)) {
                selectBlock(block);
            }
        file.close();
    }

    std::vector<Block*> getBlocks(){
        return blocks;
    }

private:
    std::vector<Block *> blocks;  // хранит все блоки
    std::string PATH = "D:\\Development\\C++Project\\Second semester\\Practice_4\\blocks.txt";
    //   std::string PATH = "blocks.txt";
    std::string types[NUM_OF_BLOCKS][QUANTITY_OF_BLOCKS] = {{"Merkuri 230",     "Nev МТ314",            "Energomera CE308"},
                                                            {"Reallab NL-16HV", "PriborElectro PRE-16", "Energoservice ENMV-1-24"},
                                                            {"Ouman S203",      "Oven TPM232"}};
    /// выбор блока
    void selectBlock(const std::string &block) {
        for (int i = 0; i < NUM_OF_BLOCKS; i++) {
            for (const std::string &item: types[i]) {
                if (item == block and (i == 0))
                    blocks.push_back(new ElectricCounterBlock(block));
                else if ((item == block) and (i == 1))
                    blocks.push_back(new DiscreteSignalBlock(block));
                else if ((item == block) and (i == 2))
                    blocks.push_back(new HeatingControlBlock(block));
            }
        }
        /*if ((block == "Merkuri 230") or (block == "Nev МТ314") or (block == "Energomera CE308")) // нужно по нормальному сделать ч-за массивы
            blocks.push_back(new ElectricCounterBlock(block));
        else if ((block == "Reallab NL-16HV") or (block == "PriborElectro PRE-16") or
                 (block == "Energoservice ENMV-1-24"))
            blocks.push_back(new DiscreteSignalBlock(block));
        else if ((block == "Ouman S203") or (block == "Oven TPM232"))
            blocks.push_back(new HeatingControlBlock(block));*/
    }
};
