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

    public:
        CanvasModel() = default;
        ~CanvasModel() = default;

        void AddPrimitive(GraphicPrimitive *graphicPrimitive);
        void RemovePrimitive(const GraphicPrimitive *graphicPrimitive);
        const std::vector<CustomUniquePtr<GraphicPrimitive>> &GetAllGraphicPrimitive() const;
    };
}