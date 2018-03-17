#ifndef _MARKER_H
#define _MARKER_H

#include <iostream>

class Marker{
    private:
        std::string color_;
        int marker_;
    public:
        Marker(std::string, int);
        void SetMarkerColor(std::string);
        void SetMarkerInt(int);
        std::string GetMarkerColor();
        int GetMarkerInt();
};

#endif
