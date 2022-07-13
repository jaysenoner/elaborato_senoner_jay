cmake_minimum_required(VERSION 3.22)
project(elaborato_senoner_jay)

set(CMAKE_CXX_STANDARD 14)

add_subdirectory(test)
set(SOURCE_FILES Date.cpp Date.h Transaction.cpp Transaction.h BankAccount.cpp BankAccount.h Hour.cpp Hour.h)


add_executable(elaborato_senoner_jay main.cpp BankAccount.cpp BankAccount.h Hour.cpp Hour.h)
add_library(core ${SOURCE_FILES} Hour.cpp Hour.h)
target_link_libraries(elaborato_senoner_jay core)
