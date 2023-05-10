set -x
set -e

for file in $(find src/ -name "*.cpp" -or -name "*.hpp" -and -not -path "src/external/*"); do
    clang-format -i "$file"
done
