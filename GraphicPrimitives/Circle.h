#include "GraphicPrimitive.h"
#include "../Math.h"

namespace otus
{
    class Circle : public GraphicPrimitive
    {
    private:
    public:
        explicit Circle(int posX, int posY, int radius);
        ~Circle();

        double GetArea() const override;
    };
}