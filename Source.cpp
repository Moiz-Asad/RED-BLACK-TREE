#include<iostream>
#include"RedBlackTree.h"
using namespace std;
void Logo()
{
	cout << "\t\t========================================="<<endl;
	cout << "\t\t|             RED BLACK TREE            |" << endl;
	cout << "\t\t=========================================" << endl;
	cout << "\t\t        |        WELCOME        |        " << endl;
	cout << "\t\t        =========================        " << endl << endl;
}
int Menu()
{
	cout << "\t\t         ======================" << endl;
	cout << "\t\t         |        MENU        |" << endl;
	cout << "\t\t         ======================" << endl << endl;
	int choice = 0;
	cout << "\t\tPress 1 to insert values in the tree" << endl;
	cout << "\t\tPress 2 to delete a value from the tree" << endl;
	cout << "\t\tPress 3 for searching a value from the tree" << endl;
	cout << "\t\tPress 4 for pre - order traversal NLR" << endl;
	cout << "\t\tPress 5 for in - order traversal LNR" << endl;
	cout << "\t\tPress 6 for post - order traversal LRN" << endl;
	cout << "\t\tPress 7 for pre - order traversal 2 NRL" << endl;
	cout << "\t\tPress 8 for in - order traversal 2 RNL" << endl;
	cout << "\t\tPress 9 for post - order traversal 2 RLN" << endl;
	cout << "\t\tPress 10 to destroy the tree(all nodes must be deleted)" << endl;
	cout << "\t\tPress 11 to delete all values in the tree greater than X" << endl;
	cout << "\t\tPress 12 for displaying parent of a node present in Tree" << endl;
	cout << "\t\tPress 13 to read integer values from the file “input.txt”" << endl;
	cout << "\t\tPress 14 to delete all duplicate values from the tree" << endl;
	cout << "\t\tPress 15 to create copy of the tree" << endl;
	cout << "\t\tPress 16 to destroy the complete tree" << endl;
	cout << "\t\tPress 17 to EXIT" << endl;
	cout << "\t\tChoice : ";
	cin >> choice;
	return choice;
}
void MenuSystem()
{
	int choice = 0;
	RedBlackTree Tree;
	do
	{
		choice = Menu();
		if (choice == 1)
		{
			char c;
			int V=0;
			do
			{
				cout << "\t\t";
				cout << "Enter Value To Insert : ";
				cin >> V;

				Tree.Insert(V);
				cout << "\t\t";
				cout << "You want to Enter another value Y|y , N|n : ";
				cin >> c;
				if (c == 'N' || c == 'n')
				{
					break;
				}
				
			}while (true);
		}
		else
		if (choice == 2)
		{
			int c = 0;
			cout << "\t\t\t";
			cout << "Enter a Value To Delete : ";
			cin >> c;
			Tree.DeleteNode(c);
		}
		else
		if (choice == 3)
		{
			int c = 0;
			cout << "\t\t\t";
			cout << "Enter a Value you wamt to search in RBT : ";
			cin >> c;
			if (Tree.IsExist(c))
			{
				cout << "\t\t\t";
				cout << c << " Found in RBT." << endl;
			}
			else
			{
				cout << "\t\t\t";
				cout << c << " does exist in RBT." << endl;
			}
		}
		else
		if (choice == 4)
		{
			cout << endl;
			Tree.PreOrder();
		}
		else
		if (choice == 5)
		{
			cout << endl;
			Tree.InOrder();
		}
		else
		if (choice == 6)
		{
			cout << endl;
			Tree.PostOrder();
		}
		else
		if (choice == 7)
		{
			cout << endl;
			Tree.PreOrder(false);
		}
		else
		if (choice == 8)
		{
			cout << endl;
			Tree.InOrder(false);
		}
		else
		if (choice == 9)
		{
			cout << endl;
			Tree.PostOrder(false);
		}
		else
		if (choice == 10)
		{
			cout << "\t\t";
			Tree.DestroyAllNodes();
			cout << "Tree Completly Destroyed Success!" << endl;
		}
		else
		if (choice == 11)
		{
			int a = 0;
			cout << "\t\t";
			cout << "Enter a Value to Delete Greater Nodes : ";
			cin >> a;
			Tree.DeleteGreaterVal(a);
		}
		else
		if (choice == 12)
		{
			int a = 0;
			cout << "\t\t";
			cout << "Enter a Value to get its Parent : ";
			cin >> a;
			Tree.ParentDisplay(a);
		}
		else
		if (choice == 13)
		{
			string Fname = "input.txt";
			Tree.ReadTree(Fname);
		}
		else
		if (choice == 14)
		{
			Tree.AllDupRemover();
		}
		else
		if (choice == 15)
		{
			RedBlackTree Tcopy(Tree);
			cout << "\t\tSuccessfully Copied!";
			cout << "\t\tSource Tree. " << endl;
			Tree.InOrder();
			cout << "\t\tDestination Tree" << endl;
			Tcopy.InOrder();
		}
		else
		if (choice == 16)
		{
			cout << "\t\t";
			Tree.DestroyAllNodes();
			cout << "Tree Destroyes Success" << endl;
		}
		else
		if (choice == 17)
		{
			break;
		}
	} 
	while (true);
}
int main()
{
	
	Logo();
	MenuSystem();
	return 0;
}