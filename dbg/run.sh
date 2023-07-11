#!/bin/zsh
source ~/.zshrc

#future features: 
#implicit/explicit multi
#dif tcs separately
#for all tcs where me.txt != sol.txt, put to q. q pick the 10 smallest test cases if q>10.

#Only change these lines
gen=true
cmp=true

#Setup
echo Starting Debug
workspaceRoot="/Users/lucaszheng/Documents/GitHub/CP_C"
echo workspaceRoot: $workspaceRoot

build() {
    g++ -std=c++17 -O2 -Wall -Wextra -Wshadow -Wfloat-equal -D_GLIBCXX_ASSERTIONS -ggdb3 -fsanitize=address,undefined -g -fno-sanitize-recover -ferror-limit=2 -Wl,-stack_size,0x10000000 $workspaceRoot/dbg/$1.cpp -o $workspaceRoot/build/$1
}
unsafe_build() {
    g++ -std=c++17 -O2 $workspaceRoot/dbg/$1.cpp -o $workspaceRoot/build/$1
}

#gen
if [ "$gen" = true ] ; then
  echo Running the generator
  build gen
  $workspaceRoot/build/gen > $workspaceRoot/io/in.txt
fi

#me
echo Running me.cpp against in.txt
ms0=$(getms)
build me
($workspaceRoot/build/me < $workspaceRoot/io/in.txt) > $workspaceRoot/io/me.txt
ms1=$(getms)
echo Your code took $((ms1-ms0)) ms

#Correct code
if [ "$cmp" = true ] ; then
  echo Running sol.cpp against in.txt
  unsafe_build sol
  ($workspaceRoot/build/sol < $workspaceRoot/io/in.txt) > $workspaceRoot/io/sol.txt

  echo Running diff between me.txt and sol.txt
  diff $workspaceRoot/io/me.txt $workspaceRoot/io/sol.txt > $workspaceRoot/io/dif.txt
fi