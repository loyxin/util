#ifndef UTIL_THREAD_THREAD_H_
#define UTIL_THREAD_THREAD_H_

#include "common/design/singleton/Singleton.h"
#include "thread/detail/thread-pool/thread_pool.hpp"

namespace util::thread {

namespace detail {
constexpr int thread_nums = 12;
}

static thread_pool pool(detail::thread_nums);

}  // namespace util::thread

#endif  // UTIL_THREAD_THREAD_H_
