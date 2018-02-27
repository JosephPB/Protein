"""Plots temperature against average energy/average length
example input: pythonw plotavg.py seededTis1Lis30.csv seededTis2Lis30.csv seededTis3Lis30.csv seededTis4Lis30.csv seededTis5Lis30.csv seededTis6Lis30.csv seededTis7Lis30.csv seededTis8Lis30.csv seededTis9Lis30.csv seededTis10Lis30.csv seededTis11Lis30.csv seededTis12Lis30.csv seededTis13Lis30.csv seededTis14Lis30.csv seededTis15Lis30.csv seededTis16Lis30.csv seededTis17Lis30.csv seededTis18Lis30.csv seededTis19Lis30.csv seededTis20Lis30.csv"""

import matplotlib.pyplot as plt
import csv
import sys
import numpy as np
from scipy.optimize import curve_fit

arr_temp = []
arr_energy = []
arr_length = []
arr_error = []

for i in range(len(sys.argv)-1):
    time = []
    energy = []
    length = []
    temperature = 0
    chain = 0

    #open csv file
    with open(str(sys.argv[i+1])) as csvfile:
        reader = csv.reader(csvfile)
        row1 = next(reader)
        temperature = row1[3] #temperature is saved in the 4th column in the csv file
        chain = row1[4] #number of amino acids is saved in the 5th column in the csv file
        for row in reader:
            time.append(row[0])
            energy.append(row[1])
            length.append(row[2])

    #delete headings of columns
    del time[0]
    del energy[0]
    del length[0]

    #convert the strings to numbers
    for j in range(len(time)):
        time[j] = int(time[j])

    for j in range(len(energy)):
        energy[j] = float(energy[j])

    for j in range(len(length)):
        length[j] = float(length[j])

    
    #average energies and lengths
    avgE = 0
    for j in energy:
        avgE += j
    avgE = avgE / len(energy)

    avgL = 0
    for j in length:
        avgL += j
    avgL = avgL / len(length)

    arr_temp.append(int(temperature))
    arr_energy.append(avgE)
    arr_length.append(avgL)

    #errors
    Evar = 0
    for j in energy:
        Evar += (j-avgE)**2
    Eerror = (Evar/(len(energy)-1))**0.5
    arr_error.append(Eerror)
    
#plot graphs    

print (min(arr_error))
print (max(arr_error))

fig, ax1 = plt.subplots()
ax1.scatter(arr_temp, arr_energy, s=60, c= 'blue', label = "Energy")
ax1.set_ylabel(r"Energy ($k_BT$)", fontsize=15)
ax1.set_xlabel(r"Temperature", fontsize=15)
ax1.set_xlim((0,20.5))

ax2 = ax1.twinx()
ax2.scatter(arr_temp, arr_length, s=60, c='red', label = "Length")
ax2.set_ylabel(r"Length", fontsize=15)
ax2.set_xlim((0,20.5))

lines, labels = ax1.get_legend_handles_labels()
lines2, labels2 = ax2.get_legend_handles_labels()
ax2.legend(lines + lines2, labels + labels2, loc='upper left')


fig.savefig("Averaged.pdf", format='pdf')
