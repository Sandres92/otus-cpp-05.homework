#include <string>
#include "../CanvasModel.h"
#include "../CustomSharedPtr.h"

namespace otus
{
    class IExporter
    {
    public:
        virtual void Export(const CustomSharedPtr<CanvasModel> &canvasModel) = 0;
    };
}