set(cmdoptionssrc detail/CommmandOptions.cpp)
add_library(cmdoptions ${cmdoptionssrc})

target_include_directories(cmdoptions PUBLIC ${Boost_INCLUDE_DIR})
target_link_libraries(cmdoptions PUBLIC ${Boost_LIBRARIES})

if(test)
  add_subdirectory(unittest)
endif()
