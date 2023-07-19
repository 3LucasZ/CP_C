#!/bin/zsh
#WARNING NOT DONE YET!
source ~/.zshrc

#Setup
echo Starting verify
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
build me

#Loop through all .in files
tcs=0
tcsAC=0
for file in $B/*.in; do
  ((tcs++))
  name=$(basename "$file" .in)
  echo "Testcase: $name"
  inFile="$B/$name.in"
  outFile="$B/$name.out"
  resFile="$B/$name.res"
  difFile="$B/$name.dif"
  #Your code
  ms0=$(getms)
  cat $inFile | java $A/$mySol > $resFile
  ms1=$(getms)
  echo $((ms1-ms0)) ms
  #Cmp
  diff $resFile $outFile > $difFile
  if cmp --silent -- "$resFile" "$outFile"; then
    echo "AC"
    ((tcsAC++))
  else
    echo "WA"
  fi
done

#End
echo "Solved: $tcsAC / $tcs"


