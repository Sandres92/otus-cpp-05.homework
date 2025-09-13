#include "GraphicPrimitive.h"

namespace otus
{
    class Square : public GraphicPrimitive
    {
    private:
    public:
        Square(int posX, int posY, int sideLengths);
        ~Square();

        double GetArea() const override;
    };
}