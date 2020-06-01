//
//  generator.c
//  PAD2-Kontaktanalyse
//
//
//

#include <stdio.h>
#include "generator.h"

int main(int argc, const char * argv[]) {
    
    printf("Code: %d\n", generate_persons("names.txt", "",0,0));
    return 0;
}

int generate_persons(char * input_path, char * output_path, int n, float infection_rate){
    int name_count = 0;
    
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

int generate_interactions(char * input_path, char * output_path, int n, int start_time, int end_time, int min_time, int max_time, int min_interactions, int max_interactions){
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
