'''
Created on Jun 28, 2021

@author:  Gabriel Dimitriu
'''
import dbm
db = dbm.open("definitions", 'c')
db["mustard"] = "yellow"
db["ketchup"] = "red"
db['pesto'] = "green"
print(len(db))
db.close()
db = dbm.open("definitions",'r')
print(db["mustard"])