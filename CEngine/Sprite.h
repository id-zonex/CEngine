#pragma once

#include <string>
#include "RenderObject.h"
#include "vector"
#include "Vector.h"


class Sprite : public  RenderObject
{
public:
    Sprite(std::vector<std::string> sprite);

    void GetContent(char* content, Vector& size) const override;
};
