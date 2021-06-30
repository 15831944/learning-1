'''
Created on Jun 29, 2021

@author:  Gabriel Dimitriu
'''
#pip3 install msgpack-rpc-python

import xmlrpc.client

proxy = xmlrpc.client.ServerProxy("http://localhost:6789/")
num = 7
result = proxy.double(num)
print("Double %s is %s" %(num,result))