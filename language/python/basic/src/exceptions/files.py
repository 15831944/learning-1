'''
Created on Mar 12, 2021

@author:  Gabriel Dimitriu
'''
filename = 'alice.txt'
try:
    with open(filename,encoding = 'utf-8') as f:
        contents = f.read()
except FileNotFoundError:
    print(f"Sorry, the file {filename} does not exists.")
    
filename = 'alice_ok.txt'
try:
    with open(filename, encoding='utf-8') as f:
        contents = f.read()
except FileNotFoundError:
    print(f"Sorry, the file {filename} does not exist.")
else:
    #Count the approximate number of worlds in 
    words = contents.split()
    num_words = len(words)
    print(f"The file {filename} has about {num_words} words.")
    print(contents)

def count_words(filename):
    """count the approximate number of words in a file. """
    try:
        with open(filename,encoding='utf-8') as f:
            contents = f.read()
    except FileNotFoundError:
        print(f"Sorry the file {filename} does not exist.")
    else:
        words = contents.split()
        num_words = len(words)
        print(f"The file {filename} has about {num_words} words.")

count_words(filename)


