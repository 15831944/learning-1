'''
Created on Mar 26, 2021

@author:  Gabriel Dimitriu
'''
import matplotlib.pyplot as plt

x_values = [1,2,3,4,5]
y_values = [1,4,9,16,25]
plt.style.use('seaborn')
fig, ax = plt.subplots()
#ax.scatter(2,4, s= 200)
ax.scatter(x_values,y_values, s= 100)
#set chart title and label axes
ax.set_title("Square numbers", fontsize = 24)
ax.set_xlabel('Value', fontsize = 24)
ax.set_ylabel("Square of Values", fontsize=24)
ax.tick_params(axis='both', which = 'major', labelsize=14)
plt.show()