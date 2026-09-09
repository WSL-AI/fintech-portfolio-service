cmake_minimum_required(VERSION 3.20)

project(fintech_portfolio_course LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(fintech_portfolio
    main.cpp
    FinancialInstrument.cpp
)
