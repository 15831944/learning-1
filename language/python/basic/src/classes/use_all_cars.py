'''
Created on Mar 12, 2021

@author:  Gabriel Dimitriu
'''
from classes.electric_car import ElectricCar
from classes.car import Car

my_tesla = ElectricCar('tesla','model s',2019)
print(my_tesla.get_descriptive_name())
my_tesla.describe_batery()
my_tesla.battery.describe_battery()
my_tesla.battery.get_range()

my_beetle = Car('folkswagen','beetle',2019)
print(my_beetle.get_descriptive_name())