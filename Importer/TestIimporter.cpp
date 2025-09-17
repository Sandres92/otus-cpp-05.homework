#include <TestIimporter.h>

namespace otus
{
    ICanvasModel *TestIimporter::Import(const std::string &fileName)
    {
        if (fileName.empty())
        {
            return nullptr;
        }

        ICanvasModel *canvasModel = new CanvasModel();
        return canvasModel;
    }
}