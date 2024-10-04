#include<iostream>
#include<stack>
#include<algorithm>

//Operator Check
bool isOperator(char C)
{
	if (!isalpha(C) && !isdigit(C))
	{
		return true;
	}
	return false;
}

//Precedence Check/Assignment
int checkPriority(char C)
{
	if (C == '+' || C == '-') return 1;
	if (C == '*' || C == '/') return 2;
	if (C == '^') return 3;
	return 0;
}

//Infix to Postfix
std::string infixtoPostfix(std::string infix)
{
	std::stack<char> char_stack;
	std::string output;

	for (int i = 0; i < infix.size() ; i++)
	{
		//Add to output if alphabet
		if (isalpha(infix[i]) || isdigit(infix[i]))
		{
			output += infix[i];
		}
		//Add to character stack if '('
		else if (infix[i] == '(')
		{
			char_stack.push(infix[i]);
		}
		//Pop all items if ')'
		else if (infix[i] == ')')
		{
			//Keep looping until the stack is not empty and top element of stack is a '('   
			while (!char_stack.empty() && char_stack.top() != '(')
			{
				output += char_stack.top();
				char_stack.pop();
			}
			//Pop out the last remaining '('
			char_stack.pop();
		}
		//Check if operator
		else if (isOperator(infix[i]))
		{
			//If stack is not empty...
			if (!char_stack.empty())
			{
				/*keep looping until the stack is not empty and the top element of the character 
				stack has greater or equal precedence to the current operator of the infix*/
				while (!char_stack.empty() && checkPriority(char_stack.top()) >= checkPriority(infix[i]))
				{
					output += char_stack.top();
					char_stack.pop();
				}
				//push the current operator to the character stack
				char_stack.push(infix[i]);
			}	
			//If stack is empty
			if (char_stack.empty())
			{
				char_stack.push(infix[i]);
			}
		}
	}
	//dump all the remaining operators/elements in the character string to the output string
	while (!char_stack.empty())
	{
		output += char_stack.top();
		char_stack.pop();
	}
	return output;
}

//String reversal for prefix
std::string reverse_and_replace(std::string infix)
{
	std::reverse(infix.begin(), infix.end());
	for (int i = 0; i < infix.length(); i++)
	{
		if (infix[i] == '(')
		{
			infix[i] = ')';
		}
		else if (infix[i] == ')')
		{
			infix[i] = '(';
		}
	}
	return infix;
}
//Infix to Prefix
std::string infixtoPrefix(std::string infix)
{
	//Reverse Infix
	std::string reverse_infix = reverse_and_replace(infix);
	//Postfix of reversed string
	std::string prefix = infixtoPostfix(reverse_infix);
	//Reverse postfix
	std::reverse(prefix.begin(),prefix.end());
	return prefix;
}

//Postfix Evaluation
int postfix_eval(std::string postfix)
{
	std::stack<int> stack;
	for (int i = 0; i < postfix.length(); i++)
	{
		if (!isdigit(postfix[i]) || postfix[i] != '+' || postfix[i] != '-' || postfix[i] != '*' || postfix[i] != '/' || postfix[i] != '^')
		{
			std::cout << "Use digits only!" << std::endl;
			return NULL;
		}
		else if (isdigit(postfix[i]))
		{
			stack.push(postfix[i] - '0');
		}
		else
		{
			int temp_1 = stack.top();
			stack.pop();
			int temp_2 = stack.top();
			stack.pop();
			switch (postfix[i])
			{
				case'+':
					stack.push(temp_1 + temp_2);
					break;
				case'-':
					stack.push(temp_1 - temp_2);
					break;
				case'*':
					stack.push(temp_1 * temp_2);
					break;
				case'/':
					stack.push(temp_1 / temp_2);
					break;
				case'^':
					stack.push(temp_1 ^ temp_2);
					break;
			}
		}
	}
	return stack.top();
}

//Recursive Multiplication
int recursive_multiply(int num, int mult)
{
	if (mult == 0)
	{
		return 0;
	}
	else if (mult == 1)
	{
		return num;
	}
	else
	{
		return num + recursive_multiply(num, mult - 1);
	}
}

//Recursive Exponent
int recursive_exponent(int num, int pow)
{
	if (pow == 0)
	{
		return 1;
	}
	else if (pow == 1)
	{
		return num;
	}
	else
	{
		return num * recursive_exponent(num, pow - 1);
	}
}

int main()
{
	char menu_selection;
	int num_1 = 0;
	int num_2 = 0;
	std::string input;

	while (1)
	{
		std::cout << "\n========== DSA LAB #3 ==========" << std::endl;
		std::cout << "\n============ MENU ==============" << std::endl;
		std::cout << "1. Inifx to Postfix Expression" << std::endl;
		std::cout << "2. Inifx to Prefix Expression" << std::endl;
		std::cout << "3. Postfix Evaluation" << std::endl;
		std::cout << "4. Recursive Multiplication" << std::endl;
		std::cout << "5. Recursive Exponential Function" << std::endl;

		std::cout << "\nEnter your choice: ";
		std::cin >> menu_selection;
		system("cls");
		switch (menu_selection)
		{
		case'1':
			std::cout << "\n============ Infix to Postfix ==============" << std::endl;
			std::cout << "Enter Infix: ";
			std::cin >> input;
			std::cout << "Postfix: " << infixtoPostfix(input) << std::endl;
			system("pause");
			system("cls");
			break;
		case'2':
			std::cout << "\n============ Infix to Pretfix ==============" << std::endl;
			std::cout << "Enter Infix: ";
			std::cin >> input;
			std::cout << "Prefix: " << infixtoPrefix(input) << std::endl;
			system("pause");
			system("cls");
			break;
		case'3':
			std::cout << "\n============ Postfix Evaluation ==============" << std::endl;
			std::cout << "Enter Postfix: ";
			std::cin >> input;
			std::cout << "Evaluated Answer: " << postfix_eval(input) << std::endl;
			system("pause");
			system("cls");
			break;
		case'4':
			std::cout << "\n============ Recursive Multiplication ==============" << std::endl;
			std::cout << "Enter Number: ";
			std::cin >> num_1;
			std::cout << "Enter Multiplicant: ";
			std::cin >> num_2;
			std::cout << "Result: " << recursive_multiply(num_1, num_2) << std::endl;
			system("pause");
			system("cls");
			break;
		case'5':
			std::cout << "\n============ Recursive Exponent Function ==============" << std::endl;
			std::cout << "Enter Number: ";
			std::cin >> num_1;
			std::cout << "Enter Exponent: ";
			std::cin >> num_2;
			std::cout << "Result: " << recursive_exponent(num_1, num_2) << std::endl;
			system("pause");
			system("cls");
			break;
		default:
			std::cout << "Wrong Choice! Try Again" << std::endl;
			system("pause");
			system("cls");
			break;
		}
	}
	return 0;
}