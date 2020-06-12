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
          printf("    || [1] - Datensatz generieren                                   ||\n");
          printf("    || [2]-  Datensatz laden                                        ||\n");
          printf("    || [3] - Verbindung zwischen zwei Personen analysieren          ||\n");
          printf("    || [4]-  Graph aus Interaktionen generieren                     ||\n");
          printf("    || [5] - Liste der infizierten Personen ausgeben                ||\n");
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

                              int count = 0;
                              do{
                                printf("Anzahl der Personen: ");
                                scanf(" %d", &n);
                              }while(count <= 0);

                              float infection_rate = 0;
                              do{
                                printf("Infektionsrate (0.0 - 1.0): ");
                                scanf(" %f", &infection_rate);
                              }while(infection_rate < 0);

                              if(generate_persons(name_file, person_file, n, infection_rate) != 0){
                                printf("Fehler beim Dateizugriff!\n\n");
                              }
                              break;

                            case 2: //INTERAKTIONEN GENERIEREN
                              printf("Name des neuen Interaktions-Datensatzes: ");
                              scanf(" %s", interaction_file);

                              int count = 0;
                              do{
                                printf("Anzahl der Interaktionen: ");
                                scanf(" %d", &count);
                              }while(count <= 0);

                              int start_time = 0;
                              do{
                                printf("Start-Zeitpunkt (in Minuten seit Epoch): ");
                                scanf(" %f", &start_time);
                              }while(start_time < 0);

                              int end_time = 0;
                              do{
                                printf("End-Zeitpunkt (in Minuten seit Epoch): ");
                                scanf(" %f", &end_time);
                              }while(end_time < 0 || (start_time >= end_time));

                              int min_time = 0;
                              do{
                                printf("Minimale Kontaktzeit (in Minuten): ");
                                scanf(" %f", &min_time);
                              }while(min_time <= 0);

                              int max_time = 0;
                              do{
                                printf("Maximale Kontaktzeit (in Minuten): ");
                                scanf(" %f", &max_time);
                              }while(max_time < 0 || (max_time < min_time));

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
                            case 1: //PERSONEN Pfad festlegen
                              printf("Pfad und Name des einzulesenden Personen-Datensatzes: ");
                              scanf(" %s", person_file);
                              printf("\n");
                              break;
                            case 2: //INTERAKTIONEN Pfad festlegen
                              printf("Pfad und Name des einzulesenden Interaktions-Datensatzes: ");
                              scanf(" %s", interaction_file);
                              printf("\n");
                              break;
                            case 3: //NAMEN Pfad festlegen
                              printf("\nPfad und Name der Namensliste (z.B. names.csv): ");
                              scanf(" %s", name_file);
                              printf("\n");
                          }

                          break;

                  case 3: printf("Verbindung zwischen zwei Personen analysieren\n");
                          break;

                  case 4: printf("Graph aus Interaktionen generieren\n");


                          int start_time = 0;
                          do{
                            printf("Start-Zeitpunkt (in Minuten seit Epoch), -1 für gesamtes Zeitfenster: ");
                            scanf(" %f", &start_time);
                          }while(start_time < -1);

                          int end_time = 0;
                          if(start_time > -1){
                            do{
                              printf("End-Zeitpunkt (in Minuten seit Epoch): ");
                              scanf(" %f", &start_time);
                            }while(n < 0 || end_time < start_time);
                          }

                          char *output_file = "";
                          printf("Name der Ausgabedatei: ");
                          scanf(" %s", output_file);

                          if(generate_txt_file(person_file, interaction_file, output_file, start_time, end_time) != 0){
                            printf("Beim generieren der Ausgabe ist ein Fehler aufgetreten!\n");
                          }
                          break;

                  case 5: printf("Liste der infizierten Personen ausgeben\n");
                          create_list_interactions(char *persons_path, char *output_path);
                          break;

                  case 6: printf("Direkte Kontakte zu einer Person anzeigen\n");
                          int create_list_interactions(char *persons_path, char *interactions_path, char *output_path, int start_timeframe, int end_timeframe)
                          break;

                  case 7: printf("Durchschnittskontaktzeit einer Person anzeigen\n");
                          int person_id = 0;
                          //print_avg_contact_time(interaction_file, person_id);
                          break;

                  case 8: printf("Statistik anzeigen\n");
                          //print_stats(person_file, interaction_file);
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
