import matplotlib.pyplot as plt
import csv

time = []
energy = []
length = []
temperature = 0
chain = 0

#open csv file
with open('data.csv') as csvfile:
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

fig,ax = plt.subplots(2, sharex = True)

ax[0].plot(time,energy, ls = '-', lw = 0.5)
ax[0].set_ylabel("Energy")
ax[0].set_title("T = {}, Chain Length = {}".format(temperature,chain))

ax[1].plot(time,length, ls = '-', lw = 0.1)
ax[1].set_xlabel(r'Monte Carlo time steps')
ax[1].set_ylabel("Length")

plt.show()
#fig.savefig("T{}, L{}.jpg".format(temperature,chain),dpi = 200)


