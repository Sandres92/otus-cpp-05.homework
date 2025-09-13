#include <string>
#include "../Canvas/ICanvasModel.h"
#include "../CustomSharedPtr.h"

namespace otus
{
    class IExporter
    {
    public:
        virtual void Export(const CustomSharedPtr<ICanvasModel> &canvasModel) = 0;
    };
}