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
{}
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
int table::hash_function_2nd(char key[]) const
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
int table::insert(const client & to_add)
{
	int index = hash_function(to_add.c_name);
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
int table::load()
{
	ifstream file_in;
	file_in.open("travel_data.txt");
	if (!file_in)
		return 0;


//Display all travel information
int table::display_all() const
{}
//Display the information from the particular location name match
int table::display_match_name(char match[])
{}
//Retrieve the information from the particular location name match
int table::retrieve_match_name(char match[], travel & find)
{}
//Remove by the locatin name
int table::remove(char location[]) const
{}
//Display by the attraction match
int table::display_match_attract(char attraction[]) const
{}
