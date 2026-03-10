#include "inverted.h"
#include "colors.h"

/* Function definitions */
int validate_files(char *filename, F_node **head)
{
    if (strstr(filename, ".txt") == NULL)
    {
        printf(RED"ERROR: Invalid filename\n"RESET);
        return FAILURE;
    }
    open_files(filename);
    return SUCCESS;
}

int open_files(char *file_name)
{
    FILE *fp = fopen(file_name, "r");
    if (fp == NULL)
    {
    	perror("fopen");
    	fprintf(stderr,RED "ERROR: Unable to open file %s\n"RESET, file_name);
        return FAILURE ;
    }
    if(fp != NULL)
    {
        fseek(fp,0,SEEK_END);
        long int  pos = ftell(fp);
        if(pos == 0)
        {
            printf(RED"There is no contents in file\n"RESET);
            return FAILURE;
        }
        rewind(fp);
    }
    return SUCCESS;
}

int insert_last(F_node **head, char *f_name)
{
    F_node *new = malloc(sizeof(F_node));
    strcpy(new->f_name, f_name);
    new->link = NULL;

    if(*head == NULL)
    {
        *head = new;
    }
    else{
        F_node *tem = *head;
        while (tem->link != NULL)
        {
            tem = tem->link;
        }
        tem->link = new;
    }
    return SUCCESS;
}

int print_filenames(F_node **head)
{
	if (*head == NULL)
	{
		printf(RED"INFO : List is empty\n"RESET);
        return FAILURE;
	}
    else
    {
        F_node *tem = *head;
	    while (tem)		
	    {
		    printf("%s -> ", tem->f_name);
		    tem = tem->link;
	    }

	    printf("NULL\n");
    }
    return SUCCESS;
}

int check_duplicates(F_node *head, char *f_name){
    F_node *temp = head;
    while (temp->link != NULL)
    {
        if(strcmp(temp->f_name, f_name) == 0)
        {
            return FAILURE;   
        }
        temp = temp->link;
    }
    return SUCCESS;
}
