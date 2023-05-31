#! /bin/bash

bison simple.yy -o simple.cc
g++ -std=c++14 simple.cc -o simple
