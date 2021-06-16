'''
Created on Jun 14, 2021

@author:  Gabriel Dimitriu
'''

class Attr:
    color = 'red'
    
a1 = Attr()
print(a1.color)
a2= Attr()
print(a2.color)
a2.color = 'blue'
print("not changed:",a1.color)
print("changed:",a2.color)
a3 = Attr()
print("not changed:",a3.color)
Attr.color = 'kaki'
a4 = Attr()
print("should be changed:",a1.color)
print("not changed:", a2.color)
print("should be changed:", a3.color)
print("changed:",a4.color)