'''
Created on Mar 8, 2021

@author:  Gabriel Dimitriu
'''
#defining a dictionary
alien_0 = {"color" : "green", "points" : 5}
print(alien_0["color"])
print(alien_0["points"])

new_points = alien_0["points"]
print(f"You just earned {new_points} points !")

#adding new value to dictionary
alien_0["x_position"] = 0
alien_0["y_position"] = 25
print(alien_0)

#starting with empty dictionary
alien_0 = {}
alien_0["color"] = "green"
alien_0["points"] = 5
print(alien_0)

#modifiying value in dictionary
print(f"The alien is {alien_0['color']}")
alien_0["color"] = "yellow"
print(f"The alien is now {alien_0['color']}")

#new exemple
alien_0 = {'x_position': 0, 'y_position' : 25, 'speed': 'medium'}
print(f"Original position: {alien_0['x_position']}")
#move the alien to the right
#determine how far to move the alien based on its current speed.
if alien_0['speed'] == 'slow':
    x_increment = 1
elif alien_0['speed'] == 'medium':
    x_increment = 2
else:
    # this must be a fast alien
    x_increment = 3
#the new position is the old position plus the increment
alien_0['x_position'] = alien_0['x_position'] + x_increment
print(f"New position: {alien_0['x_position']}")

#removing key-value from dictionary
alien_0['toRemove'] = 'value'
print(alien_0)
del alien_0['toRemove']
print(alien_0)

favorite_languages = {
    'jen': 'python',
    'sarah': 'c',
    'eduard': 'ruby',
    'cosmin': 'python',
    }
language = favorite_languages['sarah'].title()
print(f"Sarah's favorite language is {language}.")

#using get to get values with default
print(alien_0.get('points', 'No point value assigned'))

#looping through all key-value pairs
for key, value in favorite_languages.items():
    print(f"Key={key}")
    print(f"Value={value}")
    
friends = ['phil','sarah']
for name in favorite_languages.keys():
    print(f"Hi {name.title()}")
    if name in friends:
        language = favorite_languages[name].title()
        print(f"{name.title()}, I see you love {language}")

#looping throught values and take only distinct values
print("The following languages have been mentioned !")
for language in set(favorite_languages.values()):
    print(language.title())
    
alien_0 = {'color': 'green', 'points': 5}
alien_1 = {'color': 'yellow', 'points': 10}
alien_2 = {'color': 'red', 'points': 15}

aliens = [alien_0, alien_1, alien_2]
for alien in aliens:
    print(alien)

# a list in a dictionary
# store information about a pizza begin ordered
pizza = {
    'crust': 'thick',
    'toppings': ['mushrooms', 'extra cheese'],
    }
#sumarize the order.
print(f"You ordered a {pizza['crust']} - curst pizza with the following toppings:")
for topping in pizza['toppings']:
    print(f"\t{topping}")

#list in dictionary
favorite_languages = {
    'jen':['python', 'ruby'],
    'sarah': ['c'],
    'edward': ['ruby', 'go'],
    'phil': ['python', 'haskell'],
    }
for name, languages in favorite_languages.items():
    print(f"\n{name.title()}'s favorite languages are:")
    for language in languages:
        print(f"\t{language.title()}")
        
#dictionary into dictionaries
users = {
    'aeinstein': {
            'first': 'albert',
            'last': 'einstein',
            'location': 'princepton',
        },
    'mcurie': {
        'first': 'marie',
        'last': 'curie',
        'location': 'paris',
        },
    }
for username, user_info in users.items():
    print(f"\nUserName: {username}")
    full_name = f"{user_info['first'].title()} {user_info['last'].title()}"
    location = user_info['location']
    print(f"\tFull name: {full_name.title()}")
    print(f"\tLocation: {location.title()}")