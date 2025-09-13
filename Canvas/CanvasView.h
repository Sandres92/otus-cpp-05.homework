#pragma once

#include <iostream>
#include "ICanvasModel.h"
#include "../CustomUniquePtr.h"
#include "../CustomSharedPtr.h"
#include "ICanvasView.h"

namespace otus
{
    class CanvasView : public ICanvasView
    {
    private:
        CustomSharedPtr<ICanvasModel> canvasModel;
        char startSymbol = 33; // "!"

    public:
        CanvasView(const CustomSharedPtr<ICanvasModel> &canvasModel);
        ~CanvasView() = default;
        void Update() override;
    };
}