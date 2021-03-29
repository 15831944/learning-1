'''
Created on Mar 26, 2021

@author:  Gabriel Dimitriu
'''

import matplotlib.pyplot as plt
from random_walk import RandomWalk
while True:
    #rw = RandomWalk()
    rw = RandomWalk(50_000)
    rw.fill_walk()
    plt.style.use('classic')
    #fig,ax = plt.subplots()
    #full screen
    fig,ax = plt.subplots(figsize=(15,9))
    point_numbers = range(rw.num_points)
    #ax.scatter(rw.x_values,rw.y_values, s=15)
    #ax.scatter(rw.x_values, rw.y_values, c=point_numbers, cmap=plt.cm.Blues, edgecolors='none', s=15)
    ax.scatter(rw.x_values, rw.y_values, c=point_numbers, cmap=plt.cm.Blues, edgecolors='none', s=1)
    #empahsize the fist and last points.
    ax.scatter(0,0,c='green',edgecolors='none',s=100)
    ax.scatter(rw.x_values[-1],rw.y_values[-1], c='red', edgecolors='none', s=100)
    
    #remove axis
    ax.get_xaxis().set_visible(False)
    ax.get_yaxis().set_visible(False)
    
    #show the graph
    plt.show()
    
    keep_running = input("Make another walk? (y/n)")
    if keep_running == 'n':
        break