set -x
set -e

valgrind -s --track-origins=yes ./build/SPM
