#pragma once

#include "../Canvas/CanvasModel.h"
#include <string>

namespace otus
{
    class IIimporter
    {
    public:
        IIimporter() = default;
        virtual ~IIimporter() = default;

        virtual ICanvasModel *Import(const std::string &fileName) = 0;
    };
}