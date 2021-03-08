'''
Created on Mar 8, 2021

@author:  Gabriel Dimitriu
'''
prompt = "If you tell us who you are, we can personalize the messages you see."
prompt +="\nWhat is you first name ? "
name = input(prompt)
print(f"Hello, {name}!")

#using int
age = input("How old are you ? ")
age = int(age)
if age > 21:
    print("You are older enought to vote !")
else:
    print("You're not older enought to vote !")