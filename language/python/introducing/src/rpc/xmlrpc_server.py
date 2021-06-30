'''
Created on Jun 29, 2021

@author:  Gabriel Dimitriu
'''
from xmlrpc.server import SimpleXMLRPCServer

def double(num):
    return num *2

server = SimpleXMLRPCServer(("localhost", 6789))
server.register_function(double, "double")
server.serve_forever()