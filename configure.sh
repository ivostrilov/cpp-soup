#!/usr/bin/env bash

main() {
  set -e

  CXX_COMPILER=${1:-clang++}
  BUILD_TYPE="${2:-debug}"

  # CMake ожидает верхний регистр
  BUILD_TYPE_UPPER=$(echo "$BUILD_TYPE" | tr '[:lower:]' '[:upper:]')

  mkdir -p build
  cd build

  cmake .. \
    -DCMAKE_EXPORT_COMPILE_COMMANDS=ON \
    -DCMAKE_CXX_COMPILER="$CXX_COMPILER" \
    -DCMAKE_BUILD_TYPE="$BUILD_TYPE_UPPER"

    cp compile_commands.json ..

    echo "✔️  Configuration complete."
    echo "ℹ️  Build type: $BUILD_TYPE_UPPER"
    echo "📂  Build directory: $(pwd)"
}

main "$@"
