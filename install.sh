#!/usr/bin/env bash
git clone https://github.com/Microsoft/vcpkg.git
./vcpkg/bootstrap-vcpkg.sh
./vcpkg/vcpkg install nlohmann-json
./vcpkg/vcpkg install cpr
./vcpkg/vcpkg integrate install
