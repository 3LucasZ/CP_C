#!/bin/zsh
source ~/.zshrc

#Only change these lines
tcs=1000
verbose=false
clear=true

#Setup
echo Starting Debug
workspaceRoot="/Users/lucaszheng/Documents/GitHub/CP_C"
echo workspaceRoot: $workspaceRoot

build() {
  g++ -std=c++17 -O2 -Wall -Wextra -Wshadow -Wfloat-equal -D_GLIBCXX_ASSERTIONS -ggdb3 -fsanitize=address,undefined -g -fno-sanitize-recover -ferror-limit=2 -Wl,-stack_size,0x10000000 $workspaceRoot/dbg/$1.cpp -o $workspaceRoot/build/$1
}
mild_build() {
  g++ -std=c++17 -O2 -D_GLIBCXX_ASSERTIONS -ggdb3 -fsanitize=address,undefined -g -fno-sanitize-recover -ferror-limit=2 -Wl,-stack_size,0x10000000 $workspaceRoot/dbg/$1.cpp -o $workspaceRoot/build/$1
}
unsafe_build() {
  g++ -std=c++17 -O2 -Wl,-stack_size,0x10000000 $workspaceRoot/dbg/$1.cpp -o $workspaceRoot/build/$1
}
build gen
build me
mild_build sol

bad=0
for i in {1..$tcs}
do
  $workspaceRoot/build/gen > $workspaceRoot/io/in/in$i.txt

  ms0=$(getms)
  $workspaceRoot/build/me < $workspaceRoot/io/in/in$i.txt > $workspaceRoot/io/me/me$i.txt
  ms1=$(getms)

  $workspaceRoot/build/sol < $workspaceRoot/io/in/in$i.txt > $workspaceRoot/io/sol/sol$i.txt

  diff $workspaceRoot/io/me/me$i.txt $workspaceRoot/io/sol/sol$i.txt > $workspaceRoot/io/dif/dif$i.txt
  if [ -s $workspaceRoot/io/dif/dif$i.txt ] ; then
    AC=false
    bad=$((bad + 1))
  else 
    AC=true
    if [ "$clear" = true ] ; then
      rm $workspaceRoot/io/in/in$i.txt
      rm $workspaceRoot/io/me/me$i.txt
      rm $workspaceRoot/io/sol/sol$i.txt
      rm $workspaceRoot/io/dif/dif$i.txt
    fi
  fi

  if [ "$verbose" = true ] ; then
    echo Test case: $i
    if [ "$AC" = true ] ; then
      echo Status: AC
    else 
      echo Status: WA
    fi
    echo Runtime: $((ms1-ms0)) ms
  fi

  if [ "$bad" = 10 ] ; then
    break
  fi
done

echo Result: $((tcs-bad))/$tcs