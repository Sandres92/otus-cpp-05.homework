#pragma once

#include "GraphicPrimitive.h"

namespace otus
{
    /**
     * @brief Graphic primitive: square
     *
     */
    class Square : public GraphicPrimitive
    {
    private:
    public:
        explicit Square(int posX, int posY, int sideLengths);
        ~Square();

        double GetArea() const override;
    };
}