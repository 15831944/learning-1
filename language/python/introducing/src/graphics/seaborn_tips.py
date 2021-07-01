'''
Created on Jun 30, 2021

@author:  Gabriel Dimitriu
'''
# pip3 install seaborn
import seaborn as sns
import matplotlib.pyplot as plt

tips = sns.load_dataset("tips")
sns.regplot(x="total_bill", y="tip", data=tips)
plt.show()