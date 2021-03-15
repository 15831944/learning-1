'''
Created on Mar 12, 2021

@author:  Gabriel Dimitriu
'''
fileName = 'pi_digits.txt'

with open(fileName, mode = 'r') as file_object:
    contents = file_object.read()
print(contents)

print("Print as it is")
#read with terminal character
with open(fileName) as file_object:
    for line in file_object:
        print(f"Line={line}")

print("Print with stripped characters")
#strip extra characters
with open(fileName) as file_object:
    for line in file_object:
        print(f"Line={line.rstrip()}")
        
#read all lines
with open(fileName) as file_object:
    lines = file_object.readlines()
pi_string = ''
for line in lines:
    pi_string += line.rstrip();
print(pi_string)
print(len(pi_string)) 

#read all lines and stip them
with open(fileName) as file_object:
    lines = file_object.readlines()
pi_string = ''
for line in lines:
    pi_string += line.strip();
print(pi_string)
print(len(pi_string))