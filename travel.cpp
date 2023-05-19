#include "table.h"
using namespace std;

//Molina Nhoung, CS163, 5/11/23, Program 3
//The purpose of this file is to implement the travel class which deals with the
//data directly with the class struct. The functions from the travel class will be used
//by the table class when dealing with data.

//Constructor to initialize the data members to zero
travel::travel()
{
	name = nullptr;
	country = nullptr;
	attract = nullptr;
	time = nullptr;
	transport = nullptr;
	notes = nullptr;
}
//Destructor to deallocate the memory
travel::~travel()
{
	if (name)
		delete [] name;
	name = nullptr;
	if (country)
		delete [] country;
	country = nullptr;
	if (attract)
		delete [] attract;
	attract = nullptr;
	if (time)
		delete [] time;
	time = nullptr;
	if (transport)
		delete [] transport;
	transport = nullptr;
	if (notes)
		delete [] notes;
	notes = nullptr;
}
//To remove any information already stored so that new information can be stored
/*int travel::clean()
{
	if (name)
		delete [] name;
	name = nullptr;
	if (country)
		delete [] country;
	country = nullptr;
	if (attract)
		delete [] attract;
	attract = nullptr;
	if (time)
		delete [] time;
	time = nullptr;
	if (transport)
		delete [] transport;
	transport = nullptr;
	if (notes)
		delete [] notes;
	notes = nullptr;
	return 1;
}*/
//Create information from the client
int travel::create(const client & to_copy)
{
	if (to_copy.c_name == nullptr || to_copy.c_country == nullptr || to_copy.c_attract == nullptr || to_copy.c_time == nullptr 
	|| to_copy.c_transport == nullptr || to_copy.c_notes == nullptr)
		return 0;
	//clean();
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
//Copy information from the client
/*int travel::copy(const travel & to_add)
{
	//clean();
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
}*/
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
//Find a match with the name and return true
int travel::find(char match[]) const
{
	if (name == nullptr || time == nullptr)
		return 0;
	if (!strcmp(match, name) || !strcmp(match, time))
		return 1;
	return 0;
}
//Retrieve travel information from the matching name
int travel::retrieve(char match[], travel & find) const
{
	if (name == nullptr)
		return 0;
	if (!strcmp(match, name))
	{
//		find.name = new char [strlen(name) + 1];
		if (!find.name)
			find.name = new char[1000];
		strcpy(find.name, name);
//		find.country = new char [strlen(country) + 1];
		if (!find.country)
			find.country = new char[1000];
		strcpy(find.country, country);
//		find.attract = new char [strlen(attract) + 1];
		if (!find.attract)
			find.attract = new char[1000];
		strcpy(find.attract, attract);
//		find.time = new char [strlen(time) + 1];
		if (!find.time)
			find.time = new char[1000];
		strcpy(find.time, time);
//		find.transport = new char [strlen(transport) + 1];
		if (!find.transport)
			find.transport = new char[1000];
		strcpy(find.transport, transport);
//		find.notes = new char [strlen(notes) + 1];
		if (!find.notes)
			find.notes = new char[1000];
		strcpy(find.notes, notes);
		return 1;
	}
	return 0;
}
