#include "GraphicPrimitive.h"

namespace otus
{
    GraphicPrimitive::GraphicPrimitive(int posX, int posY, int wigth, int height) : posX(posX), posY(posY), wigth(wigth), height(height)
    {
    }

    GraphicPrimitive::~GraphicPrimitive()
    {
    }

    int GraphicPrimitive::GetPosX() const
    {
        return posX;
    }
    int GraphicPrimitive::GetPosY() const
    {
        return posY;
    }
    int GraphicPrimitive::GetWigth() const
    {
        return wigth;
    }
    int GraphicPrimitive::GetHeight() const
    {
        return height;
    }

    void GraphicPrimitive::SetPosX(int posX)
    {
        this->posX = posX;
    }
    void GraphicPrimitive::SetPosY(int posY)
    {
        this->posY = posY;
    }
    void GraphicPrimitive::SetWigth(int wigth)
    {
        this->wigth = wigth;
    }
    void GraphicPrimitive::SetHeight(int height)
    {
        this->height = height;
    }
}