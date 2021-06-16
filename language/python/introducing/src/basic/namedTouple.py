'''
Created on Jun 16, 2021

@author:  Gabriel Dimitriu
'''
from collections import namedtuple
Duck = namedtuple('Duck', 'bill tail')
duck = Duck('wide orange', 'long')
print(duck)
print(duck.bill)
print(duck.tail)

parts = {'bill':'wide orange', 'tail': 'long'}
duck2 = Duck(**parts)
print(duck2)
print(duck2.bill)
print(duck2.tail)

duck3 = duck2._replace(tail='magnificent', bill='crushing') #imutable
print(duck3)
print(duck2)