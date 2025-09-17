#pragma once

#include <iostream>
#include "ICanvasModel.h"
#include "../CustomUniquePtr.h"
#include "../CustomSharedPtr.h"
#include "ICanvasView.h"
#include <functional>

namespace otus
{
    class CanvasView : public ICanvasView
    {
    private:
        CustomSharedPtr<ICanvasModel> canvasModel;
        char startSymbol = 33; // "!"
        std::function<void(const std::vector<CustomUniquePtr<GraphicPrimitive>> &)> allCanvasCallback;
        uint64_t allCanvasCallbackId = 0;

    public:
        CanvasView(const CustomSharedPtr<ICanvasModel> &canvasModel);
        ~CanvasView();
        void Update2(const std::vector<CustomUniquePtr<GraphicPrimitive>> &canvasModel) override;
        void SetCanvasModel(const CustomSharedPtr<ICanvasModel> &canvasModel) override;
    };
}