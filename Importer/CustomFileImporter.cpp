#include "CustomFileImporter.h"

namespace otus
{
    CanvasModel &CustomFileImporter::Import(const std::string &fileName)
    {
        if (fileName.empty())
        {
        }
        CanvasModel *canvasModel = new CanvasModel();
        return *canvasModel;
    }
}