#include<iostream>
#include<string>
#include<cstdlib>

class House
{
private:
	std::string owner;
	std::string address;
	int bedrooms;
	float price;
public:
	House() {}

	//setters
	void setOwner(std::string owner)
	{
		this->owner = owner;
	}
	void setAddress(std::string address)
	{
		this->address = address;
	}
	void setBedrooms(int num)
	{
		this->bedrooms = num;
	}
	void setPrice(float num)
	{
		this->price = num;
	}

	//getters
	std::string getOwner()
	{
		return this->owner;
	}
	std::string getAddress()
	{
		return this->address;
	}
	int getBedrooms()
	{
		return this->bedrooms;
	}
	float getPrice()
	{
		return this->price;
	}
};

//Array of available houses
House available[100];

int houses_in_database = 0;


void addHouse(int index)
{
	std::string owner;
	std::string address;
	int bedrooms = 0;
	float price = 0.0;

	std::cin.ignore();
	std::cout << "Enter owner's name: ";
	getline(std::cin, owner);
	std::cout << "Enter address: ";
	getline(std::cin, address);
	std::cout << "Enter number of bedrooms:";
	std::cin >> bedrooms;
	std::cout << "Enter price:";
	std::cin >> price;

	available[index].setOwner(owner);
	available[index].setAddress(address);
	available[index].setBedrooms(bedrooms);
	available[index].setPrice(price);
	houses_in_database++;
}

void showHouse()
{
	std::cout << "Owner\t" << "Address\t" << "Bedrooms\t" << "Price\t" << std::endl;
	for (int i = 0; i <= houses_in_database; i++)
	{
		std::cout << available[i].getOwner() << "\t" << available[i].getAddress() << "\t" << available[i].getBedrooms() << "\t" << available[i].getPrice() << "\t" << std::endl;
	}
}

int property_add_index = 0;

int main()
{
	char main_menu_choice;

	do
	{
		std::cout << "   -- Property Management Software --   " << std::endl;
		std::cout << "1. Add Property" << std::endl;
		std::cout << "2. View Properties" << std::endl;
		std::cout << "3. Exit" << std::endl;
		std::cout << "Choice: ";

		std::cin >> main_menu_choice;

		system("cls");
		switch (main_menu_choice)
		{
		case'1':
			addHouse(property_add_index);
			system("cls");
			break;
		case'2':
			showHouse();
			system("pause");
			system("cls");
			break;
		}
	} while (main_menu_choice != 3);

	return 0;
}