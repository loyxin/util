set(unittestSrc
    main.cpp
)

add_executable(unittestCmdoptions ${unittestSrc})
target_include_directories(unittestCmdoptions PRIVATE ${GTEST_INCLUDE_DIRS})
target_link_libraries(unittestCmdoptions util_cmdoptions ${GTEST_LIBRARIES})

add_test(unittestCmdoptions unittestCmdoptions)
