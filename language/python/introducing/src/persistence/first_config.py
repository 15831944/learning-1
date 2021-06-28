'''
Created on Jun 28, 2021

@author:  Gabriel Dimitriu
'''
import configparser

cfg = configparser.ConfigParser()
cfg.read('settings.cfg')
print(cfg['french'])
print(cfg['french']['greeting'])