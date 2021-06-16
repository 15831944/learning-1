'''
Created on Jun 14, 2021

@author:  Gabriel Dimitriu
'''
class Methods:
    count = 0 # static
    def __init__(self):
        Methods.count +=1
    def exclaim(self):
        print("I'm an Methods ! with count ",self.count)
    @classmethod
    def number(cls):
        print("Methods has", cls.count,"little objects")
    @staticmethod
    def something():
        print("somethig that is independent of Methods")   
        
m1 = Methods()
m1.exclaim()
m2 = Methods()
m2.exclaim()
m3 = Methods()
m3.exclaim()
Methods.number()
Methods.something()