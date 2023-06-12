#include <iostream>
#include <string.h>

using namespace std;

FILE *fptr = NULL;
/*
Read file function
*/
void read_file(void* file_name) {
	// Convert file's name to char
	char* r_file = NULL;
	r_file = (char*)file_name;

	// Open text file in reading mode
	fptr = fopen(r_file, "r");
	// Exit if cannot open file
	if(fptr == NULL)
	{
		printf("Cannot open to read file");
		exit(1);
	}

	char file_content[201];
	// Read file
	while(fgets(file_content, sizeof(file_content), fptr))
	{
		cout << file_content;
	}

	// Close file
	fclose(fptr);
}


int main()
{
	char* file_name = "data.txt";
	read_file(file_name);

	return 0;
}