'''
Created on Jun 23, 2021

@author:  Gabriel Dimitriu
'''
import threading

def do_this(what):
    whoami(what)

def whoami(what):
    print("Thread %s says: %s\n" % (threading.current_thread(), what))
    
if __name__ == "__main__":
    whoami("I'm the main thread")
    for n in range(4):
        p = threading.Thread(target= do_this, args=("I'm function %s" %n,))
        p.start()