/*************************************************

Course: CS 4540 – Fall 2014
Assignment 3 - Problem 1
Name: Kyle Chipps
E-mail: kyle.d.chipps@wmich.edu
Submitted:  /*************************************************

This program generates a series of random points (x,y) then uses the monte carlo method to esimate the value of pi.
It is multithreaded with each thread generating NT_PTS x,y pairs.  Pi is estimated at the end of each thread, along with 
after all the threads have exited.  In general it is accurate to 4-5 decimal places.  Currently it will generate 50 million 
pairs and esitmate after each 10 millionth generation.