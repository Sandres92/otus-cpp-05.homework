#pragma once

#include <iostream>
#include "ICanvasModel.h"
#include "../CustomUniquePtr.h"
#include "../CustomSharedPtr.h"

namespace otus
{
    class ICanvasView : public IObserver
    {
    public:
        virtual ~ICanvasView() = default;
    };
}