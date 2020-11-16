# CSCI 2312 Assignment 4

#### Ethan Bacurio (109977009)

Project Status: Compiles and runs as intended.

### Structure
The project structure is illustrated below:
```
root
  |
  |__build //generated after make
  |    |
  |    |__apps //dir for binaries
  |    |
  |    |__objects //dir for compiled obj.
  |
  |__include //dir for all the header files.
  |
  |__src //dir for all source files.

```

All of the class definition can be found in a single header `Creature.h` to simplify the importation of all sub classes.

_this project is managed using Makefile (for csegrid) and Cmake (for clion)_

### Compilation
To compile the project
```
make clean all
```
Compiled objs can be found in ```/build/objects``` and the executable binary can be found in `/build/apps`.

To run after compilation
```
./build/apps/Creatures
```
