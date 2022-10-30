#pragma once
#include "RenderObject.h"


class Rect : public RenderObject
{
public:
    Rect(Vector size, char chapter, bool isFill);
    void GetContent(char* content, Vector& size) const override;

private:
    void CreateFilledBox(char chapter);
    void CreateBox(char chapter);
};
