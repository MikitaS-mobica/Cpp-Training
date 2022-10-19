cmake_minimum_required(VERSION 3.0.0)
project(CppTraining_FractalImageProject VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable(
    CppTraining_FractalImageProject
    main.cpp
    BitmapImage.h
    BitmapImage.cpp
    BitmapFileHeaders.h
    BitmapFileHeaders.cpp
    FractalImage.h
    FractalImage.cpp
    ImageUtils.h
    ImageUtils.cpp
    Mandlebrot.h
    Mandlebrot.cpp
)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
