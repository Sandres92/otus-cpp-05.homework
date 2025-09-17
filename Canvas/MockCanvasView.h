#pragma once

#include <iostream>
#include "ICanvasModel.h"
#include "../CustomUniquePtr.h"
#include "../CustomSharedPtr.h"
#include "ICanvasView.h"
#include <functional>

namespace otus
{
    class MockCanvasView : public ICanvasView
    {
    private:
        CustomSharedPtr<ICanvasModel> canvasModel;
        std::function<void(const std::vector<CustomUniquePtr<GraphicPrimitive>> &)> allCanvasCallback;
        uint64_t allCanvasCallbackId = 0;

        int updateCount = 0;

    protected:
        void Update2(const std::vector<CustomUniquePtr<GraphicPrimitive>> &canvasModel) override;

    public:
        MockCanvasView(const CustomSharedPtr<ICanvasModel> &canvasModel);
        ~MockCanvasView();
        void SetCanvasModel(const CustomSharedPtr<ICanvasModel> &canvasModel) override;

        int GetUpdateCount() const;
    };
}