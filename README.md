![cafe menu logo](/extras/artwork/cafe_menu_logo_1.png)

# Cafe Menu
<!-- ### Unit Test and Documentation Generation Workflow Status -->
![GH Actions Workflow Status](https://img.shields.io/github/last-commit/A-E-H-M/cafe-menu?style=for-the-badge)
![GH Actions Workflow Status](https://img.shields.io/github/actions/workflow/status/A-E-H-M/cafe-menu/build_run_unit_test_cmake.yml?style=for-the-badge)
![GH Actions Workflow Status](https://img.shields.io/github/license/A-E-H-M/cafe-menu?style=for-the-badge)
<!-- ![GH Actions Workflow Status] -->
<!-- ![GH Tag] -->

## Overview
Cafe Menu is a simple point of sale system built in C++. It supports three key areas of an order transaction: menu management, order management, and order calculations.

## Organization
Cafe Menu is a combination of two separate libraries: cafe_menu_core (CMC) and cafe_menu_iostream (CMIO). CMC contains all the business logic, whereas CMIO only handles display input and output. Ex. CMC contains a function to calculate a total, whereas CMIO contains a function to display the total.

It is important to note that CMIO is an optional library that provides an out of the box options to get users running as soon as possible.

Cafe Menu is designed to be as modular as possible to give users the ability to easily incorporate other libraries. Instead of using CMIO to manage display prompts, users can use CMC with other graphics libraries to achieve a variety of display options.

## Quick Start
For ease, there is a dedicated namespace for accessing all the classes called cafe_menu.

## Continuous Integration
### Supported Environments & Compilers
CI workflows currently build and unit test on g++ (through Ubuntu). In the future, MSVC (through Windows) and clang (through macOS) will be supported.

## Requirements
### Dependencies
Cafe Menu uses [CPM.cmake](https://github.com/cpm-cmake/CPM.cmake) for dependency management in Cmake. The build has been configured to download CMP from its Github repo if it is not already installed.

The unit test code uses [Catch2](https://github.com/catchorg/Catch2.git). If the 'CAFE_MENU_BUILD_TESTS' flag is provided to Cmake the Cmake configure / generate will download the Catch2.

### C++ Standard
C++ 11 is the minimum required C++ standard. However, C++ 17 is recommended as future versions will include C++ 17 features.

<!-- ## Generated Documentation -->
<!-- The generated Doxygen documentation for 'cafe_menu' is [here] (https) -->

## Build and Run Unit Tests
...Instructions to come...

## About Cafe Menu
Cafe Menu started out as a simple, single file programming exercise from a college course. It has now become a way to explore continuous integration and software design.
