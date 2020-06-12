//
//  dijkstra.c
//  PAD2-Kontaktanalyse
//
//
//

#include<stdio.h>
#include <stdlib.h>
#include<conio.h>
#include<process.h>
#include<string.h>

int dij_array(int id_1, char * input_path_interactions, int kont,int time_matrix[kont][kont]);
void dijsktra(int id_1, int count, int time_matrix[count*2][count*2]);

int main()
{
    int kont;
    int id_1;


    printf("geben Sie die Anzahl von Personen an : ");
    scanf("%d",&kont);

    int time_matrix[kont][kont];

    printf("geben Sie sie die ID der ersten infizierten Person an: ");
    scanf("%d",&id_1);

    printf("\n\n");

    dij_array(id_1, "interactions.csv", kont, time_matrix);

    return 0;

}

int dij_array(int id_1,char * input_path_interactions, int kont, int time_matrix[kont][kont])
{


    int i,j;

    int contact;
    int person_id_1;
    int person_id_2;
    int start_time;
    int end_time;


    int tot_time=0;
    int count=0;



    // open input interactions_file
    FILE *input_file=fopen(input_path_interactions, "r");
    if(input_file == NULL)
    {
        return -1;
    }


    // initialize contact_matrix array with zero
    for (i=0; i<kont; i++)
    {
        for (j=0; j<kont; j++)
        {

            time_matrix[i][j]=0;
        }
    }



    while(fscanf(input_file,"%d; %d; %d; %d; %d", &contact, &person_id_1, &person_id_2, &start_time, &end_time)!=EOF)
    {

        tot_time=end_time-start_time;
        time_matrix[person_id_1][person_id_2]=tot_time;
        time_matrix[person_id_2][person_id_1]=tot_time;

        //printf("%d  %d\n",contact, time_matrix[person_id_1][person_id_2]);

        count++;
    }

    // number of lines of interations file
    //printf("Number of contacts %d\n",count);


    fclose(input_file);

    dijsktra(id_1, count ,time_matrix);


    return 0;

}


void dijsktra(int id_1,int count, int time_matrix[count*2][count*2])
{
    int total= count*2; // contactlist *2 = num of involve persons

    int time[total]; // Time-array
    int visited[total]; //visited nodes

    int i;
    int j;
    int id_3=0;


    for(i=0; i<=total; i++)
    {
        time[i]=0;
        visited[i]=0;
    }

  printf("[%d] ->", id_1);

    for(j=1; j<=total; j++)
    {
        for(i=1; i<total; i++)
        {
            time[i]=time[i-1];

            if(time[i]<time_matrix[id_1][i] && visited[i]==0)
            {
                id_3=i;
                time[i]=time_matrix[id_1][id_3];

            }
        }

    printf(" [%d] ->", id_3);
        //printf("Sie hatten %d Minuten miteinander Kontakt.\n\n", time[id_3]);
        visited[id_1]=1;
        visited[id_3]=1;
        id_1 = id_3;

        if(time[id_3]==0)
        {
            break;
        }

    }
    printf("\n\nLetzte infizierte Peron ID %d\n", id_3);
}
