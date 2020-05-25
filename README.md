# Partition_problem
c++ algorithm solving problem called PARTITION described in Readme

PARTITION problem is a task of deciding wether an input set of positive integers can be partitioned into two subsets such that the sum of all of the elements of subset 1 is equal to the sum of all of the elements of subset 2. The problem is NP-complete.

My program is of dynamic programming class. The idea is to create matrix of booleans that are true if the x and y of matrix are equal to 0 or if the element above is true or if the element one row higher and i columns on the left is true, and false on all other circumstances. If the last element of the matrix is true, then the whole problem has a positive solution - and negative otherwise.
