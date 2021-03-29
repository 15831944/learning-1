'''
Created on Mar 26, 2021

@author:  Gabriel Dimitriu
'''

from die import Die
from plotly.graph_objs import Bar,Layout
from plotly import offline

die_1 =Die()
#die_2 =Die()
die_2 = Die(10)

tries = 50000
results = []
for roll_num in range(tries):
    result = die_1.roll() + die_2.roll()
    results.append(result)
    
#Analyze the results
frequencies = []
max_result = die_1.num_sides + die_2.num_sides
for value in range(1,max_result + 1):
    frequency = results.count(value)
    frequencies.append(frequency)
    
#print(frequencies)

#make a histogram of the values
x_values = list(range(1,max_result+1))
data = [Bar(x=x_values, y = frequencies)]

x_axis_config = {'title': 'Result', 'dtick' : 1}
y_axis_config = {'title': 'Frequency of Result'}
my_layout = Layout(title=f"Results of rolling two dies {tries} times", xaxis=x_axis_config, yaxis=y_axis_config)
offline.plot({'data': data, 'layout' : my_layout}, filename='dice.html')


