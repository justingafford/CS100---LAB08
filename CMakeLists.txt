CMAKE_MINIMUM_REQUIRED(VERSION 2.8)
 
ADD_SUBDIRECTORY(googletest)
 
SET(CMAKE_CXX_STANDARD 11)
 
ADD_EXECUTABLE(test
   unit_test.cpp
   Add.cpp
   Div.cpp
   Op.cpp
   Rand.cpp
   Mult.cpp
   Pow.cpp
   Sub.cpp
)
 
TARGET_LINK_LIBRARIES(test gtest)
TARGET_COMPILE_DEFINITIONS(test PRIVATE gtest_disable_pthreads=ON)
