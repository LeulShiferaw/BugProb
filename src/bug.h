/**
 * \brief This class represents a Bug object
 * 
 * \file bug.h
 * \author Zihan Qi
 * \author Matius Chairani
 * \date 2018-03-05
 */
#ifndef _BUG_H
#define _BUG_H

#include <iostream>

class Bug {
    private:
        //unique integer id that determine the order
        //in which the bug takes its turn to move or sense
        int id_;
        //"Red" or "Black", color of Bug
        std::string color_;
        //the current state of a Bug's brain, range from 0 to 9999
        int current_state_;
        //time the Bug has to rest after its last move before any other action
        int resting_;
        //current direction, from 0(east) to 5(north-east) in clockwise order
        int direction_;
        //number of food the Bug is carring
        //a Bug can hold only a single unit of food at a time
        int number_of_food_carried_;
        //if a Bug currently carries a food particle
        bool has_food_;
        //current position
        std::pair <unsigned, unsigned> position_;
        //if a bug is dead
        bool is_dead_;


    public:
        /**
         * \brief Default constructor of Bug
         */
        Bug();

        /**
         * \brief Constructor of a Bug
         * 
         * \param id id of Bug
         * \param color color of Bug
         */
        Bug(int id, std::string color);

        /**
         * \brief Copy constructor of Bug
         * 
         * \param bug_to_copy bug to copy
         */
        Bug(const Bug & bug_to_copy);

        /**
         * \brief Getting function which returns the id of Bug
         * 
         * \return int id of Bug
         */
        int GetId();

        /**
         * \brief Getting function which returns the color of Bug
         * 
         * \return std::string color of Bug
         */
        std::string GetColor();

        /**
         * \brief Getting function which returns the current state of Bug
         * 
         * \return int current state of Bug
         */
        int GetCurrentState();

        /**
         * \brief Getting function which returns the resting of Bug
         * 
         * \return int resting of Bug
         */
        int GetResting();

        /**
         * \brief Getting function which returns the direction of Bug
         * 
         * \return int current direction of Bug
         */
        int GetDirection();

        /**
         * \brief Getting function which returns the number of food carried by a Bug
         * 
         * \return int number of food carried by a Bug
         */
        int GetNumberOfFoodCarried();

        /**
         * \brief Function which test whether a Bug has food or not
         * 
         * \return true if Bug has food
         * \return false if Bug doesn't have food
         */
        bool HasFood();

        /**
         * \brief Getting function which returns the current position of Bug
         * 
         * \return std::pair <unsigned, unsigned> current position of Bug
         */
        std::pair <unsigned, unsigned> GetPosition();

        /**
         * \brief Function which tests whether a Bug is dead or not
         * 
         * \return true if a Bug is dead
         * \return false if a Bug is not dead
         */
        bool IsDead();

        /**
         * \brief Setting function which sets the state of Bug
         * 
         * \param state current state of Bug to set
         */
        void SetState(int state);

        /**
         * \brief Setting function which sets the resting of Bug
         * 
         * \param resting resting of Bug to set
         */
        void SetResting(int resting);

        /**
         * \brief Setting function which sets the direction of Bug
         * 
         * \param direction direction of Bug to set
         */
        void SetDirection(int direction);

        /**
         * \brief Setting function which sets if a Bug has food
         * 
         * \param has_food if a Bug has food or not
         */
        void SetHasFood(bool has_food);

        /**
         * \brief Setting function which sets the position of Bug
         * 
         * \param coordinate coordinate of Bug to set 
         */
        void SetPosition(std::pair <unsigned, unsigned> coordinate);

        /**
         * \brief Setting function which sets a Bug to dead
         */
        void Dead();

};

#endif
