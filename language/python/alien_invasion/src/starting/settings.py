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
        self.ship_limit = 3
        #bullets
        self.bullet_speed = 1.0
        self.bullet_width = 3
        self.bullet_height= 15
        self.bulet_color = (60,60,60)
        self.bullet_allowed = 3
        #alien settings
        self.alien_speed = 1.0
        self.fleet_drop_speed = 50
        # 1 represents right -1 represents left
        self.fleet_direction = 1