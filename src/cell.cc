/**
 * \brief Implementation of Cell class
 *
 * \file cell.cc
 * \author Zihan Qi
 * \author Matius Chairani
 * \date 2018-03-04
 */

#include <iostream>
#include "cell.h"

Cell::Cell(std::pair <unsigned, unsigned> coordinate, bool is_obstructed) {
    coordinate_ = coordinate;
    is_occupied_ = false;
    is_obstructed_ = is_obstructed;
    number_of_food_ = 0;
}

std::pair <unsigned, unsigned> Cell::GetCoordinate() {return coordinate_;}

bool Cell::IsObstructed() {return is_obstructed_;}

bool Cell::IsOccupied() {return is_occupied_;}

unsigned Cell::GetNumberOfFood() {return number_of_food_;}

Bug Cell::GetBug() {
    return bug_;
}

void Cell::SetFood(unsigned number_of_food) {
    if(!IsObstructed())
        number_of_food_ = number_of_food;
    //
}

void Cell::SetBug(Bug bug_to_place) {
    if(!IsOccupied()) {
        is_occupied_ = true;
        bug_ = bug_to_place;
        bug_.SetPosition(coordinate_);
    }
    //
}

std::pair <unsigned, unsigned> Cell::AdjacentCell(unsigned direction) {
    // std::cout << coordinate_.first << coordinate_.second << std::endl;

    auto even = coordinate_.second % 2 == 0;
    // std::cout << even <<std::endl;
    std::pair <unsigned, unsigned> adjacent_cell;
    switch(direction) {
        case 0:
            adjacent_cell = std::make_pair(coordinate_.first + 1, coordinate_.second);
            break;
        case 1:
            if(even) {
                adjacent_cell = std::make_pair(coordinate_.first, coordinate_.second + 1);
            }
            else {
                adjacent_cell = std::make_pair(coordinate_.first + 1, coordinate_.second + 1);
            }
            break;
        case 2:
            if(even) {
                adjacent_cell = std::make_pair(coordinate_.first - 1, coordinate_.second + 1);
                break;
            }
            else {
                adjacent_cell = std::make_pair(coordinate_.first, coordinate_.second + 1);
                break;
            }
        case 3:
            adjacent_cell = std::make_pair(coordinate_.first - 1, coordinate_.second);
            break;
        case 4:
            if(even) {
                adjacent_cell = std::make_pair(coordinate_.first - 1, coordinate_.second - 1);
                break;
            }
            else {
                adjacent_cell = std::make_pair(coordinate_.first, coordinate_.second - 1);
                break;
            }
        case 5:
            if(even) {
                adjacent_cell = std::make_pair(coordinate_.first, coordinate_.second - 1);
                break;
            }
            else {
                adjacent_cell = std::make_pair(coordinate_.first + 1, coordinate_.second - 1);
                break;
            }
        default:
            throw std::invalid_argument("Invalid direction value.");
            break;
    }
    return adjacent_cell;
}

unsigned Cell::Turn(std::string left_right, unsigned direction) {
    if (direction > 5) {
      throw std::invalid_argument("Invalid direction value.");
    }
    return left_right == "left" ? (direction + 5) % 6 : left_right == "right" ? (direction + 1) % 6 : direction;
}

std::pair <unsigned, unsigned> Cell::SensedCell(unsigned direction, std::string sensing) {
    std::pair <unsigned, unsigned> sensed_cell;
    if(sensing == "here") sensed_cell = coordinate_;
    else if(sensing == "ahead") sensed_cell = AdjacentCell(direction);
    else if(sensing == "leftAhead") sensed_cell = AdjacentCell(Turn("left", direction));
    else if(sensing == "rightAhead") sensed_cell = AdjacentCell(Turn("right", direction));
    else throw std::invalid_argument("Invalid sensing value.");
    return sensed_cell;
}

//void Cell::Kill() {
//}
