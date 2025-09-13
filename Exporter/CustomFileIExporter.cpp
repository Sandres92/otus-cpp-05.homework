#include "CustomFileIExporter.h"

namespace otus
{
    void CustomFileIExporter::Export(const CustomSharedPtr<ICanvasModel> &canvasModel)
    {
        canvasModel.get()->GetAllGraphicPrimitive();
    }
}