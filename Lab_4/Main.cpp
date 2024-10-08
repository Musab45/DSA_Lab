#include<iostream>

template<class T> class Queue
{
private:
	int front;
	int rear;
	int size;
	int count;
	T* data;
public:
	Queue(int s) : size(s)
	{
		front = -1;
		rear = -1;
		count = 0;
		data = new T[size];
	}
	
	bool isEmpty()
	{
		if (front == -1 && rear == -1)
		{
			return true;
		}
		 return false;
	}
	bool isFull()
	{
		if (count==size)
		{
			return true;
		}
		return false;
	}
	void enqueue(T value)
	{
		if (isFull())
		{
			std::cout << "Queue Overflow!" << std::endl;
			return;
		}
		else
		{
			data[rear] = value;
			rear = (rear + 1) % size;
			++count;
		}
	}
	T dequeue()
	{
		int temp;
		if (isEmpty())
		{
			std::cout << "Queue Underflow!" << std::endl;
			return NULL;
		}
		else if (front == rear)
		{
			temp = front;
			front = rear = -1;
			return temp;
			front = rear = -1;
		}
		else
		{
			temp = data[front];
			front = (front + 1) % size;
			--count;
			return temp;
		}
	}
	void displayQueue()
	{
		if (count == 0)
		{
			std::cout << "[Empty!]" << std::endl;
		}
		else
		{
			std::cout << "[ ";
			for (int i = front ; i < rear; i++)
			{
				std::cout << data[i] << " ";
			}
			std::cout << "]" << std::endl;
			if (isFull())
			{
				std::cout << "Queue Overflow!" << std::endl;
			}
			if (isEmpty())
			{
				std::cout << "Queue Underflow!" << std::endl;
			}
		}
	}
};

int main()
{
	char choice;
	Queue<int> temp(5);
	while (1)
	{
		temp.displayQueue();
		std::cout << "\n" << std::endl;
		std::cout << "1. Add to Queue" << std::endl;
		std::cout << "2. Pop from Queue" << std::endl;
		std::cout << "Enter Choice: ";
		std::cin >> choice;
		system("cls");
		switch (choice)
		{
		case'1':
			temp.displayQueue();
			std::cout << "\n" << std::endl;
			int temp_num;
			std::cout << "Enter number: ";
			std::cin >> temp_num;
			temp.enqueue(temp_num);
			system("cls");
			break;
		case'2':
			temp.displayQueue();
			std::cout << "\n" << std::endl;
			std::cout << temp.dequeue() << " removed from queue." << std::endl;
			system("pause");
			system("cls");
			break;
		}
	}
}