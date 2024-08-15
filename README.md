# Cafe Menu
Cafe Menu is a simple point of sale library written in C++.
<!-- ### Unit Test and Documentation Generation Workflow Status -->
<!-- ![GH Actions Workflow Status] -->
<!-- ![GH Actions Workflow Status] -->
<!-- ![GH Actions Workflow Status] -->
<!-- ![GH Tag] -->

## Overview
Cafe Menu is built to provide library users the basic functionality of a point of sale system. It supports three key areas of an order transaction: menu management, order management, and order calculations.

## Organization
Cafe Menu is a combination of two separate libraries: cafe_menu_core (CMC) and cafe_menu_iostream (CMIO). CMC contains all the business logic that does not handle display input or output, whereas CMIO only handles display input and output. Ex. CMC contains a function to calculate a total, whereas CMIO contains a function to display the total.

While CMIO does not have to be used and the library user can create their own input/output handling, it provides an out-of-the-box option to get the library user up and running as fast as possible.

There is a dedicated namespace for accessing all the classes called cafe_menu.

## Who Should Use Cafe Menu
Cafe Menu is for anyone who feels like they want a lean point of sale system. It could be for any user who would like to create a point of sale application with the support of their graphics library of their choosing.

## Supported Environments & Compilers
Continuous integration workflows currently build and unit test on g++ (through Ubuntu). In the future, MSVC (through Windows) and clang (through macOS) will be supported.

## Dependencies
Cafe Menu uses [CPM.cmake](https://github.com/cpm-cmake/CPM.cmake) for dependency management in Cmake. The build has been configured to download CMP from its Github repo if it is not already installed.

The unit test code uses [Catch2](https://github.com/catchorg/Catch2.git). If the 'CAFE_MENU_BUILD_TESTS' flag is provided to Cmake the Cmake configure / generate will download the Catch2.

## C++ Standard
C++ 11 is the minimum required C++ standard. However, C++ 17 is recommended as future versions will include C++ 17 features.

<!-- ## Generated Documentation -->
<!-- The generated Doxygen documentation for 'cafe_menu' is [here] (https) -->

## Build and Run Unit Tests
...Instructions to come...
