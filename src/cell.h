/**
 * \brief This class represents a Cell object
 * 
 * A Cell is the basic unit of bug world
 * which is a hexagonal grid
 * which is adjacent to six other Cells
 * 
 * \file cell.h
 * \author Zihan Qi
 * \author Matius Chairani
 * \date 2018-03-04
 */
#ifndef _CELL_H
#define _CELL_H

#include <iostream>
#include "bug.h"

class Cell{
    private:
        //Bug in the Cell
        Bug bug_;
        //coordinate of current Cell
        std::pair <unsigned, unsigned> coordinate_;
        //if a Cell is occupied by a Bug
        bool is_occupied_;
        //if a Cell is rocky or clear
        bool is_obstructed_;
        //non-negative number of food particles in a Cell
        unsigned number_of_food_;

        //std::string color_;
        //std::set <Marker> marker_;
    
    public:
        /**
         * \brief Constructor of a Cell object
         * 
         * \param coordinate coordinate that Cell is assigned
         * \param is_obstructed whether the Cell is rocky or clear
         */
        Cell(std::pair <unsigned, unsigned> coordinate, bool is_obstructed);
        
        /**
         * \brief Getting function which returns the coordinate of a Cell
         * 
         * \return std::pair <unsigned, unsigned> return coordinate of Cell
         */
        std::pair <unsigned, unsigned> GetCoordinate();

        /**
         * \brief Getting function which returns if the Cell is obstructed
         * 
         * \return true if the Cell is rocky
         * \return false if the Cell is clear
         */
        bool IsObstructed();

        /**
         * \brief Getting function which returns if the Cell is occupied by a Bug
         * 
         * \return true if the Cell is occupied
         * \return false if the Cell is free
         */
        bool IsOccupied();

        /**
         * \brief Getting function which returns the number of food particles in the Cell
         * not include the food carried by Bug
         * 
         * \return unsigned number of food particles
         */
        unsigned GetNumberOfFood();

        /**
         * \brief Getting function which returns the Bug object
         * 
         * \return Bug Bug in the Cell
         */
        Bug GetBug();


        /**
         * \brief Setting function which sets number of food particles if the Cell is clear
         * 
         * \param number_of_food number of food particles to set
         */
        void SetFood(unsigned number_of_food);

        /**
         * \brief Setting function which places a Bug in the Cell
         * 
         * \param bug_to_place Bug to place
         */
        void SetBug(Bug bug_to_place);

        /**
         * \brief Function which return coordinate of adjacent Cell according to relative direction to current Cell
         * 
         * \param direction relative direction of adjacent Cell to current Cell, from 0(east) to 5(north-east) in clockwise order
         * \return std::pair <unsigned, unsigned> coordinate of adjacent Cell
         */
        std::pair <unsigned, unsigned> AdjacentCell(unsigned direction);

        /**
         * \brief Function which return a suitably adjusted direction
         * 
         * \param left_right "left" or "right"
         * \param direction relative direction of adjacent Cell to current Cell, from 0(east) to 5(north-east) in clockwise order
         * \return unsigned adjusted direction to turn to
         */
        unsigned Turn(std::string left_right, unsigned direction);

        /**
         * \brief Function which calculates the coordinates of Cell being sensed
         * 
         * \param direction relative direction of adjacent Cell to current Cell, from 0(east) to 5(north-east) in clockwise order
         * \param sensing {"here" | "leftAhead" | "rightAhead" | "ahead"}, one sensing label inside the list of strings
         * \return std::pair <unsigned, unsigned> the coordinates of Cell being sensed
         */
        std::pair <unsigned, unsigned> SensedCell(unsigned direction, std::string sensing);

        /**
         * \brief Function which kills the Bug in the Cell
         */
        void Kill();

};

#endif