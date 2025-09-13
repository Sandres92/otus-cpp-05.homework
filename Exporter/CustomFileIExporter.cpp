#include "CustomFileIExporter.h"

namespace otus
{
    void CustomFileIExporter::Export(const CustomSharedPtr<CanvasModel> &canvasModel)
    {
        canvasModel.get()->GetAllGraphicPrimitive();
    }
}