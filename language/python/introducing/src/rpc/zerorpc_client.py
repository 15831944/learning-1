'''
Created on Jun 29, 2021

@author:  Gabriel Dimitriu
'''
#pip3 install zerorpc
import zerorpc

client = zerorpc.Client()
client.connect("tcp://localhost:6789")
num = 7
result = client.double(num)
print("Double %s is %s" % (num,result))