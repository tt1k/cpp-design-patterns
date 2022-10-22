#!/bin/bash

clean() {
  rm -rf build
  rm -rf CMakeFiles
  rm -f cmake_install.cmake
  rm -f CMakeCache.txt
}

build() {
  clean
  rm -rf build
  mkdir build
  cd build
  cmake ..
  cmake --build .
}

xcode() {
  find . -name '.DS_Store' -type f -delete
  rm -rf build
  mkdir build
  cd build
  cmake -G Xcode ..
  open cdps.xcodeproj
}

format() {
  find . -iname "*.h" -or -iname "*.hpp" -or -iname "*.cpp" | xargs clang-format -i
}

if [ "$1" == "--build" ] || [ "$1" == "-b" ]; then
  build
elif [ "$1" == "--xcode" ] || [ "$1" == "-x" ]; then
  xcode
elif [ "$1" == "--format" ] || [ "$1" == "-f" ]; then
  format
elif [ "$1" == "--clean" ] || [ "$1" == "-c" ]; then
  format
else
  echo "Unknown command $1"
  echo "Commands:"
  echo "-b, --build   Build project"
  echo "-x, --xcode   Generate Xcode project"
  echo "-f, --format  Format project with clang-format"
  echo "-c, --clean  Clean project"
fi
