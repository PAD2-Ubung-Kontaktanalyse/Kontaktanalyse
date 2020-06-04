//
//  generator.h
//  PAD2-Kontaktanalyse
//
//
//

#ifndef generator_h
#define generator_h

/**
 *  @brief Reads list of names from a text file, randomly generates persons and family stuctures, and saves the output in a text file
 *  @details Format of output file: person-id | name | family-id | infection-status
 *  @param input_path Path + file name of the full list of names
 *  @param output_path Path + file name where to output should be saved
 *  @param n Number of persons to generate
 *  @param infection_rate Probability for a person to be flagged "infected". Range: [0-1]
 *  @return Returns 0 in case of sucess, -1 for input error, -2 for output error
 */
int generate_persons(char * input_path, char * output_path, int n, float infection_rate);

/**
 *  @brief Reads list of persons from a text file, randomly generates interactions, and saves the output in a text file
 *  @details Format of output file: interaction-id | person1-id | person2-id | start-time | end-time
 *  @param input_path Path + file name of the full list of names
 *  @param output_path Path + file name where to output should be saved
 *  @param n Maximum number of interactions to generate (0 for unlimited)
 *  @param start_time Start of the time frame for all interactions in minutes since epoch
 *  @param end_time End of the time frame for all interactions in minutes since epoch
 *  @param min_time Minimum time span of an interaction in minutes
 *  @param max_time Maximum time span of an interaction in minutes
 *  @param min_interactions Minimum number of interactions with persons outside the family
 *  @param max_interactions Maximum number of interactions with persons outside the family
 *  @return Returns 0 in case of sucess, -1 for input error, -2 for output error
 */
int generate_interactions(char * input_path, char * output_path, int n, int start_time, int end_time, int min_time, int max_time, int min_interactions, int max_interactions);

/**
 *  @brief Counts the number of lines of a file
 *  @param input_file Pointer to input file stream
 *  @return Number of lines
 */
int line_count(FILE * input_file);


#endif /* generator_h */
