#include <iostream>																	//davidk12
#include "List.h"																	//David Hafthor Kristinsson
#include "Node.h"

List::List()
{
	//Initializes a new empty list.
	head = NULL; 
}

List::~List()
{
	//Deletes each node in the list.
	removeAll();
}

int List::length()
{
	//Iterates through the list and raises the counter in each loop.
	int counter = 0;
	if(head != NULL)
	{
		for(NodePtr temp = head; temp != NULL; temp = temp->getLink())
		{
			counter++;
		}
	}
	return counter;
}

void List::headInsert(int the_number)
{
	NodePtr newNode = new Node();
	//If the list is empty
	if(head == NULL)
	{
		head = newNode;
	}
	else
	{
		//If the list is not empty, reconnect the nodes.
		newNode->setLink(head);
		head = newNode;
	}
	newNode->setData(the_number);
}

void List::endInsert(int the_number)
{
	NodePtr newNode = new Node();
	//If the list is empty simply make the head point to the new node.
	if(head == NULL)
	{
		head = newNode;
	}
	else
	{
		//If the list is not empty then iterate through the list
		//and connect the last node to the new node.
		NodePtr temp = head;
		for(; temp->getLink() != NULL; temp = temp->getLink()){ }
		temp->setLink(newNode);
	}
	newNode->setData(the_number);
	newNode->setLink(NULL);
}

void List::remove(int the_number)
{
	NodePtr temp = head;
	NodePtr before = NULL;
	for(; temp != NULL; temp = temp->getLink())
	{
		if(temp->getData() == the_number)
		{
			if(temp == head) 
			{
				//If it's the first node
				head = temp->getLink();
				delete temp;
				break;
			}
			else
			{
				//If the nodes are more than 1, then connect the node before the node
				//to be deleted, to the node after the node to be deleted, then delete
				//the node before.
				before->setLink(temp->getLink());
				delete temp;
				break;
			}
		}
	
		else
		{
			before = temp;
		}
	}
	before = NULL;
	temp = NULL;
}

void List::removeAll()
{
	/*
	If the list is not empty, iterate through the list and keep the node before 
	the current node, and delete the one before the current node in each iteration.
	*/
	if(head != NULL)
	{
		NodePtr nav = head;
		NodePtr before = NULL;
		while(nav != NULL)
		{
			before = nav;
			nav = nav->getLink();
			head = nav;
			delete before;
		}
		head = NULL;
	}
}

void List::reverse()
{
	/*
	Iterate through the list, keeping a pointer to the
	node after the current node in the iteration,
	then switching the pointers accordingly.
	*/
	NodePtr last = NULL;
	NodePtr nav = head;
	while (nav != NULL)
	{
		NodePtr temp = nav->getLink();
		nav->setLink(last);
		last = nav;
		nav = temp;
	}
	head = last;
}
ostream& operator <<(ostream& outs, const List& lis)
{
	//Iterates through the list and prints out each nodes data.
	for(NodePtr nav = lis.head; nav != NULL; nav = nav->getLink())
	{
		outs << nav->getData() << " ";
	}

	return outs;
}