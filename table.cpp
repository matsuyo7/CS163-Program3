#include "table.h"
using namespace std;

//Molina Nhoung, CS163, 5/11/23, Program 3
//The purpose of this file is to implement the hash table functions
//using the travel class that would be dealing with the data. This will
//test out two different hash functions to get a better understanding of
//how a hash function and hash table really work.

//Constructor that will initialize the data to their equivalent zeros
table::table(int size)
{
	hash_table = new node*[size];
	for (int i = 0; i < size; ++i)
	{
		hash_table[i] = nullptr;
	}
	hash_table_size = size;
}
//Destructor to deallocate the memory
table::~table()
{
	for (int i = 0; i < hash_table_size; ++i)
	{
		node * current = hash_table[i];
		node * previous = current;
		while (current)
		{
			current = current->next;
			delete previous;
			previous = current;
		}
		hash_table[i] = nullptr;
	}
	delete [] hash_table;
	hash_table = nullptr;
}
//First hash function that passes in the key to work with to return a number
int table::hash_function(const char key[])
{
	int sum = 0;
	int length = strlen(key);
	for (int i = 0; i < length; ++i)
	{
		sum+=key[i];
	}
	return sum % hash_table_size;
}
//Second hash function to try that passes in the key to work with and return a number
int table::hash_function_2nd(const char key[])
{
	int sum = 0;
	int length = strlen(key);
	for (int i = 0; i < length; ++i)
	{
		if (tolower(key[i]) == 'a' || tolower(key[i]) == 'e' || tolower(key[i]) == 'i' || tolower(key[i]) == 'o' || tolower(key[i]) == 'u')
			sum = sum * key[i];
		else
			sum+=key[i];
	}
	return sum % hash_table_size;
}
//Add a travel item that's passed in as an argument and add it to the hash table
int table::insert(const travel & to_add, const client & to_key)
{
	int index = hash_function(to_key.c_name);
	node * temp = new node;
	if (!temp->trip.copy(to_add))
	{
		delete temp;
		return 0;
	}
	temp->next = hash_table[index];
	hash_table[index] = temp;
	return 1;
}
//Load in information from the external data file
int table::load(char file[], client & to_load, travel & to_add)
{
	ifstream file_in;
	file_in.open(file);	//open file
	if (!file_in)	//are we not connected
		return 0;
	//prime the pump
	file_in.get(to_load.c_name, SIZE, '|');
	file_in.ignore(100, '|');
	while (file_in && !file_in.eof())
	{
		//read the rest
		file_in.get(to_load.c_country, SIZE, '|');
		file_in.ignore(100, '|');
		file_in.get(to_load.c_attract, SIZE, '|');
		file_in.ignore(100, '|');
		file_in.get(to_load.c_time, SIZE, '|');
		file_in.ignore(100, '|');
		file_in.get(to_load.c_transport, SIZE, '|');
		file_in.ignore(100, '|');
		file_in.get(to_load.c_notes, SIZE, '\n');
		file_in.ignore(100, '\n');
		to_add.create(to_load);
		insert(to_add, to_load);

		//prime the pump
		file_in.get(to_load.c_name, SIZE, '|');
		file_in.ignore(100, '|');
	}
	file_in.close();
	return 1;
}
//Display all travel information
int table::display_all() const
{
	for (int i = 0; i < hash_table_size; ++i)
	{
		cout << "\nGroup " << i;
		node * current = hash_table[i];
		while (current)
		{
			current->trip.display();
			current = current->next;
		}
	}
	return 1;
}
//Display the information from the particular location name match
int table::display_match_name(char match[])
{
	int index = hash_function(match);
	node * current = hash_table[index];
	bool found = false;
	while (current)
	{
		if (current->trip.find(match))
		{
			current->trip.display();
			found = true;
		}
		current = current->next;
	}
	return found;
}
//Retrieve the information from the particular location name match
int table::retrieve_match_name(char match[], travel & find)
{
	int index = hash_function(match);
	node * current = hash_table[index];
	bool found = false;
	while (current)
	{
		if (current->trip.retrieve(match, find))
			found = true;
		current = current->next;
	}
	return found;
}
//Remove by the locatin name
int table::remove(char location[]) const
{}
//Display by the attraction match
int table::display_match_attract(char attraction[]) const
{}
