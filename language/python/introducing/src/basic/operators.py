'''
Created on Jun 16, 2021

@author:  Gabriel Dimitriu
'''
class Word():
    def __init__(self, text):
        self.text = text
    def __eq__(self, word2):
        return self.text.lower() == word2.text.lower()
    def __str__(self):
        return self.text
    def __repr__(self):
        return 'Word("' + self.text + '")'
    def __ne__(self, word2):
        return self.text.lower() != word2.text.lower()
    def __lt__(self, word2):
        return self.text < word2.text
    def __gt__(self,word2):
        return self.text > word2.text
    
first = Word("ab")
second = Word("AB")
third = Word("cd")

print("using eq",first == second)
print("using eq", first == third)
print("using ne", first != third)

print(first) #uses  __str__
first #uses __repr__ by the interpreter to output on stdout
print("using lt", first < third)
print("using gt", first > third)