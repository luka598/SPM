set -x
set -e

for file in $(find src/ -name "*.cpp" -or -name "*.hpp"); do
    clang-format -i "$file"
done
