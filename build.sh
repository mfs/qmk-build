#!/usr/bin/env bash

set -eu

QMK_VERSION=0.7.15

# clone repo/tag
git clone --depth 50 --recursive --branch $QMK_VERSION https://github.com/qmk/qmk_firmware.git

# (ci) install dependencies

# copy configs
cp -nrv keyboards qmk_firmware/

# build
cd qmk_firmware

#CFLAGS="-Wno-error=deprecated" make planck/rev4:mfs firmware too big
CFLAGS="-Wno-error=deprecated" make planck/rev6:mfs
make bigswitch:mfs
make snagpad:mfs