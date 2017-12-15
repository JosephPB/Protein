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

    #plot graphs
    """
    plt.plot(time,energy,ls = '-',lw = 0.5)
    plt.xlabel("Monte Carlo time steps")
    plt.ylabel("Energy")
    plt.title("T = {}, Chain Length = {}".format(temperature,chain))
    
    plt.savefig("Energy:Tis{}Lis{}.jpg".format(temperature,chain),dpi = 200)
    
    plt.plot(time,length,ls = '-',lw = 0.1)
    plt.xlabel(r'Monte Carlo time steps')
    plt.ylabel("Length")
    plt.title("T = {}, Chain Length = {}".format(temperature,chain))

    plt.savefig("Length:Tis{}Lis{}.jpg".format(temperature,chain),dpi = 200)
    """
    
    avgE = 0
    for i in energy:
        avgE += i
    avgE = avgE / len(energy)

    avgL = 0
    for i in length:
        avgL += i
    avgL = avgL / len(length)

    arr_temp.append(temperature)
    arr_energy.append(avgE)
    arr_length.append(avgL)

plt.plot(arr_temp,arr_energy,ls = '.',lw = 0.5)
plt.xlabel("Temperature")
plt.ylabel("Energy")
plt.title("Energy vs. Temperature")

print arr_temp
print arr_energy
print arr_length

plt.savefig("Averaged Energy.jpg", dpi = 200)

plt.plot(arr_temp,arr_length,ls = '-',lw = 0.5)
plt.xlabel("Temperature")
plt.ylabel("Length")
plt.title("Length vs. Temperature")

plt.savefig("Averaged Length.jpg", dpi = 200)

