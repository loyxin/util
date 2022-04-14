#ifndef UTIL_COMMON_TIMER_H_
#define UTIL_COMMON_TIMER_H_

#include <boost/timer/timer.hpp>

#include "dbg.h"

namespace util::common {
class Timer {
public:
    Timer() = default;
    ~Timer()
    {
#ifndef DBG_MACRO_DISABLE
        dbg("FIXME", m_time.format());
#endif
    }

    [[nodiscard]] bool is_stopped() noexcept
    {
#ifndef DBG_MACRO_DISABLE
        return m_time.is_stopped();
#endif
        return true;
    }

    void start() noexcept
    {
#ifndef DBG_MACRO_DISABLE
        m_time.start();
#endif
    }

    void stop() noexcept
    {
#ifndef DBG_MACRO_DISABLE
        m_time.stop();
#endif
    }

    void resume() noexcept
    {
#ifndef DBG_MACRO_DISABLE
        m_time.resume();
#endif
    }

private:
#ifndef DBG_MACRO_DISABLE
    boost::timer::cpu_timer m_time;
#endif
};
}  // namespace util::common

#endif  // UTIL_COMMON_TIMER_H_
