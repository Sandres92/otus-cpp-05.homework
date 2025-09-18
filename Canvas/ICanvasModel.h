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
    /**
     * @brief Class (Interface) Canvas, which contains data of graphic editor.
     *
     * @details A set of graphical primitives
     *
     */
    class ICanvasModel
    {
    protected:
        using ActionParam = const std::vector<CustomUniquePtr<GraphicPrimitive>> &;

    public:
        ICanvasModel() = default;
        virtual ~ICanvasModel() = default;

        /**
         * @brief Function to add graphic primitive on canvas
         *
         * @param <in> new graphic primitive
         *
         */
        virtual void AddPrimitive(GraphicPrimitive *graphicPrimitive) = 0;

        /**
         * @brief Function to remove graphic primitive from canvas
         *
         * @param <in> removed graphic primitive
         *
         */
        virtual void RemovePrimitive(const GraphicPrimitive *graphicPrimitive) = 0;

        /**
         * @brief Return all graphic primitives of canvas
         *
         * @return All graphic primitives of canvas
         *
         */
        virtual const std::vector<CustomUniquePtr<GraphicPrimitive>> &GetAllGraphicPrimitive() const = 0;

        virtual void AddObserver(IObserver *observer) = 0;

        /**
         * @brief Function to add callback, when on canvas was changed
         *
         * @param <in> new callback function
         *
         * @return Id of callback function
         *
         */
        virtual uint64_t AddObserver2(std::function<void(ActionParam)> callback) = 0;

        /**
         * @brief Function to remove callback, when on canvas was changed
         *
         * @param <in> Id callback function
         *
         */
        virtual void RemoveObserver2(uint64_t id) = 0;

        /**
         * @brief Alert call function, when on canvas was changed
         *
         */
        virtual void Notify() = 0;
    };
}