'''
Created on Jun 30, 2021

@author:  Gabriel Dimitriu
'''
import urllib.request as req

url = "http://www.example.com/"
conn = req.urlopen(url)
print("Status",conn.status)
data = conn.read()
print(data[:50])
for key, value in conn.getheaders():
    print(key,value)

print ("Now with requests library")
import requests
resp = requests.get(url)
print(resp)
print(resp.status_code)
print(resp.text[:50])