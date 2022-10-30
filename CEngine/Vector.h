#pragma once

class Vector
{
public:
    Vector() : x(0), y(0) {}
    Vector(int x, int y) : x(x), y(y) {}

    int x;
    int y;

    Vector operator+(Vector b) const {return {x + b.x, y + b.y}; }
    Vector operator-(Vector b) const {return {x + b.x, y - b.y}; }
    Vector operator*(Vector b) const {return {x + b.x, y * b.y}; }
    Vector operator/(int b) const {return {x / b,  y / b}; }

    Vector operator*(float scale) const {return {static_cast<int>(x * scale), static_cast<int>(y * scale)}; }
};
