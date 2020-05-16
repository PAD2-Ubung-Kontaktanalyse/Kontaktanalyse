#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n = 0;
    
    printf("Bitte waehlen Sie eine der folgenden Aktionen aus:\n");
    printf("             Menu:\n\n");
    printf("    || [1] - Verbindung zwischen zwei Personen analysieren          ||\n");
    printf("    || [2]-  Direkte Kontakte zu einer Person anzeigen              ||\n");
    printf("    || [3] - Durchschnittskontaktzeit einer Person                  ||\n");
    printf("    || [4]-  Statistik anzeigen                                     ||\n");
    printf("    || [5] - Liste der Personen ausgeben                            ||\n");
    printf("    || [6] - Liste der Kontakte ausgeben                            ||\n");
    printf("    || [7] - Person erstellen/bearbeiten/entfernen                  ||\n");
    printf("    || [8] - Kontakt erstellen/bearbeiten/entfernen                 ||\n");
    printf("    || [0] - Programm beenden                                       ||\n");

    scanf("%d", &n);

    switch(n) {
	case 1: printf("Verbindung zwischen zwei Personen analysieren\n");
	break;
	case 2: printf("Direkte Kontakte zu einer Person anzeigen\n");
	break;
    case 3: printf("Durchschnittskontaktzeit einer Person\n");
	break;
	case 4: printf("Statistik anzeigen\n");
	break;
	case 5: printf("Liste der Personen ausgeben\n");
	break;
    case 6: printf("Liste der Kontakte ausgeben\n");
	break;
	case 7: printf("Person erstellen/bearbeiten/entfernen");
	break;
	case 8: printf("Kontakt erstellen/bearbeiten/entfernen");
	break;
	case 0: printf("Programm beenden");
	break;
	default: printf("Falsche Eingabe!\n");
}


    return 0;
}





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
}
