'''
Created on Jun 30, 2021

@author:  Gabriel Dimitriu
'''
# pip3 install bubbles, sqlalchemy
#does not work with latest sqlalchemy
import bubbles
p = bubbles.Pipeline()
p.source(bubbles.data_object("csv_source","zoo.csv"), infer_fields=True)
p.aggregate("animal","hush")
p.pretty_print()