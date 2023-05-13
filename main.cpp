#include "table.h"
using namespace std;

//Molina Nhoung, CS163, 5/12/23, Program 3
//The purpose of this file is to test the ADT and act as the application.
//This will prompt the user and send information to the ADT to be used,
//then the ADT will return success/failure for the application to
//output the right messages.

//Prototypes
int menu();
void get_travel(client & your_trip, travel & add_trip);
int main()
{
	//Variables
	travel add_trip, my_trip;
	table my_table;
	client your_trip;
	load_file my_file;
	int option {0};

	do
	{
		option = menu();
		if (option == 1)
		{
			get_travel(your_trip, add_trip);
		}
		if (option == 2)
		{}
		if (option == 3)
		{}
		if (option == 4)
		{}
		if (option == 5)
		{}
		if (option == 6)
		{}
	} while (option != 7);
	return 0;
}

//Functions
//Menu for the user to choose
int menu()
{
	int option = 0;
	cout << "\n***TRAVEL LIST***"
		<< "\n1. Add a place to visit"
		<< "\n2. Display all"
		<< "\n3. Display the info for a particular match by location name"
		<< "\n4. Retrieve the infor for a particular match by location name"
		<< "\n5. Remove a location by name"
		<< "\n6. Display all by activities"
		<< "\n7. Quit";
	do
	{
		cout << "\nPick an option: ";
		cin >> option;
		cin.ignore(100, '\n');
		if (option < 1 || option > 7)
			cout << "\nTry again" << endl;
	} while (option < 1 || option > 7);
	return option;
}
//Prompt the user for the travel information
void get_travel(client & your_trip, travel & add_trip)
{
	cout << "\nName of the location: ";
	cin.get(your_trip.c_name, SIZE, '\n');
	cin.ignore(100, '\n');
	cout << "\nState and/or country (state, country): ";
	cin.get(your_trip.c_country, SIZE, '\n');
	cin.ignore(100, '\n');
	cout << "\nBest thing to do there: ";
	cin.get(your_trip.c_attract, SIZE, '\n');
	cin.ignore(100, '\n');
	cout << "\nHow to travel to there: ";
	cin.get(your_trip.c_transport, SIZE, '\n');
	cin.ignore(100, '\n');
	cout << "\nImportant notes: ";
	cin.get(your_trip.c_notes, SIZE, '\n');
	cin.ignore(100, '\n');
	add_trip.create(your_trip);
	add_trip.display();
}

