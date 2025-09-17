#pragma once

#include <iostream>
#include "ICanvasModel.h"
#include "../CustomUniquePtr.h"
#include "../CustomSharedPtr.h"

namespace otus
{
    class ICanvasView
    {
    public:
        ICanvasView(const CustomSharedPtr<ICanvasModel> &canvasModel)
        {
            (void)canvasModel;
        };
        virtual ~ICanvasView() = default;
        virtual void Update2(const std::vector<CustomUniquePtr<GraphicPrimitive>> &canvasModel) = 0;
        virtual void SetCanvasModel(const CustomSharedPtr<ICanvasModel> &canvasModel) = 0;
    };
}