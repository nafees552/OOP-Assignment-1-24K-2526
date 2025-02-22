#include <iostream>
#include <string>
using namespace std;

class User
{
private:
    int UserId;
    string name;
    int age;
    string licenseType;
    string contact;

public:
    User(int id, string n, int a, string l, string c)
    {
    	UserId = id;
    	name = n;
    	licenseType = l;
    	contact = c;
	}

    int getUserID()
    {
        return UserId;
    }
    string getName()
    {
        return name;
    }
    int getAge()
    {
        return age;
    }
    string getLicenseType()
    {
        return licenseType;
    }
    string getContact()
    {
        return contact;
    }

    void setName(string n)
    {
        name = n;
    }
    void setAge(int a)
    {
        age = a;
    }
    void setLicenseType(string l)
    {
        licenseType = l;
    }
    void setContact(string c)
    {
        contact = c;
    }
};

class Vehicle
{
private:
    string model;
    double rentalPrice;
    string requiredLicense;

public:
    Vehicle(string m, double r, string license)
    {
    	model = m;
    	rentalPrice = r;
    	requiredLicense = license;
	}

    string getModel()
    {
        return model;
    }
    double getRentalPrice()
    {
        return rentalPrice;
    }
    string getRequiredLicense()
    {
        return requiredLicense;
    }
};

class RentalSystem
{
private:
    Vehicle *vehicle[3];
    int vehicleCount;

public:
    RentalSystem()
    {
    	vehicleCount = 0;
	}

    void addVehicle(Vehicle *v)
    {
        if (vehicleCount < 3)
        {
            vehicle[vehicleCount++] = v;
        }
    }

    void showAvailableVehicles()
    {
        for (int i = 0; i < vehicleCount; i++)
        {
            cout << "Model: " << vehicle[i]->getModel() << ", Price: " << vehicle[i]->getRentalPrice() << endl;
        }
    }

    void rentVehicle(User &user, string model)
    {
        for (int i = 0; i < vehicleCount; i++)
        {
            if (vehicle[i]->getModel() == model)
            {
                if (user.getLicenseType() == vehicle[i]->getRequiredLicense())
                {
                    cout << user.getName() << " rented " << model << " successfully!" << endl;
                }
                else
                {
                    cout << "You do not have the required license to rent this vehicle." << endl;
                }
                return;
            }
        }
        cout << "Vehicle not found!" << endl;
    }
};

int main()
{
    cout<<"Nafees Uddin 24K-2526"<<endl;
    User user1(249, "Nafees", 18, "Full", "854-693");
    Vehicle v1("Tesla", 5000, "Full");
    Vehicle v2("Porsche", 3000, "Learner");
    RentalSystem rentalSystem;
    rentalSystem.addVehicle(&v1);
    rentalSystem.addVehicle(&v2);

    cout << "Available vehicles:" << endl;
    rentalSystem.showAvailableVehicles();

    rentalSystem.rentVehicle(user1, "Tesla");
    rentalSystem.rentVehicle(user1, "Porsche");

    return 0;
}