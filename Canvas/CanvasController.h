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
    /**
     * @brief Class CanvasController, contains canvasModel and canvasView.
     *
     * @details Controls the rendering process
     *
     */
    class CanvasController
    {
    private:
        CustomSharedPtr<ICanvasModel> canvasModel;
        CustomSharedPtr<ICanvasView> canvasView;

        /**
         * @brief Add new Circle on canvas
         *
         */
        void CreateCircle();

        /**
         * @brief Add new Square on canvas
         *
         */
        void CreateSquare();

    public:
        /**
         * @brief Class CanvasController constructor, set canvasModel and canvasView.
         *
         * @param <in> canvasModel. Graphic primitives data
         * @param <in> canvasView. Class for drawing
         *
         */
        CanvasController(const CustomSharedPtr<ICanvasModel> &canvasModel, const CustomSharedPtr<ICanvasView> &canvasView);
        ~CanvasController() = default;

        /**
         * @brief Set new canvasModel
         *
         * @param <in> New canvasModel. Graphic primitives data
         *
         */
        void SetCanvasModel(const CustomSharedPtr<ICanvasModel> &canvasModel);

        /**
         * @brief Set new canvasView
         *
         * @param <in> New canvasView
         *
         */
        void SetCanvasView(const CustomSharedPtr<ICanvasView> &canvasModel);

        /**
         * @brief Set new canvasModel and canvasView
         *
         * @param <in> canvasModel. Graphic primitives data
         * @param <in> canvasView. Class for drawing
         *
         */
        void SetCanvasModelAndView(const CustomSharedPtr<ICanvasModel> &canvasModel,
                                   const CustomSharedPtr<ICanvasView> &canvasView);

        /**
         * @brief Add new Graphic primitives on canvas
         *
         * @param <in> Graphic primitive by type
         *
         */
        void CreateGraphicPrimitive(GraphicPrimitiveType primitiveType);

        /**
         * @brief Remove canvasModel and canvasView
         *
         */
        void Reset();
    };
}