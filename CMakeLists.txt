cmake_minimum_required(VERSION 3.5.0)
project(CQ VERSION 0.1.0 LANGUAGES C)

include(CTest)
enable_testing()

add_executable(CQ 4-3/ExpressionTree.c 4-3/TestET.c) 

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
