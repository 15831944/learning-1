'''
Created on Mar 9, 2021

@author:  Gabriel Dimitriu
'''
#return a simple value from function
def get_formatted_name(first_name, last_name):
    """Return a full name, neatly formatted."""
    full_name = f"{first_name} {last_name}"
    return full_name.title()

musician = get_formatted_name("jimi", "hendrix")
print(musician)

#make an argument optional
#first phase
def get_formatted_name_1(first_name, middle_name, last_name):
    """Return a full name, neatly formatted."""
    full_name = f"{first_name} {middle_name} {last_name}"
    return full_name.title()

musician = get_formatted_name_1("john","lee","hooker")
print(musician)

def get_formatted_name_2(first_name, last_name, middle_name = ''):
    """Return a full name, neatly formatted."""
    if middle_name:
        full_name = f"{first_name} {middle_name} {last_name}"
    else:
        full_name = f"{first_name} {last_name}"
    return full_name.title()

musician = get_formatted_name_2("john","hooker","lee")
print(musician)
musician = get_formatted_name_2("jimi", "hendrix")
print(musician)

while True:
    print("\nPlease tell me your name:")
    print("(enter 'q' at any time to quit)")
    f_name = input("First name: ")
    if f_name == 'q':
        break
    l_name = input("Last name: ")
    if l_name == 'q':
        break
    formated_name = get_formatted_name(f_name, l_name)
    print(f"\nHello, {formated_name}")
