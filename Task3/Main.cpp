#include<iostream>
#include<stack>

bool isOperator(char C)
{
	if (!isalpha(C) && !isdigit(C))
	{
		return true;
	}
	return false;
}

int checkPriority(char C)
{
	if (C == '+' || C == '-') return 1;
	if (C == '*' || C == '/') return 2;
	if (C == '^') return 3;
	return 0;
}

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

int main()
{
	std::string s = ("(A+B)*(C+D)");
	std::cout << infixtoPostfix(s);
	return 0;
}