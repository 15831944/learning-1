'''
Created on Mar 26, 2021

@author:  Gabriel Dimitriu
'''

from random import randint

class Die:
    """a class representing a single die."""
    def __init__(self,num_sides=6):
        self.num_sides =num_sides
    
    def roll(self):
        """return a random value between 1 and number of sides"""
        return randint(1,self.num_sides)

