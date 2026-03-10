#include "inverted.h"
#include "colors.h"
int update_database(M_node *HT[], F_node **head)
{
    char new_file[20];
    int insert_ret,dup_ret;

    printf("Enter the new file name\n");
    scanf("%s",new_file);

    int ret = validate_files(new_file, head);

    if(ret == SUCCESS)
    {
        insert_ret = insert_last(head,new_file);
        if(insert_ret != SUCCESS)
        {
            printf(RED"Inserting filename not possible\n"RESET);
            return FAILURE;
        }
	    dup_ret = check_duplicates(*head,new_file);
        if(dup_ret != SUCCESS)
        {
            printf(RED"Duplicate file name found\n"RESET);
            return FAILURE;
        }
        if(insert_ret == dup_ret == SUCCESS)
        {
            load_data(new_file,HT);
            printf("---------------------------------------------------------------\n");
	        printf(GREEN"                DATABASE UPDATED SUCCESSFULLY              \n"RESET);
	        printf("---------------------------------------------------------------\n");
	        printf(CYAN"Now you can see tha updated database by displaying!!!\n"RESET);
        }
    }
    else
    {
        printf(RED"Given file is not valid!!!!\n"RESET);
        return FAILURE;
    }
}
