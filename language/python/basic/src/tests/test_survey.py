'''
Created on Mar 15, 2021

@author:  Gabriel Dimitriu
'''
import unittest

from tests.survey import AnonymousSurvey
class TestAnonymousSurvey(unittest.TestCase):
    """Test the class AnonymousSurvey"""
    def test_Store_single_response(self):
        """Test that a single response is stored properly."""
        question = "What language did you first learn to speak ?"
        my_survey = AnonymousSurvey(question)
        my_survey.store_response("English")
        self.assertIn("English",my_survey.responses)
        
    def test_store_three_reponses(self):
        """Test that three individual responses are stored properly."""
        question = "What language did you first learn to speak ?"
        my_survey = AnonymousSurvey(question)
        responses = ['English', 'Spanish', "Mandarin"]
        for response in responses:
            my_survey.store_response(response)
            
        for response in responses:
            self.assertIn(response, my_survey.responses)
if __name__== '__main__':
    unittest.main() 