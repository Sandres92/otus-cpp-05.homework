#pragma once

#include <string>

namespace otus
{
    class GraphicPrimitive
    {
    protected:
        std::string name;
        int posX;
        int posY;
        int wigth;
        int height;

    public:
        GraphicPrimitive(std::string name, int posX, int posY, int wigth, int height);
        virtual ~GraphicPrimitive() = default;

        std::string GetName() const;
        int GetPosX() const;
        int GetPosY() const;
        int GetWigth() const;
        int GetHeight() const;

        double virtual GetArea() const = 0;

        void SetPosX(int posX);
        void SetPosY(int posY);
        void SetWigth(int wigth);
        void SetHeight(int height);
    };
}