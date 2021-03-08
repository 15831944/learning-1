'''
Created on Mar 8, 2021

@author:  Gabriel Dimitriu
'''
# filling a dictionary
responses = {}
polling_active = True
while polling_active:
    #prompt person name and response
    name = input("What is your name? ")
    response = input("Which mountain whould you climb someday? ")
    #store the response
    responses[name] = response
    #find out if anyone else is going to take the poll.
    repeat = input("Whould you like to let another person respond? (yes/no) ")
    if repeat == 'no':
        polling_active = False
#polling is complete show the result
print("\n--- Poll Results ---")
for name,response in responses.items():
    print(f"{name} would like to climb {response}.")