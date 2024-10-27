#include<iostream>

struct Node
{
	int data;
	Node* next;
	//Constructor
	Node(int data)
	{
		this->data = data;
		this->next = nullptr;
	}
};

class LinkedList
{
	Node* head;
public:
	LinkedList() : head(NULL) {}
	//Traversal
	void traverse()
	{
		Node* current = head;
		std::cout << "[ ";
		while (current != nullptr)
		{
			std::cout << current->data;
			current = current->next;
			if (current == nullptr)
			{
				break;
			}
			std::cout << ", ";
		}
		std::cout << " ]" << std::endl;
	}
	//Searching
	bool search(int target)
	{
		while (head != nullptr)
		{
			if (head->data == target)
			{
				return true;
			}
			head = head->next;
		}
		return false;
	}
	//Finding Length
	int length()
	{
		int length = 0;
		Node* current = head;
		while (current != nullptr)
		{
			length++;
			current = current->next;
		}
		return length;
	}
	//Insertions
	//at beginning
	void insert_atBeginning(int value)
	{
		Node* newNode = new Node(value);
		newNode->next = head;
		head = newNode;
	}
	//at End
	void insert_atEnd(int value)
	{
		Node* newNode = new Node(value);
		Node* current = head;
		if (head == NULL)
		{
			head = newNode;
		}
		else
		{
			while (current->next != nullptr)
			{
				current = current->next;
			}
			current->next = newNode;
		}
	}
	//at Position
	void insert_atPosition(int value, int pos)
	{
		if (pos < 1)
		{
			std::cout << "Invalid Position!" << std::endl;
		}
		if (pos == 1)
		{
			Node* temp = new Node(value);
			temp->next = head;
		}
		else
		{
			Node* prev = head;
			for (int i = 1; i < pos - 1 && prev != nullptr; i++)
			{
				prev = prev->next;
			}
			if (prev == nullptr)
			{
				std::cout << "Invalid Position!" << std::endl;
			}
			else
			{
				Node* temp = new Node(value);
				temp->next = prev->next;
				prev->next = temp;
			}
		}
	}
	//Deletion
	//from beginning
	void delete_fromBeginning()
	{
		if (head == nullptr)
		{
			return;
		}
		else
		{
			head = head->next;
		}
	}
	//from End
	void delete_fromEnd()
	{
		if (head == nullptr)
		{
			return;
		}
		else if (head->next == nullptr)
		{
			delete head;
		}
		else
		{
			Node* secondLast = head;
			while (secondLast->next->next != nullptr)
			{
				secondLast = secondLast->next;
			}
			delete(secondLast->next);
			secondLast->next = nullptr;
		}
	}
	//from Position
	void delete_fromPosition(int pos)
	{
		if (head == nullptr || pos < 1)
		{
			std::cout << "Invalid Position!" << std::endl;
			return;
		}
		else if (pos == 1)
		{
			Node* temp = head;
			head = head->next;
			delete temp;
			return;
		}
		else
		{
			Node* current = head;
			for (int i = 1; i < pos - 1 && current != nullptr; i++)
			{
				current = current->next;
			}
			if (current == NULL || current->next == nullptr)
			{
				return;
			}
			else
			{
				Node* temp = current->next;
				current->next = current->next->next;
				delete temp;
				return;
			}
		}
	}
};

int main()
{
	LinkedList list1;
	int choice, value, pos;

	while (true)
	{
		system("cls");  // Clear the screen for a clean display

		std::cout << "===== Linked List =====" << std::endl;
		list1.traverse();
		std::cout << "=======================\n";
		std::cout << "1. Insert at Beginning\n";
		std::cout << "2. Insert at End\n";
		std::cout << "3. Insert at Position\n";
		std::cout << "4. Delete from Beginning\n";
		std::cout << "5. Delete from End\n";
		std::cout << "6. Delete from Position\n";
		std::cout << "7. Search\n";
		std::cout << "8. Get Length\n";
		std::cout << "9. Exit\n";
		std::cout << "Enter your choice: ";
		std::cin >> choice;

		switch (choice)
		{
		case 1:
			std::cout << "Enter value to insert at beginning: ";
			std::cin >> value;
			list1.insert_atBeginning(value);
			std::cout << "Inserted " << value << " at the beginning.\n";
			system("pause");
			break;

		case 2:
			std::cout << "Enter value to insert at end: ";
			std::cin >> value;
			list1.insert_atEnd(value);
			std::cout << "Inserted " << value << " at the end.\n";
			system("pause");
			break;

		case 3:
			std::cout << "Enter value to insert: ";
			std::cin >> value;
			std::cout << "Enter position to insert at: ";
			std::cin >> pos;
			if (pos > list1.length() + 1)
			{
				std::cout << "Error! Invalid Position Entered." << std::endl;
				system("pause");
				break;
			}
			list1.insert_atPosition(value, pos);
			std::cout << "Inserted " << value << " at position " << pos << ".\n";
			system("pause");
			break;

		case 4:
			list1.delete_fromBeginning();
			std::cout << "Deleted node from the beginning.\n";
			system("pause");
			break;

		case 5:
			list1.delete_fromEnd();
			std::cout << "Deleted node from the end.\n";
			system("pause");
			break;

		case 6:
			std::cout << "Enter position to delete from: ";
			std::cin >> pos;
			list1.delete_fromPosition(pos);
			std::cout << "Deleted node at position " << pos << ".\n";
			system("pause");
			break;

		case 7:
			std::cout << "Enter value to search for: ";
			std::cin >> value;
			if (list1.search(value))
				std::cout << "Value " << value << " found in the list.\n";
			else
				std::cout << "Value " << value << " not found in the list.\n";
			system("pause");
			break;

		case 8:
			std::cout << "Length of the list: " << list1.length() << std::endl;
			system("pause");
			break;

		case 9:
			std::cout << "Exiting..." << std::endl;
			return 0;

		default:
			std::cout << "Invalid choice! Please try again.\n";
			system("pause");
			break;
		}
	}

	return 0;
}
