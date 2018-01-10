"""Plots temperature against average energy/average length
example input: pythonw plotavg.py seededTis1Lis30.csv seededTis2Lis30.csv seededTis3Lis30.csv seededTis4Lis30.csv seededTis5Lis30.csv seededTis6Lis30.csv seededTis7Lis30.csv seededTis8Lis30.csv seededTis9Lis30.csv seededTis10Lis30.csv seededTis11Lis30.csv seededTis12Lis30.csv seededTis13Lis30.csv seededTis14Lis30.csv seededTis15Lis30.csv seededTis16Lis30.csv seededTis17Lis30.csv seededTis18Lis30.csv seededTis19Lis30.csv seededTis20Lis30.csv"""

import matplotlib.pyplot as plt
import csv
import sys

arr_temp = []
arr_energy = []
arr_length = []

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
    for i in range(len(time)):
        time[i] = int(time[i])

    for i in range(len(energy)):
        energy[i] = float(energy[i])

    for i in range(len(length)):
        length[i] = float(length[i])

    
    #average energies and lengths
    avgE = 0
    for i in energy:
        avgE += i
    avgE = avgE / len(energy)

    avgL = 0
    for i in length:
        avgL += i
    avgL = avgL / len(length)

    arr_temp.append(int(temperature))
    arr_energy.append(avgE)
    arr_length.append(avgL)

#plot graphs    

f = plt.figure(1)
plt.plot(arr_temp,arr_energy,'ro',lw = 0.5)
plt.xlabel("Temperature")
plt.ylabel("Energy")
plt.title("Energy vs. Temperature")

f.savefig("Averaged Energy.jpg", dpi = 200)

g = plt.figure(2)
plt.plot(arr_temp,arr_length,'ro',lw = 0.5)
plt.xlabel("Temperature")
plt.ylabel("Length")
plt.title("Length vs. Temperature")

g.savefig("Averaged Length.jpg", dpi = 200)
