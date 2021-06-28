'''
Created on Jun 28, 2021

@author:  Gabriel Dimitriu
'''
import pandas

data = pandas.read_csv("villains.cvs")
print(data)

dates = pandas.date_range('2021-01-01', periods=3, freq='MS')
print(dates)