'''
Created on Mar 12, 2021

@author:  Gabriel Dimitriu
'''
#arbitrary number of arguments
def make_pizza(*toppings):
    print(toppings)
    
make_pizza('peperoni')
make_pizza('mushrooms','green pepers','extra cheese')