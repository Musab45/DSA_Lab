#include <iostream>

template <class T> class Stack
{
private:
	int top;
	int size; //get length of the input string to set size of array
	T* array; //dynamic array allocation
public:
	Stack(int s): size(s) //constructor with size as parameter
	{
		top = -1;
		array = new T[size];
	}
	bool isEmpty()
	{
		if (top < 0)
		{
			return true;
		}
		return false;
	}
	bool isFull()
	{
		if (top == size)
		{
			return true;
		}
		return false;
	}
	void push(T value)
	{
		if (!isFull())
		{
			top++;
			array[top] = value;
		}
		else 
		{
			std::cout << "Stack Overflow!" << std::endl;
		}
	}
	T pop()
	{
		if (!isEmpty())
		{
			T returned_value = array[top];
			top--;
			return returned_value;
		}
		else
		{
		std::cout << "Stack Underflow!" << std::endl;
		}
	}
	T peak()
	{
		if (!isEmpty())
		{
			return array[size];
		}
	}
};	

void main()
{
	do
	{
		std::string input_string;
		std::string palindrome_check;

		std::cout << "Enter a string: ";
		std::cin >> input_string;

		Stack<char> palindrome(input_string.length()); //Declaring char as data type for the class and passing input string's length as parameter

		for (int i = 0; i < input_string.length(); i++)
		{
			palindrome.push(input_string[i]);
		}

		for (int j = 0; j < input_string.length(); j++)
		{
			palindrome_check += palindrome.pop();
		}

		if (palindrome_check == input_string)
		{
			std::cout << "Is Palindrome!" << std::endl;
			system("pause");
			system("cls");
		}

		else
		{
			std::cout << "Is not Palindrome!" << std::endl;
			system("pause");
			system("cls");
		}
	} while (-1);
}