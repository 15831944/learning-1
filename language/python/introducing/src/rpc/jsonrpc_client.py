'''
Created on Jun 29, 2021

@author:  Gabriel Dimitriu
'''
#pip3 install jsonrpcclient

from jsonrpcclient import request

num = 7
response = request("http://localhost:6789", "double", num = num)
print("Double %s is %s" % (num,response.data.result))