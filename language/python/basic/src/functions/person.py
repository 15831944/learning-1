'''
Created on Mar 9, 2021

@author:  Gabriel Dimitriu
'''
def build_person(first_name, last_name):
    """ Return a dictionary of information about a person """
    person = {'first': first_name, 'last' : last_name}
    return person

musician = build_person('jimi', 'hendrix')
print(musician) 
#with optional
def build_person_1(first_name, last_name, age = None):
    """ Return a dictionary of information about a person """
    person = {'first': first_name, 'last' : last_name}
    if age:
        person['age'] = age
    return person

musician = build_person_1('jimi', 'hendrix', age=27)
print(musician) 