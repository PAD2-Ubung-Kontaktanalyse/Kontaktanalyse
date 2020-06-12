//
//  Funktion zum erzeugen von Listen 
//  die Interaktionen einer Person ausgibt
//

#ifndef generate_list_interactions_h
#define generate_list_interactions_h

/**
 *  @brief Reads generated List and converts it into new List
 *  @details Format of output file: .txt 
 *  @param persons_path Path + file name of the full list of persons
 *  @param interactions_path Path + file name of the full list of interactions
 *  @param output_path Path + file name where to output should be saved
 *  @param start_timeframe Beginning of the time frame in minutes since epoch, -1 to disable timeframe
 *  @param end_timeframe End of the time frame in minutes since epoch
 *  @return Returns 0 if successful, -1 in case of an error
 */
 
int create_list_interactions(char *persons_path, char *interactions_path, char *output_path, char *Name_zur_Analyse);

#endif /* generate_list_interactions_h */
