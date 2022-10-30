#pragma once
#include "Vector.h"

class Transform
{
public:
    Transform() : position({}), angle(0) {}
    Transform(Vector position, float angle) : position(position), angle(angle) {}

    Vector position;
    float angle;

    Vector GetBias(int x, int y) const;
};
