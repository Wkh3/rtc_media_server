# !/bin/bash
cmake -B build
cd build
make -j8

cd ..
cp build/compile_commands.json .

