# Inverted-Search-Project
Inverted Search Project is a C program that builds an inverted index from multiple text files. It stores each word in a hash table along with the file names and the number of occurrences. Using hashing and linked lists, the program allows efficient creation, display, searching, saving, and updating of the database for fast word lookup across files.
Inverted Search Using Hashing (C Language)

📌 Overview:
The Inverted Search Project creates an inverted index from multiple text files.
It stores each word along with the files where it appears and the number of occurrences.
This allows fast searching of words across many files, similar to how search engines work.
The project is implemented in C using Hash Tables and Linked Lists.

🎯 Objectives
Read multiple files from the command line
Extract words from the files
Store words in a hash table
Maintain:
Word
File name
Word frequency
Allow displaying and searching of words
Allow saving and updating database

1️⃣ File Linked List
Stores the list of input files.
2️⃣ Main Node (Word Node)
Stores the word and file count.
3️⃣ Sub Node (File Node)
Stores the file name and word occurrence count.

🧠 Data Structure Diagram
Hash Table
   |
   |---- index 0
   |       |
   |       → Main Node (word: apple)
   |               |
   |               → Sub Node → file1.txt → count = 2
   |               → Sub Node → file2.txt → count = 1
   |
   |---- index 7
           |
           → Main Node (word: hi)
                   |
                   → Sub Node → file1.txt → count = 1
                   → Sub Node → file2.txt → count = 1

🧮 Hash Function
The hash table size is 27.

⚙️ Project Modules

1️⃣ File Validation
Checks:
File exists
File is not empty
Duplicate files are avoided
Functions used:
validate_files()
insert_last()
check_duplicates()

2️⃣ Create Database
Reads each word from files and stores it in the hash table.
Functions:
create_database()
load_data()
get_index()

3️⃣ Display Database
Displays all words, file names, and word counts.

5️⃣ Save Database
Stores database into a backup file.
Example format:
#7;hi;2;file1.txt;1;file2.txt;1;

🖥️ Compilation
Compile the project:
gcc main.c create.c display.c search.c save.c update.c file_validation.c -o inverted
Run the program:
./inverted file1.txt file2.txt
