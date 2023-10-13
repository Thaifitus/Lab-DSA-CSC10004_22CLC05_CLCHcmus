#include <iostream>
#include <string.h>

using namespace std;

struct Node{
	Node* pLeft;
	Node* pRight;
	char data[201];
};

Node* Search(Node* &pRoot, char* x)
{
    if(pRoot == NULL)
        return nullptr;

    if(strcmp(pRoot->data, x) == 0)
        return pRoot;
    else if(strcmp(pRoot->data, x) > 0)
        return Search(pRoot->pLeft, x);
    else
        return Search(pRoot->pRight, x);
}
Node* createNode(char* data)
{
	Node* temp = new Node;
	temp->pLeft = NULL;
	temp->pRight = NULL;
	strcpy(temp->data, data);
	return temp;
}
void Insert(Node* &pRoot, char* x)
{
	if(pRoot == NULL)
		pRoot = createNode(x);

	if(strcmp(pRoot->data, x) == 0)
		return;
	else if(strcmp(pRoot->data, x) > 0)
	{
		Insert(pRoot->pLeft, x);
	}
	else
		Insert(pRoot->pRight, x);
}
void NLR(Node* pRoot)
{
	if(pRoot == NULL)
		return;

	cout << pRoot->data << " ";
	if(pRoot->pLeft != NULL)
	{
		NLR(pRoot->pLeft);
	}
	if(pRoot->pRight != NULL)
	{
		NLR(pRoot->pRight);
	}
	return;
}
void LRN(Node* pRoot)
{
	if(pRoot == NULL)
		return;

	if(pRoot->pLeft != NULL)
	{
		LRN(pRoot->pLeft);
	}
	if(pRoot->pRight != NULL)
	{
		LRN(pRoot->pRight);
	}
	cout << pRoot->data << " ";
	return;
}
void LNR(Node* pRoot)
{
	if(pRoot == NULL)
		return;

	if(pRoot->pLeft != NULL)
	{
		LNR(pRoot->pLeft);
	}
	cout << pRoot->data << " ";
	if(pRoot->pRight != NULL)
	{
		LNR(pRoot->pRight);
	}
	return;
}

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
	char* file_name = "input.txt";
	// read_file(file_name);

	return 0;
}