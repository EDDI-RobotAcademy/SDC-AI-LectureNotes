cmake_minimum_required(VERSION 3.26)
project(newUi)

set(CMAKE_CXX_STANDARD 17)

add_executable(newUi main.cpp
        ui/console/controller/ConsoleUiController.h
        ui/console/controller/ConsoleUiController.cpp
        ui/console/user_keyboard/user_keyboard_input.cpp
        ui/console/user_keyboard/user_keyboard_input.h
        ui/console/service/ConsoleUiServiceImpl.h
        ui/console/service/ConsoleUiServiceImpl.cpp
        ui/console/service/ConsoleUiService.h
#        ui/console/controller/request/ConsoleUiAccountLoginRequest.cpp
#        ui/console/controller/request/ConsoleUiAccountLoginRequest.h
)
