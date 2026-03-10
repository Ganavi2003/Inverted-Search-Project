#include "inverted.h"
#include "colors.h"
void search_database(M_node *HT[])
{
    char word[20];
    printf("Enter the word you want to search: ");
    scanf("%s",word);

    printf("---------------------------------------------------------------\n");
    for(int i = 0; i < 27; i++)
    {
        M_node *mtemp = HT[i];
        while(mtemp != NULL)
        {
            if(strcmp(word, mtemp->word) == 0)
            {
                printf(CYAN"                  WORD \"%s\" FOUND AT INDEX %d       "RESET, word, i);
                printf("\n---------------------------------------------------------------\n");
                printf("Found in %d files\n", mtemp->file_count);

                S_node *stemp = mtemp->sub_link;
                while(stemp != NULL)
                {
                    printf(CYAN"File: "RESET);
                    printf("%s  -> Word Count: %d\n",
                           stemp->filename,
                           stemp->word_count);

                    stemp = stemp->sub_link;
                }
                printf("---------------------------------------------------------------\n");
                return;
            }
            mtemp = mtemp->main_link;
        }
    }

    printf(RED"Word \"%s\" not found in database\n"RESET, word);
    printf("---------------------------------------------------------------\n");
}
