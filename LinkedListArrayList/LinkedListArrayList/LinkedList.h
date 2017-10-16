#pragma once

#include "stdafx.h"
#include<iostream>

struct node
{
	int number;
	node *next;
};
//Setting definitions for functions
bool isEmpty(node *head);
char menu();
void insertAsFirstElement(node *&head, node *&last, int number);
void insert(node *&head, node *&last, int number);
void remove(node *&head, node *&last);
void showlist(node *current);
//checks to see if head is empty. Returns true if it is, false if it is not
bool isEmpty(node *head)
{
	if (head == NULL)
		return true;
	else
		return false;

}
//LinkedList Menu
char menu()
{
	char choice;
	std::cout << "Menu" << std::endl;
	std::cout << "1. Add an item" <<std:: endl;
	std::cout << "2. Remove an item" << std::endl;
	std::cout << "3. Show the List" << std::endl;
	std::cout << "4. Exit" << std::endl;
	
	std::cin >> choice;

	return choice;
}
//inserts as a first element
void insertAsFirstElement(node *&head, node *&last, int number)
{
	node *temp = new node; //creates a new instance of node
	temp->number = number; //sets the number from the struct to the number from this function
	temp->next = NULL; //sets the next node from struct to null
	
	//sets both the head and last to the temp node within the insertAsFirstElement 
	head = temp;
	last = temp;

}


void insert(node *&head, node *&last, int number)
{
	//checks to see if head is empty or not, if it is,
	//runs the insertAsFirstElement function. 
	//if not, it runs the first three parts of the insertAsFirstElement function

	if (isEmpty(head))
		insertAsFirstElement(head, last, number);
	else
	{
		node *temp = new node;
		temp->number = number;
		temp->next = NULL;

		//sets previous next last values to null 
		//and points last to temp;
		last->next = temp;
		last= temp;
	}
}
void remove(node *&head, node *&last)
{
	//checks to see if head is empty, if it is, it tells the user
	//if head is the same as last, head is deleted, and head and last are se to null
	if (isEmpty(head))
		std::cout << "This list is already empty. \n" <<std:: endl;
	else if (head == last)
	{
		delete head;
		head = NULL;
		last = NULL;

	}
	else
	{
		//creates a new node set to head
		//sets head to next head and deletes the temp
		node *temp = head;
		head = head->next;
		delete temp;

	}

}

void showlist(node *current)
{//verifies if list is empty
	if (isEmpty(current))
		std::cout << "The list is empty";
	else
	{
		std::cout << "This list contains: \n";
		while (current != NULL)
		{
			std::cout << current->number << std::endl;
			current = current->next;
		}
	}
};
