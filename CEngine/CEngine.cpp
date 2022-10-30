#include "Rect.h"
#include "Renderer.h"
#include "Sprite.h"
#include "Windows.h"


int main(int argc, char* argv[])
{
    Transform spriteTransform({0, 0}, 0);

    Rect* sprite = new Rect({100, 30}, '*', false);
    
    auto renderer = new Renderer(100, 30);
    int x = 0;
    int y = 0;
    while(true)
    {
        renderer->WriteSpriteToBuffer(spriteTransform, *sprite);
        renderer->Update();
        Sleep(100);
    }
}
