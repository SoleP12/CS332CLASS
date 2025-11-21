/*
Name: Jonathan Player
BlazerId: jlplayer
Project #: Lab12
To compile: gcc -O -Wall jlplayerlab12.c -lpthread
To run:  ./a.out 1000 4
*/

Description -----
            I first introduce the standard libraries needed for mutexing,threading, and the C header file
            From the pthread_sum I initalize a mutex called mutex. I then create a struct to hold variables and data
            a pointer to the array,pointer to the final sum, total number of elements, a size for number of threads, and thread
            identification number.

            Function compute()----
                I create a function called compute which has a void* argument. The values passed to compute are
                cast to a pointer to the struct threadVari. This will allow to use all the required variables.I 
                then take the values using the *data pointer to allow for each thread to have its own info.
                I then calculate the number of elements the starting index,ending index. I initalize a variable I which will be 
                used to iterate over the array elements. I check whether the thread can be divided evenly. I then compute the partial sum of each thread.
                I lock a specific thread using mutex, updat the global sum, and then release the lock alloing for the next thread to compute
                the partial sum.
            ----------------------

            Function main()----
            In the main function I get the amount of element from the first argv passed and the number of Threads
            with the second argv passed. I covert the cml strings to ints and allocate the threads and then initalize the struct threadVari. I create multiple
            threads based upon the second command passed in a for loop and create each thread. I then wait for
            all threads to complete and output the expected sum and mysum in the threads.
            -------------------
-----------------

Purpose ---------
This lab aims for us to become more familiar with POSIX threads library, threads and mutexes. Threads 
are essentially the smallest unit of processes or segment of a process. We want to learn more about this 
topic becuase of how efficicent they are in handling multiple tasks at the same time. With mutexes we
are able to handle critical moments within code where a race condition can occur, which is why it is integral
to this lab as well.
-----------------