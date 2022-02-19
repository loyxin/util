
#include "cmdoptions/CommmandOptions.h"

#include <iostream>

using util::cmdoptions::CommandOptions;
using util::common::Color;

void CommandOptions::init()
{
    m_options->m_ptrColor = &m_isColor;
    auto usage = m_options->buildOptions();
    using boost::program_options::value;
    usage.add_options()("help,h", "");
    usage.add_options()("color,c", value<bool>(&(m_isColor))->default_value(true), "");

	using boost::program_options::command_line_parser;
	using boost::program_options::notify;
	using boost::program_options::store;
	store(command_line_parser(m_argc, m_argv).options(usage).allow_unregistered().run(), m_vmap);
	notify(m_vmap);
}

void CommandOptions::printHelpMsg()
{
    auto with = [this](common::Color color, std::string&& str) -> std::string {
        return m_isColor ? common::color::colorStr(color, str) : str;
    };

    std::string colorOpt = with(common::Color::FG_GREEN, "Boolean: true/false") + "\n";
    std::string strColor("Print Colorful Message.\nThe default is ");
    std::string colorMsg = colorOpt + strColor + with(Color::FG_YELLOW, "true.");

    auto usage = m_options->buildOptions();
    usage.add_options()("help,h", "Print Command Help Message.");
    usage.add_options()("color,c", colorMsg.c_str());
    std::cout << "This is Loyxin command option.\n";
    std::cout << usage << std::endl;
}
