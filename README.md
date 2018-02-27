# Protein
## Introduction
Proteins fold into biologically 'active' states which allow them to perform important tasks. Whether or not they can perform this task is dependent on their folded structure, and if they are not in the correct 'active' state, then they are considered 'dead'. A build up of 'dead' proteins in the body is not just inefficient, it can also be harmful to the bodies function. Therefore, understanding the folding of these structures is crucial, to academic biolgists, as well as companies designing productes whic may interact with proteins.

This model simulates the folding of a randomly generated protein, given certain input parameters (length, temperature of solution, interaction energies etc.) on an infinite lattice.

## Documentation
For more information on the background, references and an application of this programme see the paper ```A Lattice Simulation Approach to Protein Folding.pdf```.

## Getting Started

Clone the repository:
```
git clone https://github.com/JosephPB/Protein
```

The files are divided into directories depending on your requirements. The ```Real``` directory contains scripts which allow the user to input the exact amino acid make up and order of the amino acids by hand. The ```Simulation``` directory contains scripts which do not require amino acid type user input, and instead will randomly generate a protein. Inside these two directories are ```2D``` and ```3D``` directories that contains a verion of the programme which runs on an infinite 2D lattice, and equivalently for the ```3D``` directory. If you have access to a batch system the ```batch``` directory is set up to run such a programme with modifications. On a batch system change the ```batch.sh``` shell file and the destination of the write file ```/mt/batch/...``` to your appropriate values.

## Running the programme

Once you have selected theappropriate directory for the simulation:
  1. Run ```make```
  2. ```./protein``` (predefined inputs can be used, see 'Inputs subsection)
  3. Input the desired paremeters (see 'Parameters' subsection)
  4. Move to the ```plotting``` directory
  5. Run the python script appropriate to plotting the desired graphs (see 'Plotting' subsection)
  
### Parameters

The parameters are as follows:
  1. ```Number of amino acids```: this is the monomer chain length desired
  2. ```Initialise unfolded protein```: ```y``` generates a totally unfolded (straight), ```n``` gives a protein produced by a non-crossing random walk beginning at the origin
  3. ```Temperature```: the temperature of the solution in arbitrary units (Boltzman factor, k = 1)
  4. ```Energy matrix```: ```i``` fills the 20x20 symmetric interaction matrix with a integer values from a uniform distribution between limits to be defined, ```r``` fills it with ```double``` values from a uniform distribution, ```j``` places at each element a ```1``` or a ```-1``` at random, and ```m``` fills the matrix with the values found in [Miyazawa and Jernigan (1985), Table VI](https://pubs.acs.org/doi/abs/10.1021/ma00145a039)
  5. (if selected ```i``` or ```r``` at step 4) ```Range```: specify the range of the distribution
  6. ```Number of time steps```: the number of times the programme will go through it's folding computation (measured in Monte Carlo time)
  7. ```Seed```: the seed value for all random number generators used in initialising the protein, ```0``` given ```time``` as a seed

### Inputs

Preset input files, to avoid manual input of the above parameters, can be stored in the```inputs``` directory. Examples are given which may be editied accordingly, or new ones added. (See ```jobs.sh``` or ```batch.sh``` in the ```3D``` and ```batch``` directories respectively for examples of using shell files with inputs.)

### Plotting

The ```plotting``` directory contains plotting code. ```plotsingle.py``` takes input from one ```.csv``` file at the command line:
```
plotsingle.py <filename.csv>
```
and plots energy vs. Monte Carlo time and lenth vs. Monte Carlo time.

Similarly ```plotavg.py``` takes multiple file inputs, of the same monomer lenth and different temperature at the command line (see ```jobs.sh``` in ```3D``` for an example) and plots average energy vs. temperature and average length vs. temperature.

Additionally, ```plotmult.py``` takes in multiple runs at three different temperatures and creates a three tiered subplot for comparison.

## Versioning

We use [SemVer](http://semver.org/) for versioning.

## Future Work

We hope to add a visual element to the process, allowing for snapshots of the protein folding process to be taken and visually realised, potentially by linking up with other established protein visualisation software. Additionally, research into domain folding may lead to increased computation speed (e.g. adapting from [Abkevich, Gutin and Shakhnovich (1995)](https://www.ncbi.nlm.nih.gov/pmc/articles/PMC2143143/) to a more generalised model).

In a later version, we hope to be able to reproduce and improve upon the work of others in this field such as [Sali, Shakhnovich and Karplus (1994)](https://www.nature.com/articles/369248a0).



