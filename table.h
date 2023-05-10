#include "travel.h"

//Molina Nhoung, CS163, 5/9/23, Program 3
//The purpose of this file is to create a hash function and hash table 
//where each index of will point to the head of a LLL of travel locations.
//The data organized will allow other programmers to examine the file to
//allow the user to manipulate their own travel location and see how the
//data is distributed.

struct node
{
	travel a_trip;	//object for one travel item
	node * next;
};

class table
{
	public:
		table(int size = 55);	//constructor that will also test the table size
		~table();	//destructor
		int insert(const travel & to_add);	//add a travel item that's passed in as an argument and add it to the hash table
		int load()	//load in information from the external data file
		int display_all() const;	//display all travel information
		int display_match_name(char match[]);	//display the information from the particular location name match
		int retrieve_match_name(char match[], travel & find);	//retrieve the information from the particular location name match
		int remove(char location[]) const;	//remove by the locatin name
		int display_match_attract(char attraction[]) const;	//display by the attraction match
	private:
		node ** hash_table;	//dynamically alocated array of head pointers
		int hash_table_size;	//size of the hash table
		int hash_function(char key[]) const;	//first hash function that passes in the key to work with to return a number
		int hash_function_2nd(char key[]) const;	//second hash function to try that passes in the key to work with and return a number
};

