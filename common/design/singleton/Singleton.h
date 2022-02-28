#ifndef UTIL_DESIGN_SINGLETON_H_
#define UTIL_DESIGN_SINGLETON_H_

#include <cassert>
#include <memory>

#include "common/design/Copyable.h"

namespace util::common::design {

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
    static std::unique_ptr<T>* getPPtr()
    {
        static std::unique_ptr<T> ptr(nullptr);
        return &ptr;
    }
};

}  // namespace util::common::design

#endif  // UTIL_DESIGN_SINGLETON_H_
