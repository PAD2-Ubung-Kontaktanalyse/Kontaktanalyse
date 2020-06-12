#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define NAME_LEN 61


/**
 *  @brief Reads generated List and converts it into Graphviz script
 *  @details Format of output file: .txt with script
 *  @param persons_path Path + file name of the full list of persons
 *  @param interactions_path Path + file name of the full list of interactions
 *  @param output_path Path + file name where to output should be saved
 *  @param start_timeframe Beginning of the time frame in minutes since epoch, -1 to disable timeframe
 *  @param end_timeframe End of the time frame in minutes since epoch
 *  @return Returns 0 if successful, -1 in case of an error
 */
 
int create_graph(char *persons_path, char *interactions_path, char *output_path, int start_timeframe, int end_timeframe);

/**
 *  @brief Reads list of names from a text file, randomly generates persons and family stuctures, and saves the output in a text file
 *  @details Format of output file: person-id | name | family-id | infection-status
 *  @param input_path Path + file name of the full list of names
 *  @param output_path Path + file name where to output should be saved
 *  @param n Number of persons to generate
 *  @param infection_rate Probability for a person to be flagged "infected". Range: [0-1]
 *  @return Returns 0 in case of success, -1 for input error, -2 for output error
 */
int generate_persons(char * input_path, char * output_path, int n, float infection_rate);

/**
 *  @brief Reads list of persons from a text file, randomly generates interactions, and saves the output in a text file
 *  @details Format of output file: interaction-id | person1-id | person2-id | start-time | end-time
 *  @param input_path Path + file name of the full list of names
 *  @param output_path Path + file name where to output should be saved
 *  @param n Maximum number of interactions to generate (0 for unlimited)
 *  @param start_time Start of the time frame for all interactions in minutes since epoch
 *  @param end_time End of the time frame for all interactions in minutes since epoch
 *  @param min_time Minimum time span of an interaction in minutes
 *  @param max_time Maximum time span of an interaction in minutes
 *  @return Returns 0 in case of sucess, -1 for input error, -2 for output error
 */
int generate_interactions(char * input_path, char * output_path, int n, int start_time, int end_time, int min_time, int max_time);

/**
 *  @brief Counts the number of lines of a file
 *  @param input_file Pointer to input file stream
 *  @return Number of lines
 */
int line_count(FILE * input_file);


