'''
Created on Mar 29, 2021

@author:  Gabriel Dimitriu
'''

import csv
import matplotlib.pyplot as plt
from datetime import datetime

#filename = 'data/sitka_weather_07-2018_simple.csv'
filename = 'data/sitka_weather_2018_simple.csv'
with open(filename) as f:
    reader = csv.reader(f)
    header_now = next(reader)
    for index,column_header in enumerate(header_now):
        print(index,column_header)
#    print(header_now)
    #get the temperature
    dates,highs = [],[],[]
    for row in reader:
        current_date = datetime.strptime(row[2],'%Y-%m-%d')
        high = int(row[5])
        dates.append(current_date)
        highs.append(high)
    #print(highs)
    #plot the high temperature
    plt.style.use('seaborn')
    fig, ax = plt.subplots()
    #ax.plot(highs, c='red')
    ax.plot(dates,highs,c='red')
    ax.set_title("Daily high temperatures -  2018", fontsize = 24)
    ax.set_xlabel('',fontsize=14)
    fig.autofmt_xdate()
    ax.set_ylabel('Teperature(F)', fontsize = 16)
    ax.tick_params(axis='both', which ='major', labelsize=16)
    plt.show()