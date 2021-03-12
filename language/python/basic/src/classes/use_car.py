'''
Created on Mar 12, 2021

@author:  Gabriel Dimitriu
'''
from classes.car import Car

   
my_new_car = Car("audi","a4",2019)
print(my_new_car.get_descriptive_name())
my_new_car.read_odometer()
my_new_car.odometer = 14
my_new_car.read_odometer()
print("And now after a testdrive")
my_new_car.update_odometer(10)
my_new_car.read_odometer()