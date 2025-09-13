#include <vector>
#include "IObserver.h"

namespace otus
{
    class IObservable
    {
    public:
        virtual ~IObservable() = default;
        virtual void AddObserver(IObserver *observer) = 0;
        virtual void RemoveObserver(IObserver *observer) = 0;

        virtual void NotifyUpdate() const = 0;
    };
}