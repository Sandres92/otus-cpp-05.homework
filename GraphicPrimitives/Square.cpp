#include "Square.h"

namespace otus
{
    Square::Square(int posX, int posY, int sideLengths) : GraphicPrimitive(posX, posX, sideLengths, sideLengths)
    {
    }

    Square::~Square()
    {
    }

    double Square::GetArea() const
    {
        return wigth * height;
    }
}