#include "program.h"

int main(int argc, char* argv[])
{
	Node* pRoot = nullptr;
	int select;
	
	// Menu
	cout << "============= OPERATION LIST =============\n";
	cout << "0: print BST tree (data tree) by PREORDER\n";
	cout << "1: create and insert new student\n";
	cout << "2: search and update student's information\n";
	cout << "3: list all students in lexicographic order of name\n";
	cout << "4: list all graduated students\n";
	cout << "5: delete a student given by its code\n";


	// Main function
	while(cin >> select)
	{
		switch(select)
		{
			// Op 0: print tree by preorder
		case 0:
			{
				cout << "\nStudent list by preorder:\n";
				NLR(pRoot);
				break;
			}

			// Op 1: create and insert
		case 1:
			{
				Student new_student;
				cout << "ID: ";
				cin >> new_student.code;
				cout << "Name: ";
				cin >> new_student.name;
				cout << "Birth: ";
				cin >> new_student.birth;
				cout << "Status: ";
				cin >> new_student.status;

				Insert(pRoot, new_student);
				break;
			}

			// Op 2: search and update found student
		case 2:
			{
				char code[200];
				cout << "Found student's code: ";
				cin >> code;
				Node* res = Search(pRoot, code);
				if(res != nullptr)
				{
					cout << "Found student's information:\n";
					cout << "Student code: " << res->data.code << endl;
					cout << "Student name: " << res->data.name << endl;
					cout << "Student birth: " << res->data.birth << endl;
					cout << "Student status: " << res->data.status << endl;

					cout << "============= Update process: =============\n";
					cout << "ID: ";
					cin >> res->data.code;
					cout << "Name: ";
					cin >> res->data.name;
					cout << "Birth: ";
					cin >> res->data.birth;
					cout << "Status: ";
					cin >> res->data.status;
				}
				else
				{
					cout << "Student doesn't exist\n";
				}
				break;
			}
			// Op 3: List all students in lexicographic order of their names
		case 3:
			{
				Node** arr = new Node*[data_size];
				int n = 0;
				NLR_op3(pRoot, n, arr);
				SelSort(arr, n);

				cout << "\n============= Student list after being sorted by name: =============\n";
				for(int i = 0; i < n; i++)
				{
					cout << "Student code: " << arr[i]->data.code << endl;
					cout << "Student name: " << arr[i]->data.name << endl;
					cout << "Student birth: " << arr[i]->data.birth << endl;
					cout << "Student status: " << arr[i]->data.status << endl;
				}
				break;
			}
		case 4:
			{
				cout << "\n============= Graduated Student list: =============\n";
				NLR_op4(pRoot);
				break;
			}
		case 5:
			{
				char code[200];
				cout << "Remove student's code: ";
				cin >> code;			
				Remove(pRoot, code);
				cout << "Student is removed!\n";
				break;
			}

		}
		cout << "\nNext selection: " << endl;
	}
	return 0;
}