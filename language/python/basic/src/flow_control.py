'''
Created on Mar 7, 2021

@author:  Gabriel Dimitriu
'''
cars = ["audi", "bmw", "subaru", "toyota"]
#if with else
for car in cars:
    if car == "bmw":
        print(car.upper())
    else:
        print(car.title())
        
#negative check
for car in cars:
    if car != "bmw":
        print(f"Is not a bmw is a {car}")

# multiple conditions
age_0 = 18
age_1 = 22
if age_0 >= 21 and age_1 >=21:
    print("There are legal age")
else:
    print("You don't have the required ages !")
if age_0 <= 22 and age_0 >= 18:
    print("You could drive a car!")
    
#check if a value is in the list
car = "subaru"
if car in cars:
    print(f"Car {car} is in the list {cars}")
    
#check if a value is not in the list
car = "mazda"
if car not in cars:
    print(f"Car {car} is not in the list {cars}")
    
#chain of ifs with condensed else if
age = 23
if age <18:
    print("You are not allowed to buy !")
elif age < 22:
    print("Price is 25$")
elif age < 40:
    print("Price is 15$")
else:
    print("Price is 10$")
    
#checking if a list is empty
requested_toppings = []
if requested_toppings:
    for request_topping in requested_toppings:
        print(f"Adding {request_topping}")
    print("\n Finished making your pizza!")
else:
    print("Are you sure you want a plain pizza!")
    

#checking in multiple lists
available_toppings=["mushrooms", "olives", "green_pepper", "pepperoni", "pineaple", "extra_cheese"]
requested_toppings = ["mushrooms", "french fries", "extra_cheese"]

for requested_topping in requested_toppings:
    if requested_topping in available_toppings:
        print(f"Adding {requested_topping}")
    else:
        print(f"Sorry, we don't have {requested_topping}")
print("\nFinished making your pizza!")

