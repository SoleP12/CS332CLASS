Name: Jonathan Player
BlazerId: jlplayer
Project #: Lab9CS332
Title--Fork() and Exec() with Signal Handle

Description - This lab introduces signal manipulation to us in C. With this prgram we are able to change specific signals like control z and cotrol c to allow them 
to preform different actions than they are normally used for. In the program when pressing control z typically it is used to suspend the process however changing the 
function of signal in the child process allows me to ignore when the button is pressed and vice versa for control C.

Functionality-----------
First Compile using -- gcc -Wall forkexecvp.c
Second run using -- ./a.out ./hw1 1000
Third -- Press Control+Z or Control+C in the terminal 
Fourth -- To terminate the suspended process press Control+\
------------------------

Warnings-- Press Control Z First (In compilation pressing control Z first allows for control C to be ignored as well and suspend)

