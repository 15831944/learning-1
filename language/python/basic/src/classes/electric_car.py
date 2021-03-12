'''
Created on Mar 12, 2021

@author:  Gabriel Dimitriu
'''
from classes.car import Car
from classes.bettery import Battery
class ElectricCar(Car):
    def __init__(self,make, model, year):
        super().__init__(make,model,year)
        self.batery_size = 75
        self.battery = Battery()
    def describe_batery(self):
        print(f"This car has a {self.batery_size}-kWh battery")
    def fill_gas_tank(self):
        print("This car doesn't have a gas tank")
