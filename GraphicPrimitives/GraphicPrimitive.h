#pragma once

#include <string>

namespace otus
{
    /**
     * @brief Graphic primitive class.
     *
     * @details Store draphic primitive data, such as Name of object
     * position x, position y, wigth, height
     *
     */
    class GraphicPrimitive
    {
    protected:
        std::string name;
        int posX;
        int posY;
        int wigth;
        int height;

    public:
        explicit GraphicPrimitive(std::string name, int posX, int posY, int wigth, int height);
        virtual ~GraphicPrimitive() = default;

        /**
         * @brief Get graphic primitive name.
         *
         * @return Return graphic primitive name
         *
         */
        std::string GetName() const;

        /**
         * @brief Get graphic primitive position x.
         *
         * @return Return graphic primitive position x
         *
         */
        int GetPosX() const;

        /**
         * @brief Get graphic primitive position y.
         *
         * @return Return graphic primitive position y
         *
         */
        int GetPosY() const;

        /**
         * @brief Get graphic primitive position wigth.
         *
         * @return Return graphic primitive position wigth
         *
         */
        int GetWigth() const;

        /**
         * @brief Get graphic primitive position height.
         *
         * @return Return graphic primitive position height
         *
         */
        int GetHeight() const;

        /**
         * @brief Get the area of a graphical primitive
         *
         * @return the area of a graphical primitive
         *
         */
        double virtual GetArea() const = 0;

        /**
         * @brief Set graphic primitive position x.
         *
         * @param <in> new position x
         *
         */
        void SetPosX(int posX);

        /**
         * @brief Set graphic primitive position y.
         *
         * @param <in> new position y
         *
         */
        void SetPosY(int posY);

        /**
         * @brief Set graphic primitive wigth.
         *
         * @param <in> new wigth
         *
         */
        void SetWigth(int wigth);

        /**
         * @brief Set graphic primitive height.
         *
         * @param <in> new height
         *
         */
        void SetHeight(int height);
    };
}