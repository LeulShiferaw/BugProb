/**
 * \brief Implementation of Bug class
 *
 * \file bug.cc
 * \author Zihan Qi
 * \author Matius Chairani
 * \date 2018-03-05
 */
#include <iostream>
#include "bug.h"

//Constructors
Bug::Bug() {}

Bug::Bug(int id, std::string color) {
    id_ = id;
    color_ = color;
    current_state_ = 0;
    resting_ = 0;
    direction_ = 0;
    number_of_food_carried_ = 0;
    has_food_ = false;
    position_ = std::make_pair(0, 0);
    is_dead_ = false;
}

//Copy Constructor
Bug::Bug(const Bug & bug_to_copy) {
    id_ = bug_to_copy.id_;
    color_ = bug_to_copy.color_;
    current_state_ = bug_to_copy.current_state_;
    resting_ = bug_to_copy.resting_;
    direction_ = bug_to_copy.direction_;
    number_of_food_carried_ = bug_to_copy.number_of_food_carried_;
    has_food_ = bug_to_copy.has_food_;
    position_ = std::make_pair(bug_to_copy.position_.first, bug_to_copy.position_.second);
    is_dead_ = bug_to_copy.is_dead_;
}

//Getting functions
int Bug::GetId() {return id_;}

std::string Bug::GetColor() {return color_;}

int Bug::GetCurrentState() {return current_state_;}

int Bug::GetResting() {return resting_;}

int Bug::GetDirection() {return direction_;}

int Bug::GetNumberOfFoodCarried() {return number_of_food_carried_;}

bool Bug::HasFood() {return has_food_;}

std::pair <unsigned, unsigned> Bug::GetPosition() {return position_;}

bool Bug::IsDead() {return is_dead_;}

//Setting functions
void Bug::SetState(int state) {
    if(state < 0 || state > 9999) {
        throw std::invalid_argument("Invalid state value.");
    }
    else
        current_state_ = state;
}

void Bug::SetResting(int resting) {resting_ = resting;}

void Bug::SetDirection(int direction) {
    if(direction < 0 || direction > 5) {
        throw std::invalid_argument("Invalid direction value.");
    }
    else
        direction_ = direction;
}

void Bug::SetHasFood(bool has_food) {has_food_ = has_food;}

void Bug::SetPosition(std::pair <unsigned, unsigned> coordinate) {position_ = coordinate;}

void Bug::Dead() {is_dead_ = true;}
