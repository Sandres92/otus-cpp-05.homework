#pragma once

#include <iostream>
#include <vector>

#include "../GraphicPrimitives/GraphicPrimitive.h"
#include "../Observe/Observable.h"
#include "../CustomUniquePtr.h"
#include "../CustomSharedPtr.h"
#include "../Action/Action.h"

namespace otus
{
    class ICanvasModel
    {
    protected:
        using ActionParam = const std::vector<CustomUniquePtr<GraphicPrimitive>> &;

    public:
        ICanvasModel() = default;
        virtual ~ICanvasModel() = default;

        virtual void AddPrimitive(GraphicPrimitive *graphicPrimitive) = 0;
        virtual void RemovePrimitive(const GraphicPrimitive *graphicPrimitive) = 0;
        virtual const std::vector<CustomUniquePtr<GraphicPrimitive>> &GetAllGraphicPrimitive() const = 0;

        virtual void AddObserver(IObserver *observer) = 0;
        virtual uint64_t AddObserver2(std::function<void(ActionParam)> callback) = 0;
        virtual void RemoveObserver2(uint64_t id) = 0;
    };
}