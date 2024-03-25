#include <functional>
#include <memory>

namespace util {
template <class Func, typename... Args>
inline constexpr auto makeInvokeUnique(Func&& f, Args... args)
{
    using result_type = typename std::remove_pointer<typename std::invoke_result<Func, Args...>::type>::type;
    return std::unique_ptr<result_type>(std::invoke(std::forward<Func>(f), std::forward<Args>(args)...));
}

template <class Func, typename... Args>
inline constexpr auto makeInvokeShared(Func&& f, Args... args)
{
    using result_type = typename std::remove_pointer<typename std::invoke_result<Func, Args...>::type>::type;
    return std::shared_ptr<result_type>(std::invoke(std::forward<Func>(f), std::forward<Args>(args)...));
}

}  // namespace util
