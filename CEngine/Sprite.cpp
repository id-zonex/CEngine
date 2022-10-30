#include "Sprite.h"


Sprite::Sprite(std::vector<std::string> sprite) :
RenderObject(
    {static_cast<int>(sprite.size()), static_cast<int>(sprite[0].size())}
    )
{

    context_ = new char[size_.x * size_.y];

    int i = 0;
    for(const std::string& line : sprite)
    {
        for(const char element : line)
        {
            context_[i] = element;
            i++;
        }
    }
}

void Sprite::GetContent(char* content, Vector& size) const
{
    content = context_;
    size = size_;
}