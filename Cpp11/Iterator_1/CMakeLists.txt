cmake_minimum_required(VERSION 3.0.0)
project(CppTraining_Iterator_1 VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable(
    CppTraining_Iterator_1
    main.cpp
    CyclicBuffer.h
    CyclicBuffer.cpp
    CyclicBufferIterator.cpp
)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
