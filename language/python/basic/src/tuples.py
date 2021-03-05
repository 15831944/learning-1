'''
Created on Mar 5, 2021

@author:  Gabriel Dimitriu
'''

#define a touple
dimensions = (200,50)
print(dimensions[0])
print(dimensions[1])

#touple do not accept reasignement

#looping throughh all values in a touple
for dimension in dimensions:
     print(dimension)
     
#writing over a tuple
print("Original dimensions")
for dimension in dimensions:
    print(dimension)
    
dimensions = (300,400)
print("Modified dimensions")
for dimension in dimensions:
    print(dimension)
