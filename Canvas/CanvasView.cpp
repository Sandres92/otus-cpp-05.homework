
#include "CanvasView.h"

namespace otus
{
    CanvasView::CanvasView(const CustomSharedPtr<ICanvasModel> &canvasModel) : ICanvasView(canvasModel), canvasModel(canvasModel)
    {
        allCanvasCallback = std::bind(&CanvasView::Update2, this, std::placeholders::_1);
        // canvasModel.get()->AddObserver(this);
        allCanvasCallbackId = canvasModel.get()->AddObserver2(allCanvasCallback);
    }

    CanvasView::~CanvasView()
    {
        canvasModel.get()->RemoveObserver2(allCanvasCallbackId);
        // canvasModel.get()->Remove(allCanvasCallback);
    }

    void CanvasView::SetCanvasModel(const CustomSharedPtr<ICanvasModel> &canvasModel)
    {
        (*this).canvasModel.get()->RemoveObserver2(allCanvasCallbackId);

        (*this).canvasModel = canvasModel;

        allCanvasCallbackId = canvasModel.get()->AddObserver2(allCanvasCallback);
        //(*this).canvasModel.get()->Notify();
    }

    void CanvasView::Update2(const std::vector<CustomUniquePtr<GraphicPrimitive>> &canvasModel)
    {
        std::cout << "Draw <<<<<<<<<<<<<<<<\n";
        for (auto it = canvasModel.begin();
             it != canvasModel.end(); ++it)
        {
            std::cout << (*it).get()->GetName() << " pos = (" << (*it).get()->GetPosX() << "," << (*it).get()->GetPosY() << ")\n";
        }
        std::cout << ">>>>>>>>>>>>>>>>\n";
    }
}