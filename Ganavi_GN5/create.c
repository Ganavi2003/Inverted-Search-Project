#include "inverted.h"
#include <ctype.h>
#include "colors.h"

void create_database(M_node *HT[], F_node *head)
{
    while (head)
    {
        load_data(head->f_name,HT);
        head = head->link;
    }
    printf("---------------------------------------------------------------\n");
	printf(GREEN"                DATABASE CREATED SUCCESSFULLY              \n"RESET);
	printf("---------------------------------------------------------------\n");
	printf(CYAN"Now you can see tha created database by displaying!!!\n"RESET);
}
void load_data(char *f_name, M_node *HT[])
{
    FILE *fp = fopen(f_name, "r");

    if(fp == NULL)
    {
        printf(RED"Unable to open file %s\n"RESET, f_name);
        return;
    }

    char word[50];
    int index;

    while(fscanf(fp, "%s", word) != EOF)
    {
        
        index = get_index(word);

        if(HT[index] == NULL)
        {
            M_node *new = malloc(sizeof(M_node));

            strcpy(new->word, word);
            new->file_count = 1;
            new->main_link = NULL;

            S_node *sub = malloc(sizeof(S_node));
            strcpy(sub->filename, f_name);
            sub->word_count = 1;
            sub->sub_link = NULL;

            new->sub_link = sub;

            HT[index] = new;
        }
        else
        {
            M_node *mtemp = HT[index];

            while(mtemp)
            {
                if(strcmp(mtemp->word, word) == 0)
                {
                    S_node *stemp = mtemp->sub_link;

                    while(stemp)
                    {
                        if(strcmp(stemp->filename, f_name) == 0)
                        {
                            stemp->word_count++;
                            break;
                        }
                        stemp = stemp->sub_link;
                    }

                    if(stemp == NULL)
                    {
                        S_node *newsub = malloc(sizeof(S_node));

                        strcpy(newsub->filename, f_name);
                        newsub->word_count = 1;
                        newsub->sub_link = mtemp->sub_link;

                        mtemp->sub_link = newsub;
                        mtemp->file_count++;
                    }

                    break;
                }

                mtemp = mtemp->main_link;
            }

            if(mtemp == NULL)
            {
                M_node *new = malloc(sizeof(M_node));

                strcpy(new->word, word);
                new->file_count = 1;
                new->main_link = HT[index];

                S_node *sub = malloc(sizeof(S_node));
                strcpy(sub->filename, f_name);
                sub->word_count = 1;
                sub->sub_link = NULL;

                new->sub_link = sub;

                HT[index] = new;
            }
        }
    }

    fclose(fp);
}
int get_index(char *word)
{
    char ch = word[0];
    if(isalpha(ch))
        return toupper(ch) - 'A';
    else
        return 26;
}
