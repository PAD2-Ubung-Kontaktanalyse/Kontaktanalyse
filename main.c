//
//  main.c
//  PAD2-Kontaktanalyse
//
//  Created by Chrysostomos Siegl on 16.05.20.
//

#include <stdio.h>
#include "main.h"

#define MAXLINES 1000000

int main(int argc, const char * argv[]) {
    
    printf("Code: %d\n", generate_persons("/Users/chrys/Documents/xcode/PAD2-Kontaktanalyse/PAD2-Kontaktanalyse/names.txt", "",0,0,0));
    return 0;
}

int generate_persons(char * input_path, char * output_path, uint8_t n, uint8_t family_size, float infection_rate){
    uint name_count = 0;
    
    //open input file
    FILE *input_file = fopen(input_path, "r");
    if(input_file == NULL) {
        return 1;
    }
    
    //open output file
    FILE *output_file = fopen(output_path, "w");
    if(output_file == NULL) {
        return 2;
    }
    
    //count names
    name_count = line_count(input_file);
    
    //handle file read errors
    if (ferror(input_file)) {
        return 1;
    }
    
    //write random names to output file
    for(int i = 0; i < n; i++){
        //TODO
    }
    
    //release files
    fclose(input_file);
    fclose(output_file);
    return 0;
}

int line_count(FILE *input_file) {
    int result = 0;
    char c = getc(input_file);
    while(c != EOF){

        if (c == '\n') {
            result++;
        }
        c = getc(input_file);
    }
    return result;
}
