#! /bin/bash

bison parser.yy -o parser.cc
flex scanner.l
g++ -std=c++17 calc++.cc driver.cc parser.cc lex.yy.cc -o calcpp
#g++ -std=c++17 lex.yy.cc calc++.cc driver.cc flex_main.cpp -o flex_test
