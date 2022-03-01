#ifndef UTIL_DESIGN_SINGLETON_H_
#define UTIL_DESIGN_SINGLETON_H_

#include <cassert>
#include <memory>

#include "common/design/Copyable.h"

namespace util::common::design {

namespace detail {

template <class T>
class Delete {
public:
    Delete() = default;
    ~Delete() = default;
    void operator()(T* ptr)
    {
        if (m_own) {
            delete ptr;
        }
    }
    bool m_own = true;
};

}  // namespace detail

template <typename T>
class Singleton final {
public:
    Singleton() = delete;
    ~Singleton() = delete;
    NONCOPYMOVE(Singleton);

    static T* getPtr()
    {
        return getPPtr()->get();
    }

    template <typename... Args>
    static void newObj(Args&... args)
    {
        assert(getPPtr()->get() == nullptr && "Have set the Sington instance");
        getPPtr()->reset(new T(std::forward<Args>(args)...));
    }

    static void factoryObj(T* ptr, bool own = false)
    {
        assert(getPPtr()->get() == nullptr && "Have set the Sington instance");
        getPPtr()->reset(ptr);
        getPPtr()->get_deleter().m_own = own;
    }

    /**
     * @brief no need to delete for free memory!!
     * this function just for new object
     */
    static void deleteObj()
    {
        assert(getPPtr()->get() != nullptr && "no object in Singleton");
        getPPtr()->reset(nullptr);
    }

private:
    static std::unique_ptr<T, detail::Delete<T>>* getPPtr()
    {
        static std::unique_ptr<T, detail::Delete<T>> ptr(nullptr);
        return &ptr;
    }
};

}  // namespace util::common::design

#endif  // UTIL_DESIGN_SINGLETON_H_
