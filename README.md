# Genie Thought Extender
Genie a PHP web app based on the colider program written in C.  Source for that is available in the source directory.
This web app was written as the final project for Harvardx's CS50x course through edx.org. This app collides two random words
out of a dictionary together and allows you to search the web with the results.  What comes out could be profound, stupid, 
or unintelliglible. It is however, fun. 

A video of it in action can be found [here.](https://www.youtube.com/watch?v=7-1hr_Le_Jg)

## Getting Started
1. Setup your Unix/Linux webserver with php installed.
2. Copy the contents of localhost into your public directory and you are all set!

## Screenshot

![Screenshot](Genie/SreenshotGenieSmall.png)


## Colider API
Colider is a program written in C that the website calls to generate collisions of words.
The program can run from the **Unix/Linux** command line with the below syntax. 

**Note: The two use cases below are the only ones currently supported.**

`./colider [number of collisions] [first Word "n" or "v"] [second Word "n" or "v" ] [seedWord or "x" if no seed]`

### Example with 10 collisions, a verb, and seed "shoe".

`./colider 10 v shoe`

### Example with 5 collisions, a verb and a noun and no seed.

`./colider 5 v n x`
