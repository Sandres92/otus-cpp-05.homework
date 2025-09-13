#include "Circle.h"

namespace otus
{
    Circle::Circle(int posX, int posY, int radius) : GraphicPrimitive("Circle", posX, posY, radius, radius)
    {
    }

    Circle::~Circle()
    {
    }

    double Circle::GetArea() const
    {
        return Math::PI * Math::Pow2(wigth);
    }

} // namespace otus
