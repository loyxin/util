#ifndef UTIL_CMDOPTIONS_COMMANDOPTIONS_H_
#define UTIL_CMDOPTIONS_COMMANDOPTIONS_H_

#include <string>

#include <boost/program_options.hpp>

#include "common/Colors.h"
#include "common/design/singleton/Singleton.h"

namespace util::cmdoptions {

class Options {
public:
    Options() = default;
    virtual ~Options() = default;
    NONCOPYMOVE(Options);
    virtual boost::program_options::options_description buildOptions() = 0;

    template <common::Color color>
    inline std::string with(std::string& str)
    {
        return *m_ptrColor ? common::color::colorStr(color, str) : str;
    }

    template <common::Color color>
    inline std::string with(std::string&& str)
    {
        return with<color>(str);
    }

    bool* m_ptrColor = nullptr;
};

class CommandOptions {
public:
    CommandOptions(Options* op, int argc, char** argv) : m_options(op), m_argc(argc), m_argv(argv)
    {
        init();
    }
    ~CommandOptions()
    {
        if (count("help")) {
            printHelpMsg();
        }
    }
    NONCOPYMOVE(CommandOptions);

    boost::program_options::variables_map& getOpts()
    {
        return m_vmap;
    }

    template <typename T>
    T getValue(const char* name)
    {
        return m_vmap[name].as<T>();
    }

    bool count(const char* name)
    {
        return m_vmap.count(name) != 0U;
    }

private:
    void init();
    void printHelpMsg();
    Options* m_options;
    boost::program_options::variables_map m_vmap;
    int m_argc;
    char** m_argv;
    bool m_isColor = false;
};

using cmdopt = util::common::design::Singleton<CommandOptions>;

}  // namespace util::cmdoptions

#endif  // UTIL_CMDOPTIONS_COMMANDOPTIONS_H_
