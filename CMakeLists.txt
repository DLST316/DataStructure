cmake_minimum_required(VERSION 3.5.0)
project(PostfixCalculator VERSION 0.1.0 LANGUAGES C)

include(CTest)
enable_testing()

add_executable(PostfixCalculator 2-2/TestCalculate.c 2-2/Calculator.c 2-2/lls.c)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
