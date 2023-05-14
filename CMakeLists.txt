cmake_minimum_required(VERSION 3.10)    # Set minimum version of CMake required
project(C_WRDICE C)    # Set project name and language

set(CMAKE_C_STANDARD 11)    # Set C standard
set(LIB_NAME libwrdice)

# Add source files to the project
set(SRC 
    src/wrdice.c
    src/battle.c
    src/stats.c
    src/dice_op.c
)


# Add source files to the project
add_executable(${PROJECT_NAME} src/main.c)
include_directories(${PROJECT_NAME} include)

add_library(${LIB_NAME} SHARED ${SRC})

# Set any necessary compiler flags
target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra -g -O2 -Wno-unused-parameter)
target_compile_options(${LIB_NAME}     PUBLIC  -Wall -Wextra -g -O2 -Wno-unused-parameter)
target_link_options(${LIB_NAME} PUBLIC -fsanitize=address)
# Set library version and SO version
set_target_properties(${LIB_NAME} PROPERTIES VERSION 1.0 SOVERSION 1 LINKER_LANGUAGE C)

# Link the executable with the shared library
target_link_libraries(${PROJECT_NAME} PRIVATE ${LIB_NAME})