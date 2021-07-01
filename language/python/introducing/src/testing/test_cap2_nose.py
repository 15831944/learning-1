'''
Created on Jun 30, 2021

@author:  Gabriel Dimitriu
'''
# pip3 install nose
import testing.cap2
from nose.tools import eq_

def test_one_word():
    text = "duck"
    result = testing.cap2.just_do_it(text)
    eq_(result,"Duck")
        
def test_multiple_words():
    text = "a veritable test"
    result = testing.cap2.just_do_it(text)
    eq_(result,"A Veritable Test") 

def test_workds_with_apostrophes():
    text = "I'm fresh out of ideas"
    result = testing.cap2.just_do_it(text)
    eq_(result,"I'm Fresh Out Of Ideas")