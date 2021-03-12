'''
Created on Mar 12, 2021

@author:  Gabriel Dimitriu
'''
def make_pizza(size,*toppings):
    """ sumarize the pizza that we want to make """
    print(f"\nMaking a {size}-inch pizza with the following toppings:")
    for topping in toppings:
        print(f"- {topping}")