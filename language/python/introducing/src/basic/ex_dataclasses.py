'''
Created on Jun 16, 2021

@author:  Gabriel Dimitriu
'''
from dataclasses import dataclass
@dataclass
class AnimalClass:
    name: str
    habitat: str
    teeth: int = 0
    
snowman = AnimalClass('yeti', 'Himalayas', 46)
duck = AnimalClass(habitat = 'lake', name = 'duck')
print(snowman)
print(duck) 