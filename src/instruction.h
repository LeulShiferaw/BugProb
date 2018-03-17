#ifndef _INSTRUCTION_H
#define _INSTRUCTION_H

#include <iostream>
#include "bug.h"

class Instruction{
    private:
        Bug* bug_;
        void Sense();
        void Mark();
        void Unmark();
        void PickUp();
        void Drop();
        void Turn();
        void Move();
        void Flip();
        void direction();
};

#endif