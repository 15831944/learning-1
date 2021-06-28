'''
Created on Jun 24, 2021

@author:  Gabriel Dimitriu
'''
import json
with open("menu.json","rt") as fin:
    menu = fin.read()
print(menu)
menu_json = json.dumps(menu)
print(menu_json)
with open("menu.json","rt") as fin:
    menu_json2 = json.load(fin)
print(menu_json2)

import datetime
now = datetime.datetime.utcnow()
now_str = str(now)
now_json = json.dumps(now_str)
print(now_json)