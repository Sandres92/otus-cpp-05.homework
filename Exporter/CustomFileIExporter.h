#include <string>

#include "IExporter.h"
#include "../Canvas/ICanvasModel.h"

namespace otus
{
    class CustomFileIExporter : public IExporter
    {
    public:
        CustomFileIExporter() = default;
        virtual ~CustomFileIExporter() = default;

        void Export(const CustomSharedPtr<ICanvasModel> &canvasModel) override;
    };
}