#include "Rect.h"


Rect::Rect(Vector size, char chapter, bool isFill):
RenderObject(size)
{
    if(isFill)
    {
        CreateFilledBox(chapter);
    }
    else
    {
        CreateBox(chapter);
    }
}

void Rect::GetContent(char* content, Vector& size) const
{
    content = context_;
    size = size_;
}

void Rect::CreateBox(char chapter)
{
    for(int i = 0; i < size_.x * size_.y; i++)
    {
        const bool isHorizontalBorder = i % size_.x == 0 || i % size_.x == size_.x - 1;
        const bool isVerticalBorder = i <= size_.x || i / size_.x == size_.y - 1;
        
        if(isVerticalBorder || isHorizontalBorder)
        {
            context_[i] = chapter;
        }
        else
        {
            context_[i] = ' ';
        }
    }
}

void Rect::CreateFilledBox(char chapter)
{
    for(int i = 0; i < size_.x * size_.y; i++)
    {
        context_[i] = chapter;
    }
}
