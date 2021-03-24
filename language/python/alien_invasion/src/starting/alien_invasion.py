'''
Created on Mar 19, 2021

@author:  Gabriel Dimitriu
'''
import sys

import pygame

from time import sleep

from starting.settings import Settings
from starting.ship import Ship
from starting.bullet import Bullet
from starting.alien import Alien
from starting.game_stats import GameStats
from starting.button import Button
from starting.scoreboard import Scoreboard

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
        self.aliens = pygame.sprite.Group()
        self.stats = GameStats(self)
        self.sb = Scoreboard(self)
        self._create_fleet()
        #make the play button
        self.play_button = Button(self,"Play")
        
    def run_game(self):
        """ start the main loop for the game."""
        while True:
            self._check_events()
            if self.stats.game_active:
                self.ship.update()
                self._update_bullets()
                self._update_aliens()
            self._update_screen()

    def _update_screen(self):
        #redraw the screen
        self.screen.fill(self.settings.bg_color)
        self.ship.draw()
        #fire bullets
        for bullet in self.bullets.sprites():
            bullet.draw_bullet() 
        self.aliens.draw(self.screen)
        #draw score information
        self.sb.show_score()
        #draw the play button if the game is inactive
        if not self.stats.game_active:
            self.play_button.draw_button()
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
            elif event.type == pygame.MOUSEBUTTONDOWN:
                mouse_pos = pygame.mouse.get_pos()
                self._check_play_button(mouse_pos)
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
        self._check_alien_hit()
        
    
    def _check_alien_hit(self):
        #check for any bullets that have hit aliens
        collisions = pygame.sprite.groupcollide(self.bullets, self.aliens,True,True)
        if collisions:
#            self.stats.score += self.settings.alien_points
            for aliens in collisions.values():
                self.stats.score += self.settings.alien_points* len(aliens)
            self.sb.prep_score()
            self.sb.check_high_score()
        if not self.aliens:
            self.bullets.empty()
            self._create_fleet()
            self.settings.increase_speed()
            #increase level
            self.stats.level += 1
            self.sb.prep_level()
    
    def _fire_bullet(self):
        """ create a new bullet and add it to the bullets group."""
#        if len(self.bullets) < self.settings.bullet_allowed:
        new_bullet = Bullet(self)
        self.bullets.add(new_bullet)
        
    def _create_fleet(self):
        """ create the fleet of aliens"""
        alien = Alien(self)
        alien_width, alien_height = alien.rect.size
        available_space_x = self.settings.screen_width - (2* alien_width)
        number_aliens_x = available_space_x // (2*alien_width)
        ship_height = self.ship.rect.height
        available_space_y = (self.settings.screen_height - (3*alien_height) - ship_height)
        number_rows = available_space_y // (2*alien_height)
        #create first row
        for row_number in range(number_rows):
            for alien_number in range(number_aliens_x):
                self._create_alien(alien_number, row_number)
    
    def _create_alien(self, alien_number, row_number):
        alien = Alien(self)
        alien_width, alien_height = alien.rect.size
        alien.x = alien_width + 2*alien_width*alien_number
        alien.rect.x = alien.x
        alien.rect.y = alien_height + 2*alien.rect.height*row_number
        self.aliens.add(alien)
        
    def _update_aliens(self):
        """update the positions of all aliens"""
        self._check_fleet_edges()
        self.aliens.update()
        #look for alien-ship collisions
        if pygame.sprite.spritecollideany(self.ship,self.aliens):
            self._ship_hit()
        self._check_aliens_on_bottom()
        
    def _check_fleet_edges(self):
        for alien in self.aliens.sprites():
            if alien.check_edges():
                self._change_fleet_direction()
                break
    
    def _change_fleet_direction(self):
        """drop the entire fleet and change the fleet's direction"""
        for alien in self.aliens.sprites():
            alien.rect.y += self.settings.fleet_drop_speed
        self.settings.fleet_direction *=-1
    
    def _ship_hit(self):
        """the ship has been hit by an alien"""
        if self.stats.ship_left > 0:
            self.stats.ship_left -= 1
            self.sb.prep_ships()
            self.aliens.empty()
            self.bullets.empty()
            self._create_fleet()
            self.ship.center_ship()
            sleep(0.5)
        else:
            self.stats.game_active = False
            pygame.mouse.set_visible(True)
    
    def _check_aliens_on_bottom(self):
        """check if any aliens has reached the bottom of the screen."""
        screen_rect = self.screen.get_rect()
        for alien in self.aliens.sprites():
            if alien.rect.bottom >= screen_rect.bottom:
                self._ship_hit()
                break
    
    def _check_play_button(self, mouse_pos):
        """ start a new game"""
        button_clicked = self.play_button.rect.collidepoint(mouse_pos) 
        if button_clicked and not self.stats.game_active:
            self.settings.initialize_dynamic_settings()
            #reset game statistics
            self.stats.reset_stats()
            self.stats.game_active = True
            self.sb.prep_score()
            self.sb.prep_level()
            self.sb.prep_ships()
            #hide the mouse cursor to not hit by mistake the play button
            pygame.mouse.set_visible(False)
            
            #clean aliens and bullets
            self.aliens.empty()
            self.bullets.empty()
            #create a new fleet and ship
            self._create_fleet()
            self.ship.center_ship()
      
if __name__ == '__main__':
    # make a game instance, and run the game
    ai = AlienInvasion()
    ai.run_game()