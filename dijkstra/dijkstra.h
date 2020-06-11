//
//  dijkstra.h
//  PAD2-Kontaktanalyse
//
//
//

#ifndef dijkstra_h
#define dijkstra_h

/**
 *  @brief reads list of interactions, stores the interaction-time between two persons in an array and passes it on to dijsktra function
 *  @param id_1 user selects a number between 0-n. N number of generated persons
 *  @param input_path_interactions Path + file reads all saved data
 *  @param kont number of persons who interact (twice as many as interactions)
 *  @param time_matrix[kont][kont] stores the time between two persons
 *  @return returns 0 in case of success, -1 for input error
 */
int dij_array(int id_1,char * input_path_interactions, int kont, int time_matrix[kont][kont]);

/**
 *  @brief function searches every connection between the selected person (id_1) and persons potentially at risk and prints the connection with the highest time spent together
 *  @param id_1 from unser selected person
 *  @param count number of interactions
 *  @param time_matrix[count*2][count*2] stores the time between two persons
 */
void dijsktra(int id_1,int count, int time_matrix[count*2][count*2]);


#endif /* dijkstra_h */
