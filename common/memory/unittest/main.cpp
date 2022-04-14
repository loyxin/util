
#include <iostream>
#include "../Alloc.h"

int main(int argc, char* argv[])
{
    constexpr int s = 100;
    auto* ptr = static_cast<int*>(util::memory::SingleBuffer::getMemory(s * sizeof(int)));
    for (int i = 0; i < s; ++i) {
        ptr[i] = i;
    }
    std::cout << sizeof(int) << std::endl;
    std::cout << ptr << std::endl;

    ptr = static_cast<int*>(util::memory::SingleBuffer::getMemory(2 * s * sizeof(int)));
    std::cout << ptr << std::endl;

    ptr = static_cast<int*>(util::memory::VectorBuffer::getMemory(2 * s * sizeof(int)));
    std::cout << ptr << std::endl;

    return 0;
}
