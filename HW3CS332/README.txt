/*
Name: Jonathan Player
BlazerId: jlplayer
Project #: Homework 3
To compile: make jlplayerHMW3
To run: make jlplayerHMW3 projects ,  ./jlplayerHMW3 projects
Further Testing - Use 'make jlplayerHMW3' and then "./jlplayerHMW3 ."
*/

Description----------
Func 1 - filetype
    This function is used to get the file type of the forked child process files
    Takes in an argument of type that returns a pointer to a string. We create a pointer to a string called
    str which we use to point to string called Directory or File. We introduce a switch statement that
    determines whether something is a directory or folder and assigns str to that string while
    returning the str or list of characters

Func 2 - printFileSIZE
    This function takes a string filename which is a pointer. We create a variable sb 
    that is a struct which will hold information provided by the stat() function. We then check whether the stat()
    call succeeded and fils the sb struct with information such as the file size. We then print this required
    information

Func 3 - wordCount
    This fucntion takes in a string pointer that is the filename. We create a pointer called filp to the File 
    structure, and then initalize a count which will keep track of the word count. It declares a variable c being read from the and previous 
    charcter.It then opens the file in read mode and creates a while loop that reads the file charcter by charcter.It checks whether
    c is a space,newline or tab and checks the same for previous and if both of these are true it increments counts and then makes prev = c to so 
    that each character is rembered for the next comparison

Func 4 - getDirectory

---------------------

Purpose--------------
To practice creating, managing, and terminating processes using system calls in C
To manipulate files and directories with system calls.
To demonstrate error handling in system-level programming.
---------------------

Warnings-Make sure to open intergrated terminal, Type make jlplayerHMW3 then ./jlplayerHMW3 projects




