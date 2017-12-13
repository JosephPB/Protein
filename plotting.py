import matplotlib.pyplot as plt
import csv

time = []
energy = []
length = []

with open('data.csv') as csvfile:
    reader = csv.reader(csvfile)
    for row in reader:
        time.append(row[0])
        energy.append(row[1])
        length.append(row[2])
        
del time[0]
del energy[0]
del length[0]

for i in range(len(time)):
    time[i] = int(time[i])

for i in range(len(energy)):
    energy[i] = float(energy[i])

for i in range(len(length)):
    length[i] = float(length[i])
    
ax = plt.subplot(1,2,1)

plt.plot(time,energy, ls = '-', lw = 0.1)
plt.xlabel(r'Monte Carlo time steps ($10^{5}$)')
plt.ylabel("Energy")
plt.title("T = 1")

plt.subplot(1,2,2)

plt.plot(time,length, ls = '-', lw = 0.1)
plt.xlabel(r'Monte Carlo time steps ($10^{5}$)')
plt.ylabel("Length")
plt.title("T = 1")

plt.show()

