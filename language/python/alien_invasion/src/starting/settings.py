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
        self.ship_limit = 3
        #bullets
        self.bullet_width = 3
        self.bullet_height= 15
        self.bulet_color = (60,60,60)
        self.bullet_allowed = 3
        
        #Speedup scale
        self.score_scale = 1.5
        self.speedup_scale = 1.1
        
        self.initialize_dynamic_settings()
    
    def initialize_dynamic_settings(self):
        """ initialize settings that change"""
        self.ship_speed = 1.0
        self.bullet_speed = 1.0
        #alien settings        
        self.fleet_drop_speed = 5
        self.alien_speed = 1.0
        # 1 represents right -1 represents left
        self.fleet_direction = 1
        #score
        self.alien_points = 50
        
    def increase_speed(self):
        """increase speed settings"""
        self.alien_speed *= self.speedup_scale
        self.ship_speed *= self.speedup_scale
        self.fleet_drop_speed *= self.speedup_scale
        self.bullet_speed *= self.speedup_scale
        self.alien_points = int(self.alien_points*self.score_scale)
        