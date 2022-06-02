#include <stdio.h> 
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <stdbool.h>

#define OPTIONS "u:t:"
#define MAX 100000

void printArt(char *text, FILE *infile);
void usage(char *exec) {
    fprintf(stderr,
        "SYNOPSIS\n"
        "   Automates login via ssh into either virtual machine or UCSC timeshare servers.\n"
        "\n"
        "USAGE\n"
        "   %s [OPTIONS]\n"
        "\n"
        "OPTIONS\n"
        "   -t         specifies which text file will be used to print ascii art.\n"
        "   -u         ssh login into UCSC timeshare.\n",
        exec);
}

int main(int argc, char **argv) {
    int opt = 0; 
    char *cruzID = "sammy";
    char *asc = "slugart.txt";
    char buf[100];
    FILE *art = NULL;
    while ((opt = getopt(argc, argv, OPTIONS)) != -1) {
        switch (opt) {
        case 'u': cruzID= optarg; puts("ID taken"); break;
        case 't': asc= optarg; puts("File taken"); break;
        default: usage(argv[0]); exit(0); break; 
        } //switch statement of all the command line options
    }
    //printf("id: %s", cruzID);
    printArt(asc, art);
    sprintf(buf, "ssh %s@unix.ucsc.edu", cruzID);
    system(buf);
    return 0;
}
void printArt(char *text, FILE *infile) {
    char *buffer = (char*)calloc(MAX, sizeof(char));
    infile = fopen(text, "r");
    while(!feof(infile)) {
        fscanf(infile, "%s", buffer);
        printf("%s\n", buffer);
    }  
    fclose(infile);
    free(buffer);
    buffer = NULL;
}