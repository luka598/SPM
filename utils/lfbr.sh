set -xe

./utils/lint.sh
./utils/format.sh
./utils/build.sh
./utils/run.sh
