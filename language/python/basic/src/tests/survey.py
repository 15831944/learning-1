'''
Created on Mar 15, 2021

@author:  Gabriel Dimitriu
'''
class AnonymousSurvey:
    """ Collect anonymous answers to a survey question."""
    def __init__(self,question):
        """Store the question, and prepare to store response"""
        self.question = question
        self.responses = []
    def show_question(self):
        """Show the survey question."""
        print(self.question)
    def store_response(self, new_response):
        """ store a single response to the survey"""
        self.responses.append(new_response)
    def show_results(self):
        """show all the responsens that have been given"""
        print("Survey results:")
        for response in self.responses:
            print(f"- {response}")
            