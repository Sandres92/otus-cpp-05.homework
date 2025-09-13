#include "GraphicPrimitive.h"

namespace otus
{
    GraphicPrimitive::GraphicPrimitive(std::string name, int posX, int posY, int wigth, int height) : name(name), posX(posX), posY(posY), wigth(wigth), height(height)
    {
    }

    std::string GraphicPrimitive::GetName() const
    {
        return name;
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