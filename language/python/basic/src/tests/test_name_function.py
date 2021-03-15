'''
Created on Mar 15, 2021

@author: Gabriel Dimitriu
'''
import unittest

from tests.name_function import get_formatted_name

class NamesTestCase(unittest.TestCase):
    """Tests for name_function.py"""
    def test_first_last_name(self):
        """ Do names like 'Janis Jplin' work?"""
        formatted_name = get_formatted_name("janis","joplin")
        self.assertEqual(formatted_name, 'Janis Joplin')
        
if __name__ == '__main__':
    unittest.main() 