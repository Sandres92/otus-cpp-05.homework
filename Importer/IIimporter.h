#pragma once

#include "../Canvas/CanvasModel.h"
#include <string>

namespace otus
{
    /**
     * @brief Class (Interface) importer
     *
     * @details Imports canvas from different file format
     *
     */
    class IIimporter
    {
    public:
        IIimporter() = default;
        virtual ~IIimporter() = default;

        /**
         * @brief Import function
         *
         * @param <in> File name
         *
         */
        virtual ICanvasModel *Import(const std::string &fileName) = 0;
    };
}