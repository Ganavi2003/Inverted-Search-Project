#include "inverted.h"
#include "colors.h"
int main(int argc, char *argv[])
{
    F_node *head = NULL;
    M_node *HT[27];
    for (int i = 0; i < 27; i++)
	{
		HT[i] = NULL;
	}
	
    // Validate_files
	if(argc == 1)
	{
	    printf(RED"ERROR: Invalid number of arguments passed!!\n"RESET);
		return 0;
	}

	int i = 1,ret1,ret2;
	while(i < argc)
	{
		int ret = validate_files(argv[i], &head);
		if(ret == SUCCESS)
		{
			printf("---------------------------------------------------------------\n");
			printf(GREEN"                 VALIDATION DONE FOR %s:               \n"RESET,argv[i]);
			printf("---------------------------------------------------------------\n");

			ret1 = insert_last(&head,argv[i]);
			ret2 = check_duplicates(head,argv[i]);
		    if(ret1 == ret2 == SUCCESS)
			{
				printf("file %s is added to list\n",argv[i]);
			}
		    else{
				printf(RED"VALIDATION FAILED!!!\n"RESET);
				return 0;
			}
		}
		else{
			printf(RED"VALIDATION FAILED\n"RESET);
			return 0;
		}
		i++;
	}

	printf("---------------------------------------------------------------\n");
	printf(PURPLE"                 LINKED LIST CREATED FOR FILES:                   \n"RESET);
	printf("---------------------------------------------------------------\n");
	print_filenames(&head);
	printf("---------------------------------------------------------------\n");

    int option;
    do
    {
	printf(BBLACK "Select your choice among following operations:\n"RESET);
	printf("1. Create Database\n2. Display Database\n3. Save Database\n4. Search\n5. Update Database\n6. Exit\n");
	printf(BGREEN"Enter your choice : "RESET);

	scanf("%d", &option);

	switch (option)
	{
	    case 1:
		create_database(HT, head);
		break;

	    case 2:
		display_database(HT);
		break;

	    case 3:
		save_database(HT);
		break;

	    case 4:
		search_database(HT);
		break;

	    case 5:
		update_database(HT, &head);
		break;

	    case 6:
		printf(RED"EXITTING!!!.....\n"RESET);
		break;

	    default:
		printf("INFO : Please enter the valid option\n");
	}
    }while( option != 6 );

    return 0;
}
