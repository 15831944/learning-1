'''
Created on Mar 12, 2021

@author:  Gabriel Dimitriu
'''
class Dog:
    """ simple dog model """
    def __init__(self, name, age):
        self.name = name
        self.age = age
        
    def sit(self):
        """ simulate a dog sitting in response to a command """
        print(f"{self.name} is now sitting")
    def roll_ove(self):
        """ simulate dog rolling over in response to a command """
        print(f"{self.name} rolled over")
    
my_dog = Dog("willie",6)
print(f"My dog's name is {my_dog.name}.")
print(f"My dog is {my_dog.age} years old.")
my_dog.sit()
my_dog.roll_ove()

your_dog = Dog("Lucy",10)
print(f"Your dog's name is {your_dog.name}.")
print(f"Your dog is {your_dog.age} years old.")
your_dog.sit()
your_dog.roll_ove()