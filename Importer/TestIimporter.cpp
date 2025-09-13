#include <TestIimporter.h>

namespace otus
{
    CanvasModel &TestIimporter::Import(const std::string &fileName)
    {
        if (fileName.empty())
        {
        }
        CanvasModel *canvasModel = new CanvasModel();
        return *canvasModel;
    }
}