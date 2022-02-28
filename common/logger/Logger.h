/*************************************************************************
    > Author: loyxin
    > Mail: loy.xin@qq.com
 ************************************************************************/

#ifndef COMMON_LOGGER_LOGGER_H_
#define COMMON_LOGGER_LOGGER_H_

#include <filesystem>
#define SPDLOG_FMT_EXTERNAL
#include <spdlog/spdlog.h>

#include "common/design/singleton/Singleton.h"
#include "common/design/Copyable.h"

namespace fs = std::filesystem;

namespace common::logger {
class Logger {
public:
    Logger();
    ~Logger();
	NONCOPYMOVE(Logger);

private:
    spdlog::logger m_logger;
	const static inline fs::path s_logdir = fs::current_path();
	const static inline char* const m_prefix = "loylog";
	static inline bool m_console = true;
};

}  // namespace common::logger
namespace common{
using loylog = util::common::design::Singleton<logger::Logger>;
}
#endif  // COMMON_LOGGER_LOGGER_H_
