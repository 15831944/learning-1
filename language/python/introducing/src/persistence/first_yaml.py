'''
Created on Jun 28, 2021

@author:  Gabriel Dimitriu
'''
import yaml

with open("mcintyre.yaml","rt") as fin:
    text = fin.read()
data = yaml.load(text)
print(data['details'])
print(len(data['poems']))
print(data['poems'][1]['title'])