#include <stdio.h>
#include <stdlib.h>
#include <time.h>

   

int main()
{
    int n = 0;
    int n2 = 0;
    int n3 = 0;


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

        scanf("%d", &n);


if(isdigit(n) >= 0)
    {
        switch(n)
            {

            case 1: printf("Bitte waehlen Sie eine der folgenden Aktionen aus:\n\n");
                    printf("[1] - Person erstellen\n");
                    printf("[2] - Person bearbeiten\n");
                    printf("[3] - Person entfernen\n");
                    scanf("%d", &n2);
                    break;
                
            case 2: printf("Bitte waehlen Sie eine der folgenden Aktionen aus:\n\n");
                    printf("[1] - Kontakt erstellen\n");
                    printf("[2] - Kontakt bearbeiten\n");
                    printf("[3] - Kontakt entfernen\n");
                    scanf("%d", &n3);
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
