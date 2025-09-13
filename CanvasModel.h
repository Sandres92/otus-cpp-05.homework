#include <vector>
#include "CustomUniquePtr.h"
#include "GraphicPrimitive.h"

namespace otus
{
    class CanvasModel
    {
    private:
        std::vector<CustomUniquePtr<GraphicPrimitive>> graphicPrimitives;
        int choosePrimitive = -1;

    public:
        CanvasModel();
        ~CanvasModel();

        void AddPrimitive(GraphicPrimitive *graphicPrimitive);
        void RemovePrimitive(const GraphicPrimitive const *graphicPrimitive);
        void ChoosePrimitive(const GraphicPrimitive const *graphicPrimitive = nullptr);
    };
}