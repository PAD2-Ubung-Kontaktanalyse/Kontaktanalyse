//
//  generator.c
//  PAD2-Kontaktanalyse
//
//
//

#include <stdio.h>
#include <stdlib.h>
#include "generator.h"

int main(int argc, const char * argv[]) {
    
    //test call of person generator
    printf("Code: %d\n", generate_persons("names.csv", "persons.csv", 100, 0.2));
    
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
        char name[61] = "";
        int status = 0;
        
        //pick random line from input file
        int line = rand() % name_count; //random number within [0; name_count)
        
        //begin from the top of the input file
        rewind(input_file);
        
        //jump to line
        for(int j = 0; j < line; j++){
            char c;
            while((c = fgetc(input_file)) != '\n');
        }
        
        //read name
        fscanf(input_file, " %s", name);
        
        //generate infection status
        int seed = rand() % 10001;
        if(seed > infection_rate * 10000){
            status = 0;
        }else{
            status = 1;
        }
        
        //write line to output file
        fprintf(output_file, "%d; %s; %d\n", i, name, status); //Format: id, name, infection-status (1=infected, 0=healthy)
    }
    
    //release files
    fclose(input_file);
    fclose(output_file);
    
    //returns 0 for successful execution
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
