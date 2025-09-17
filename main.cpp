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

#include "Exporter/IExporter.h"
#include "Exporter/CustomFileIExporter.h"

#include "Importer/IIimporter.h"
#include "Importer/CustomFileImporter.h"

#include "GraphicPrimitives/GraphicPrimitiveType.h"

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
    std::cout << "First canvas ====================  \n";
    otus::CustomSharedPtr<otus::ICanvasModel> canvasModel(new otus::CanvasModel());
    otus::CustomSharedPtr<otus::ICanvasView> canvasView(new otus::CanvasView(canvasModel));
    otus::CanvasController canvasController(canvasModel, canvasView);

    // canvasController.Reset();
    canvasView.Reset();
    canvasModel.Reset();

    // a = std::shared_ptr<otus::ICanvasModel>(new otus::CanvasModel());
    std::cout << "Second canvas ==================== \n";
    canvasModel = otus::CustomSharedPtr<otus::ICanvasModel>(new otus::CanvasModel());
    canvasView = otus::CustomSharedPtr<otus::ICanvasView>(new otus::CanvasView(canvasModel));
    canvasController = otus::CanvasController(canvasModel, canvasView);

    canvasView.Reset();
    canvasModel.Reset();
    std::cout << "Third canvas ==================== \n";
    canvasModel = otus::CustomSharedPtr<otus::ICanvasModel>(new otus::CanvasModel());
    canvasView = otus::CustomSharedPtr<otus::ICanvasView>(new otus::CanvasView(canvasModel));
    canvasController = otus::CanvasController(canvasModel, canvasView);

    otus::CustomUniquePtr<otus::IExporter> exporter(new otus::CustomFileIExporter());
    exporter.get()->Export(canvasModel);

    otus::CustomUniquePtr<otus::IIimporter> importer(new otus::CustomFileImporter());
    otus::CanvasModel *importCanvasModel = dynamic_cast<otus::CanvasModel *>(importer.get()->Import("Test"));
    canvasModel = otus::CustomSharedPtr<otus::ICanvasModel>(importCanvasModel);
    canvasView.get()->SetCanvasModel(canvasModel);
    canvasController.SetCanvasModel(canvasModel);
    canvasController.CreateGraphicPrimitive(otus::GraphicPrimitiveType::Square);

    return 0;
}