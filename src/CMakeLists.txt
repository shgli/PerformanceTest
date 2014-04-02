INCLUDE(CollectSrcs)
PROJECT(PerformanceTest)
INCLUDE_DIRECTORIES(${CMAKE_SOURCE_DIR})
INCLUDE_DIRECTORIES(${CMAKE_SOURCE_DIR}/include)
INCLUDE_DIRECTORIES($ENV{BOOST_INCLUDE})
LINK_DIRECTORIES($ENV{BOOST_LIB})
ADD_SUBDIRECTORY(common)

IF (NOT Win32)
    ADD_DEFINITIONS(-DBOOST_TEST_DYN_LINK)
ENDIF()

SET(PerformanceTest_SUBDIRS . common)

GET_SRCS(PerformanceTest_SRCLISTS PerformanceTest_SUBDIRS)
ADD_EXECUTABLE(PerformanceTest ${PerformanceTest_SRCLISTS})

TARGET_LINK_LIBRARIES(PerformanceTest boost_filesystem)
TARGET_LINK_LIBRARIES(PerformanceTest boost_system)
TARGET_LINK_LIBRARIES(PerformanceTest boost_unit_test_framework)
TARGET_LINK_LIBRARIES(PerformanceTest boost_timer boost_thread)
TARGET_LINK_LIBRARIES(PerformanceTest boost_timer tbb)
TARGET_LINK_LIBRARIES(PerformanceTest sigar)
TARGET_LINK_LIBRARIES(PerformanceTest odb odb-pgsql odb-boost)

INSTALL(TARGETS PerformanceTest 
    RUNTIME DESTINATION bin
    ARCHIVE DESTINATION lib)

INSTALL(DIRECTORY ${CMAKE_SOURCE_DIR}/PerformanceTest/
    DESTINATION include/PerformanceTest
    FILES_MATCHING PATTERN "*.h")


