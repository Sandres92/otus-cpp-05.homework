
#include "CanvasModel.h"

namespace otus
{
    CanvasModel::CanvasModel()
    {
    }
    CanvasModel::~CanvasModel()
    {
    }

    void CanvasModel::AddPrimitive(GraphicPrimitive *graphicPrimitive)
    {
        CustomUniquePtr<GraphicPrimitive> g(graphicPrimitive);
        graphicPrimitives.push_back(std::move(g));
    }

    void CanvasModel::RemovePrimitive(const GraphicPrimitive const *graphicPrimitive)
    {
        for (auto it = graphicPrimitives.begin(); it != graphicPrimitives.end(); ++it)
        {
            if ((*it).get() == graphicPrimitive)
            {
                graphicPrimitives.erase(it);
                break;
            }
        }
    }

    void CanvasModel::ChoosePrimitive(const GraphicPrimitive const *graphicPrimitive = nullptr)
    {
        if (graphicPrimitive == nullptr)
        {
            choosePrimitive = -1;
            return;
        }

        for (size_t i = 0; i != graphicPrimitives.size(); ++i)
        {
            if (graphicPrimitives[i].get() == graphicPrimitive)
            {
                choosePrimitive = i;
                break;
            }
        }
    }
}