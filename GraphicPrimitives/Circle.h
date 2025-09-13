#include "GraphicPrimitive.h"
#include "../Math.h"

namespace otus
{
    class Circle : public GraphicPrimitive
    {
    private:
    public:
        Circle(int posX, int posY, int radius);
        ~Circle();

        double GetArea() const override;
    };
}