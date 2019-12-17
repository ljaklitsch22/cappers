cmake_minimum_required(VERSION 3.12)
project(cappers)

set(CMAKE_CXX_STANDARD 14)

add_executable(cappers main.cpp Match.h BetSlip.cpp BetSlip.h Capper.h Match.cpp BettingBoard.cpp BettingBoard.h Database.cpp Date.cpp Date.h)