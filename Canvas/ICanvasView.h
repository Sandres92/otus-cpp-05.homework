#pragma once

#include <iostream>
#include "ICanvasModel.h"
#include "../CustomUniquePtr.h"
#include "../CustomSharedPtr.h"

namespace otus
{
    /**
     * @brief Class (Interface) Canvas View
     *
     * @details The visual part of the graphic editor
     *
     */
    class ICanvasView
    {
    protected:
        /**
         * @brief Update function of the graphic editor. Redraw canvas
         *
         * @param <in> canvas datas
         *
         */
        virtual void Update2(const std::vector<CustomUniquePtr<GraphicPrimitive>> &canvasModel) = 0;

    public:
        ICanvasView(const CustomSharedPtr<ICanvasModel> &canvasModel)
        {
            (void)canvasModel;
        };
        virtual ~ICanvasView() = default;

        /**
         * @brief Function to set new canvas datas
         *
         * @param <in> new canvas datas (canvasModel)
         *
         */
        virtual void SetCanvasModel(const CustomSharedPtr<ICanvasModel> &canvasModel) = 0;
    };
}