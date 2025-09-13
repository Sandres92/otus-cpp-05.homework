#include "Observable.h"

namespace otus
{
    void Observable::AddObserver(IObserver *observer)
    {
        CustomUniquePtr<IObserver> o(observer);
        observers.push_back(std::move(o));
    }

    void Observable::RemoveObserver(IObserver *observer)
    {
        for (auto it = observers.begin(); it != observers.end(); ++it)
        {
            if ((*it).get() == observer)
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
            (*it).get()->update();
        }
    }
}