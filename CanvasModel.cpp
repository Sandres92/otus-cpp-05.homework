
#include "CanvasModel.h"

namespace otus
{
    void CanvasModel::AddPrimitive(GraphicPrimitive *graphicPrimitive)
    {
        CustomUniquePtr<GraphicPrimitive> g(graphicPrimitive);
        graphicPrimitives.push_back(std::move(g));

        NotifyUpdate();
    }

    void CanvasModel::RemovePrimitive(const GraphicPrimitive *graphicPrimitive)
    {
        for (auto it = graphicPrimitives.begin(); it != graphicPrimitives.end(); ++it)
        {
            if ((*it).get() == graphicPrimitive)
            {
                graphicPrimitives.erase(it);
                break;
            }
        }

        NotifyUpdate();
    }

    const std::vector<CustomUniquePtr<GraphicPrimitive>> &CanvasModel::GetAllGraphicPrimitive() const
    {
        return graphicPrimitives;
    }
}