'''
Created on Mar 8, 2021

@author:  Gabriel Dimitriu
'''
#functions with multiple arguments
def describe_pet(animal_type, pet_name):
    print(f"\nI have a {animal_type}.")
    print(f"My {animal_type}'s name is {pet_name.title()}.")
    
describe_pet('hamster', 'harry')
describe_pet('dog', 'willie')
#with keyword arguments
describe_pet(pet_name='harry', animal_type='hamster')

#functions with defaults
def describe_pet_def(pet_name, animal_type='dog'):
    print(f"\nI have a {animal_type}.")
    print(f"My {animal_type}'s name is {pet_name.title()}.")

describe_pet_def('willy')
describe_pet_def(pet_name='harry', animal_type='hamster')
describe_pet_def('harry','hamster')