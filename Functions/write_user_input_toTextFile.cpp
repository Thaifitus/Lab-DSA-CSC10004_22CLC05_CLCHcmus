#include <iostream>
#include <string.h>

using namespace std;

FILE *fptr = NULL;
/*
Write to file function
*/
void write_file(void* file_name) {
	// Convert file's name to char
	char *w_file = NULL;
    w_file = (char*)file_name;

    // Open text file in writing mode
    fptr = fopen(w_file, "w");
    // Exit if cannot open file
    if(fptr == NULL)
    {
        printf("Cannot open to write file");
        exit(1);
    }

    // Write to file
        char input[100];
        while(cin.getline(input,sizeof(input)))
        {
            fprintf(fptr, "%s\n", input);
        }
    
    // Close file
    fclose(fptr);
}

int main()
{
	char* file_name = "data.txt";
	write_file(file_name);
	return 0;
}