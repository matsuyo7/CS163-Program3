#include <iostream>
#include <cctype>
#include <cstring>

//Molina Nhoung, CS163, 5/9/23, Program 3
//The purpose of this file is to organize the data for the travel class and
//client inputed data to be used by other functions. This allows other 
//programmers to examine this file to know what to take and give to the user.

const int SIZE {200};	//constant size for static arrays

struct client
{
	char c_name[SIZE];	//user input name of the location
	char c_country[SIZE];	//user input state/city and country
	char c_attract[SIZE];	//user input attraction
	char c_time[SIZE];	//user input best time of year
	char c_transport[SIZE];	//user input how to get there
	char c_climate[SIZE];	//user input the weather
};

class travel
{
	public:
		travel();	//constructor
		~travel();	//destructor
		int copy(const client & to_copy);	//copy information from the client
		int display() const;	//display a travel information
		int retrieve(char match[]) const;	//retrieve travel information from the matching name
		int remove(char match[]);	//remove travel information form the matching name
	private:
		char * name;	//name of the location
		char * country;	//state/city and country
		char * attract;	//best things to do there
		char * time;	//best time of year
		char * transport;	//how to get there
		char * climate;	//type of weather there
};
