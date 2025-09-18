#pragma once

#include <string>
#include "../Canvas/ICanvasModel.h"
#include "../CustomSharedPtr.h"

namespace otus
{
    /**
     * @brief Class (Interface) exporter
     *
     * @details Exports canvas to different file format
     *
     */
    class IExporter
    {
    public:
        IExporter() = default;
        virtual ~IExporter() = default;

        /**
         * @brief Export function
         *
         * @param <in> Data of canvas
         *
         */
        virtual void Export(const CustomSharedPtr<ICanvasModel> &canvasModel) = 0;
    };
}