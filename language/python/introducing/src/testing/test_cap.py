'''
Created on Jun 30, 2021

@author:  Gabriel Dimitriu
'''
import unittest
import cap

class TestCap(unittest.TestCase):
    def setUp(self):
        pass
    def tearDown(self):
        pass
    
    def test_one_word(self):
        text = "duck"
        result = cap.just_do_it(text)
        self.assertEqual(result,"Duck")
        
    def test_multiple_words(self):
        text = "a veritable test"
        result = cap.just_do_it(text)
        self.assertEqual(result,"A Veritable Test") 

    def test_workds_with_apostrophes(self):
        text = "I'm fresh out of ideas"
        result = cap.just_do_it(text)
        self.assertEqual(result,"I'm Fresh Out Of Ideas")
if __name__ == "__main__":
    unittest.main()