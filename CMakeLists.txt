# Copyright (C) 2022 The Qt Company Ltd.
# SPDX-License-Identifier: BSD-3-Clause

cmake_minimum_required(VERSION 3.16)

include(.cmake.conf)
project(QtBreezeStyle
    VERSION "${QT_REPO_MODULE_VERSION}"
    DESCRIPTION "Qt Breeze Style Plugin"
    HOMEPAGE_URL "https://qt.io/"
    LANGUAGES CXX C
)

find_package(Qt6 ${PROJECT_VERSION} CONFIG REQUIRED COMPONENTS BuildInternals Widgets)
find_package(Qt6 ${PROJECT_VERSION} QUIET CONFIG OPTIONAL_COMPONENTS Widgets)
qt_internal_project_setup()

if(NOT TARGET Qt::Widgets)
    message(NOTICE "Skipping the build as the condition \"TARGET Qt::Widgets\" is not met.")
    return()
endif()
qt_build_repo()
