/*
Name: Jonathan Player
BlazerId: jlplayer
Project #: Lab11
To compile: gcc -Wall jlplayerlab11.c
To run:  ./a.out
*/

Description --- This code takes the input of the user in the command line
                and uses the popen and pclose functions in C. With popen we are able
                to create a pipe between the calling program and the executed command. In this
                program we simply prompt the user to enter a charcter in an infinite loop while also accepting
                wildcards beacuse of how popen passes them to the shell. If the user enters quit the 
                command stops

Purpose --- The reason behind this lab was to build on the knowledge of pipes that we learned
            in class and see the usages and power of this technique

