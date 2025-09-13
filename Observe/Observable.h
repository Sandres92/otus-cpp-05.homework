#include <vector>
#include "IObserver.h"
#include "IObservable.h"
#include "../CustomUniquePtr.h"

namespace otus
{
    class Observable : IObservable
    {
    private:
        std::vector<CustomUniquePtr<IObserver>> observers;

    public:
        void AddObserver(IObserver *observer) override;

        void RemoveObserver(IObserver *observer) override;

        void NotifyUpdate() const override;
    };
}