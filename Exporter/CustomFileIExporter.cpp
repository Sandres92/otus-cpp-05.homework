#include "CustomFileIExporter.h"

namespace otus
{
    void CustomFileIExporter::Export(const CustomSharedPtr<ICanvasModel> &canvasModel)
    {
        std::cout << "Export ----------------\n";
        for (auto it = canvasModel.get()->GetAllGraphicPrimitive().begin();
             it != canvasModel.get()->GetAllGraphicPrimitive().end(); ++it)
        {
            std::cout << (*it).get()->GetName() << " pos = (" << (*it).get()->GetPosX() << "," << (*it).get()->GetPosY() << ")\n";
        }
        std::cout << "----------------\n";
    }
}