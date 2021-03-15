'''
Created on Mar 12, 2021

@author:  Gabriel Dimitriu
'''
filename ='test.txt'
with open(filename,'w') as file_object:
    file_object.write("I love programming!")
#read the file
print("First read of file")    
with open(filename) as file_object:
    print(file_object.readlines())
#write as append to the file
with open(filename,'a') as file_object:
    file_object.write("\nnew string")
    
print("Read again the file!")
with open(filename) as file_object:
    print(file_object.readlines())
