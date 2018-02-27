'''Plots energy against Monte Carlo time reading from 3 input files of the same number of time steps and chain length'''

import matplotlib.pyplot as plt
from matplotlib import ticker
import csv
import sys
import numpy as np



energy = []
length = []
temperature = []
time = []
chain = 0

for i in range(len(sys.argv)-1):
    time = []
    chain = 0
    #open csv file
    with open(str(sys.argv[i+1])) as csvfile:
        reader = csv.reader(csvfile)
        row1 = next(reader)
        temperature.append(row1[3]) #temperature is saved in the 4th column in the csv file
        chain = row1[4] #number of amino acids is saved in the 5th column in the csv file
        for row in reader:
            time.append(row[0])
            energy.append(row[1])

        #delete headings of columns
    del time[0]

    #convert the strings to numbers
    for j in range(len(time)):
        time[i] = int(time[j])
            
    for j in range(len(energy)):
        energy[i] = float(energy[j])

time_for1 = len(time)-2
time_for2 = 2*time_for1
time_for3 = 3*time_for1
energy1 = []
energy2 = []
energy3 = []

del energy[0]
del energy[1]
del energy[2]
del time[0]
del time[1]
del energy[time_for1]
del energy[time_for2]

for i in range(time_for1):
    energy1.append(energy[i])

for i in range(time_for1,time_for2):
    energy2.append(energy[i])

for i in range(time_for2,time_for3):
    energy3.append(energy[i])

print temperature 



f, (ax1, ax2, ax3) = plt.subplots(3, sharex=True, figsize=(8,8.5))
ax1.plot(time, energy1, label = "T = {}".format(temperature[0]), lw=0.5)
ax1.yaxis.set_ticks(np.arange(-60,-19,20))
ax1.set_title("T = {}".format(temperature[0]), fontsize=15)
ax1.set_ylabel(r"Energy ($k_BT$)")
ax2.plot(time, energy2, label = "T = {}".format(temperature[1]), lw=0.5)
ax2.set_title("T = {}".format(temperature[1]), fontsize=15)
ax2.yaxis.set_ticks(np.arange(-70,11,20))
ax2.set_ylabel(r"Energy ($k_BT$)")
ax3.plot(time, energy3, label = "T = {}".format(temperature[2]), lw=0.5)
ax3.set_title("T = {}".format(temperature[2]), fontsize=15)
ax3.yaxis.set_ticks(np.arange(-80,11,30))
ax3.set_ylabel(r"Energy ($k_BT$)")
# Fine-tune figure; make subplots close to each other and hide x ticks for
# all but bottom plot.
f.subplots_adjust(hspace=0.2)
scale_pow = -5
def my_formatter_fun(x, p):
    return "%i" % (x * (10 ** scale_pow))
ax3.get_xaxis().set_major_formatter(ticker.FuncFormatter(my_formatter_fun))
ax3.set_xlabel('Monte Carlo Time Steps' + ' (x$10^5$)', fontsize=15)
plt.setp([a.get_xticklabels() for a in f.axes[:-1]], visible=False)

f.savefig("Singles,T{}T{}T{}, L{}.pdf".format(temperature[0],temperature[1],temperature[2],chain),format='pdf')

