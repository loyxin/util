#ifndef UTIL_TERM_PRINT_H_
#define UTIL_TERM_PRINT_H_

#include <atomic>
#include <functional>
#include <thread>
#include <queue>

#include "common/design/Copyable.h"

namespace util::detail {
class TermPrint {
public:
    TermPrint() = delete;
    NONCOPYMOVE(TermPrint);
    ~TermPrint()
    {
		m_isRunning = false;
        m_thread.join();
    }

    std::atomic<bool> m_paused = false;
private:
    void worker();
    bool pop_task(std::function<void()> &task);
    void sleep_or_yield();

    std::thread m_thread;
    std::atomic<bool> m_isRunning = true;
    std::queue<std::function<void()>> m_tasks = {};
    std::atomic<unsigned int> m_tasks_total = 0;
};

}  // namespace util::detail

#endif  // UTIL_TERM_PRINT_H_
