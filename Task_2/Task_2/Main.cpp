#include <iostream>
#define max_value 5

template <class T> class Stack
{
private:
	int top;
	T array[max_value];
public:
	Stack() { top = -1; }
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
		if (top == 5)
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
			return array[5];
		}
	}
};	

void main()
{
	int loop = 1;
	do
	{
		std::string input_string;
		std::string palindrome_check;
		std::cout << "Enter a string: ";
		std::cin >> input_string;
		Stack<char> palindrome;
		for (int i = 0; i < input_string.length(); i++)
		{
			palindrome.push(input_string[i]);
		};
		for (int j = 0; j < max_value; j++)
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
	} while (loop>0);
}