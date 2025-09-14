#include "../CustomUniquePtr.h"
#include "../CustomSharedPtr.h"
#include "CanvasModel.h"
#include "CanvasView.h"

#include "../GraphicPrimitives/Circle.h"
#include "../GraphicPrimitives/Square.h"
#include "../GraphicPrimitives/GraphicPrimitiveType.h"

#include <iostream>
namespace otus
{
    class CanvasController
    {
    private:
        CustomSharedPtr<ICanvasModel> canvasModel;
        CustomSharedPtr<ICanvasView> canvasView;

        void CreateCircle();
        void CreateSquare();

    public:
        CanvasController(const CustomSharedPtr<ICanvasModel> &canvasModel, const CustomSharedPtr<ICanvasView> &canvasView);
        ~CanvasController() = default;

        void CreateGraphicPrimitive(GraphicPrimitiveType primitiveType);
        void Reset();
    };

}