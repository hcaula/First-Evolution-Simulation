# First Evolution Simulation
My very first time trying to simulate evolution (well, sorta).

In order to understand my simulation, I have to tell you what the node I use consist of.

A node is a struct with three atributes:
- a left associated number;
- a right associated number;
- an average between its left and right numbers.

So, what I try to do is, by starting with an array of random generated left and right numbers nodes, do a "natural selection" to pick those with the greatest average numbers.

First, we generate the "world" and name it Generation 0. Then, we sort its average numbers from greatest to lowest. Finally, we eliminate the bottom half of it.

Now that I delete half of my original world, I want to repopulate them. So, each couple on the top half will produce two sons. Those sons will look like:

- Son 1: left = dad's left || right = mom's left
- Son 2: left = dad's right || right = mom's right

So, after I do this for every couple on the top half, I again sort it and name it Generation 1.

And so, the process continues.

# Expectation
Here are the values I started with:
  - The randomly generated left and right nodes are limited to 0 and 999;
  - Each generation has 100 nodes.
  
So, by the end, I expect that most of the nodes have a average of 999 or close to it.
I also expect that, for each time I run the simulation, I have different final generations (or not even have a final generation).

# Conclusion
Most of my experiments tended to 996 instead of the expected 999. I then assume that, since there was no "threat", the nodes never had to become greater than 996.
By the end, every node had an average of 996, so everyone would survive (well, except for the unlucky ones that, because of the sorting algorithm, would be on the bottom half of the array and get killed).

Maybe this would change if I used a larger broad of numbers (more than 999) and perhaps increase the quantity variables to compare (add a "center" value to the node, or use another statistical measure in addition to "average").

This is yet really primitive, but maybe it can be the start of something great.
