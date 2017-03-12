Universe Simulation
===================

This is a fork of [UniverseSimulation by snwfdhmp](https://github.com/snwfdhmp/UniverseSimulation).

## Current status
- Loading the set of genes and possible alleles from a JSON file works
- Generating a random population of arbitrary size works
- Writing the generated population to a file works

## Known problems
- The representation of genes is not optimal. Each gene in each individual
  repeats the name and ID of the gene. A better solution would be to have
  each gene reference its type from the genome and store its alleles only. That
  will be more and more useful as we add metadata to the various genes and
  alleles to more accurately model the real world.
- Individuals don't have identity. The only way to differentiate individuals
  at the moment is by their pointer, since 2 genetically identical individuals
  is possible. A possible solution would be to use their index in the population
  array as an unique identifier.
- Similarly, the representation of the parent-child relationship uses pointers
  to the individual in the population array, which will change as soon as that
  array is resized to accomodate more individuals. One solution would be to use
  an identifier system, which would still work when adding a significant number
  of individuals.
- The current representation of genetical dominance is to attribute a weight to
  each allele. Real genetics have more complex relationships where dominance is
  determined by which 2 genes are opposed. This should be represented.
- The current model only uses [dominance](https://en.wikipedia.org/wiki/Dominance_(genetics)) 
  to determine allele expression. [Epistasis](https://en.wikipedia.org/wiki/Epistasis) 
  is not taken into account.
- Representing the population as JSON creates several problems, most notably
  file size (in the case of large populations) and the absence of a native
  referencing mechanism. A custom, binary format would be a better alternative,
  but the data wouldn't be human-readable anymore.

## To do
- Specify and implement a binary format that allows for storage of genome and
  population information. Goals are time efficiency of loading and saving, and
  optimal disk-space usage.
- Implement a more advanced, CMake-based build-system.
- Implement and automate unit testing of the code.
- Create graphical tools to help control the simulation and analyze its results.
- Expand the model so that the simulation is more accurate.

