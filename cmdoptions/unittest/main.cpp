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
    using util::cmdoptions::cmdopt;
    using util::common::design::Singleton;
    Singleton<MyCmdOptions>::newObj();
    auto* test = dynamic_cast<MyCmdOptions::Options*>(Singleton<MyCmdOptions>::getPtr());
    cmdopt::newObj(test, argc, argv);
    std::cout << Singleton<MyCmdOptions>::getPtr() << std::endl;
    std::cout << cmdopt::getPtr() << std::endl;
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
