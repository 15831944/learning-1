'''
Created on Mar 22, 2021

@author:  Gabriel Dimitriu
'''
class GameStats:
    """Track statistics for alien invasion"""
    def __init__(self,ai_game):
        """initialize statistics"""
        self.settings = ai_game.settings
        self.reset_stats()
        self.game_active = False
         #high score should never be reset
        self.high_score = 0
    
    def reset_stats(self):
        """ initialize statistics"""
        self.ship_left = self.settings.ship_limit
        self.score = 0
        self.level = 1