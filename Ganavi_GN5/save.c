#include "inverted.h"
#include "colors.h"
void save_database(M_node *HT[])
{
    char save_file[20];
    printf("Enter the file name where we have to store data: \n");
    scanf("%s",save_file);
    
    FILE *fp = fopen(save_file, "w");
    if(fp == NULL)
    {
        printf(RED"Unable to open file %s\n"RESET, save_file);
        return;
    }

    for(int i = 0; i < 27; i++)
    {
        M_node *mtemp = HT[i];
        if(HT[i] == NULL)
        continue;

        while(mtemp != NULL)
        {
            S_node *stemp = mtemp->sub_link;

            while(stemp != NULL)
            {
                fprintf(fp, "$%d::%s::%d::%s::%d$\n",i,mtemp->word,mtemp->file_count,stemp->filename,stemp->word_count);
                stemp = stemp->sub_link;
            }
            mtemp = mtemp->main_link;
        }
    }
    printf("---------------------------------------------------------------\n");
	printf(GREEN"                DATABASE SAVED SUCCESSFULLY              \n"RESET);
	printf("---------------------------------------------------------------\n");
    fclose(fp);
}   
