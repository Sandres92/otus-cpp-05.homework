#include "CanvasController.h"

namespace otus
{
    CanvasController::CanvasController(const CustomSharedPtr<ICanvasModel> &canvasModel, const CustomSharedPtr<ICanvasView> &canvasView) : canvasModel(canvasModel), canvasView(canvasView)
    {
        CreateCircle();
        CreateSquare();
    }

    void CanvasController::CreateCircle()
    {
        otus::Circle *circle = new Circle(5, 5, 3);
        canvasModel.get()->AddPrimitive(circle);
    }

    void CanvasController::CreateSquare()
    {
        otus::Square *square = new Square(10, 10, 3);
        canvasModel.get()->AddPrimitive(square);
    }
}