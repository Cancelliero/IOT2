cmake_minimum_required(VERSION 3.12)

include(pico_sdk_import.cmake)

project(per_timer C CXX ASM)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

#Caso seja a Raspberry Pi Pico W
set(PICO_BOARD pico_w)
#Caso seja a Raspberry Pi Pico 
#set(PICO_BOARD pico)

pico_sdk_init()

add_executable(per_timer main.c)

#Caso seja a Raspberry Pi Pico 
#target_link_libraries(int pico_stdlib)

#Caso seja a Raspberry Pi Pico W
target_link_libraries(per_timer pico_stdlib hardware_adc hardware_timer)


pico_enable_stdio_usb(per_timer 1)
pico_enable_stdio_uart(per_timer 0)

pico_add_extra_outputs(per_timer)