#pragma once
namespace otus
{
    class IObserver
    {
    public:
        IObserver() = default;
        virtual ~IObserver() = default;

        virtual void update() = 0;
    };
}