/*
MEMBER FUNCTION DESCRIPTIONS: 

Database()
Pre-Conditions: None
Post-Conditions: None
Description: Constructor for database

addRecord()
Pre-Conditions: int, string, int 
Post-Conditions: None
Description: 
uses hashing to add record into database array, 
rehashes value in case of collision 

deleteRecord()
Pre-Conditions: int, string, int 
Post-Conditions: None
Description: 
takes value and searches for value, if found 
deletes from array 

searchRecords()
Pre-Conditions: int, string, int
Post-Conditions: None
Description: 
Takes in value and searches for it using hashing, 
displays value found or prints that it does not exist

printTable()
Pre-Conditions: None 
Post-Conditions: None
Description: 
prints out all values of database array 

hashFunction()
Pre-Conditions: int 
Post-Conditions: returns int 
Description: 
takes int and hashes it, returns hash value back 

rehashFunction()
Pre-Conditions: int
Post-Conditions: returns int 
Description: 
reshashes function, and returns it.  Occurs when 
triggered by collision.  
*/
#ifndef DB_H
#define DB_H
#include <string>

using namespace std;

const int SIZE = 19; //declaring the constant value of the hash table (array) size

class Database //class declaration for the database
{
  public:
  	  Database(); //constructor function for database 
  	   
	  void addRecord(int custIDkey, string str_custName, int custAge); //function to add records to the database
	  void deleteRecord(int custIDkey, string str_custName, int custAge); //function to delete records from the database
	  int searchRecords(int custIDkey, string str_custName, int int_custName, int custAge); //function to search the database records
	  void printTable(); //function to display the contents of the database
	  int hashFunction(int custIDkey); //function for the hashing method
	  int rehashFunction(int custIDkey); //function for the hashing method
  	 
  private:
	  struct CustDB //structure to declare record data
	  {
		int custIDkey; //variable for customer ID
		string str_custName; //variable for customer name as a string (before atoi conversion)
		int int_custName; //variable for customer name as an int (after atoi conversion)
		int custAge; //variable for customer age
	  };
	   
	  CustDB hashTable[SIZE]; //array of structs
	  CustDB *custIDkeyPtr; //pointer for custIDkey variable
	  CustDB *custNamePtr; //pointer for custName variable
	  CustDB *custAgePtr; //pointer for custAge variable
	  int tableSlot; //current array slot variable
	  int nextSlot; //next proceeding slot variable in the array
	  int startIndex; //starting index variable in the array
};

#endif
