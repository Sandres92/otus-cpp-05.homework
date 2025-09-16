
#include "CanvasModel.h"

namespace otus
{
    CanvasModel::CanvasModel()
    {
    }
    CanvasModel::~CanvasModel()
    {
        // observable.get()->RemoveAllObserver();
        action.RemoveAll();
    }

    void CanvasModel::AddPrimitive(GraphicPrimitive *graphicPrimitive)
    {
        CustomUniquePtr<GraphicPrimitive> g(graphicPrimitive);
        graphicPrimitives.push_back(std::move(g));

        Notify();
        // observable.get()->NotifyUpdate();
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

        Notify();
        // observable.get()->NotifyUpdate();
        // action.get()->Invoke(graphicPrimitives);
    }

    const std::vector<CustomUniquePtr<GraphicPrimitive>> &CanvasModel::GetAllGraphicPrimitive() const
    {
        return graphicPrimitives;
    }

    void CanvasModel::AddObserver(IObserver *observer)
    {
        if (observer)
        {
            std::cout << "CanvasModel::AddObserver(IObserver *observer) \n";
        }
        // observable.get()->AddObserver(observer);
    }
    uint64_t CanvasModel::AddObserver2(std::function<void(ActionParam)> callback)
    {
        return action.AddFunction(callback);
    }

    void CanvasModel::RemoveObserver2(uint64_t id)
    {
        // auto it = std::remove(actions.begin(), actions.end(), action);
        action.RemoveFunction(id);
    }

    void CanvasModel::Notify()
    {
        action.Invoke(graphicPrimitives);
    }
}