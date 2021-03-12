'''
Created on Mar 12, 2021

@author:  Gabriel Dimitriu
'''
class Battery:
    """ simple model of a battery """
    def __init__(self, battery_size = 75):
        self.battery_size = battery_size
        
    def describe_battery(self):
        print(f"This car has a {self.battery_size}-kWh battery.")
        
    def get_range(self):
        if self.battery_size == 75:
            range = 260
        elif  self.battery_size == 100:
            range = 315
        print(f"This car can ga about {range} miles on a full charge.")
        