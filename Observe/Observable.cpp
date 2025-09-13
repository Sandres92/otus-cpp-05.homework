#include "Observable.h"

namespace otus
{
    void Observable::AddObserver(IObserver *observer)
    {
        observers.push_back(observer);
    }

    void Observable::RemoveObserver(IObserver *observer)
    {
        for (auto it = observers.begin(); it != observers.end(); ++it)
        {
            if (*it == observer)
            {
                observers.erase(it);
                break;
            }
        }
    }

    void Observable::NotifyUpdate() const
    {
        for (auto it = observers.begin(); it != observers.end(); ++it)
        {
            (*it)->Update();
        }
    }
}