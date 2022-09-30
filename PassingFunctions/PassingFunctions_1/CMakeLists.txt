cmake_minimum_required(VERSION 3.0.0)
project(CppTraining_PassingFunctions VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable(CppTraining_PassingFunctions
    main.cpp
    Bridge.h
    Bridge.cpp
    ArchBridge.h
    ArchBridge.cpp
    TiedArchBridge.h
    TiedArchBridge.cpp)


set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
