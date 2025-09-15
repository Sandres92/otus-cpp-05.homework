#pragma once

#include <vector>
#include "../CustomUniquePtr.h"
#include "GraphicPrimitive.h"
#include "../Observe/Observable.h"
#include "../Canvas/ICanvasModel.h"

namespace otus
{
    class CanvasModel : public ICanvasModel
    {
    private:
        std::vector<CustomUniquePtr<GraphicPrimitive>> graphicPrimitives;
        int choosePrimitive = -1;

        CustomUniquePtr<IObservable> observable;

    public:
        CanvasModel();
        ~CanvasModel();

        void AddPrimitive(GraphicPrimitive *graphicPrimitive);
        void RemovePrimitive(const GraphicPrimitive *graphicPrimitive);
        const std::vector<CustomUniquePtr<GraphicPrimitive>> &GetAllGraphicPrimitive() const;
        void AddObserver(IObserver *observer) override;
        inline static int countCreation = 0;
    };
}