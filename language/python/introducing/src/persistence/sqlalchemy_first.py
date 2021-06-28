'''
Created on Jun 28, 2021

@author:  Gabriel Dimitriu
'''
import sqlalchemy as sa
#dialect + driver :// user : password @ host : port / dbname
conn = sa.create_engine('sqlite://')
#create the table
conn.execute('''CREATE TABLE zoo(critter VARCHAR(20) PRIMARY KEY, count INT, damages FLOAT)''')
#insert data
conn.execute('INSERT INTO zoo VALUES("duck", 5, 0.0)')
ins = 'INSERT INTO zoo(critter, count, damages) VALUES(?,?,?)'
conn.execute(ins,"bear",2,1000.0)
conn.execute(ins,('weasel',1,2000.0))
#fetch all
rows = conn.execute('SELECT * from zoo')
print(rows)
for row in rows:
    print(row)

rows = conn.execute('SELECT * from zoo ORDER BY count')
print(rows)
for row in rows:
    print(row)
