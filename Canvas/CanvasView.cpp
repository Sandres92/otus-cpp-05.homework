
#include "CanvasView.h"

namespace otus
{
    CanvasView::CanvasView(const CustomSharedPtr<ICanvasModel> &canvasModel) : canvasModel(canvasModel)
    {
        canvasModel.get()->AddObserver(this);
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
}