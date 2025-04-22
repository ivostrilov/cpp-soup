#!/usr/bin/env bash

PROJECT_ROOT="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
TARGET_PROJECT="$1"

run_cpplint() {
  echo "🔍 Running cpplint..."

  local CPPLINT_RESULT=0
  local TARGET_DIR

  if [[ -n "${TARGET_PROJECT:-}" ]]; then
    TARGET_DIR="$PROJECT_ROOT/projects/$TARGET_PROJECT"
    echo "📁 Project scope: $TARGET_PROJECT"
  else
    TARGET_DIR="$PROJECT_ROOT/projects"
    echo "📁 Project scope: ALL"
  fi

  FILES=$(find "$TARGET_DIR" -type f \( -name "*.cpp" -o -name "*.hpp" \))

  for file in $FILES; do
    if ! cpplint --config="cpplint.cfg" "$file"; then
      CPPLINT_RESULT=1
    fi
  done

  if [[ $CPPLINT_RESULT -ne 0 ]]; then
    echo "❌ cpplint failed. Please fix the issues before proceeding with clang-tidy."
    return 1
  else
    echo "✅ cpplint passed successfully."
    return 0
  fi
}

run_clang_tidy() {
  if [[ ! -f "$PROJECT_ROOT/compile_commands.json" ]]; then
    echo "❌ compile_commands.json not found in $PROJECT_ROOT"
    exit 1
  fi

  local TARGET_DIR
  if [[ -n "${TARGET_PROJECT:-}" ]]; then
    TARGET_DIR="$PROJECT_ROOT/projects/$TARGET_PROJECT"
  else
    TARGET_DIR="$PROJECT_ROOT/projects"
  fi

  CPP_FILES=$(find "$TARGET_DIR" -type f -name '*.cpp')

  echo "🔍 Running clang-tidy on:"
  for file in $CPP_FILES; do
    echo "  • $file"
    clang-tidy "$file" \
      --quiet --export-fixes=- -p "$PROJECT_ROOT" \
      --config-file="$PROJECT_ROOT/.clang-tidy"
  done
}

main() {
  set -euo pipefail
  cd "$PROJECT_ROOT"

  run_cpplint
  run_clang_tidy
}

main "$@"
