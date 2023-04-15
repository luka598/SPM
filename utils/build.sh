set -x
set -e

if [ ! -d build ]; then
	mkdir build
fi
cd build
# CXX=clang++ CC=clang
cmake -S .. -B . -DCMAKE_BUILD_TYPE=Debug
make
