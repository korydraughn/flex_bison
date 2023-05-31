#! /bin/bash

bison parser.yy -o parser.cc
flex scanner.l
g++ -std=c++17 calc++.cc driver.cc parser.cc lex.yy.c -o calcpp
