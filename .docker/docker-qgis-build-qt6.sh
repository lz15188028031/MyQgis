#!/usr/bin/env bash

set -e

mkdir /usr/src/qgis/build
cd /usr/src/qgis/build || exit 1

CLANG_WARNINGS="-Wrange-loop-construct"

cmake -GNinja \
 -DWITH_QT6=ON \
 -DWITH_QUICK=OFF \
 -DWITH_3D=OFF \
 -DWITH_ANALYSIS=OFF \
 -DWITH_DESKTOP=OFF \
 -DWITH_GUI=OFF \
 -DWITH_STAGED_PLUGINS=ON \
 -DWITH_GRASS=OFF \
 -DWITH_QGIS_PROCESS=OFF \
 -DWITH_QTWEBKIT=OFF \
 -DWITH_QT5SERIALPORT=OFF \
 -DSUPPRESS_QT_WARNINGS=ON \
 -DENABLE_MODELTEST=ON \
 -DENABLE_PGTEST=OFF \
 -DENABLE_SAGA_TESTS=OFF \
 -DENABLE_MSSQLTEST=OFF \
 -DWITH_QSPATIALITE=OFF \
 -DWITH_QWTPOLAR=OFF \
 -DWITH_APIDOC=OFF \
 -DWITH_ASTYLE=OFF \
 -DWITH_CUSTOM_WIDGETS=OFF \
 -DWITH_DESKTOP=OFF \
 -DWITH_BINDINGS=OFF \
 -DWITH_SERVER=OFF \
 -DWITH_ORACLE=OFF \
 -DDISABLE_DEPRECATED=ON \
 -DCXX_EXTRA_FLAGS="${CLANG_WARNINGS}" \
 -DCMAKE_C_COMPILER=/bin/clang \
 -DCMAKE_CXX_COMPILER=/bin/clang++ \
 -DADD_CLAZY_CHECKS=ON \
 -DWERROR=TRUE \
 ..

ninja