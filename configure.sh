#!/usr/bin/env bash

set -euo pipefail

show_help() {
  cat << EOF
Usage: $0 [OPTIONS]

Configure the CMake build system.

Options:
  --compiler <path>        Path to C++ compiler (default: clang++)
  --build-type <type>      Build type: debug or release (default: debug)
  --enable-tests <true|false> Enable building tests (default: true)
  --cmake-flags "<flags>"  Additional flags to pass to CMake
  --help                   Show this help message and exit

Examples:
  $0 --compiler /usr/bin/g++ --build-type release --enable-tests true
  $0 --cmake-flags "-DENABLE_LOGGING=ON"
EOF
}

main() {
  local CXX_COMPILER="clang++"
  local BUILD_TYPE="debug"
  local ENABLE_TESTS="true"
  local CMAKE_FLAGS=""

  while [[ $# -gt 0 ]]; do
    case $1 in
      --compiler)
        CXX_COMPILER="$2"
        shift 2
        ;;
      --build-type)
        BUILD_TYPE="$2"
        shift 2
        ;;
      --enable-tests)
        ENABLE_TESTS="$2"
        shift 2
        ;;
      --cmake-flags)
        CMAKE_FLAGS="$2"
        shift 2
        ;;
      --help)
        show_help
        exit 0
        ;;
      *)
        echo "❌ Unknown option: $1"
        show_help
        exit 1
        ;;
    esac
  done

  local BUILD_TYPE_UPPER
  BUILD_TYPE_UPPER=$(echo "$BUILD_TYPE" | tr '[:lower:]' '[:upper:]')

  mkdir -p build
  cd build

  cmake .. \
    -DCMAKE_EXPORT_COMPILE_COMMANDS=ON \
    -DCMAKE_CXX_COMPILER="$CXX_COMPILER" \
    -DCMAKE_BUILD_TYPE="$BUILD_TYPE_UPPER" \
    -DBUILD_TESTS="$( [[ "$ENABLE_TESTS" == "false" ]] && echo "OFF" || echo "ON" )" \
    "$CMAKE_FLAGS"

  cp compile_commands.json ..

  echo "✔️  Configuration complete."
  echo "🛠️  Compiler: $CXX_COMPILER"
  echo "🧱  Build type: $BUILD_TYPE_UPPER"
  echo "🧪  Tests enabled: $ENABLE_TESTS"
  echo "📂  Build directory: $(pwd)"
}

main "$@"
