#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include "Layer.h"
#include <Windows.h>
template<class T>
class Node
{
public:
	Node();
	Node(T data, Node<T>* nextNode, Node<T>* prevNode);
	T data;
	Node<T>* prevNode;
	Node<T>* nextNode;
};

template<class T>
Node<T>::Node()
{
	this->nextNode = nullptr;
	this->prevNode = nullptr;
	this->thisNode = nullptr;
}

template<class T>
Node<T>::Node(T data, Node<T>* nextNode, Node<T>* prevNode)
{
	this->data = data;
	this->nextNode = nextNode;
	this->prevNode = prevNode;
}

template<class T>
class LinkedList
{
public:
	LinkedList();
	LinkedList(Node<T>* head);
	~LinkedList();
	Node<T>* head;
	Node<T>* tail;
	void push_back(T val);
	int getSize();
	void printPicture();
private:
	int size;
};

template<class T>
int LinkedList<T>::getSize()
{
	return this->size;
}

template<class T>
LinkedList<T>::LinkedList()
{
	this->head = nullptr;
	this->tail = nullptr;
	this->size = 0;
}

template<class T>
LinkedList<T>::LinkedList(Node<T>* head)
{
	this->head = head;
	this->tail = head;
	this->size = 0;
}

template<class T>
void LinkedList<T>::push_back(T val)
{
	if (this->head == nullptr && this->tail == nullptr)
	{
		Node<T>* newNode = new Node<T>(val, nullptr, nullptr);
		this->tail = newNode;
		this->head = newNode;
	}
	else
	{
		Node<T>* newNode = new Node<T>(val, nullptr, this->tail);
		Node<T>* tempPrev = this->tail;
		this->tail->nextNode = newNode;
		this->tail = this->tail->nextNode;
		this->tail->prevNode = tempPrev;
	}
	size++;
}

#define xxPrintWhiteTextOnBlackBackground SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x07);
#define xxPrintPinkTextonBlackBackGround SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x50 | 0x07);
template<class T>
void LinkedList<T>::printPicture()
{
	if (this->size == 0)
	{
		return;
	}
	
	for (int iLength = 0; iLength < LENGTH; iLength++)
	{
		if (iLength > 0) std::cout << std::endl;
		for (int iWidth = 0; iWidth < WIDTH; iWidth++)
		{
			bool printed = false;
			Node<T>* currentNode = this->head;
			while (!printed)
			{
				//yeah have to actually do the young casting here
				//will break if it is not a layer
				switch (((Layer)currentNode->data).imageData[iLength][iWidth])
				{
					case 0:
					{
						//todo black
						printed = true;
						xxPrintWhiteTextOnBlackBackground;
						std::cout << "  ";
						break;
					}
					case 1:
					{
						//todo white
						printed = true;
						xxPrintPinkTextonBlackBackGround;
						std::cout << "  ";
						break;
					}
					case 2:
					{
						currentNode = currentNode->nextNode;
						break;
					}
					default:
					{
						throw;
					}
				}
				xxPrintWhiteTextOnBlackBackground;

			}
		}
	}
}

template<class T>
LinkedList<T>::~LinkedList()
{
	Node<T>* currentNode = this->head;
	Node<T>* nextNode = this->head->nextNode;
	while (nextNode != nullptr)
	{
		delete currentNode;
		currentNode = nullptr;
		currentNode = nextNode;
		nextNode = currentNode->nextNode;
	}
	delete currentNode;
	currentNode = nullptr;
	this->size = 0;
}
#endif // !LinkedList

