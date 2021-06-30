'''
Created on Jun 29, 2021

@author:  Gabriel Dimitriu
'''

import zmq

host = "127.0.0.1"
port = 6789

context = zmq.Context()
sub = context.socket(zmq.SUB)
sub.connect("tcp://%s:%s" %(host,port))
topics = ["maine coon", "persian"]
# to subscribe to all topics use b''
for topic in topics:
    sub.setsockopt(zmq.SUBSCRIBE, topic.encode(encoding='utf_8', errors='strict'))
while True:
    cat_bytes, hat_bytes = sub.recv_multipart()
    cat = cat_bytes.decode("utf-8")
    hat = hat_bytes.decode("utf-8")
    print("Subscribe: %s wears a %s" % (cat,hat))