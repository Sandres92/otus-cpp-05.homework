#pragma once

namespace otus
{
    class IObserver
    {
    public:
        virtual ~IObserver() = default;
        virtual void Update() = 0;
    };
}