#include "Observable.h"

namespace otus
{
    void Observable::AddObserver(IObserver *observer)
    {
        if (std::find(observers.begin(), observers.end(), observer) == observers.end())
        {
            observers.push_back(observer);
        }
    }

    void Observable::RemoveObserver(IObserver *observer)
    {
        auto it = std::remove(observers.begin(), observers.end(), observer);
        observers.erase(it, observers.end());
    }

    void Observable::RemoveAllObserver()
    {
        observers.clear();
    }

    void Observable::NotifyUpdate() const
    {
        for (auto it = observers.begin(); it != observers.end(); ++it)
        {
            (*it)->Update();
        }
    }
}