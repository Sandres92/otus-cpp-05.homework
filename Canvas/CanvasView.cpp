
#include "CanvasView.h"

namespace otus
{
    CanvasView::CanvasView(const CustomSharedPtr<ICanvasModel> &canvasModel) : canvasModel(canvasModel)
    {
        allCanvasCallback = std::bind(&CanvasView::Update2, this, std::placeholders::_1);
        canvasModel.get()->AddObserver(this);
    }
    CanvasView::~CanvasView()
    {
        // canvasModel.get()->Remove(allCanvasCallback);
    }

    void CanvasView::Update()
    {
        std::cout << "<<<<<<<<<<<<<<<<\n";
        for (auto it = canvasModel.get()->GetAllGraphicPrimitive().begin();
             it != canvasModel.get()->GetAllGraphicPrimitive().end(); ++it)
        {
            std::cout << (*it).get()->GetName() << " pos = (" << (*it).get()->GetPosX() << "," << (*it).get()->GetPosY() << ")\n";
        }
        std::cout << ">>>>>>>>>>>>>>>>\n";
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