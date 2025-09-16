#pragma once

#include <vector>
#include "../CustomUniquePtr.h"
#include "GraphicPrimitive.h"
#include "../Observe/Observable.h"
#include "../Canvas/ICanvasModel.h"
#include "../Action/Action.h"

namespace otus
{
    class CanvasModel : public ICanvasModel
    {
    private:
        std::vector<CustomUniquePtr<GraphicPrimitive>> graphicPrimitives;
        int choosePrimitive = -1;

        // CustomUniquePtr<IObservable> observable;
        //  std::vector<Action<const std::vector<CustomUniquePtr<GraphicPrimitive>> &>> actions;
        Action<ActionParam> action;

    public:
        CanvasModel();
        ~CanvasModel();

        void AddPrimitive(GraphicPrimitive *graphicPrimitive);
        void RemovePrimitive(const GraphicPrimitive *graphicPrimitive);
        const std::vector<CustomUniquePtr<GraphicPrimitive>> &GetAllGraphicPrimitive() const;
        void AddObserver(IObserver *observer) override;

        uint64_t AddObserver2(std::function<void(ActionParam)> callback) override;
        void RemoveObserver2(uint64_t id) override;
        void Notify();
    };
}