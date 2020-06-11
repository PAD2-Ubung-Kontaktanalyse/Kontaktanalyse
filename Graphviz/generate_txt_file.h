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
  
#ifndef generate_txt_file_h
#define generate_txt_file_h

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

#endif /* generate_txt_file_h */
