cmake_minimum_required(VERSION 3.18 FATAL_ERROR)
project(example-app)

# Sett CMakePrefixPath til din LibTorch-mappe
set(CMAKE_PREFIX_PATH "C:\Users\seyon\Documents\tdt4102\Project tdt4102\libtorch-shared-with-deps-latest.zip")  # Erstatt med riktig sti til din libtorch-mappe

# Finn LibTorch-biblioteket
find_package(Torch REQUIRED)

# Sett C++-flaggene for å bruke LibTorch
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${TORCH_CXX_FLAGS}")

# Legg til din eksisterende main.cpp-fil i prosjektet
add_executable(example-app main.cpp)

# Link bibliotekene fra LibTorch
target_link_libraries(example-app "${TORCH_LIBRARIES}")

# Sett C++-standard til 17
set_property(TARGET example-app PROPERTY CXX_STANDARD 17)

# Kopier DLL-filer hvis du bruker MSVC
if (MSVC)
  file(GLOB TORCH_DLLS "${TORCH_INSTALL_PREFIX}/lib/*.dll")
  add_custom_command(TARGET example-app
                     POST_BUILD
                     COMMAND ${CMAKE_COMMAND} -E copy_if_different
                     ${TORCH_DLLS}
                     $<TARGET_FILE_DIR:example-app>)
endif (MSVC)
