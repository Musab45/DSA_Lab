#include<iostream>
#include<string>

class House
{
private:
	std::string owner;
	std::string city;
	int bedrooms;
	float price;
public:
	//Constructor
	House(std::string ownerName, std::string housecity, int numBedrooms, float housePrice)
		: owner(ownerName), city(housecity), bedrooms(numBedrooms), price(housePrice) {}

    House() : owner("Unassigned"), city("Unassigned"), bedrooms(0), price(0.0f) {}

    //Getters
    std::string getOwner() 
    {
        return owner;
    }
    std::string getcity() 
    {
        return city;
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
    void setcity(std::string housecity) 
    {
        city = housecity;
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

    void displayHouseDetails() 
    {
        std::cout << "Owner: " << owner << std::endl;
        std::cout << "City: " << city << std::endl;
        std::cout << "Bedrooms: " << bedrooms << std::endl;
        std::cout << "Price: $" << price << std::endl;
    }
};

int main()
{
    House* houses = new House[100];

    std::string owner;
    std::string city;
    int bedrooms;
    int bedrooms_check;
    float price;
    float price_check;
    int index = 0;

    char menu_selection;
    char filter_selection;
    std::string filter_city;
    int filter_bedroom;

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

            std::cin.ignore();
            std::cout << "Owner: ";
            std::getline(std::cin, owner);
            std::cout << "City: ";
            std::getline(std::cin, city);
            std::cout << "Bedrooms: ";
            std::cin >> bedrooms_check;
            std::cout << "Price: ";
            std::cin >> price_check;

            if (bedrooms_check > 2 && price_check > 1000)
            {
                bedrooms = bedrooms_check;
                price = price_check;

                //values for each house object
                houses[index].setOwner(owner);
                houses[index].setcity(city);
                houses[index].setBedrooms(bedrooms);
                houses[index].setPrice(price);
                index++;
            }
            else
            {
                std::cout << "\nProperty entered is not valid. It must be of the following requirements:" << std::endl;
                std::cout << "1. More than 2 bedrooms\n2. More than 1000 in price" << std::endl;
                system("pause");
                system("cls");
            }
            system("cls");
            break;
        case'2':
            std::cout << "1. View all properties" << std::endl;
            std::cout << "2. Filter by city" << std::endl;
            std::cout << "3. Filter by price" << std::endl;
            std::cout << "4. Filter by number of bedrooms" << std::endl;
            std::cout << "Choice: ";
            std::cin >> filter_selection;
            system("cls");
            switch (filter_selection)
            {
            case'1':
                for (int i = 0; i < index; i++)
                {
                    std::cout << "\nDetails of house " << i + 1 << ":" << std::endl;
                    houses[i].displayHouseDetails();
                }
                break;
            case'2':
                std::cout << "Enter city name: ";
                std::cin.ignore();
                std::getline(std::cin, filter_city);

                for (int i = 0; i < index; i++)
                {
                    if (houses[i].getcity().find(filter_city) != std::string::npos)
                    {
                        std::cout << "\nDetails of house " << i + 1 << ":" << std::endl;
                        houses[i].displayHouseDetails();
                    }
                }
                break;
            case'3':
                std::cout << "Enter price range:" << std::endl;
                float low_price, high_price;
                std::cout << "Low:";
                std::cin >> low_price;
                std::cout << "High: ";
                std::cin >> high_price;
                for (int i = 0; i < index; i++)
                {
                    if (houses[i].getPrice() >= low_price && houses[i].getPrice() <= high_price)
                    {
                        std::cout << "\nDetails of house " << i + 1 << ":" << std::endl;
                        houses[i].displayHouseDetails();
                    }
                }
                break;
            case'4':
                std::cout << "Enter numeber of bedrooms: ";
                std::cin >> filter_bedroom;
                for (int i = 0; i < index; i++)
                {
                    if (houses[i].getBedrooms() == filter_bedroom)
                    {
                        std::cout << "\nDetails of house " << i + 1 << ":" << std::endl;
                        houses[i].displayHouseDetails();
                    }
                }
                break;
            }
            system("pause");
            system("cls");
            break;
        }
    } while (menu_selection != 3);
	return 0;
}