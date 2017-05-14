
cmake_minimum_required(VERSION 3.6)
project(basic_function_usage)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        libs/biky-arrays/src/copying.cc
        libs/biky-arrays/src/set-value.cc
        source/main.cc
        source/biky-basic-functions.cc
        source/biky-linear-algebra/src/linear-operations.cc
        source/biky-linear-algebra/src/products.cc
        source/biky-linear-algebra/src/initializations.cc
        source/13-determinant.cc
        source/13-inverse.cc
        )

add_executable(basic_function_usage ${SOURCE_FILES})