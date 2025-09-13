#pragma once

#include <iostream>
#include "CanvasModel.h"
#include "CustomUniquePtr.h"
#include "CustomSharedPtr.h"

namespace otus
{
    class CanvasView : public IObserver
    {
    private:
        CustomSharedPtr<CanvasModel> canvasModel;
        char startSymbol = 33; // "!"

    public:
        CanvasView(const CustomSharedPtr<CanvasModel> &canvasModel);
        ~CanvasView() = default;
        void Update() override;
    };
}