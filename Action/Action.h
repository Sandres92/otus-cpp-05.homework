#pragma once

#include <vector>
#include <functional>
#include <algorithm>
#include <cstdint>

namespace otus
{
    /**
     * @brief Class to realize pattern Publisher-subscriber.
     *
     * @details Store callbacks on event, call it
     *
     * @param <in> T is type of callback Incoming parameter
     *
     */
    template <typename T>
    class Action
    {
    private:
        using Callback = std::function<void(T)>;
        uint64_t id = 0;
        std::vector<std::pair<uint64_t, Callback>> callbacks;

    public:
        /**
         * @brief Call all callbacks function without parameters
         *
         */
        void Invoke()
        {
            for (auto &[id, callback] : callbacks)
            {
                callback();
            }
        }

        /**
         * @brief Call all callbacks function with parameters
         *
         * @param <in> Incoming parameter
         *
         */
        void Invoke(const T &t)
        {
            for (auto &[id, callback] : callbacks)
            {
                callback(t);
            }
        }

        /**
         * @brief Add new callback function
         *
         * @param <in> callback function
         *
         * @return Return id of callback function
         *
         */
        uint64_t AddFunction(const Callback &cb)
        {
            ++id;
            callbacks.push_back(std::make_pair(id, cb));
            return id;
        }

        /**
         * @brief Add new callback function
         *
         * @param <in> id of callback function
         *
         */
        void RemoveFunction(uint64_t id)
        {
            auto it = std::remove_if(callbacks.begin(), callbacks.end(), [id](const auto &p)
                                     { return p.first == id; });
            callbacks.erase(it, callbacks.end());
        }

        /**
         * @brief Remove all callbacks functions
         *
         */
        void RemoveAll()
        {
            callbacks.clear();
        }
    };
}