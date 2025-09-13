#pragma once

#include <iostream>
#include <vector>

#include "../GraphicPrimitives/GraphicPrimitive.h"
#include "../Observe/Observable.h"
#include "../CustomUniquePtr.h"
#include "../CustomSharedPtr.h"

namespace otus
{
    class ICanvasModel : public Observable
    {
    public:
        ICanvasModel() = default;
        virtual ~ICanvasModel() = default;

        virtual void AddPrimitive(GraphicPrimitive *graphicPrimitive) = 0;
        virtual void RemovePrimitive(const GraphicPrimitive *graphicPrimitive) = 0;
        virtual const std::vector<CustomUniquePtr<GraphicPrimitive>> &GetAllGraphicPrimitive() const = 0;
    };
}