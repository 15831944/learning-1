'''
Created on Mar 19, 2021

@author:  Gabriel Dimitriu
'''
class Settings:
    """Class for settings"""
    def __init__(self):
        """ initialize the game settings"""
        #screen settings
        self.screen_width = 1200
        self.screen_height = 800
        self.bg_color = (230,230,230)
        #ship settings
        self.ship_speed = 1.0