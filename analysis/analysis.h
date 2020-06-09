//
//  analysis.h
//  PAD2-Kontaktanalyse
//
//
//

#ifndef analysis_h
#define analysis_h

/**
*  @brief stores a single person
*/
typedef struct{
    char *name; /** first name of the person */
    int infected; /** 1 if person is infected, 0 if healthy */
}person;

/**
*  @brief stores a single interaction between two persons
*/
typedef struct{
    person *person0; /** pointer to the first person */
    person *person1; /** pointer to the second person */
    int start_time; /** start time of the interaction, in minutes since epoch */
    int end_time; /** end time of the interaction, in minutes since epoch */
}interaction;

#endif /* analysis_h */
