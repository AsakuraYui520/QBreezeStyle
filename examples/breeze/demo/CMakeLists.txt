# Generated from afterrequest.pro.

cmake_minimum_required(VERSION 3.14)

project(demo LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt6 COMPONENTS Widgets)

add_executable(demo
        main.cpp
        widgetfactory.h
        widgetfactory.cpp
        widgetfactory.ui
)
target_link_libraries(demo PRIVATE
        Qt::Widgets
)
