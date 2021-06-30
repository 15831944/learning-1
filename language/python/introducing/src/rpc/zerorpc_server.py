'''
Created on Jun 29, 2021

@author:  Gabriel Dimitriu
'''
#pip3 install zerorpc
import zerorpc
from datetime import datetime

class RPC():
    def double(self,num):
        return num * 2
    
server = zerorpc.Server(RPC())
server.bind("tcp://0.0.0.0:6789")
print("Starting at", datetime.now())
server.run()