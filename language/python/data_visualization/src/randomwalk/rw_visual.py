'''
Created on Mar 26, 2021

@author:  Gabriel Dimitriu
'''

import matplotlib.pyplot as plt
from random_walk import RandomWalk

rw = RandomWalk()
rw.fill_walk()
plt.style.use('classic')
fig,ax = plt.subplots()
ax.scatter(rw.x_values,rw.y_values, s=15)
#show the graph
plt.show()