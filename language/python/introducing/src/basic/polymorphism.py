'''
Created on Jun 14, 2021

@author:  Gabriel Dimitriu
'''

class Base:
    def __init__(self, value):
        self.value = value
    def getValue(self):
        return self.value
    def show(self):
        print("Value is ", self.value)
        
class Derived(Base):
    def show(self):
        print("Derived value is ", self.value)
        
class Unrelated():
    def show(self):
        print("Unrelated")
        
def objectPoly(obj):
    obj.show()
    
b = Base(10)
d = Derived(5)
b.show()
d.show()
unrelated  = Unrelated()
objectPoly(unrelated)
objectPoly(d)
objectPoly(b)