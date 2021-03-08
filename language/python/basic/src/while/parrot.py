'''
Created on Mar 8, 2021

@author:  Gabriel Dimitriu
'''
# letting the user choose when to quit
prompt = "\nTell me somthing, and I will repeat back to you:"
prompt += "\nEnter 'quit' to end the program. "

message = ""
while message != 'quit':
    message = input(prompt)
    if message != 'quit':
        print(message)
