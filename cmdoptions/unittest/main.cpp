#include <gtest/gtest.h>

#include "cmdoptions/CommmandOptions.h"

class MyCmdOptions : public util::cmdoptions::Options {
public:
    boost::program_options::options_description buildOptions() override 
    {
        boost::program_options::options_description usage;
        return usage;
    }
};

int main(int argc, char* argv[])
{
    auto* test = dynamic_cast<util::cmdoptions::Options*>(new MyCmdOptions);
    util::cmdoptions::cmdopt::newObj(test, argc, argv);
	testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
