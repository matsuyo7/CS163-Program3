#include "table.h"
using namespace std;

//Molina Nhoung, CS163, 5/12/23, Program 3
//The purpose of this file is to test the ADT and act as the application.
//This will prompt the user and send information to the ADT to be used,
//then the ADT will return success/failure for the application to
//output the right messages.

//Prototypes
int menu();
void get_travel(client & your_trip, travel & add_trip, table & my_table);
void name_match(char match_name[], table & my_table);
void retrieve_match(char match_retrieve[], table & my_table, travel & to_retrieve);


int main()
{
	//Variables
	travel add_trip, my_trip, to_retrieve;
	table my_table;
	client your_trip;
	//load_file my_file;
	char file_name[SIZE] = "travel_data.txt";
	int option {0};
	char match_name[SIZE];
	char match_retrieve[SIZE];

	//file_name = "travel_data.txt";
	//my_table.display_all();
	do
	{
		option = menu();
		if (option == 1)
		{
			get_travel(your_trip, add_trip, my_table);
		}
		if (option == 2)
		{
			my_table.load(file_name, your_trip, add_trip);
		}
		if (option == 3)
		{
			my_table.display_all();
		}
		if (option == 4)
		{
			name_match(match_name, my_table);
		}
		if (option == 5)
		{
			retrieve_match(match_retrieve, my_table, to_retrieve);
		}
		if (option == 6)
		{}
		if (option == 8)
		{}
	} while (option != 8);
	return 0;
}

//Functions
//Menu for the user to choose
int menu()
{
	int option = 0;
	cout << "\n***TRAVEL LIST***"
		<< "\n1. Add a place to visit"
		<< "\n2. Load from an external file"
		<< "\n3. Display all"
		<< "\n4. Display the info for a particular match by location name"
		<< "\n5. Retrieve the infor for a particular match by location name"
		<< "\n6. Remove a location by name"
		<< "\n7. Display all by activities"
		<< "\n8. Quit";
	do
	{
		cout << "\nPick an option: ";
		cin >> option;
		cin.ignore(100, '\n');
		if (option < 1 || option > 8)
			cout << "\nTry again" << endl;
	} while (option < 1 || option > 8);
	return option;
}
//Prompt the user for the travel information
void get_travel(client & your_trip, travel & add_trip, table & my_table)
{
	cout << "\nName of the location: ";
	cin.get(your_trip.c_name, SIZE, '\n');
	cin.ignore(100, '\n');
	cout << "\nState and/or country (state, country): ";
	cin.get(your_trip.c_country, SIZE, '\n');
	cin.ignore(100, '\n');
	cout << "\nBest thing to do there: ";
	cin.get(your_trip.c_attract, SIZE, '\n');
	cin.ignore(SIZE, '\n');
	cout << "\nHow to travel to there: ";
	cin.get(your_trip.c_transport, SIZE, '\n');
	cin.ignore(100, '\n');
	cout << "\nImportant notes: ";
	cin.get(your_trip.c_notes, SIZE, '\n');
	cin.ignore(100, '\n');
	add_trip.create(your_trip);
	if (!my_table.insert(add_trip, your_trip))
		cerr << "\nCouldn't insert" << endl;
	//add_trip.display();
}
//Display a particular match by name
void name_match(char match_name[], table & my_table)
{
	cout << "\nWhat location do you want to find: ";
	cin.get(match_name, SIZE, '\n');
	cin.ignore(100, '\n');
	if (!my_table.display_match_name(match_name))
		cout << "\nCouldn't find match" << endl;
}
//Retrieve a particular match by name but not displaying it
void retrieve_match(char match_retrieve[], table & my_table, travel & to_retrieve)
{
	cout << "\nWhat location do you want to retrieve: ";
	cin.get(match_retrieve, SIZE, '\n');
	cin.ignore(100, '\n');
	if (!my_table.retrieve_match_name(match_retrieve, to_retrieve))
		cerr << "\nCouldn't retrieve" << endl;
	else
		cout << "\nRetrieved!" << endl;
}
