#!/bin/bash
set -e

# Set up build directories for debug and release configurations. Using Ninja as the generator, and we also set to export compile_commands.json for clangd
cmake -S . -B build/debug -G Ninja -DCMAKE_C_COMPILER=clang -DCMAKE_CXX_COMPILER=clang++ -DCMAKE_BUILD_TYPE=Debug -DCMAKE_EXPORT_COMPILE_COMMANDS=On -DCMAKE_TOOLCHAIN_FILE="$VCPKG_ROOT/scripts/buildsystems/vcpkg.cmake"
cmake -S . -B build/release -G Ninja -DCMAKE_C_COMPILER=clang -DCMAKE_CXX_COMPILER=clang++ -DCMAKE_BUILD_TYPE=Release -DCMAKE_EXPORT_COMPILE_COMMANDS=On -DCMAKE_TOOLCHAIN_FILE="$VCPKG_ROOT/scripts/buildsystems/vcpkg.cmake"

# Link compile_commands.json from the debug build to the project root so that clangd can find it.
[[ -L compile_commands.json || -f compile_commands.json ]] && rm ./compile_commands.json
ln -s build/debug/compile_commands.json ./compile_commands.json

# Compile project once so clangd can read the module files and understand the project structure. This is required for clangd to work properly.
cmake --build build/debug
