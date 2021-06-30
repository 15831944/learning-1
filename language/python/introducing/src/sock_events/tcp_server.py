'''
Created on Jun 29, 2021

@author:  Gabriel Dimitriu
'''
from datetime import datetime
import socket

address = ("localhost", 6789)
max_size = 1000

print("Start the server at", datetime.now())
print("Waiting for a client to call.")

server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
server.bind(address)
server.listen(5)

client, addr = server.accept()
data = client.recv(max_size)

print("At", datetime.now(), client, "said", data)
client.sendall(b'Are you talking to me ?')
client.close()
server.close()