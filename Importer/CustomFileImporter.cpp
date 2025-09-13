#include "CustomFileImporter.h"

namespace otus
{
    ICanvasModel &CustomFileImporter::Import(const std::string &fileName)
    {
        if (fileName.empty())
        {
        }
        ICanvasModel *canvasModel = new CanvasModel();
        return *canvasModel;
    }
}