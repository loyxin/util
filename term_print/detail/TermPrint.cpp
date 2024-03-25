#include "term_print/thread.h"

namespace util::detail {

void TermPrint::worker()
{
    while (m_isRunning) {
        std::function<void()> task;
        if (!m_paused && pop_task(task)) {
            task();
            m_tasks_total--;
        } else {
            sleep_or_yield();
        }
    }
}

bool TermPrint::pop_task(std::function<void()>& task)
{
    if (m_tasks.empty()) {
        return false;
    }
    task = std::move(m_tasks.front());
    m_tasks.pop();
    return true;
}

}  // namespace util::detail
