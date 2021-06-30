'''
Created on Jun 29, 2021

@author:  Gabriel Dimitriu
'''
#pip3 install msgpack-rpc-python

from msgpackrpc import Server, Address
from datetime import datetime

class Services():
    def double(self, num):
        return num * 2

server = Server(Services())
server.listen(Address("localhost",6789))
print("Starting at", datetime.now())
server.start()