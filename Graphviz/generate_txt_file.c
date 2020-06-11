//	Header für PAD2-Kontaktanalyse
//
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
  
#ifndef scriptwriter_h
#define scriptwriter_h 
 
/**
 *  @brief Reads generated List and converts it into Graphviz script 
 *  @details Format of output file: .txt with script
 *  @param input_path Path + file name of the full list of names
 *  @param output_path Path + file name where to output should be saved
 *  @return Returns 0
 */
 
int create_txt(FILE *myfile, FILE *newfile, FILE *infectfile){

FILE *myfile;
   char Dateiname[81];
FILE *newfile;
   char Nametxt[81]
FILE *infectfile;
   char Infectname[81];	    
	    
int Interaktion_ID;                                                   // Fortlaufende Nummerrierung des einlesens                 
int ID_Person_1;                                                      // Identifikationsnummer von Person 1 
int ID_Person_2;
int Person_ID;								// Identifikationsnummer von Person 2
int Start_Zeit;								
int End_Zeit;
int Infektionsstatus; 
	
printf("Geben Sie die Bezeichnung der Datei ein welche die Interaktionen enthält:\n Achtung! 80 Zeichen Maximum!\n");		      // Dateiname abfragen
scanf("%s", Dateiname);
myfile = fopen(Dateiname, "r");                                 	      // Datei zum schreiben öffnen 
    
printf("Geben Sie die Bezeichnung der Datei ein welche den Infektionsstatus festhalten:\n Achtung! 80 Zeichen Maximum!\n");		      // Dateiname abfragen
scanf("%s", Infectname);
infectfile = fopen(Infectname, "r");  
	
printf("Geben Sie die Bezeichnung der Datei ein in die geschrieben werden soll:\n Achtung! 80 Zeichen Maximum!\n");		      // Dateiname abfragen
scanf("%s", Nametxt);
newfile = fopen("Code_Graphviz %d .txt", Nametxt, "w");				      // Datei neu erzeugen bzw. ueberschreiben, wenn es sie schon gibt	
    
if(myfile == NULL) {                                        	      // Fehlerbehandlung 
	printf("could not open %s", Dateiname);
	return 0;
}
if(newfile == NULL) {                                        	      // Fehlerbehandlung 
        printf("could not open  %s", Nametxt);
        return 0;
}
if(newfile == NULL) {                                        	      // Fehlerbehandlung 
        printf("could not open  %s", infectname);
        return 0;
}	

fprintf(newfile,"digraph G { \n\n"); 
	
while(fscanf(myfile, " %d,%d,%d,%d,%d", 
	&Interaktion_ID, 
	&ID_Person_1, 
	&ID_Person_2,
	&Start_Zeit, 
	&End_Zeit,) != EOF)    					      // Einlesen der Zeilen bis End Of File 	
	{
	fprintf(newfile,"	%d -> %d;\n", ID_Person1, ID_Person2); 
        }
while(fscanf(infectfile, " %d,%d,%d", 
	&Personen_ID, 
	&Name_Person, 
	&Infektionsstatus,) != EOF) 
	{
		if(Infektionsstatus == 1) {
		fprintf(infectfile,"	%d P1 [color="0.000 1.000 1.000"];\n" Personen_ID, Infektionsstatus);	
		}
	}
fprintf(newfile,"\n}"};	
	
fclose(myfile);
fclose(newfile);
fclose(infectfile);

}

	
int create_txt_with_time(FILE *myfile, FILE *newfile, FILE *infectfile){

FILE *myfile;
   char Dateiname[81];
FILE *newfile;
   char Nametxt[81]
FILE *infectfile;
   char Infectname[81];	    
	    
int Interaktion_ID;                                                   // Fortlaufende Nummerrierung des einlesens                 
int ID_Person_1;                                                      // Identifikationsnummer von Person 1 
int ID_Person_2;
int Person_ID;								// Identifikationsnummer von Person 2
int Start_Zeit;								
int End_Zeit;
int Infektionsstatus; 
int Zeit_eingabe;

printf("Geben Sie die Bezeichnung der Datei ein welche die Interaktionen enthält:\n Achtung! 80 Zeichen Maximum!\n");		      // Dateiname abfragen
scanf("%s", Dateiname);
myfile = fopen(Dateiname, "r");                                 	      // Datei zum schreiben öffnen 
    
printf("Geben Sie die Bezeichnung der Datei ein welche den Infektionsstatus festhalten:\n Achtung! 80 Zeichen Maximum!\n");		      // Dateiname abfragen
scanf("%s", Infectname);
infectfile = fopen(Infectname, "r");  
	
printf("Geben Sie die Bezeichnung der Datei ein in die geschrieben werden soll:\n Achtung! 80 Zeichen Maximum!\n");		      // Dateiname abfragen
scanf("%s", Nametxt);
newfile = fopen("Code_Graphviz %d .txt", Nametxt, "w");				      // Datei neu erzeugen bzw. ueberschreiben, wenn es sie schon gibt	
 
printf("Bitte geben Sie ein ab welchen Zeitpunkt die Analyse starten soll\n");
scanf("%d", &Zeiteingabe);


if(myfile == NULL) {                                        	      // Fehlerbehandlung 
	printf("could not open %s", Dateiname);
	return 0;
}
if(newfile == NULL) {                                        	      // Fehlerbehandlung 
        printf("could not open  %s", Nametxt);
        return 0;
}
if(newfile == NULL) {                                        	      // Fehlerbehandlung 
        printf("could not open  %s", infectname);
        return 0;
}	

fprintf(newfile,"digraph G { \n\n"); 
	
  while(fscanf(myfile, " %d,%d,%d,%d,%d", 
    &Interaktion_ID, 
    &ID_Person_1, 
    &ID_Person_2,
    &Start_Zeit, 
    &End_Zeit,) != EOF)    					      // Einlesen der Zeilen bis End Of File 	
    {
        if(Zeit_eingabe > Start_zeit) {
        fprintf(newfile,"	%d -> %d;\n", ID_Person1, ID_Person2); 
        }
    }
          
  while(fscanf(infectfile, " %d,%d,%d", 
    &Personen_ID, 
    &Name_Person, 
    &Infektionsstatus,) != EOF) 
    {
      if(Infektionsstatus == 1) {
      fprintf(infectfile,"	%d P1 [color="0.000 1.000 1.000"];\n" Personen_ID, Infektionsstatus);	
      }
    }
fprintf(newfile,"\n}"};	
	
fclose(myfile);
fclose(newfile);
fclose(infectfile);

}
	
	
#endif /* scriptwriter_h */
