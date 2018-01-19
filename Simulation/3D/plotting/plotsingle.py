import matplotlib.pyplot as plt
from matplotlib import ticker
import csv
import sys
import numpy as np

time = []
energy = []
length = []
temperature = 0
chain = 0

#open csv file
with open(str(sys.argv[1])) as csvfile:
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

#plot graphs

fig, ax1 = plt.subplots()
lns1 = ax1.plot(time, energy, lw=0.5, color="blue", label = "Energy")
ax1.set_ylabel(r"Energy ($k_BT$)", fontsize=15)
scale_pow = -5
def my_formatter_fun(x, p):
    return "%i" % (x * (10 ** scale_pow))
ax1.get_xaxis().set_major_formatter(ticker.FuncFormatter(my_formatter_fun))
ax1.set_xlabel('Monte Carlo Time Steps' + ' (x$10^5$)', fontsize=15)

    
ax2 = ax1.twinx()
lns2 = ax2.plot(time, length, lw=0.5, color="red", label = "Length")
ax2.set_ylabel(r"Length", fontsize=15)

lns = lns1+lns2
labs = [l.get_label() for l in lns]
ax1.legend(lns, labs, loc="upper right")

fig.savefig("T{}, L{}.pdf".format(temperature,chain),format='pdf')
