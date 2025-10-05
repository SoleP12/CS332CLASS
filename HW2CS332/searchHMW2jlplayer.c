#include <stdio.h>
#include <getopt.h>







int main (int argc, char *argv[]){
    int opt;
    while((opt = getopt(argc,argv, "Ssf")) != 1){
        switch(opt){
            case 'S' :break;

            case 's' :break;

            case 'f' :break;
        }
    }

     
}
