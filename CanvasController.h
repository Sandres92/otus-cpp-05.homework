#include "CustomUniquePtr.h"
#include "CustomSharedPtr.h"
#include "CanvasModel.h"
#include "CanvasView.h"

#include "GraphicPrimitives/Circle.h"
#include "GraphicPrimitives/Square.h"

#include <iostream>

namespace otus
{
    class CanvasController
    {
    private:
        CustomSharedPtr<CanvasModel> canvasModel;
        CustomSharedPtr<CanvasView> canvasView;

        void CreateCircle();
        void CreateSquare();
        void CreateGraphicPrimitive();

    public:
        CanvasController(const CustomSharedPtr<CanvasModel> &canvasModel, const CustomSharedPtr<CanvasView> &canvasView);
        ~CanvasController() = default;
    };

}