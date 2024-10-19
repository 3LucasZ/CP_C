import sys
import os

bad_words = ["debug.cpp", "dbg("]

input = sys.argv
# print(input)
filepath = input[0]
# print(filepath)
workspaceDir = os.path.dirname(filepath)
# print(workspaceDir)
inputFilepath = input[1] if len(input) == 2 else os.path.join(workspaceDir, "template-0.cpp")
# print(inputFilepath)
outputFilepath = os.path.join(workspaceDir, "ZZZZZ.cpp")

with open(inputFilepath) as oldfile, open(outputFilepath, 'w+') as newfile:
    for line in oldfile:
        if not any(bad_word in line for bad_word in bad_words):
            line = line.split("//")[0] # remove comments!!
            newfile.write(line)

print("ZZZZZ ready!")