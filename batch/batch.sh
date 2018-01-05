#!/bin/bash

#SBATCH --mail-type=ALL
#SBATCH --mail-user=j.p.bullock@durham.ac.uk

srun /mt/home/jbullock/Documents/Protein/protein < /mt/home/jbullock/Documents/Protein/inputs/seededTis1Lis30.txt
srun /mt/home/jbullock/Documents/Protein/protein < /mt/home/jbullock/Documents/Protein/inputs/seededTis2Lis30.txt
srun /mt/home/jbullock/Documents/Protein/protein < /mt/home/jbullock/Documents/Protein/inputs/seededTis3Lis30.txt
srun /mt/home/jbullock/Documents/Protein/protein < /mt/home/jbullock/Documents/Protein/inputs/seededTis4Lis30.txt
srun /mt/home/jbullock/Documents/Protein/protein < /mt/home/jbullock/Documents/Protein/inputs/seededTis5Lis30.txt
srun /mt/home/jbullock/Documents/Protein/protein < /mt/home/jbullock/Documents/Protein/inputs/seededTis6Lis30.txt
srun /mt/home/jbullock/Documents/Protein/protein < /mt/home/jbullock/Documents/Protein/inputs/seededTis7Lis30.txt
srun /mt/home/jbullock/Documents/Protein/protein < /mt/home/jbullock/Documents/Protein/inputs/seededTis8Lis30.txt
srun /mt/home/jbullock/Documents/Protein/protein < /mt/home/jbullock/Documents/Protein/inputs/seededTis9Lis30.txt
srun /mt/home/jbullock/Documents/Protein/protein < /mt/home/jbullock/Documents/Protein/inputs/seededTis10Lis30.txt
srun /mt/home/jbullock/Documents/Protein/protein < /mt/home/jbullock/Documents/Protein/inputs/seededTis11Lis30.txt
srun /mt/home/jbullock/Documents/Protein/protein < /mt/home/jbullock/Documents/Protein/inputs/seededTis12Lis30.txt
srun /mt/home/jbullock/Documents/Protein/protein < /mt/home/jbullock/Documents/Protein/inputs/seededTis13Lis30.txt
srun /mt/home/jbullock/Documents/Protein/protein < /mt/home/jbullock/Documents/Protein/inputs/seededTis14Lis30.txt
srun /mt/home/jbullock/Documents/Protein/protein < /mt/home/jbullock/Documents/Protein/inputs/seededTis15Lis30.txt
srun /mt/home/jbullock/Documents/Protein/protein < /mt/home/jbullock/Documents/Protein/inputs/seededTis16Lis30.txt
srun /mt/home/jbullock/Documents/Protein/protein < /mt/home/jbullock/Documents/Protein/inputs/seededTis17Lis30.txt
srun /mt/home/jbullock/Documents/Protein/protein < /mt/home/jbullock/Documents/Protein/inputs/seededTis18Lis30.txt
srun /mt/home/jbullock/Documents/Protein/protein < /mt/home/jbullock/Documents/Protein/inputs/seededTis19Lis30.txt
srun /mt/home/jbullock/Documents/Protein/protein < /mt/home/jbullock/Documents/Protein/inputs/seededTis20Lis30.txt
srun hostname -f > worknode
mv /mt/batch/jbullock/plotting/*.csv /mt/home/jbullock/Documents/Protein/plotting

exit 0
