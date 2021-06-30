'''
Created on Jun 29, 2021

@author:  Gabriel Dimitriu
'''
#pip3 install msgpack-rpc-python

from msgpackrpc import Client,Address

client = Client(Address("localhost",6789))
num = 8
result = client.call("double", num)
print("Double %s is %s" % (num,result))