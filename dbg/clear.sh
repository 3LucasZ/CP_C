#!/bin/zsh
source ~/.zshrc

#Setup
echo Starting Clear
workspaceRoot="/Users/lucaszheng/Documents/GitHub/CP_C"
echo workspaceRoot: $workspaceRoot

#Clearing
echo Clearing io folder: dif
rm $workspaceRoot/io/dif/*
echo Clearing io folder: in
rm $workspaceRoot/io/in/*
echo Clearing io folder: me
rm $workspaceRoot/io/me/*
echo Clearing io folder: sol
rm $workspaceRoot/io/sol/*