#ifndef UTIL_DESIGN_SINGLETON_H_
#define UTIL_DESIGN_SINGLETON_H_

#include <cassert>
#include <utility>
#include <memory>

namespace util::common::design {

template <typename T>
class Singleton final {
public:
    Singleton() = delete;
    ~Singleton() = delete;
    Singleton(const Singleton&) = delete;
    Singleton(Singleton&&) = delete;
    Singleton operator=(Singleton&&) = delete;
    Singleton& operator=(const Singleton&) = delete;

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


private:
    static std::unique_ptr<T>* getPPtr()
    {
        static std::unique_ptr<T> ptr(nullptr);
        return &ptr;
    }
};

}  // namespace util::common::design

#endif  // UTIL_DESIGN_SINGLETON_H_
