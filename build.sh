#!/usr/bin/env bash

set -eu

QMK_VERSION=0.7.30

# clone repo/tag
git clone --depth 50 --recursive --branch $QMK_VERSION https://github.com/qmk/qmk_firmware.git

# copy configs
cp -nrv keyboards qmk_firmware/

# build
cd qmk_firmware

CFLAGS="-Wno-error=deprecated" make planck/rev5:mfs
CFLAGS="-Wno-error=deprecated" make planck/rev6:mfs
make bigswitch:mfs
make snagpad:mfs

# artifacts
mkdir ../artifacts
cp -v *.bin *.hex ../artifacts/
