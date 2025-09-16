
#include "CanvasView.h"

namespace otus
{
    CanvasView::CanvasView(const CustomSharedPtr<ICanvasModel> &canvasModel) : canvasModel(canvasModel)
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

    void CanvasView::Update2(const std::vector<CustomUniquePtr<GraphicPrimitive>> &canvasModel)
    {
        std::cout << "2 <<<<<<<<<<<<<<<<\n";
        for (auto it = canvasModel.begin();
             it != canvasModel.end(); ++it)
        {
            std::cout << (*it).get()->GetName() << " pos = (" << (*it).get()->GetPosX() << "," << (*it).get()->GetPosY() << ")\n";
        }
        std::cout << "2 >>>>>>>>>>>>>>>>\n";
    }
}