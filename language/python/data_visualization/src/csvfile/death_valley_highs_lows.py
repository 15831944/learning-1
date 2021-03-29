'''
Created on Mar 29, 2021

@author:  Gabriel Dimitriu
'''

import csv
import matplotlib.pyplot as plt
from datetime import datetime

filename = 'data/death_valley_2018_simple.csv'

with open(filename) as f:
    reader = csv.reader(f)
    header_row = next(reader)
    #get the temperature
    dates,highs,lows = [],[],[]
    for row in reader:
        current_date = datetime.strptime(row[2],'%Y-%m-%d')
        try:
            high = int(row[4])
            low= int(row[5])
        except ValueError:
            print(f"Missing data for {current_date}")
        else:
            dates.append(current_date)
            highs.append(high)
            lows.append(low)
    #print(highs)
    #plot the high temperature
    plt.style.use('seaborn')
    fig, ax = plt.subplots()
    #ax.plot(highs, c='red')
    ax.plot(dates,highs,c='red', alpha = 0.5)
    ax.plot(dates,lows,c='blue', alpha = 0.5)
    ax.fill_between(dates,highs,lows, facecolor='blue', alpha = 0.1)
    ax.set_title("Daily high and low temperatures -  2018", fontsize = 24)
    ax.set_xlabel('',fontsize=14)
    fig.autofmt_xdate()
    ax.set_ylabel('Teperature(F)', fontsize = 16)
    ax.tick_params(axis='both', which ='major', labelsize=16)
    plt.show()