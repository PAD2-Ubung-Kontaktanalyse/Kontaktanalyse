#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int create_list_interactions(char *persons_path, char *output_path){

    FILE *persons_file;
    FILE *output_file;
    
    int Person_ID = 0;
    int Infektionsstatus = 0;
    char Name_Person[80] = "";
    int ID = 0;
    
    persons_file = fopen(persons_path, "r"); // Liste mit Personen oeffnen
    output_file = fopen(output_path, "w"); // Ausgabe-Datei neu erzeugen bzw. ueberschreiben, wenn es sie schon gibt
    
    if(persons_file == NULL) {                                        	      // Fehlerbehandlung
        printf("could not open %s", persons_path);
        return -1;
    }
    if(output_file == NULL) {                                        	      // Fehlerbehandlung
        printf("could not open  %s", output_path);
        return -1;
    }
    fprintf(output_file,"Liste aller infizierten Personen:\n");

    rewind(persons_file);
    while(fscanf(persons_file, " %d; %s %d", &Person_ID, Name_Person, &Infektionsstatus) != EOF)
    {
        if(Infektionsstatus == 1) {
            fprintf(output_file,"&c \n", Name_Person);
        }
    }
    
    fclose(persons_file);
    fclose(output_file);
    return 0;
}
