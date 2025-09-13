#include <iostream>
#include "CustomUniquePtr.h"
#include "CustomSharedPtr.h"

#include "Canvas/ICanvasModel.h"
#include "Canvas/CanvasModel.h"
#include "Canvas/CanvasController.h"
#include "Canvas/CanvasView.h"
#include "Canvas/ICanvasView.h"
#include <memory>

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
    otus::CustomSharedPtr<otus::ICanvasModel> canvasModel(new otus::CanvasModel());
    otus::CustomSharedPtr<otus::ICanvasView> canvasView(new otus::CanvasView(canvasModel));
    otus::CanvasController canvasController(canvasModel, canvasView);

    return 0;
}