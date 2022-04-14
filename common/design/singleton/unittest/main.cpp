#include <iostream>
#include <ostream>
#include "../Singleton.h"

class A {
public:
    explicit A(int i) : x(i) {}

private:
    int x;
};

int main(int argc, char* argv[])
{
    using namespace util::common::design;
    int x = 1;
    Singleton<A>::newObj(x);
    auto* a = Singleton<A>::getPtr();
    std::cout << a << std::endl;
    auto* b = util::memory::SingleBuffer::getMemory(5);
    std::cout << b << std::endl;
    return 0;
}
