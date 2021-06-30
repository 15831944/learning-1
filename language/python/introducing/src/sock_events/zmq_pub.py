'''
Created on Jun 29, 2021

@author:  Gabriel Dimitriu
'''
import zmq
import random
import time

cats = ["siamese", "persian", "maine coon", "norwegian forest"]
hats = ["stovepipe", "bowler","tam-o-shanter", "fedora"]

host = "*"
port = 6789
context = zmq.Context()
pub = context.socket(zmq.PUB)
pub.bind("tcp://%s:%s" % (host,port))

time.sleep(1)

for msg in range(10):
    cat = random.choice(cats)
    cat_bytes =  cat.encode("utf-8")
    hat = random.choice(hats)
    hat_bytes = hat.encode("utf-8")
    print("Publish: %s wears a %s" % (cat,hat))
    pub.send_multipart([cat_bytes, hat_bytes])
    