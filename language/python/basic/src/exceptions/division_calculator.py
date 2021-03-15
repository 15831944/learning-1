'''
Created on Mar 12, 2021

@author:  Gabriel Dimitriu
'''
try:
    print(5/0)
except ZeroDivisionError:
    print("You could not divide by zero")
    
print("Give me two numbers, and I'll divede the,.")
print("Enter 'q' to quit.")
while True:
    first_number = input('\nFirst number: ')
    if first_number == 'q':
        break
    second_number = input("Scond number: ")
    if second_number == 'q':
        break
    try:
        answer = int(first_number)/int(second_number)
    except ZeroDivisionError:
        print("You could not divide by zero.")
    else:
        print(answer)