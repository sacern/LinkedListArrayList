

#include<iostream>

template<class T> class arrayList
{
private:
	T *data;
	int arrayLength;//length of the array
	int listSize;//number of elements in the array
	void resize();//resize the array if needed
	bool needToResize();//will see if we need to resize

public:
	//constructor
	arrayList()
	{
		//set up array
		data = new T[5];
		//initialize the parameters
		arrayLength = 5;
		listSize = 0;

	}
	//accesors
	bool Empty(node *head);
	bool contains(T item);
	int indexof(T item);
	int lastIndexOf(T item);
	T *get(int index);
	int size();//how many it takes, not how much there is
	//modifiers
	void add(T item);
	void add(int index, T item);
	void set(int index, T item);
	void remove(int index);
	

};

bool Empty(node *head)
{
	if (head == NULL)
		return true;
	else
		return false;

}

template<class T>
void arrayList<T>::resize()
{
	//resize array so it can accomodate more data
	//precondition->>>>the sice of the array==size of data
	//postcondition->>>>New array that is twice the size

	//get array

	T *temp = new T[arrayLength * 2];

	for (int i = 0; i < arrayLength; i++)
		temp[i] = data[i];
	data = temp;
	arrayLength *= 2;

}

template<class T>
bool arrayList<T>::needToResize()
{
	//return if the data is equal to the arrayLength
	return arrayLength == listSize;
}

template<class T>
void arrayList<T>::add(T item)
{
	//add the item to the end of the list

	//check to see if there's enough space
	if (needToResize())
		resize();
	data[listSize] = item;
	listSize++;
}

template <class T>
void arrayList<T>::add(int index, T item)
{
	//adding item to the indicated index
	//everything else gets bumped down

	if (needToResize())
		resize();
	for (int i = listSize; i >= index; i--)
		data[listSize + 1] = data[listSize];
	data[index] = item;
	listSize++;

}

//removes current index. 
template<class T>
void arrayList<T>::remove(int index)
{
	for (int i = index; i < listSize; i++)
		data[i] = data[i + 1];
	listSize--;//decreases size by 1
}

template<class T>
T* arrayList<T>::get(int index)
{
	if (index >= 0 && index <= listSize)
		return &data[index];//returns the data as a reference 
	//else
	return NULL;
}

template<class T>
void arrayList<T>::set(int index, T item)
{
	if (index >= 0 && index <= listSize)
		data[index] = item;//sets the data to item
}

template<class T>
int arrayList<T>::indexof(T item)
{

	for (int i = 0; i <= listSize; i++)
		if (item == data[i])
			return i;
	//didn't find it
	return -1;//returns it back to its original state if it cannot find it
}

template<class T>
int arrayList<T>::lastIndexOf(T item)
{
	for (int i = listSize; i >= 0; i--)
		if (item == data[i])
			return i;

	return -1;
}

template <class T>
bool arrayList<T>::contains(T item)
{
	return (indexOf(item) > -1);
}

template <class T>
int arrayList<T>::size()
{
	return listSize;
}

void show(node *current)
{//verifies if list is empty
	if (Empty(current))
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





