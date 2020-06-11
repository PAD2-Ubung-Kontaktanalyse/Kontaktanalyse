//	Header für PAD2-Kontaktanalyse
//	int create_txt()
//	int create_txt_with_time()
//	Arbeitsablauf der Funktion 
//	
//	Öffnen der Angegebenen Quellatei
//	Es wird eine Neue Datei "Code_Graphviz.txt" erstellt. 
//	Die Quelldatei wird Zeile für Zeile eingelesen und 
//	Daten entsprechend in die neue .txt Datei geschrieben
//	Das Format der .txt Datei kann in Graphviz online eingegeben werden. 
//
//	http://www.webgraphviz.com/
//
//	Hierzu bitte das vorhande Skript mit dem Inhalt der .txt Datei ersetzen. 
//
///////////////////////////////////////////////////////////////////////

#import <stdio.h>
#import <stdlib.h>
#import "generate_txt_file.h"

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
