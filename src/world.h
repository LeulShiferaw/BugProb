/**
 * \brief This class represents a World object
 * 
 * \file world.h
 * \author Zihan Qi
 * \author Matius Chairani
 * \date 2018-03-04
 */
#ifndef _WORLD_H
#define _WORLD_H

#include <iostream>
#include <vector>
#include <unordered_map>
#include <functional>
#include "cell.h"

// max 200
const int kWidth = 10;
const int kLength = 10;

class World{
    private:
        //vector of Cells
        std::vector <Cell> cells_;
        //hash function for coordinate
        struct pairhash {
            std::size_t operator()(const std::pair<unsigned, unsigned> &x) const{
                return std::hash<int>()(x.first) ^ std::hash<int>()(x.second);
            }
        };
        //hash table, key: coordinate, value: index of cells_ vector, initialized in constructor
        std::unordered_map <std::pair<unsigned, unsigned>, unsigned, pairhash> hash_table_;

    public:
        /**
         * \brief Constructor of World
         */
        World();

        /**
         * \brief Getting function which return the Cell at certain coordinate
         * 
         * \param coordinate coordinate to look at
         * \return Cell Cell at certain coordinate
         */
        Cell& CellAt(std::pair <unsigned, unsigned> coordinate);

        /**
         * \brief Function which return "red" if input is "black", 
         * return "black" if input is "red"
         * 
         * \param color 
         * \return std::string 
         */
        std::string OtherColor(std::string color);
};

#endif
