#!/bin/bash

#SBATCH --mail-type=ALL
#SBATCH --mail-user=j.p.bullock@durham.ac.uk

#to select different lengths and temperatures, chanch input directory as required

srun /mt/home/jbullock/Documents/Protein/batch/protein < /mt/home/jbullock/Documents/Protein/batch/inputs/seededTis1Lis30.txt
srun /mt/home/jbullock/Documents/Protein/batch/protein < /mt/home/jbullock/Documents/Protein/batch/inputs/seededTis2Lis30.txt
srun /mt/home/jbullock/Documents/Protein/batch/protein < /mt/home/jbullock/Documents/Protein/batch/inputs/seededTis3Lis30.txt
srun /mt/home/jbullock/Documents/Protein/batch/protein < /mt/home/jbullock/Documents/Protein/batch/inputs/seededTis4Lis30.txt
srun /mt/home/jbullock/Documents/Protein/batch/protein < /mt/home/jbullock/Documents/Protein/batch/inputs/seededTis5Lis30.txt
srun /mt/home/jbullock/Documents/Protein/batch/protein < /mt/home/jbullock/Documents/Protein/batch/inputs/seededTis6Lis30.txt
srun /mt/home/jbullock/Documents/Protein/batch/protein < /mt/home/jbullock/Documents/Protein/batch/inputs/seededTis7Lis30.txt
srun /mt/home/jbullock/Documents/Protein/batch/protein < /mt/home/jbullock/Documents/Protein/batch/inputs/seededTis8Lis30.txt
srun /mt/home/jbullock/Documents/Protein/batch/protein < /mt/home/jbullock/Documents/Protein/batch/inputs/seededTis9Lis30.txt
srun /mt/home/jbullock/Documents/Protein/batch/protein < /mt/home/jbullock/Documents/Protein/batch/inputs/seededTis10Lis30.txt
srun /mt/home/jbullock/Documents/Protein/batch/protein < /mt/home/jbullock/Documents/Protein/batch/inputs/seededTis11Lis30.txt
srun /mt/home/jbullock/Documents/Protein/batch/protein < /mt/home/jbullock/Documents/Protein/batch/inputs/seededTis12Lis30.txt
srun /mt/home/jbullock/Documents/Protein/batch/protein < /mt/home/jbullock/Documents/Protein/batch/inputs/seededTis13Lis30.txt
srun /mt/home/jbullock/Documents/Protein/batch/protein < /mt/home/jbullock/Documents/Protein/batch/inputs/seededTis14Lis30.txt
srun /mt/home/jbullock/Documents/Protein/batch/protein < /mt/home/jbullock/Documents/Protein/batch/inputs/seededTis15Lis30.txt
srun /mt/home/jbullock/Documents/Protein/batch/protein < /mt/home/jbullock/Documents/Protein/batch/inputs/seededTis16Lis30.txt
srun /mt/home/jbullock/Documents/Protein/batch/protein < /mt/home/jbullock/Documents/Protein/batch/inputs/seededTis17Lis30.txt
srun /mt/home/jbullock/Documents/Protein/batch/protein < /mt/home/jbullock/Documents/Protein/batch/inputs/seededTis18Lis30.txt
srun /mt/home/jbullock/Documents/Protein/batch/protein < /mt/home/jbullock/Documents/Protein/batch/inputs/seededTis19Lis30.txt
srun /mt/home/jbullock/Documents/Protein/batch/protein < /mt/home/jbullock/Documents/Protein/batch/inputs/seededTis20Lis30.txt
srun hostname -f > worknode
mv /mt/batch/jbullock/plotting/*.csv /mt/home/jbullock/Documents/Protein/plotting

exit 0
