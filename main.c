#include <stdio.h>
#include <stdlib.h>
#include <time.h>



int main()
{
    char input[11] = "";
    char input_2[11] = "";
    char input_3[11] = "";
    int n = 10;
    int n2 = 0;
    int n3 = 0;



    do{
        if(n <= 0)
        {
            printf("Falsche Eingabe!\n\n");
        }

        printf("             Bitte waehlen Sie eine der folgenden Aktionen aus:\n\n");
        printf("             Menu:\n\n");
        printf("    || [1] - Person erstellen/bearbeiten/entfernen                  ||\n");
        printf("    || [2]-  Kontakt erstellen/bearbeiten/entfernen                 ||\n");
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
                        printf("[1] - Person erstellen\n");
                        printf("[2] - Person bearbeiten\n");
                        printf("[3] - Person entfernen\n");
                        scanf(" %s", input_2);
                        n2 = atoi(input_2);
                }while(n2 <= 0 || n2 > 3);
                        break;

                case 2: do{
                        printf("Bitte waehlen Sie eine der folgenden Aktionen aus:\n\n");
                        printf("[1] - Kontakt erstellen\n");
                        printf("[2] - Kontakt bearbeiten\n");
                        printf("[3] - Kontakt entfernen\n");
                        scanf(" %s", input_3);
                        n3 = atoi(input_3);
                }while(n3 <= 0 || n3 > 3);
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
                        break;

                default: printf("Falsche Eingabe!\n");
                }
        }
    else
    {
        printf("Falsche Eingabe!\n\n");
    }


    return 0;
}


/*
int main() {
  //[1] - Verbindung zwischen 2 Personen analysieren 
  [2] - Alle direkten Kontakte einer Person anzeigen 
  [3] - Durchschnittskontaktzeit einer Person anzeigen [4] - Statistik anzeigen 
  [5] - Liste der Personen ausgeben 
  [6] - Liste der Kontakte ausgeben 
  [7] - Person erstellen/bearbeiten/entfernen 
  [8] - Kontakt erstellen/bearbeiten/entfernen 
  [0] - Beenden
  return 0;
}
int n;
    printf("Menu:\n");
    printf("[0] - End Program\n");
    printf("[1] - Verbindung zwischen zwei Personen analysieren.\n");
    printf("[2]- Direkte Kontakte zu einer Person anzeigen\n");
    printf("[3] - Durchschnittskontaktzeit einer Person\n");
    printf("[4]- Statistik anzeigen\n");
    printf("[5] - Liste der Personen ausgeben\n");
    printf("[6] - Liste der Kontakte ausgeben\n");
    printf("[7] - Person erstellen/bearbeiten/entfernen\n");
    printf("[8] - Kontakt erstellen/bearbeiten/entfernen\n");
    
    do {
    printf("Bitte geben Sie ihre Auswahl an: ");
    scanf("%d",&n);
switch (n) {
  
      case 1: Verbindung zwischen zwei personen
      Funtkion_zweiPersonen(){
      char name1;
      char name2;
      fgets(name1);
      fgets(name2);
      erstelle Liste mit kontakten
      print Liste
      }
      case 2: Alle direkten Kontakte einer Person
      case 3: Durchschnittskontaktzeit einer Person
      case 4: Statistik anzeigen
      case 5: Liste der Personen ausgeben
       print liste 
      case 6: Liste der Kontakte ausgeben
      case 7: Person erstellen/bearbeiten/entfernen
            case1: erstellen
            case2: bearbeiten
            case3: entfernen 
      case 8: Kontakt erstellen/bearbeiten/entfernen
          case1: erstellen
          case2: bearbeiten
          case3: entfernen
      case 9: beenden
        allen speicher freigeben
        freundlich ciao sagen
        beenden 
}*/
