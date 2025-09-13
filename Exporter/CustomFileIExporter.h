#include <string>

#include "IExporter.h"
#include "../CanvasModel.h"

namespace otus
{
    class CustomFileIExporter : public IExporter
    {
    public:
        void Export(const CustomSharedPtr<CanvasModel> &canvasModel) override;
    };
}