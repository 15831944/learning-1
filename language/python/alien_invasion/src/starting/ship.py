'''
Created on Mar 19, 2021

@author:  Gabriel Dimitriu
'''
import pygame

class Ship:
    """ class that contain the ship """
    def __init__(self, ai_game):
        """ initialize the ship and set its starting position"""
        self.screen = ai_game.screen
        self.settings = ai_game.settings
        self.screen_rect = ai_game.screen.get_rect()
        # load the ship image and get its rectangle
        self.image = pygame.image.load("images/ship.bmp")
        self.rect = self.image.get_rect()
        #start each new ship at the bottom center of the screen
        self.center_ship()
        self.moving_right = False
        self.moving_left = False
        
        
    def update(self):
        """ update ship position based on movement flag"""        
        if self.moving_right:
            if self.screen_rect.right > (self.x + self.settings.ship_speed + self.image.get_rect().right):
                self.x += self.settings.ship_speed
                self.rect.x = self.x
            else:
                self.moving_right = False
        elif self.moving_left:
            if self.screen_rect.left < (self.x - self.settings.ship_speed):
                self.x -= self.settings.ship_speed
                self.rect.x = self.x
            else:
                self.moving_left = False
        
    def draw(self):
        """ draw the ship at its current location"""
        self.screen.blit(self.image,self.rect) 
        
    def center_ship(self):
        """ center the ship on the screen"""
        self.rect.midbottom = self.screen_rect.midbottom     
        self.x =float(self.rect.x)