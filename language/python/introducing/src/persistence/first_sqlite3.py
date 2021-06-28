'''
Created on Jun 28, 2021

@author:  Gabriel Dimitriu
'''
import sqlite3
conn = sqlite3.connect('zoo.db')
curs = conn.cursor()
#create the table
curs.execute('''CREATE TABLE zoo(critter VARCHAR(20) PRIMARY KEY, count INT, damages FLOAT)''')
#insert data
curs.execute('INSERT INTO zoo VALUES("duck", 5, 0.0)')
curs.execute('INSERT INTO zoo VALUES("bear",2,1000.0)')
ins = 'INSERT INTO zoo(critter, count, damages) VALUES(?,?,?)'
curs.execute(ins,('weasel',1,2000.0))
#fetch all
curs.execute('SELECT * from zoo')
rows = curs.fetchall()
print(rows)

curs.execute('SELECT * from zoo ORDER BY count')
rows = curs.fetchall()
print(rows)
#close all connections
curs.close()
conn.close()