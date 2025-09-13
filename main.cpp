#include <iostream>
#include "CustomUniquePtr.h"
#include "CustomSharedPtr.h"

#include "CanvasModel.h"
#include "CanvasController.h"
#include "CanvasView.h"
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
    std::unique_ptr<int> m;
    otus::CustomSharedPtr<otus::CanvasModel> canvasModel(new otus::CanvasModel());
    otus::CustomSharedPtr<otus::CanvasView> canvasView(new otus::CanvasView(canvasModel));
    otus::CanvasController canvasController(canvasModel, canvasView);

    return 0;
}