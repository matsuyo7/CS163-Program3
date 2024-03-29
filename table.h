#include <iostream>
#include <cctype>
#include <cstring>
#include <fstream>

//Molina Nhoung, CS163, 5/19/23, Program 3
//The purpose of this file is to create a hash function and hash table 
//where each index of will point to the head of a LLL of travel locations.
//The data organized will allow other programmers to examine the file to
//allow the user to manipulate their own travel location and see how the
//data is distributed.

const int SIZE {200};	//constant size for static arrays

struct client
{
	char c_name[SIZE];	//user input name of the location
	char c_country[SIZE];	//user input state and country
	char c_attract[SIZE];	//user input attraction
	char c_time[SIZE];	//user input best time of year
	char c_transport[SIZE];	//user input how to get there
	char c_notes[SIZE];	//user input important information to know about
};

class travel
{
	public:
		travel();	//constructor
		~travel();	//destructor
		int create(const client & to_copy);	//create information from the client
		int copy(const travel & to_add);	//copy information to be inserted
		int display() const;	//display a travel information
		int find(char match[]) const;	//find a match with the name and return true
		int retrieve(char match[], travel & find) const;	//retrieve travel information from the matching name
	private:
		char * name;	//name of the location
		char * country;	//state/city and country
		char * attract;	//best things to do there
		char * time;	//best time of year
		char * transport;	//how to get there
		char * notes;	//important notes to know about
};

struct node
{
	travel trip;	//object for one travel item
	node * next;
};

class table
{
	public:
		table(int size = 101);	//constructor that will also test the table size
		~table();	//destructor
		int insert(const client & to_key);	//add a travel item that's passed in as an argument and add it to the hash table
		int load(char file[], client & to_load, travel & to_add);	//load in information from the external data file
		int display_all() const;	//display all travel information
		int display_match_name(char match[]);	//display the information from the particular location name match
		int retrieve_match_name(char match[], travel & find);	//retrieve the information from the particular location name match
		int remove_location(char location[]);	//remove by the locatin name
		int display_match_time(char season[]) const;	//display by the seasonal match
	private:
		node ** hash_table;	//dynamically alocated array of head pointers
		int hash_table_size;	//size of the hash table
		int hash_function(const char key[]);	//first hash function that passes in the key to work with to return a number
		int hash_function_2nd(const char key[]);	//second hash function to try that passes in the key to work with and return a number
		int display_match_name(node * head, char match[]);	//recursive call for display match name
};

