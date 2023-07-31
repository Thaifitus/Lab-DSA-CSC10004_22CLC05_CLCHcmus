#ifndef _program_
#define _program_

#include <iostream>
#include <string.h>

using namespace std;

const int data_size = 200;
struct Student{
	char code[data_size];
	char name[data_size];
	char birth[data_size];
	int status;
};
struct Node{
	Student data;
	Node* pLeft;
	Node* pRight;
};

// Print tree by preorder
void NLR(Node* pRoot);

// Operation 1
Node* CreateNode(Student data);
void Insert(Node* &pRoot, Student data);

// Operation 2
Node* Search(Node* &pRoot, char* code);

// Operation 3: list all students in lexicographic order of their names
void NLR_op3(Node* pRoot, int &i, Node** arr);
void SelSort(Node** &arr, int n);

// Operation 4: list all graduated students
void NLR_op4(Node* pRoot);

// Operation 5: delete a student given by its code
void Remove(Node* &pRoot, char* code);


#endif