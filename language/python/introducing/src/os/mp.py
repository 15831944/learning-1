'''
Created on Jun 22, 2021

@author:  Gabriel Dimitriu
'''
import multiprocessing
import os

def whoami(what):
    print("Process %s says: %s\n" % (os.getpid(), what))

if __name__ == "__main__":
    whoami("I'm the main program")
    for n in range(4):
        p = multiprocessing.Process(target=whoami,          args=("I'm function %s" % n,))
        p.start()