'''
Created on Jun 29, 2021

@author:  Gabriel Dimitriu
'''
import zmq

host = "127.0.0.1"
port = 6789

context = zmq.Context()
client = context.socket(zmq.REQ)
client.connect("tcp://%s:%s" % (host, port))

for num in range(1,6):
    request_str = "message #%s" % num
    request_bytes = request_str.encode(encoding='utf_8', errors='strict')
    client.send(request_bytes)
    reply_bytes = client.recv()
    reply_str = reply_bytes.decode("utf-8")
    print("Sent %s, received %s" %(request_str, reply_str))