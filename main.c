#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "generator/generator.h"
#include "Graphviz/generate_txt_file.h"
#include "analysis/analysis.h"


char *name_file = "names.csv";
char *person_file = "";
char *interaction_file = "";

int main()
{
    char input[11] = "";
    char input_2[11] = "";
    char input_3[11] = "";
    int n = 10;
    int n2 = 0;
    int n3 = 0;

    while(1){ //endless loop for menu

      do{
          if(n <= 0)
          {
              printf("Falsche Eingabe!\n\n");
          }

          printf("             Bitte waehlen Sie eine der folgenden Aktionen aus:\n\n");
          printf("             Menu:\n\n");
          printf("    || [1] - Datensatz generieren                                    ||\n");
          printf("    || [2]-  Datensatz laden                                    ||\n");
          printf("    || [3] - Verbindung zwischen zwei Personen analysieren          ||\n");
          printf("    || [4]-  Liste der Personen ausgeben                            ||\n");
          printf("    || [5] - Liste der Kontakte ausgeben                            ||\n");
          printf("    || [6] - Direkte Kontakte zu einer Person anzeigen              ||\n");
          printf("    || [7] - Durchschnittskontaktzeit einer Person anzeigen         ||\n");
          printf("    || [8] - Statistik anzeigen                                     ||\n");
          printf("    || [9] - Programm beenden                                       ||\n");


          scanf(" %s", input);
          n = atoi(input);

      }while(n <= 0 || n > 9);


          if(n >= 1 && n <= 9)
          {
              switch(n)
                  {

                  case 1: do{
                          printf("Bitte waehlen Sie eine der folgenden Aktionen aus:\n\n");
                          printf("[0] - Zurück zum Hauptmenue\n");
                          printf("[1] - Liste mit Personen generieren\n");
                          printf("[2] - Liste mit Interaktionen generieren\n");
                          scanf(" %s", input_2);
                          n2 = atoi(input_2);
                  }while(n2 < 0 || n2 > 2);
                          switch (n2) {
                            case 0: //ZURUECK
                              break;

                            case 1: //PERSONEN GENERIEREN
                              printf("\nName des neuen Personen-Datensatzes: ");
                              scanf(" %s\n", person_file);

                              int n = 0;
                              do{
                                printf("Anzahl der Personen: ");
                                scanf(" %d", &n);
                              }while(n <= 0);

                              float infection_rate = 0;
                              do{
                                printf("Infektionsrate (0.0 - 1.0): ");
                                scanf(" %f", &infection_rate);
                              }while(n <= 0);

                              if(generate_persons(name_file, person_file, n, infection_rate) != 0){
                                printf("Fehler beim Dateizugriff!\n\n");
                              }
                              break;

                            case 2: //INTERAKTIONEN GENERIEREN
                              printf("\nName des neuen Interaktions-Datensatzes: ");
                              scanf(" %s\n", interaction_file);

                              int n = 0;
                              do{
                                printf("Anzahl der Interaktionen: ");
                                scanf(" %d", &n);
                              }while(n <= 0);

                              int start_time = 0;
                              do{
                                printf("Start-Zeitpunkt (in Minuten seit Epoch): ");
                                scanf(" %f", &start_time);
                              }while(n < 0);

                              int end_time = 0;
                              do{
                                printf("End-Zeitpunkt (in Minuten seit Epoch): ");
                                scanf(" %f", &end_time);
                              }while(n < 0 || (start_time >= end_time));

                              int min_time = 0;
                              do{
                                printf("Minimale Kontaktzeit (in Minuten): ");
                                scanf(" %f", &min_time);
                              }while(n <= 0);

                              int max_time = 0;
                              do{
                                printf("Maximale Kontaktzeit (in Minuten): ");
                                scanf(" %f", &max_time);
                              }while(n < 0 || (max_time < min_time));

                              if(generate_interactions(person_file, interaction_file, n, start_time, end_time, min_time, max_time) != 0){
                                printf("Fehler beim Dateizugriff!\n\n");
                              }
                            break;
                          }
                          break;

                  case 2: do{
                          printf("Bitte waehlen Sie eine der folgenden Aktionen aus:\n\n");
                          printf("[0] - Zurück zum Hauptmenue\n");
                          printf("[1] - Datensatz mit Personen laden\n");
                          printf("[2] - Datensatz mit Kontakten laden\n");
                          printf("[3] - Namensliste laden\n")
                          scanf(" %s", input_3);
                          n3 = atoi(input_3);
                  }while(n3 < 0 || n3 > 3);
                          switch(n3){
                            case 0: //ZURUECK
                              break;
                            case 1:
                              printf("Pfad und Name des einzulesenden Personen-Datensatzes: ");
                              scanf(" %s", person_file);
                              printf("\n");
                              break;
                            case 2:
                              printf("Pfad und Name des einzulesenden Interaktions-Datensatzes: ");
                              scanf(" %s", interaction_file);
                              printf("\n");
                              break;
                            case 3:
                              printf("\nPfad und Name der Namensliste (z.B. names.csv): ");
                              scanf(" %s\n", name_file);
                              printf("\n");
                          }

                          break;

                  case 3: printf("Verbindung zwischen zwei Personen analysieren\n");
                          break;

                  case 4: printf("Liste der Personen ausgeben\n");

                          break;

                  case 5: printf("Liste der Kontakte ausgeben\n");
                          break;

                  case 6: printf("Direkte Kontakte zu einer Person anzeigen\n");
                          break;

                  case 7: printf("Durchschnittskontaktzeit einer Person anzeigen\n");
                          break;

                  case 8: printf("Statistik anzeigen\n");
                          break;

                  case 9: printf("Programm beenden\n");
                          exit(EXIT_SUCCESS);
                          break;

                  default: printf("Falsche Eingabe!\n");
                  }
          }
      else
      {
          printf("Falsche Eingabe!\n\n");
      }

    }
    return 0;
}
