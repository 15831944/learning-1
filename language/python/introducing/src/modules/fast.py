'''
Created on Jun 16, 2021

@author:  Gabriel Dimitriu
'''
from random import choice
places = ['McDonalds', 'Zao', "KFC", 'Burger King']
def pick():
    """Return random food places"""
    return choice(places)