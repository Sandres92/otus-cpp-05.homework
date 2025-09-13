#pragma once

namespace otus
{
    class IObserver
    {
    public:
        virtual void Update() = 0;
    };
}