#!/bin/zsh
source ~/.zshrc

echo Starting Script...
CP="/Users/lucaszheng/Documents/GitHub/CP_C"
A=$CP/Solutions
echo CP: $CP
echo A: $A
echo
echo -n "LINES OF CODE: "
find $A -name '*.cpp' | xargs wc -l | grep total | awk '{$1=$1};1'
echo -n "PROBLEMS SOLVED: "
find $A -name '*.cpp' | wc -l | awk '{$1=$1};1'