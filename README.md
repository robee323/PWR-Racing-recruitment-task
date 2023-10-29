# PWR-Racing-recruitment-task
The program on input take the name of the file in which the points are located in the following format:
<n> - the first line of the file will contain the number of points,
<x> <y> - the next n lines will contain the coordinates of these points,
the x-coordinate should be separated by a space from the y-coordinate.
The coordinates of the points do not have to be integers.
The program, after finishing its operation, writes out in the terminal the points forming the convex hull.

Example input data:  
 8  
 2 3  
 1 0  
 1 2  
 5 3  
 2.5 2  
 -1 2  
 4 -1  
 3 1  

Output:
[(2.0, 3.0), (1.0, 0.0), (5.0, 3.0), (-1.0, 2.0), (4.0, -1.0)]