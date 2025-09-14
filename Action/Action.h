#include <vector>
#include <functional>
#include <algorithm>

namespace otus
{
    template <typename T>
    class Action
    {
    private:
        using Callback = std::function<void(T)>;
        std::vector<Callback> callbacks;

    public:
        void Invoke()
        {
            for (const auto &callback : callbacks)
            {
                callback();
            }
        }

        void Invoke(T t)
        {
            for (const auto &callback : callbacks)
            {
                callback(t);
            }
        }
        void AddFunction(const Callback &cb)
        {
            // bool isContains = false;
            // for (sizt_t i = 0; i != v.size(); ++i)
            //{
            //     if (v[i] == f)
            //     {
            //         isContains = true;
            //         break;
            //     }
            // }
            //
            // if (!isContains)
            //{
            //    v.push_back(f);
            //}

            if (std::find(callbacks.begin(), callbacks.end(), cb) == callbacks.end())
            {
                callbacks.push_back(cb);
            }
        }
        void RemoveFunction(const Callback &cb)
        {
            // for (sizt_t i = 0; i != v.size(); ++i)
            //{
            //     if (v[i] == f)
            //     {
            //         v.erase(f);
            //         break;
            //     }
            // }

            auto ne = std::remove(callbacks.begin(), callbacks.end(), cb);
            callbacks.erase(ne, callbacks.end());
        }
        void RemoveAll()
        {
            callbacks.clear();
        }
    };
}