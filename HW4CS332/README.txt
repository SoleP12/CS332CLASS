/*
Name: Jonathan Player
BlazerId: jlplayer
Project #: HMW4
To compile: make
To run:  ./jlplayerHMW4CS332
*/

Purpose -------
    The purpose of thsi HMW4 assignmnet was to culminate evrything together that we have learned from teh previous labs. 
    We use semaphores,mutexs,pipes,and threads. The assignment aims to hone our skills in process managament,
    IPC,synchronization, file operations, and signaling.
---------------

Functions -----

    First I initalize some constant factors presented in the assignemnt guidelines. These include 
    the number of producer threads,how many numbers each producer should generate, teh bounds of the
    number generation, the number of consumer threads in the child, and how many numbers each consumer
    will read from the pipe.

    I then initalize a pipe file descriptor, a mutex for pipe reading,writing, and printf, and then a
    sum tracker to get the final average in the end

    I create a structure called threadVari that was implemented in a lab assignment to handle passing parameters
    to multiple threads

    Random-- This is the first function that I create which will create 500 randomly genrated numbers between 0 and 1000.
    It will genrate a random number check if the number has been genrated, store and move to the next index. If the number
    has been used it will be marked looping until 500 numbers are genrated.


    Producer--This function will generate numbers and write them to the pipe. It does this by initalizing a for loop
    that will index over 500 numbers, wait for other threads to write, and lock them if neccessary. It will write one int at a time
    and release the pipe whne neccessary.It will also lock teh printf so that the threads will not get mixed


    Consume---


    Main ----

---------------