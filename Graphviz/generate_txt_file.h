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
  
#ifndef scriptwriter_h
#define scriptwriter_h 
 
/**
 *  @brief Reads generated List and converts it into Graphviz script 
 *  @details Format of output file: .txt 
 *  @param input_path Path + file name of the full list of names
 *  @param input_path Path + file name of the infection list
 *  @param output_path Path + file name where to output should be saved
 *  @return Returns 0
 */
 
int create_txt(){

/**
 *  @brief Reads generated List specific time and converts it into Graphviz script from 
 *  @details Format of output file: .txt 
 *  @param input_path Path + file name of the full list of names
 *  @param input_path Path + file name of the infection list
 *  @param output_path Path + file name where to output should be saved
 *  @return Returns 0
 */

int create_txt_with_time(){

#endif /* scriptwriter_h */
