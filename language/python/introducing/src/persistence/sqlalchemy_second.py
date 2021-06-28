'''
Created on Jun 28, 2021

@author:  Gabriel Dimitriu
'''
import sqlalchemy as sa
#dialect + driver :// user : password @ host : port / dbname
conn = sa.create_engine('sqlite://')
#create the table
meta = sa.MetaData()
zoo = sa.Table('zoo', meta,
                sa.Column("critter", sa.String,primary_key = True),
               sa.Column("count",sa.Integer),
               sa.Column("damages",sa.Float))
meta.create_all(conn)
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
    
result = conn.execute(zoo.select())
rows = result.fetchall()
print(rows)
