#pragma once

#include <iostream>
#include "ICanvasModel.h"
#include "../CustomUniquePtr.h"
#include "../CustomSharedPtr.h"
#include "ICanvasView.h"
#include <functional>

namespace otus
{
    /**
     * @brief Class canvas view, which draw canvas and graphic primitives.
     *
     */
    class CanvasView : public ICanvasView
    {
    private:
        CustomSharedPtr<ICanvasModel> canvasModel;
        char startSymbol = 33; // "!"
        std::function<void(const std::vector<CustomUniquePtr<GraphicPrimitive>> &)> allCanvasCallback;
        uint64_t allCanvasCallbackId = 0;

    protected:
        void Update2(const std::vector<CustomUniquePtr<GraphicPrimitive>> &canvasModel) override;

    public:
        CanvasView(const CustomSharedPtr<ICanvasModel> &canvasModel);
        ~CanvasView();
        void SetCanvasModel(const CustomSharedPtr<ICanvasModel> &canvasModel) override;
    };
}