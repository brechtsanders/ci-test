#!/bin/sh
# path where this script is located
BUILDDIR=$(realpath $(dirname $0))
# path to install to
BUILDOUT=$BUILDDIR/build_cmake/out
# configure, build and test
mkdir -p $BUILDOUT &&
cmake -Wno-dev -GNinja -DCMAKE_INSTALL_PREFIX:PATH=$BUILDOUT -DCMAKE_BUILD_TYPE:STRING=Release -DBUILD_SHARED:BOOL=ON -DBUILD_STATIC:BOOL=ON -DBUILD_UTILS:BOOL=ON -S$BUILDDIR/.. -B$BUILDDIR/build_cmake &&
ninja -C$BUILDDIR/build_cmake install/strip &&
$BUILDOUT/bin/myapplication &&
echo Done
# to run:
#   build/build_cmake.sh
# to clean up:
#   rm -rf build/build_cmake doc/man doc/html