#include <vector>

namespace otus
{
    class GraphicPrimitive
    {
    protected:
        int posX;
        int posY;
        int wigth;
        int height;

    public:
        GraphicPrimitive(int posX, int posY, int wigth, int height);
        ~GraphicPrimitive();

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