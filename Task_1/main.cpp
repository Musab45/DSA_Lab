#include<iostream>
#include<string>

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

	getline(std::cin, owner);
	getline(std::cin, address);
	std::cin >> bedrooms;
	std::cin >> price;

	available[index].setOwner(owner);
	available[index].setAddress(address);
	available[index].setBedrooms(bedrooms);
	available[index].setPrice(price);
}

void showHouses(int index)
{
	std::cout << "Owner\t" << "Address\t" << "Bedrooms\t" << "Price\t" << std::endl;
	std::cout << available[0].getOwner() << "\t" << available[0].getAddress() << "\t" << available[0].getBedrooms() << "\t" << available[0].getPrice() << "\t" << std::endl;
}

int main()
{
	int index = 0;
	addHouse(0);

	
	return 0;
}