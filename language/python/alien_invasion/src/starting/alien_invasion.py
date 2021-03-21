'''
Created on Mar 19, 2021

@author:  Gabriel Dimitriu
'''
import sys

import pygame

from starting.settings import Settings
from starting.ship import Ship
from starting.bullet import Bullet

class AlienInvasion:
    """ overall class to manage game assets and bahavior. """
    def __init__(self):
        pygame.init()
        self.settings = Settings()
        #for full screen mode
        #self.screen = pygame.display.set_mode((0,0), pygame.FULLSCREEN)
        #self.settings.screen_width = self.screen.get_rect().width;
        #self.settings.screen_height = self.screen.get_rect().height;
        self.screen = pygame.display.set_mode((self.settings.screen_width, self.settings.screen_height))
        pygame.display.set_caption("Alien Invasion")
        self.ship = Ship(self)
        self.bullets = pygame.sprite.Group()
        
    def run_game(self):
        """ start the main loop for the game."""
        while True:
            self._check_events()
            self.ship.update()
            self._update_bullets()
            self._update_screen()

    def _update_screen(self):
        #redraw the screen
        self.screen.fill(self.settings.bg_color)
        self.ship.draw()
        #fire bullets
        for bullet in self.bullets.sprites():
            bullet.draw_bullet() 
        # make the most recently drawn screen visible.
        pygame.display.flip()
        
    #this will check the user events and make the move of the ship
    def _check_events(self):
        # watch for keyboard and mouse events.
        for event  in pygame.event.get():
            if event.type == pygame.QUIT:
                sys.exit()
            elif event.type == pygame.KEYDOWN:
                if event.key == pygame.K_RIGHT:
                    # move the ship to the right
                    #self.ship.rect.x += 1
                    self.ship.moving_right = True
                elif event.key == pygame.K_LEFT:
                    #move the ship to the left
                    #self.ship.rect.x -= 1
                    self.ship.moving_left = True
                elif event.unicode == "+":
                    self.settings.ship_speed += 0.5
                elif event.unicode == "-":                    
                    self.settings.ship_speed -= 0.5
                    if self.settings.ship_speed < 0:
                        self.settings.ship_speed = 0.5
                elif event.key == pygame.K_q:
                    sys.exit()
                elif event.key == pygame.K_SPACE:
                    self._fire_bullet()
            elif event.type == pygame.KEYUP:
                self.ship.moving_left =False
                self.ship.moving_left = False

    def _update_bullets(self):
        self.bullets.update()
        #get rid of bullets that have disapear
        for bullet in self.bullets.copy():
            if bullet.rect.bottom <= 0:
                self.bullets.remove(bullet)
        #print(len(self.buletts))
    
    def _fire_bullet(self):
        """ create a new bullet and add it to the bullets group."""
#        if len(self.bullets) < self.settings.bullet_allowed:
        new_bullet = Bullet(self)
        self.bullets.add(new_bullet)
if __name__ == '__main__':
    # make a game instance, and run the game
    ai = AlienInvasion()
    ai.run_game()