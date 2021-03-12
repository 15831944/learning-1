'''
Created on Mar 8, 2021

@author:  Gabriel Dimitriu
'''

def greet_user():
    print("Hello !")
    
def greet_user1(username):
    print(f"Hello, {username.title()} !")
    
greet_user()
greet_user1('Gaby')

#pass list to a function
def greet_users(names):
    """ print a simple greeting to each user in the list"""
    for name in names:
        msg = f"Hello, {name.title()}"
        print(msg)
        
usernames = ['hannah', 'ty', 'margot']
greet_users(usernames)

