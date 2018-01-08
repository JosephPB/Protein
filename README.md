# Protein
## Introduction
Proteins fold into biologically 'active' states which allow them to perform important tasks. Whether or not they can perform this task is dependent on their folded structure, and if they are not in the correct 'active' state, then they are considered 'dead'. A build up of 'dead' proteins in the body is not just inefficient, it can also be harmful to the bodies function. Therefore, understanding the folding of these structures is crucial, to academic biolgists, as well as companies designing productes whic may interact with proteins.

This model simulates the folding of a randomly generated protein, given certain input parameters (length, temperature of solution, interaction energies etc.) on an infinite lattice.

## Getting Started

Clone the repository:
```
git clone https://github.com/JosephPB/Protein
```

The files are divided into directories depending on your requirements. The ```2D``` directory contains a verion of the programme which runs on an infinite 2D lattice, and equivalently for the ```3D``` directory. If you have access to a bbatch system the ```batch``` directory is set up to run such a programme with modifications. On a batch system change the ```batch.sh``` shell file and the destination of the write file ```/mt/batch/...``` to your appropriate values.

## Running the programme

Once you have selected theappropriate directory for the simulation:
  1. Run ```make```
  2. ```./protein``` (predefined inputs can be used, see 'Inputs subsection)
  3. Input the desired paremeters (see 'Parameters' subsection)
  4. Move to the ```plotting``` directory
  5. Run the python script appropriate to plotting the desired graphs (see 'Plotting' subsection)
  
### Parameters

The parameters are as follows:
  1. ```number of amino acids```: this is the monomer chain length desired
  2. ```Temperature```: the temperature of the solution in arbitrary units (Boltzman factor, k = 1)
  3. ```energy matrix```:
