#include <iostream>
#include <string>
using namespace std;

class Student
{
private:
    int studentID;
    string name;
    int semester;
    bool transportCardActive;

public:
    Student()
	{
        studentID = 00000;
        name = "ABC";
        semester = 0;
        transportCardActive = false;
    }

    void registerStudent(int id, string n, int sem)
	{
        studentID = id;
        name = n;
        semester = sem;
        transportCardActive = false;
        cout << "Student registered: " << name << "ID: " << studentID <<endl;
    }

    void payFees()
	{
        transportCardActive = true;
        cout << "Fees paid! Transport card activated for " << name << "ID: " << studentID <<endl;
    }

    int getID()
	{
	return studentID;
	}
    string getName()
	{
	return name;
	}
    bool isCardActive()
	{
	return transportCardActive;
	}
};

class BusRoute
{
private:
    int routeID;
    string stops[10];
    int stopCount;
    string busNumber;

public:
    BusRoute()
    {
        routeID = 0000;
        busNumber = "ABC";
        stopCount = 0;
    }

    void createRoute(int id, string bus)
	{
        routeID = id;
        busNumber = bus;
        stopCount = 0;
    }

    void addStop(string stop)
	{
        if (stopCount < 10)
		{
            stops[stopCount] = stop;
            stopCount++;
        }
		else
		{
            cout << "Cannot add more stops."<<endl;
        }
    }

    void displayStops()
	{
        cout << "Route " << routeID << " Bus: " << busNumber << " Stops: ";
        for (int i = 0; i < stopCount; i++)
		{
            cout << stops[i] << " -> ";
        }
        cout << "End"<<endl;
    }
};

class Attendance
{
private:
    int studentID;
    string date;
    bool status;

public:
    void recordAttendance(int id, string d)
	{
        studentID = id;
        date = d;
        status = true;
        cout << "Attendance recorded for Student ID: " << studentID << " on " << date << endl;
    }
};

class TransportSystem
{
private:
    Student students[10];
    int studentCount;
    BusRoute routes[5];
    int routeCount;
    Attendance attendance[50];
    int attendanceCount;

public:
    TransportSystem()
	{
        studentCount = 0;
        routeCount = 0;
        attendanceCount = 0;
    }

    void registerStudent(int id, string name, int sem)
	{
        if (studentCount < 10)
		{
            students[studentCount].registerStudent(id, name, sem);
            studentCount++;
        }
		else
		{
            cout << "Cannot register more students."<<endl;
        }
    }

    void processPayment(int id)
	{
        for (int i = 0; i < studentCount; i++)
		{
            if (students[i].getID() == id)
			{
                students[i].payFees();
                return;
            }
        }
        cout << "Student ID not found!"<<endl;
    }

    void addBusRoute(int id, string bus)
	{
        if (routeCount < 5)
		{
            routes[routeCount].createRoute(id, bus);
            routeCount++;
        }
		else
		{
            cout << "Cannot add more routes.\n";
        }
    }

    void addStopToRoute(int id, string stop)
	{
        for (int i = 0; i < routeCount; i++)
		{
            routes[i].addStop(stop);
            return;
        }
        cout << "Route not found!"<<endl;
    }

    void recordAttendance(int id, string date)
	{
        for (int i = 0; i < studentCount; i++)
		{
            if (students[i].getID() == id && students[i].isCardActive())
			{
                if (attendanceCount < 50)
				{
                    attendance[attendanceCount].recordAttendance(id, date);
                    attendanceCount++;
                }
				else
				{
                    cout << "Attendance record full.\n";
                }
                return;
            }
        }
        cout << "Attendance failed: Card not active or student not found.\n";
    }
};

int main()
{
	cout<<"Nafees Uddin 24K-2526"<<endl;
    TransportSystem system;

    system.registerStudent(1, "Nafees", 3);
    system.registerStudent(2, "Anas", 2);

    system.processPayment(1);

    system.addBusRoute(101, "Bus 1");
    system.recordAttendance(1, "2025-02-20");
    system.recordAttendance(2, "2025-02-21");
    
    return 0;
}