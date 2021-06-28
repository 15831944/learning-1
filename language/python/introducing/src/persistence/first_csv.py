'''
Created on Jun 24, 2021

@author:  Gabriel Dimitriu
'''
import csv
villains_out = [['Doctor', 'No'],['Rosa', 'Klebb'],['Mister', 'Big'],
            ['Auric', 'Goldfinger'],['Ernst', 'Blofeld'],]
with open('villains','wt') as fout:
    csvout = csv.writer(fout)
    csvout.writerows(villains_out)
    
with open('villains','rt') as fin:
    cin = csv.reader(fin)
    villains_in = [row for row in cin]
    
print(villains_in)

print("Using DictReader with field names")
with open('villains', 'rt') as fin:
    cin = csv.DictReader(fin, fieldnames=['first','last'])
    villains_in = [row for row in cin]
print(villains_in)

print ("Using DictWriter and DictReader with field in dictionay")
villains_out_d = [
    {'first': 'Doctor', 'last': 'No'},
    {'first': 'Rosa', 'last': 'Klebb'},
    {'first': 'Mister', 'last': 'Big'},
    {'first': 'Auric', 'last': 'Goldfinger'},
    {'first': 'Ernst', 'last': 'Blofeld'},
    ]

with open('villains.cvs', 'wt') as fout:
    cout = csv.DictWriter(fout,['first','last'])
    cout.writeheader()
    cout.writerows(villains_out_d)
    

with open('villains.cvs', 'rt') as fin:
    cin = csv.DictReader(fin)
    villains_in_d = [row for row in cin]
print(villains_in_d)