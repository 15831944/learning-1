'''
Created on Mar 4, 2021

@author:  Gabriel Dimitriu
'''
#first list
bicycles = ["trek","cannondale", "redline","specialized"]
print(bicycles)

#print first element
print(bicycles[0])
print(bicycles[0].title())
#print second element
print(bicycles[1])
#print last element
print(bicycles[3])
print(bicycles[-1])

#using individual elements
message = f"My first bicycle was a {bicycles[0].title()}"
print(message)

#modifying elements in list
motorcycles =["honda", "yamaha", "suzuki"]
print(motorcycles)
motorcycles[0] = "ducati"
print(motorcycles)

#appnding elements to the end of the list
motorcycles.append("honda")
print(motorcycles)

#creation from empty list
print("Create a list from empty list")
motorcycles = []
print(motorcycles)

motorcycles.append("honda")
motorcycles.append("yamaha")
motorcycles.append("suzuki")
print(motorcycles)

#inserting elements into a list
print("inserting at 0 ducati")
motorcycles.insert(0,"ducati")
print(motorcycles)

#removing element from list
print("removing first element")
del motorcycles[0]
print(motorcycles)

#pop from a list
print("Pop from list")
popped_motorcycle = motorcycles.pop()
print(popped_motorcycle)
print(motorcycles)

print("Pop with index")
motorcycles =["honda", "yamaha", "suzuki"]
popped_motorcycle = motorcycles.pop(1)
print(popped_motorcycle)
print(motorcycles)

print("Remove with value")
motorcycles =["honda", "yamaha", "ducati","suzuki"]
print(motorcycles)
motorcycles.remove("ducati")
print(motorcycles)

#sorting a list
motorcycles =["honda", "yamaha", "ducati","suzuki"]
print("Unsorted")
print(motorcycles)
print("Sorted with reverse")
motorcycles.sort(reverse=True)
print(motorcycles)
print("Sorted without arguments")
motorcycles.sort()
print(motorcycles)

#sorting only temporary
print("Original")
motorcycles =["honda", "yamaha", "ducati","suzuki"]
print(motorcycles)
sorted_tmp = sorted(motorcycles)
print("Sorted")
print(sorted_tmp)
print("Again the original untouched")
print(motorcycles)

print("Reverse")
sorted_tmp.reverse()
print(sorted_tmp)
print("Length of list")
print(len(motorcycles))

#looping into lists
print("loop in list")
motorcycles =["honda", "yamaha", "ducati","suzuki"]
print(motorcycles)
for motorcycle in motorcycles:
    print(motorcycle)
    print(f"Great {motorcycle}")
print("All good for road")

#wrong indentation looping into lists
print("loop in list with wrong indentation")
motorcycles =["honda", "yamaha", "ducati","suzuki"]
print(motorcycles)
for motorcycle in motorcycles:
    print(motorcycle)
print(f"Great {motorcycle}")
print("All good for road")

#range example
print("Range example")
for value in range(1,6):
    print(value)

#generate list using range
print("Generate list 1-5")
print(list(range(1,6)))

#generate even numbers
print("Generate even numbers 2-10")
print(list(range(2,11,2)))

#populate a list with squares
print("Populate a list with square numbers 1-10")
squares = []
for value in range(1,11):
    squares.append(value ** 2)
print(squares)
print("Show max and min into a list")
print(max(squares))
print(min(squares))

#another condensed method
squares = []
squares = [value ** 2 for value in range(1,11)]
print(squares)

#slicing a list
print("Slicing a list")
motorcycles =["honda", "yamaha", "ducati","suzuki"]
print(motorcycles[1:3])
print(motorcycles[:3])
print(motorcycles[2:])
print(motorcycles[-3:])

#looping through a slice
print("First 3 motorcycles")
for motorcycle in motorcycles[:3]:
    print(motorcycle.title())

#copy a list
motorcycles_copy = motorcycles[:]
print(motorcycles_copy)

motorcycles.append("Harley")
print(motorcycles)
print(motorcycles_copy)

