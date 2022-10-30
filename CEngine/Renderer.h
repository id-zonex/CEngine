#pragma once

#include "RenderObject.h"
#include "Transform.h"

class Renderer
{
public:
    Renderer(int sizeX, int sizeY);
    ~Renderer();

    void Update() const;
    void ClearBuffer() const;

    void WriteCharToBuffer(Transform transform, char chapter) const;
    void WriteSpriteToBuffer(Transform transform, const RenderObject& sprite) const;
    
private:
    char* buffer_;
    
    int sizeX_ = 0;
    int sizeY_ = 0;
};
