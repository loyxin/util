set(cmdoptionssrc detail/CommmandOptions.cpp)
add_library(util_cmdoptions ${cmdoptionssrc})

target_include_directories(util_cmdoptions PUBLIC ${Boost_INCLUDE_DIR})
target_link_libraries(util_cmdoptions PUBLIC ${Boost_LIBRARIES})

if(test)
  add_subdirectory(unittest)
endif()
