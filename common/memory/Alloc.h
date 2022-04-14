#ifndef UTIL_MEMORY_ALLOC_H_
#define UTIL_MEMORY_ALLOC_H_

#include <cassert>
#include <experimental/memory_resource>
#include <memory>
#include <memory_resource>
#include <vector>

namespace util::memory {
namespace detail {
constexpr int maxSizeOnStack = 1 << 12;
constexpr int defaultVectorSize = 8;
constexpr int LittleMemorySize = 1 << 13;
constexpr int MediumMemorySize = 1 << 18;
constexpr int BigMemorySize = 1 << 23;

enum ResidentType { Little = 0, Medium = 1, Big = 2 };
constexpr int getSize(ResidentType type)
{
    switch (type) {
    case Little:
        return LittleMemorySize;
    case Medium:
        return MediumMemorySize;
    case Big:
        return BigMemorySize;
    }
}
}  // namespace detail

template <size_t size = detail::maxSizeOnStack>
class StackBuffer {
public:
    StackBuffer() = default;
    ~StackBuffer() = default;
    void* operator new(size_t) = delete;
    void operator delete(void* ptr) = delete;

    std::pmr::monotonic_buffer_resource& getPool()
    {
        return m_pool;
    }

private:
    std::array<int8_t, size> m_buffer = {};
    std::pmr::monotonic_buffer_resource m_pool{std::data(m_buffer), std::size(m_buffer)};
};

template <detail::ResidentType type>
class ResidentBuffer {
public:
    static void* getMemory(int64_t size)
    {
        constexpr auto blockSize = getSize(type);
        assert(size < blockSize);
        auto newBlockInMemory = [size]() {
            m_memoryVec.emplace_back(new char[blockSize]);
            auto* ptr = m_memoryVec.back().get();
            m_currentPtr = ptr + size;
            return ptr;
        };
        if (m_currentPtr == nullptr) {
            m_memoryVec.reserve(detail::defaultVectorSize);
            return newBlockInMemory();
        }
        auto* newPtr = m_currentPtr + size;
        if ((newPtr - m_memoryVec.back().get()) > blockSize) {
            return newBlockInMemory();
        }
        std::swap(newPtr, m_currentPtr);
        return newPtr;
    }

private:
    inline static std::vector<std::unique_ptr<char[]>> m_memoryVec;
    inline static char* m_currentPtr{nullptr};
};

using SingleBuffer = ResidentBuffer<detail::Little>;
using VectorBuffer = ResidentBuffer<detail::Medium>;
using ImageBuffer = ResidentBuffer<detail::Big>;

}  // namespace util::memory
#endif  // UTIL_MEMORY_ALLOC_H_
