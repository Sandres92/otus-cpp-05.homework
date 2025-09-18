#pragma once

#include "GraphicPrimitive.h"
#include "../Math.h"

namespace otus
{
    /**
     * @brief Circle primitive: square
     *
     */
    class Circle : public GraphicPrimitive
    {
    private:
    public:
        explicit Circle(int posX, int posY, int radius);
        ~Circle();

        double GetArea() const override;
    };
}