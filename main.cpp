#include <iostream>
#include <memory>

#include "CustomUniquePtr.h"
#include "CustomSharedPtr.h"

#include "Canvas/ICanvasModel.h"
#include "Canvas/CanvasModel.h"
#include "Canvas/CanvasController.h"
#include "Canvas/CanvasView.h"
#include "Canvas/ICanvasView.h"
#include "Action/Action.h"

using namespace std;

/**
 * @brief Entry point
 *
 * Execution of the program
 * starts here.
 *
 * @return Program exit status
 */
int main()
{
    std::cout << "First canvas: \n";
    otus::CustomSharedPtr<otus::ICanvasModel> canvasModel(new otus::CanvasModel());
    otus::CustomSharedPtr<otus::ICanvasView> canvasView(new otus::CanvasView(canvasModel));
    otus::CanvasController canvasController(canvasModel, canvasView);
    std::shared_ptr<otus::ICanvasModel> a(new otus::CanvasModel());

    std::cout << "==============================================\n";
    canvasController.Reset();
    canvasView.Reset();
    canvasModel.Reset();

    // a = std::shared_ptr<otus::ICanvasModel>(new otus::CanvasModel());
    std::cout << "Second canvas: \n";
    canvasModel = otus::CustomSharedPtr<otus::ICanvasModel>(new otus::CanvasModel());
    canvasView = otus::CustomSharedPtr<otus::ICanvasView>(new otus::CanvasView(canvasModel));
    canvasController = otus::CanvasController(canvasModel, canvasView);

    return 0;
}