#include "inverted.h"
#include "colors.h"

void display_database(M_node *HT[])
{
    printf("---------------------------------------------------------------\n");
    printf(PURPLE"INDEX\tWORD\tFILE_COUNT\tFILE_NAME\tWORD_COUNT\n"RESET);
    printf("---------------------------------------------------------------\n");

    for(int i = 0; i < 27; i++)
    {
        M_node *mtemp = HT[i];

        while(mtemp != NULL)
        {
            S_node *stemp = mtemp->sub_link;

            while(stemp != NULL)
            {
                if(stemp == mtemp->sub_link)
                printf("%d\t%-10s\t%d\t%-15s\t%d\n",i,mtemp->word,mtemp->file_count,stemp->filename,stemp->word_count);
                else
                printf("\t\t\t\t%-15s\t%d\n",stemp->filename,stemp->word_count);
                stemp = stemp->sub_link;
            }
            mtemp = mtemp->main_link;
        }
    }
    printf("---------------------------------------------------------------\n");
}