#pragma once

#include <vector>
#include <functional>
#include <algorithm>
#include <cstdint>

namespace otus
{
    template <typename T>
    class Action
    {
    private:
        using Callback = std::function<void(T)>;
        uint64_t id = 0;
        std::vector<std::pair<uint64_t, Callback>> callbacks;

    public:
        void Invoke()
        {
            for (auto &[id, callback] : callbacks)
            {
                callback();
            }
        }

        void Invoke(const T &t)
        {
            for (auto &[id, callback] : callbacks)
            {
                callback(t);
            }
        }
        uint64_t AddFunction(const Callback &cb)
        {
            ++id;
            callbacks.push_back(std::make_pair(id, cb));
            return id;
        }
        void RemoveFunction(uint64_t id)
        {
            auto it = std::remove_if(callbacks.begin(), callbacks.end(), [id](const auto &p)
                                     { return p.first == id; });
            callbacks.erase(it, callbacks.end());
        }
        void RemoveAll()
        {
            callbacks.clear();
        }
    };
}