int generate_persons(char * input_path, char * output_path, int n, float infection_rate){
    int name_count = 0;
    
    //open input file
    FILE *input_file = fopen(input_path, "r");
    if(input_file == NULL) {
        return -1;
    }
    
    //open output file
    FILE *output_file = fopen(output_path, "w");
    if(output_file == NULL) {
        return -2;
    }
    
    //count names
    name_count = line_count(input_file);
    
    //handle file read errors
    if (ferror(input_file)) {
        return -1;
    }
    
    //write random names to output file
    for(int i = 0; i < n; i++){
        char name[NAME_LEN] = "";
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

int generate_interactions(char * input_path, char * output_path, int n, int start_time, int end_time, int min_time, int max_time){
    
    int person_count = 0;
    
    //open input file
    FILE *input_file = fopen(input_path, "r");
    if(input_file == NULL) {
        return -1;
    }
    
    //open output file
    FILE *output_file = fopen(output_path, "w");
    if(output_file == NULL) {
        return -2;
    }
    
    //count persons
    person_count = line_count(input_file);
    
    //generate n interactions
    for(int i = 0; i < n; i++){
        int person_id[2] = {0};
        int time[2] = {0};
        
        //pick 2 random persons
        for(int j = 0; j <= 1; j++){
            //begin from the top of the input file
            rewind(input_file);
            
            //pick random id
            person_id[j] = rand() % person_count;
        }
        
        //generate start time
        time[0] = start_time + (rand() % (end_time - start_time + 1));
        
        //generate end time
        time[1] = time[0] + min_time + (rand() % (max_time - min_time + 1));
        
        //write line to output file
        fprintf(output_file, "%d; %d; %d; %d; %d\n", i, person_id[0], person_id[1], time[0], time[1]); //Format: interaction-id, person-1-id, person-2-id, start-time, end-time
    }
    
    //release files
    fclose(input_file);
    fclose(output_file);
    
    //returns 0 for successful execution
    return 0;
}

int line_count(FILE *input_file){
    int result = 0;
    char c = getc(input_file);
    
    //iterate result for every new line character
    while(c != EOF){
        if (c == '\n') {
            result++;
        }
        c = getc(input_file);
    }
    return result;
}

int create_graph(char *persons_path, char *interactions_path, char *output_path, int start_timeframe, int end_timeframe){

    FILE *persons_file;
    FILE *interactions_file;
    FILE *output_file;
    
    int Interaktion_ID;         // Fortlaufende Nummerrierung des Einlesens
    int ID_Person_1;            // Identifikationsnummer von Person 1
    int ID_Person_2;            // Identifikationsnummer von Person 2
    int Person_ID = 0;
    int Start_Zeit = -1;
    int End_Zeit = 0;
    int Infektionsstatus = 0;
    char Name_Person[80] = "";

    persons_file = fopen(persons_path, "r"); // Liste mit Personen oeffnen
    interactions_file = fopen(interactions_path, "r"); // Liste mit Interaktionen oeffnen
    output_file = fopen(output_path, "w"); // Ausgabe-Datei neu erzeugen bzw. ueberschreiben, wenn es sie schon gibt
    
    if(persons_file == NULL) {                                        	      // Fehlerbehandlung
        printf("could not open %s", persons_path);
        return -1;
    }
    if(interactions_file == NULL) {                                        	  // Fehlerbehandlung
        printf("could not open  %s", interactions_path);
        return -1;
    }
    if(output_file == NULL) {                                        	      // Fehlerbehandlung
        printf("could not open  %s", output_path);
        return -1;
    }

    fprintf(output_file,"digraph G { \n\n");

    rewind(interactions_file);
    while(fscanf(interactions_file, " %d; %d; %d; %d; %d",
        &Interaktion_ID,
        &ID_Person_1,
        &ID_Person_2,
        &Start_Zeit,
        &End_Zeit) != EOF)    					    // Einlesen der Zeilen bis End Of File
        {
            if(start_timeframe == -1 || (Start_Zeit > start_timeframe && Start_Zeit < end_timeframe && End_Zeit < end_timeframe && End_Zeit > start_timeframe)) {
            fprintf(output_file,"\t%d -> %d;\n", ID_Person_1, ID_Person_2);
            }
    }

    rewind(persons_file);
    while(fscanf(persons_file, " %d; %s %d", &Person_ID, Name_Person, &Infektionsstatus) != EOF)
    {
        if(Infektionsstatus == 1) {
            fprintf(output_file,"\t%d [color=\"0.000 1.000 1.000\"];\n", Person_ID);
        }
    }
    
    fprintf(output_file,"\n}");
    
    fclose(persons_file);
    fclose(interactions_file);
    fclose(output_file);
    return 0;
}

int main(){ 
   printf("Bitte geben Sie den Pfad für die Namensdatei ein:\n");
   char Quelldatei[50];
   scanf("%s", Quelldatei);
   printf("Bitte geben Sie den Pfad für die Outputdatei ein:\n");
   char Outputfile[50];
   scanf("%s", Outputfile);
   printf("Bitte geben Sie die Anzahl der Personen ein:\n");
   int n;
   scanf("%d", &n);
   printf("Bitte geben Sie die Infektionsrate an:\n");
   float Infektionsrate;
   scanf("%f", &Infektionsrate);
 
   generate_persons(Quelldatei, Outputfile, n, Infektionsrate);
          
   int start_time = 100;
   int end_time = 200;
   int min_time = 5;
   int max_time = 30;
          
   generate_interactions(Outputfile, Quelldatei, n, start_time, end_time, min_time, max_time);
      
   printf("Bitte geben Sie den Pfad für die Graphviz-Outputdatei ein:\n");
   char Graphviz_Outputfile[50];
   scanf("%s", Graphviz_Outputfile);
          
   create_graph(Quelldatei, Outputfile, Graphviz_Outputfile, -1, 0);
          
          
   }
}
          
    
          
          
   
