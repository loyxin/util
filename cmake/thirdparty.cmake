# boost
find_package(Boost REQUIRED program_options)
if(Boost_FOUND)
	set(Boost_USE_STATIC_LIBS ON)
	message(STATUS "boost include path is : ${Boost_INCLUDE_DIRS}")
	message(STATUS "boost library path is : ${Boost_LIBRARY_DIRS}")
	message(STATUS "boost libraries is : ${Boost_LIBRARIES}")
	include_directories(${Boost_INCLUDE_DIRS})
	link_directories(${Boost_LIBRARY_DIRS})
else()
    message(WARNING "boost not found.")
endif()


# gtest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})
