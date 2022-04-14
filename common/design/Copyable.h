/*************************************************************************
    > Author: loyxin
    > Mail: loy.xin@qq.com
 ************************************************************************/

#ifndef UTIL_COMMON_DESIGN_COPYABLE_H_
#define UTIL_COMMON_DESIGN_COPYABLE_H_

#define NONCOPYMOVE(ClassName)                             \
    ClassName(const ClassName&) = delete;                  \
    ClassName(ClassName&&) = delete;                       \
    const ClassName& operator=(const ClassName&) = delete; \
    void operator=(ClassName&&) = delete;

#define NONCOPY(ClassName)                \
    ClassName(const ClassName&) = delete; \
    const ClassName& operator=(const ClassName&) = delete;

#define DEFAULTCOPYMOVE(ClassName)                          \
    ClassName(const ClassName&) = default;                  \
    ClassName(ClassName&&) = default;                       \
    const ClassName& operator=(const ClassName&) = default; \
    void operator=(ClassName&&) = default;

#endif  // UTIL_COMMON_DESIGN_COPYABLE_H_
