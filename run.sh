set -x
set -e

if [ ! -d build ]; then
	mkdir build
fi
cd build
cmake -S .. -B . -DCMAKE_BUILD_TYPE=Debug
make
echo "- - - - -"
# gdb -tui ./SPM
./SPM
