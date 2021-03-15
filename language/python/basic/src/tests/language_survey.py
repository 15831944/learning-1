'''
Created on Mar 15, 2021

@author:  Gabriel Dimitriu
'''
from tests.survey import AnonymousSurvey

#define the question, and make a survey
question = "What language did you first learn to speak?"
my_survey = AnonymousSurvey(question)

#show the question, and store the response to the question.
my_survey.show_question()
print("Enter 'q' at any time to quit.\n")
while True:
    response = input("Language: ")
    if response == 'q':
        break
    my_survey.store_response(response)
    
#Show the survey results
print("\nTank you to everyone who participated in this survery !")
my_survey.show_results()