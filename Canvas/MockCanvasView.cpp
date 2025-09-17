
#include "MockCanvasView.h"

namespace otus
{
    MockCanvasView::MockCanvasView(const CustomSharedPtr<ICanvasModel> &canvasModel) : ICanvasView(canvasModel), canvasModel(canvasModel)
    {
        allCanvasCallback = std::bind(&MockCanvasView::Update2, this, std::placeholders::_1);
        // canvasModel.get()->AddObserver(this);
        allCanvasCallbackId = canvasModel.get()->AddObserver2(allCanvasCallback);
    }

    MockCanvasView::~MockCanvasView()
    {
        canvasModel.get()->RemoveObserver2(allCanvasCallbackId);
        // canvasModel.get()->Remove(allCanvasCallback);
    }

    void MockCanvasView::SetCanvasModel(const CustomSharedPtr<ICanvasModel> &canvasModel)
    {
        (*this).canvasModel.get()->RemoveObserver2(allCanvasCallbackId);

        (*this).canvasModel = canvasModel;

        allCanvasCallbackId = canvasModel.get()->AddObserver2(allCanvasCallback);
        //(*this).canvasModel.get()->Notify();
    }

    void MockCanvasView::Update2(const std::vector<CustomUniquePtr<GraphicPrimitive>> &canvasModel)
    {
        void(canvasModel.size());

        ++updateCount;
    }

    int MockCanvasView::GetUpdateCount() const
    {
        return updateCount;
    }
}