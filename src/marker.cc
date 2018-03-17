#include <iostream>
#include "marker.h"

Marker::Marker(std::string color, int marker) {
    color_ = color;
    marker_ = marker;
}

void Marker::SetMarkerColor(std::string color) {
  color_ = color;
}

void Marker::SetMarkerInt(int marker) {
  marker_ = marker;
}

std::string Marker::GetMarkerColor() {
  return color_;
}

int Marker::GetMarkerInt() {
  return marker_;
}
