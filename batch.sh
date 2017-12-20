#!/bin/bash

#SBATCH --mail-type=ALL
#SBATCH --mail-user=j.p.bullock@durham.ac.uk

srun ~/mt/home/jbullock/Documents/Protein/protein < ~/mt/home/jbullock/Documents/Protein/inputs/seededTis1Lis30.txt
srun hostname -f > worknode
mv ~/mt/batch/jbullock/plotting/*.csv ~/mt/home/jbullock/Documents/Protein/plotting

exit 0
