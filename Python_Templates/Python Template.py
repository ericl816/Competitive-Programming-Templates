# Python input and output to .txt files example

import sys
raw_input = sys.stdin.readline

class InputReader:
    def __init__(self, inputDir):
        self.inputDir = inputDir

    def ReadandWriteFile(self, fileName, fileName1):
        path = self.inputDir + fileName
        path1 = self.inputDir + fileName1
        f = open(path, 'r')
        g = open(path1, 'w')
        print(f.read())

temp = InputReader('')
temp.ReadandWriteFile('in.txt', 'out.txt')