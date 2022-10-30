#include "Transform.h"
#include "cmath"

Vector Transform::GetBias(int x, int y) const
{
    return {
        static_cast<int>(std::cos(angle)*x + -std::sin(angle)*y),
        static_cast<int>( std::sin(angle)*x + std::cos(angle)*y)
    };
}
