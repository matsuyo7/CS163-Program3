#include "table.h"
using namespace std;

//Molina Nhoung, CS163, 5/11/23, Program 3
//The purpose of this file is to implement the travel class which deals with the
//data directly with the class struct. The functions from the travel class will be used
//by the table class when dealing with data.

//Constructor to initialize the data members to zero
travel::travel()
{}
//Destructor to deallocate the memory
travel::~travel()
{}
//Create information from the client
int travel::create(const client & to_copy)
{
	if (to_copy.c_name == nullptr || to_copy.c_country == nullptr || to_copy.c_attract == nullptr || to_copy.c_time == nullptr 
	|| to_copy.c_transport == nullptr || to_copy.c_notes == nullptr)
		return 0;
	name = new char [strlen(to_copy.c_name) + 1];
	strcpy(name, to_copy.c_name);
	country = new char [strlen(to_copy.c_country) + 1];
	strcpy(country, to_copy.c_country);
	attract = new char [strlen(to_copy.c_attract) + 1];
	strcpy(attract, to_copy.c_attract);
	time = new char [strlen(to_copy.c_time) + 1];
	strcpy(time, to_copy.c_time);
	transport = new char [strlen(to_copy.c_transport) + 1];
	strcpy(transport, to_copy.c_transport);
	notes = new char [strlen(to_copy.c_notes) + 1];
	strcpy(notes, to_copy.c_notes);
	return 1;
}
//Create information from the external file
int travel::create_file(const load_file & to_copy)
{}
//Copy information from the client
int travel::copy(const travel & to_add)
{
	name = new char [strlen(to_add.name) + 1];
	strcpy(name, to_add.name);
	country = new char [strlen(to_add.country) + 1];
	strcpy(country, to_add.country);
	attract = new char [strlen(to_add.attract) + 1];
	strcpy(attract, to_add.attract);
	time = new char [strlen(to_add.time) + 1];
	strcpy(time, to_add.time);
	transport = new char [strlen(to_add.transport) + 1];
	strcpy(transport, to_add.transport);
	notes = new char [strlen(to_add.notes) + 1];
	strcpy(notes, to_add.notes);
	return 1;
}
//Display a travel information
int travel::display() const
{
	if (name == nullptr || country == nullptr || attract == nullptr || time == nullptr || transport == nullptr || notes == nullptr)
		return 0;
	cout << "\nName: " << name
		<< "\nState/Country: " << country
		<< "\nAttraction: " << attract
		<< "\nBest time of year: " << time
		<< "\nHow to get there: " << transport
		<< "\nNotes: " << notes << endl;
	return 1;
}
//Retrieve travel information from the matching name
int travel::retrieve(char match[]) const
{}
//Remove travel information form the matching name
int travel::remove(char match[])
{}
