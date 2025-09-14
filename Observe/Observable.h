#pragma once

#include <vector>
#include <algorithm>

#include "IObserver.h"
#include "IObservable.h"
#include "../CustomSharedPtr.h"

namespace otus
{
    class Observable : public IObservable
    {
    private:
        std::vector<IObserver *> observers;

    public:
        void AddObserver(IObserver *observer) override;
        void RemoveObserver(IObserver *observer) override;
        void RemoveAllObserver() override;

        void NotifyUpdate() const override;
    };
}