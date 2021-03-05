'''
Created on Mar 4, 2021

@author: Gabriel Dimitriu
'''
#define strings
name = "Gabriel Dimitriu"
print (name.title())

name = 'New "Name"'
print(name)
print(name.upper())
print(name.lower())

first_name = "Gabriel"
last_name = "Dimitriu"

#concatenate
full_name = f"Fullname={first_name} {last_name}"
print(full_name)
print(f"Hello, {first_name} {last_name}")
message = f"Hello again, {first_name} {last_name}"
print(message)
full_name = "{} {}".format(first_name,last_name)
message = f"Hello again 1, {full_name.title()}"
print(message)

#Striping
message = " python "
print(f"l{message.rstrip()}r")
print(f"l{message.lstrip()}r")
print(f"l{message.strip()}r")