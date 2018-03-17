/**
 * \brief Implement of World class
 * 
 * \file world.cc
 * \author Zihan Qi
 * \author Matius Chairani
 * \date 2018-03-04
 */

#include <iostream>
#include <vector>
#include <unordered_map>
#include <functional>
#include "world.h"

extern const int kWidth;
extern const int kLength;

World::World() {
    unsigned index = 0;
    for (unsigned i = 0; i < kLength; ++i) {
        for (unsigned j = 0; j < kWidth; ++j){
            //hash table, key: coordinate, value: index of cells_ vector, initialized in constructor
            hash_table_[std::make_pair(i, j)] = index++; 
            //cells initialized to be clear
            cells_.push_back(Cell(std::make_pair(i, j), 0));
        }
    }
}

Cell& World::CellAt(std::pair <unsigned, unsigned> coordinate) {
    return cells_[hash_table_[coordinate]];
}

std::string World::OtherColor(std::string color) {
    if(color != "black" && color != "red")
        throw std::invalid_argument("Invalid color value.");
    return color == "red" ? "black" : "red";
}