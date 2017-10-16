/* Stephen Brittain
ArrayList and LinkedList Practice
*/
#ifndef ARRAYLIST_H

#endif // !ARRAYLIST_H

#include "stdafx.h"
#include <string>
#include <iomanip>
#include <array>
#include <iostream>
#include "LinkedList.h"
#include "ArrayList.h"

#include <time.h>
#include <stdlib.h>
#include <string>



using namespace std;


int main()
{
	char mainChoice;
	cout << "Please Select 'L' for Linked List or 'A' for Array List:  " << endl;
	cin >> mainChoice;

	switch (mainChoice)
	{
		
	case'L':
	//********LINKED LIST IMPLEMENTATION**********
	{
	char choice;
	int number;
	node *head = NULL;
	node *last = NULL;

	do {
		choice = menu();

		switch (choice)
		{

		case'1':
		{cout << "Please Enter a Number:  ";
		cin >> number;
		insert(head, last, number); }
		break;

		case'2':
		{remove(head, last); }
		break;
		case'3':
		{showlist(head); }
		break;
		case '4':
		{cout << "System Exit "; }
		break;
		}
	} while (choice != '4');
	}
	case 'A':
		//*******ArrayList********
		arrayList<int> itemList;
			
		itemList.add(15);
		itemList.add(54);
		itemList.add(78);

		
	}
	}

	
	
	


	
	



