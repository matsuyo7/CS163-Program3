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
//Copy information from the client
int travel::copy(const client & to_copy)
{}
//Display a travel information
int travel::display() const
{}
//Retrieve travel information from the matching name
int travel::retrieve(char match[]) const
{}
//Remove travel information form the matching name
int travel::remove(char match[])
{}
