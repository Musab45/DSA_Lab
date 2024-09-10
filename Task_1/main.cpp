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

void addHouse(int index)
{
	std::string owner;
	std::string address;
	int bedrooms = 0;
	float price = 0.0;

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
}

void showHouse(int index)
{
	std::cout << "Owner\t" << "Address\t" << "Bedrooms\t" << "Price\t" << std::endl;
	std::cout << available[0].getOwner() << "\t" << available[0].getAddress() << "\t" << available[0].getBedrooms() << "\t" << available[0].getPrice() << "\t" << std::endl;
}

int property_add_index = 0;

int main()
{
	char main_menu_choice;

	std::cout << "   -- Property Management Software --   " << std::endl;
	std::cout << "1. Add Property" << std::endl;
	std::cout << "2. View Properties" << std::endl;
	std::cout << "3. Exit" << std::endl;
	std::cout << "Choice: ";

	std::cin >> main_menu_choice;

	system("cls");

	do
	{
		switch (main_menu_choice)
		{
		case'1':
			addHouse(property_add_index);
			char add_choice;
			std::cout << "Add another?(y/n)" << std::endl;
			std::cout << "Choice: ";
			std::cin >> add_choice;
			while (add_choice != 'n' || add_choice != 'N')
			{
				if (add_choice == 'y' || add_choice == 'Y')
				{
					property_add_index++;
					addHouse(property_add_index);
				}
			}
		}
	} while (main_menu_choice != 3);

	return 0;
}