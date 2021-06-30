'''
Created on Jun 29, 2021

@author:  Gabriel Dimitriu
'''
# pip3 install jsonrpcserver
from jsonrpcserver import method, serve

@method
def double(num):
    return num * 2

if __name__ == "__main__":
    serve(port=6789)