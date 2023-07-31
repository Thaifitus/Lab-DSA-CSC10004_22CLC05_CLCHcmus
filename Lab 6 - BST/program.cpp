#include "program.h"

void NLR(Node* pRoot)
{
	if(pRoot == nullptr)
		return;

	cout << "Student code: " << pRoot->data.code << endl;
	cout << "Student name: " << pRoot->data.name << endl;
	cout << "Student birth: " << pRoot->data.birth << endl;
	cout << "Student status: " << pRoot->data.status << endl;
	
	if(pRoot->pLeft != nullptr)
	{
		NLR(pRoot->pLeft);
	}
	if(pRoot->pRight != nullptr)
	{
		NLR(pRoot->pRight);
	}
	return;
}

Node* CreateNode(Student data)
{
	Node* temp = new Node;
	temp->pLeft = nullptr;
	temp->pRight = nullptr;

	strcpy(temp->data.code, data.code);
	strcpy(temp->data.name, data.name);
	strcpy(temp->data.birth, data.birth);
	temp->data.status = data.status;
	
	return temp;

}
void Insert(Node* &pRoot, Student data)
{
	if(pRoot == nullptr)
		pRoot = CreateNode(data);

	if(strcmp(pRoot->data.code, data.code)==0)
		return;
	else if(strcmp(pRoot->data.code, data.code)>0)
		Insert(pRoot->pLeft, data);
	else
		Insert(pRoot->pRight, data);
}

Node* Search(Node* &pRoot, char* code)
{
    if(pRoot == nullptr)
        return nullptr;

	if(strcmp(pRoot->data.code, code)==0)
		return pRoot;
	else if(strcmp(pRoot->data.code, code)>0)
		Search(pRoot->pLeft, code);
	else
		Search(pRoot->pRight, code);
}

void NLR_op3(Node* pRoot, int &i, Node** arr)
{
	if(pRoot == nullptr)
		return;

	arr[i++] = pRoot;

	if(pRoot->pLeft != nullptr)
	{
		NLR_op3(pRoot->pLeft, i, arr);
	}
	if(pRoot->pRight != nullptr)
	{
		NLR_op3(pRoot->pRight, i, arr);
	}
	return;

}
void SelSort(Node** &arr, int n)
{
	int max;
	for(int i = n - 1; i > 0; i--)
	{
		max = i;
		for(int j = i - 1; j >= 0; j--)
		{
			if(strcmp(arr[j]->data.name, arr[max]->data.name)>0)
				max = j;
		}
		Node* temp = arr[max];
		arr[max] = arr[i];
		arr[i] = temp;
	}
}

void NLR_op4(Node* pRoot)
{
	if(pRoot == nullptr)
		return;
	if(pRoot->data.status == 1)
	{
		cout << "Student code: " << pRoot->data.code << endl;
		cout << "Student name: " << pRoot->data.name << endl;
		cout << "Student birth: " << pRoot->data.birth << endl;
		cout << "Student status: " << pRoot->data.status << endl;
	}

	if(pRoot->pLeft != nullptr)
	{
		NLR_op4(pRoot->pLeft);
	}
	if(pRoot->pRight != nullptr)
	{
		NLR_op4(pRoot->pRight);
	}
	return;
}

void Remove(Node* &pRoot, char* code)
{
	if(pRoot == nullptr)
		return;
	if(strcmp(pRoot->data.code, code)<0)
	{
		Remove(pRoot->pRight, code);
	}
	else if(strcmp(pRoot->data.code, code)>0)
	{
		Remove(pRoot->pLeft, code);
	}
	else
	{
		if(pRoot->pLeft == nullptr && pRoot->pRight == nullptr)
		{
			delete pRoot;
			pRoot = nullptr;
		}
		else if(pRoot->pRight == nullptr && pRoot->pLeft != nullptr)
		{
			pRoot = pRoot->pLeft;
		}
		else if(pRoot->pRight != nullptr && pRoot->pLeft == nullptr)
		{
			pRoot = pRoot->pRight;
		}
		else if(pRoot->pLeft != nullptr && pRoot->pRight != nullptr) // most-pRight Node of pLeft subtree
		{
			Node* temp = pRoot->pLeft;
			while(temp->pRight != nullptr)
				temp = temp->pRight;
			strcpy(pRoot->data.code, temp->data.code);
			strcpy(pRoot->data.name, temp->data.name);
			strcpy(pRoot->data.birth, temp->data.birth);
			pRoot->data.status = temp->data.status;

			Remove(pRoot->pLeft, temp->data.code);
		}
	}
}
