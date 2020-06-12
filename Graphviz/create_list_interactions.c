#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int create_list_interactions(char *persons_path, char *interactions_path, char *output_path, int start_timeframe, int end_timeframe){

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
    char Name_zur_Analyse[80] = "";
    int ID = 0;
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
    
    printf("Bitte geben Sie einen Namen ein:\n");
    scanf("%c", Name_zur_Analyse);
    fprintf(output_file,"Herr/Frau %c hatte folgende Kontakte:\n",Name_zur_Analyse);
    
    rewind(persons_file);
    while(fscanf(persons_file, " %d; %s %d", &Person_ID, Name_Person, &Infektionsstatus) != EOF) {
            if(Name_zur_Analyse == Name_Person) {
            ID = Person_ID;
            }
    }
    
    rewind(interactions_file);
    while(fscanf(interactions_file, " %d; %d; %d; %d; %d",
        &Interaktion_ID,
        &ID_Person_1,
        &ID_Person_2,
        &Start_Zeit,
        &End_Zeit) != EOF)    					    // Einlesen der Zeilen bis End Of File
        {
            if(ID == ID_Person_1 || ID == ID_Person_2 ) {
                if(ID == ID_Person_1) {
                      fprintf(output_file,"%d \n",ID_Person_2);  
                } else if(ID == ID_Person_2) {
                      fprintf(output_file," %d \n",ID_Person_1);
                  }
            }
    }
    
    fclose(persons_file);
    fclose(interactions_file);
    fclose(output_file);
    return 0;
}
