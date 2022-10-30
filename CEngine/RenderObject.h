#pragma once

#include <string>
#include <vector>
#include "Vector.h"


class RenderObject
{
public:
    RenderObject(Vector size) : context_(new char[size.x * size.y]), size_(size) {}
    virtual ~RenderObject() { delete[] context_; }
    
    virtual void GetContent(char* content, Vector& size) const = 0;
    virtual Vector GetSize() const {return size_; }
    
    virtual char GetElement(Vector index) const { return context_[index.x + index.y * size_.x]; }
    virtual char GetElement(int x, int y) const { return context_[x + y * size_.x]; }
    
protected:
    char* context_ = nullptr;
    Vector size_;
};
