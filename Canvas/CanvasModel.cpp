
#include "CanvasModel.h"

namespace otus
{
    CanvasModel::CanvasModel() : observable(CustomUniquePtr<IObservable>(new Observable()))
    {
    }
    CanvasModel::~CanvasModel()
    {
        observable.get()->RemoveAllObserver();
    }

    void CanvasModel::AddPrimitive(GraphicPrimitive *graphicPrimitive)
    {
        CustomUniquePtr<GraphicPrimitive> g(graphicPrimitive);
        graphicPrimitives.push_back(std::move(g));

        observable.get()->NotifyUpdate();
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

        observable.get()->NotifyUpdate();
    }

    const std::vector<CustomUniquePtr<GraphicPrimitive>> &CanvasModel::GetAllGraphicPrimitive() const
    {
        return graphicPrimitives;
    }

    void CanvasModel::AddObserver(IObserver *observer)
    {
        observable.get()->AddObserver(observer);
    }
}