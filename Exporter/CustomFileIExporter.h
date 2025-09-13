#include <string>

#include "IExporter.h"
#include "../Canvas/ICanvasModel.h"

namespace otus
{
    class CustomFileIExporter : public IExporter
    {
    public:
        void Export(const CustomSharedPtr<ICanvasModel> &canvasModel) override;
    };
}