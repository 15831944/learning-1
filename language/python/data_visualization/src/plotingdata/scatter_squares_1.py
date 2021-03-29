'''
Created on Mar 26, 2021

@author:  Gabriel Dimitriu
'''
import matplotlib.pyplot as plt

x_values = range(1,1001)
y_values = [x**2 for x in x_values]
plt.style.use('seaborn')
fig, ax = plt.subplots()
#ax.scatter(2,4, s= 200)
#ax.scatter(x_values,y_values, c='red', s= 10)
ax.scatter(x_values,y_values, c=y_values, cmap=plt.cm.Blues, s= 10)
#set chart title and label axes
ax.set_title("Square numbers", fontsize = 24)
ax.set_xlabel('Value', fontsize = 24)
ax.set_ylabel("Square of Values", fontsize=24)
ax.tick_params(axis='both', which = 'major', labelsize=14)
ax.axis([0,1100,0,1100000])
plt.savefig('squares_plot.png',bbox_inches='tight')
plt.show()