#include "table.h"
using namespace std;

//Molina Nhoung, CS163, 5/12/23, Program 3
//The purpose of this file is to test the ADT and act as the application.
//This will prompt the user and send information to the ADT to be used,
//then the ADT will return success/failure for the application to
//output the right messages.

//Prototypes
int menu();
void get_travel(client & your_trip, table & my_table);
void name_match(char match_name[], table & my_table);
void retrieve_match(char match_retrieve[], table & my_table, travel & to_retrieve);
void remove_match(char match_remove[], table & my_table);
void display_all_time(char match_time[], table & my_table);

int main()
{
	//Variables
	travel add_trip, to_retrieve;
	table my_table;
	client your_trip;
	char file_name[SIZE] = "travel_data.txt";
	int option {0};
	char match_name[SIZE];
	char match_retrieve[SIZE];
	char match_remove[SIZE];
	char match_time[SIZE];

	do
	{
		option = menu();
		if (option == 1)
		{
			get_travel(your_trip, my_table);
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
		{
			remove_match(match_remove, my_table);
		}
		if (option == 7)
		{
			display_all_time(match_time, my_table);
		}
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
void get_travel(client & your_trip, table & my_table)
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
	cout << "\nBest time/season to go there: ";
	cin.get(your_trip.c_time, SIZE, '\n');
	cin.ignore(100, '\n');
	cout << "\nHow to travel to there: ";
	cin.get(your_trip.c_transport, SIZE, '\n');
	cin.ignore(100, '\n');
	cout << "\nImportant notes: ";
	cin.get(your_trip.c_notes, SIZE, '\n');
	cin.ignore(100, '\n');
	if (!my_table.insert(your_trip))
		cerr << "\nCouldn't insert" << endl;
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
		to_retrieve.display();
}
//Remove by a matching location name
void remove_match(char match_remove[], table & my_table)
{
	cout << "\nWhat location do you want to remove: ";
	cin.get(match_remove, SIZE, '\n');
	cin.ignore(100, '\n');
	if (!my_table.remove_location(match_remove))
		cout << "\nCouldn't remove" << endl;
	else
		cout << "\nRemoved" << endl;
}
//Display all locations with good seasonal times to go
void display_all_time(char match_time[], table & my_table)
{
	cout << "\nWhat season(s) to look for: ";
	cin.get(match_time, SIZE, '\n');
	cin.ignore(100, '\n');
	if (!my_table.display_match_time(match_time))
		cout << "\nCouldn't display" << endl;
}
