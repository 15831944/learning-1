'''
Created on Mar 12, 2021

@author:  Gabriel Dimitriu
'''
class Car:
    """ simple car model"""
    def __init__(self, make, model, year):
        self.make = make
        self.model = model
        self.year = year
        self.odometer = 0
        self.gasoline = 0
    
    def get_descriptive_name(self):
        """ return formated description of car """
        long_name = f"{self.year} {self.make} {self.model}"
        return long_name.title()
    def read_odometer(self):
        print(f"This car has {self.odometer} miles on it.")
    def update_odometer(self,miles):
        self.odometer += miles
    def fill_gas_tank(self):
        self.gasoline = 45