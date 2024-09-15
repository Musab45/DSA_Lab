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
	//Constructor
	House(std::string ownerName, std::string houseAddress, int numBedrooms, float housePrice)
		: owner(ownerName), address(houseAddress), bedrooms(numBedrooms), price(housePrice) {}

    House() : owner("Unknown"), address("Unknown"), bedrooms(0), price(0.0f) {}

    //Getters
    std::string getOwner() 
    {
        return owner;
    }
    std::string getAddress() 
    {
        return address;
    }
    int getBedrooms()
    {
        return bedrooms;
    }
    float getPrice() 
    {
        return price;
    }

    //Setters
    void setOwner(std::string ownerName) 
    {
        owner = ownerName;
    }
    void setAddress(std::string houseAddress) 
    {
        address = houseAddress;
    }
    void setBedrooms(int numBedrooms) 
    {
        if (numBedrooms > 2) 
        {
            bedrooms = numBedrooms;
        }
        else 
        {
            std::cout << "Invalid number of bedrooms! Cannot be less than 2" << std::endl;
        }
    }
    void setPrice(float housePrice) 
    {
        if (housePrice > 1000) 
        {
            price = housePrice;
        }
        else 
        {
            std::cout << "Invalid price! Cannot be less than 1000" << std::endl;
        }
    }

    void displayHouseDetails() {
        std::cout << "Owner: " << owner << std::endl;
        std::cout << "Address: " << address << std::endl;
        std::cout << "Bedrooms: " << bedrooms << std::endl;
        std::cout << "Price: $" << price << std::endl;
    }
};

int main()
{
    House* houses = new House[100];
    std::string owner;
    std::string address;
    int bedrooms;
    float price;
    int index = 0;
    char menu_selection;
    do
    {
        std::cout << "   -- Property Manager --   " << std::endl;
        std::cout << "1. Add Property" << std::endl;
        std::cout << "2. View Property" << std::endl;
        std::cout << "3. Exit" << std::endl;
        std::cout << "Choice: ";
        std::cin >> menu_selection;
        system("cls");
        switch (menu_selection)
        {
        case'1':
            
            std::cout << "Enter details for property " << index + 1 << std::endl;
            std::cout << "Owner: ";
            std::cin >> owner;
            std::cout << "Address: ";
            std::cin >> address;
            std::cout << "Bedrooms: ";
            std::cin >> bedrooms;
            std::cout << "Price: ";
            std::cin >> price;

            // Set the values for each house object
            houses[index].setOwner(owner);
            houses[index].setAddress(address);
            houses[index].setBedrooms(bedrooms);
            houses[index].setPrice(price);
            index++;
            system("cls");
            break;
        case'2':
            for (int i = 0; i < index; i++) {
                std::cout << "\nDetails of house " << i + 1 << ":" << std::endl;
                houses[i].displayHouseDetails();
            }
            system("pause");
            system("cls");
            break;
        }
    } while (menu_selection != 3);
	return 0;
}