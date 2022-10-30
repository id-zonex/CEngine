#include "Renderer.h"
#include <string>
#include "iostream"
#include "Transform.h"

Renderer::Renderer(int sizeX, int sizeY)
: sizeX_(sizeX), sizeY_(sizeY)
{
    const std::string command = "MODE CON COLS=" + std::to_string(sizeX) + " LINES=" + std::to_string(sizeY);
    system(command.c_str());  // NOLINT(concurrency-mt-unsafe)

    // fill buffer
    buffer_ = new char[sizeY];
    for(int i = 0; i < sizeY * sizeX; i++)
    {
        buffer_[i] = ' ';
    }
}

Renderer::~Renderer()
{
    delete[] buffer_;
}


void Renderer::Update() const
{
    buffer_[sizeY_ * sizeX_] = '\0';  // NOLINT(bugprone-implicit-widening-of-multiplication-result)
    std::cout << buffer_;
    ClearBuffer();
}

void Renderer::ClearBuffer() const
{
    for(int i = 0; i < sizeX_ * sizeY_; i++)
    {
        buffer_[i] = ' ';
    }
}

void Renderer::WriteCharToBuffer(Transform transform, char chapter) const 
{
    buffer_[transform.position.x + transform.position.y * sizeX_] = chapter;
}

void Renderer::WriteSpriteToBuffer(Transform transform, const RenderObject& sprite) const
{
    const Vector size = sprite.GetSize();
    
    for (int i = 0; i < size.y; i++)
    {
        for (int j = 0; j < size.x; j++)
        {
            buffer_[transform.position.x + j + (transform.position.y + i) *
                sizeX_] = sprite.GetElement(j, i);
        }
    }
}
