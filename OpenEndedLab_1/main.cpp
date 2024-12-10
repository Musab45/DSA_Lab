////Open Ended Lab 1
////Doubly Linked Lists
//
//#include<iostream>
//
//class Node
//{
//public:
//	int data;
//	Node* next;
//	Node* prev;
//	Node(int x) :data(x) 
//	{
//		this->next = nullptr;
//		this->prev = nullptr;
//	}
//};
//
//class LinkedList
//{
//private:
//	Node* head;
//public:
//	LinkedList() :head(NULL) {}
//
//	//----Insetions
//	//Add Runs at Start
//	void addAtBeginning(int value)
//	{
//		Node* newNode = new Node(value);
//		if (head == nullptr)
//		{
//			head = newNode;
//			return;
//		}
//		newNode->next = head;
//		head->prev = newNode;
//		head = newNode;
//	}
//	//Add Runs at End
//	void addAtEnd(int value)
//	{
//		Node* newNode = new Node(value);
//		Node* current = head;
//		if (current == nullptr)
//		{
//			head = newNode;
//			return;
//		}
//		while (current -> next != nullptr)
//		{
//			current = current->next;
//		}
//		current->next = newNode;
//		newNode->prev = current;
//	}
//	//----Deletions
//	//Delete alll occurences of a score
//	void deleteByValue(int value)
//	{
//		Node* current = head;
//		while (current != nullptr) 
//		{
//			if (current->data == value) 
//			{
//				Node* nodeToDelete = current;
//				if (current == head)
//				{
//					head = current->next;
//					if (head != nullptr) 
//					{
//						head->prev = nullptr;
//					}
//				}
//				else 
//				{
//					if (current->prev != nullptr) current->prev->next = current->next;
//					if (current->next != nullptr) current->next->prev = current->prev;
//				}
//				current = current->next;
//				delete nodeToDelete;
//			}
//			else
//			{
//				current = current->next;
//			}
//		}
//	}
//	//-----Displays
//	//Display Score in Sequence
//	void displaySequence()
//	{
//		Node* current = head;
//		int i = 1;
//		if (current == nullptr)
//		{
//			std::cout << "List is empty!" << std::endl;
//			return;
//		}
//		while (current != nullptr)
//		{
//			std::cout << "==============================" << std::endl;
//			std::cout << "Match " << i << ": " << current->data << std::endl;
//			current = current->next;
//			i++;
//		}
//		std::cout << "==============================" << std::endl;
//	}
//	//Display Score in Reverse Sequence
//	void displayReverseSequence()
//	{
//		Node* current = head;
//		int i = 1;
//		if (current == nullptr) 
//		{
//			std::cout << "The list is empty." << std::endl;
//			return;
//		}
//		while (current->next != nullptr)
//		{
//			current = current->next;
//			i++;
//		}
//		while (current != nullptr) 
//		{
//			std::cout << "==============================" << std::endl;
//			std::cout << "Match " << i << ": " << current->data << std::endl;
//			current = current->prev;
//			i--;
//		}
//		std::cout << "==============================" << std::endl;
//	}
//	//----Min/Max Score
//	int MinScore()
//	{
//		if (head == nullptr)
//		{
//			std::cout << "List is empty!" << std::endl;
//			return NULL;
//		}
//		Node* current = head;
//		int minValue = current->data;
//		while (current != nullptr)
//		{
//			if (current->data < minValue)
//			{
//				minValue = current->data;
//			}
//			current = current->next;
//		}
//		return minValue;
//	}
//	int MaxScore()
//	{
//		if (head == nullptr)
//		{
//			std::cout << "List is empty!" << std::endl;
//			return NULL;
//		}
//		Node* current = head;
//		int maxValue = current->data;
//		while (current != nullptr)
//		{
//			if (current->data > maxValue)
//			{
//				maxValue = current->data;
//			}
//			current = current->next;
//		}
//		return maxValue;
//	}
//};
//
//int main()
//{
//	LinkedList matchList;
//	char choice;
//	int value;
//	while (true)
//	{
//		std::cout << "===== Match Score Manager =====" << std::endl;
//		std::cout << "===============================" << std::endl;
//		std::cout << "1. Add Match Details" << std::endl;
//		std::cout << "2. Remove Match Details" << std::endl;
//		std::cout << "3. View Match Details" << std::endl;
//		std::cout << "4. View Minimum Score" << std::endl;
//		std::cout << "5. View Maximum Score" << std::endl;
//		std::cout << "===============================" << std::endl;
//		std::cout << "Enter Selection: ";
//		std::cin >> choice;
//		system("cls");
//		switch(choice)
//		{
//		case'1':
//			//Insertion Functions
//			std::cout << "===== Insert Match Score =====" << std::endl;
//			std::cout << "==============================" << std::endl;
//			std::cout << "1. Enter at Beginnning" << std::endl;
//			std::cout << "2. Enter at End" << std::endl;
//			std::cout << "==============================" << std::endl;
//			std::cout << "Enter Selection: ";
//			std::cin >> choice;
//			switch(choice)
//			{
//			case'1':
//				std::cout << "Enter Score for New Match: ";
//				std::cin >> value;
//				matchList.addAtBeginning(value);
//				break;
//			case'2':
//				std::cout << "Enter Score for New Match: ";
//				std::cin >> value;
//				matchList.addAtEnd(value);
//				break;
//			default:
//				std::cout << "Incorrect Input! Try Again." << std::endl;
//				break;
//			}
//			system("pause");
//			system("cls");
//			break;
//		case'2':
//			//Deletion Functions
//			std::cout << "===== Delete Match Score =====" << std::endl;
//			std::cout << "==============================" << std::endl;
//			std::cout << "Enter Score for Matches to Delete: ";
//			std::cin >> value;
//			matchList.deleteByValue(value);
//			system("pause");
//			system("cls");
//			break;
//		case'3':
//			//Display Functions
//			//Insertion Functions
//			std::cout << "===== Display Match Score =====" << std::endl;
//			std::cout << "===============================" << std::endl;
//			std::cout << "1. Normal Sequence" << std::endl;
//			std::cout << "2. Reverse Sequence" << std::endl;
//			std::cout << "===============================" << std::endl;
//			std::cout << "Enter Selection: ";
//			std::cin >> choice;
//			system("cls");
//			switch (choice)
//			{
//			case'1':
//				matchList.displaySequence();
//				system("pause");
//				system("cls");
//				break;
//			case'2':
//				matchList.displayReverseSequence();
//				system("pause");
//				system("cls");
//				break;
//			default:
//				std::cout << "Incorrect Input! Try Again." << std::endl;
//				system("pause");
//				system("cls");
//				break;
//			}
//			break;
//		case'4':
//			std::cout << "=============================================" << std::endl;
//			std::cout << "Minimum Score from All Matches: " << matchList.MinScore() << std::endl;
//			std::cout << "=============================================" << std::endl;
//			system("pause");
//			system("cls");
//			break;
//		case'5':
//			std::cout << "=============================================" << std::endl;
//			std::cout << "Maximum Score from All Matches: " << matchList.MaxScore() << std::endl;
//			std::cout << "=============================================" << std::endl;
//			system("pause");
//			system("cls");
//			break;
//		default:
//			std::cout << "Incorrect Input! Try Again." << std::endl;
//			system("pause");
//			system("cls");
//			break;
//		}
//	}
//	return 0;
//}