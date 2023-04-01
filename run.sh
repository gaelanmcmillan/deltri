#!/bin/sh

#/usr/local/Cellar/llvm/15.0.7_1/bin/clang++ -std=c++2a -c -Xclang -emit-module-interface -fexperimental-library -fmodules-ts src/point_lib.cpp -o point_lib.pcm
#/usr/local/Cellar/llvm/15.0.7_1/bin/clang++ -std=c++2a -fmodules-ts -c -fexperimental-library -fprebuilt-module-path=. src/main.cpp -o main.o
#/usr/local/Cellar/llvm/15.0.7_1/bin/clang++ -std=c++2a -fmodules-ts -o bin/main main.o *.pcm

/usr/local/Cellar/llvm/15.0.7_1/bin/clang++ -std=c++20 -c -Xclang -emit-module-interface -fexperimental-library src/point_lib.cpp -o out/point_lib.pcm
/usr/local/Cellar/llvm/15.0.7_1/bin/clang++ -std=c++2a -c -fexperimental-library -fmodules-ts -fprebuilt-module-path=out src/main.cpp -o out/main.o
/usr/local/Cellar/llvm/15.0.7_1/bin/clang++ -std=c++2a -fmodules-ts -o bin/main out/main.o out/*.pcm

./bin/main
