#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include "db.h"

using namespace std;

Database::Database() //constructor function for database
{
   custIDkeyPtr = hashTable;
   custNamePtr = hashTable;
   custAgePtr = hashTable;
   tableSlot = 0;
  
   for(tableSlot = 0; tableSlot < SIZE; tableSlot++)
   {
	 custIDkeyPtr[tableSlot].custIDkey = 0;
	 custNamePtr[tableSlot].str_custName = "Empty";
	 custAgePtr[tableSlot].custAge = 0;
   }	
}

int Database::hashFunction(int custIDkey) //function for the hashing method
{
   return (custIDkey % SIZE); //mod custID by 19
}

int Database::rehashFunction(int custIDkey) //function for the hashing method
{
   return ((custIDkey + 1) % SIZE); //mod custId by 19 
}

void Database::addRecord(int custIDkey, string str_custName, int custAge) //function to add records to the database
{
   int tableSlot = hashFunction(custIDkey); //hash customer id to find array slot
   bool empty = true; 
   
   if(custIDkeyPtr[tableSlot].custIDkey == 0) //if value of tableslot is empty, enter in data
   {
     custIDkeyPtr[tableSlot].custIDkey = custIDkey; //initial key and data values entered into the current empty array slot
     custNamePtr[tableSlot].str_custName = str_custName;
     custAgePtr[tableSlot].custAge = custAge;
   }
   else //if collision, rehash customer id 
   {
   	 int tableSlot = rehashFunction(custIDkey); //rehash customer id 
   	 
	 custIDkeyPtr[tableSlot].custIDkey = custIDkey; 
	 custNamePtr[tableSlot].str_custName = str_custName; 
	 custAgePtr[tableSlot].custAge = custAge; 
   }
}

void Database::deleteRecord(int custIDkey, string str_custName, int custAge) //function to delete records from the database
{
   int tableSlot = hashFunction(custIDkey); //hash search value 
   
   if(custIDkeyPtr[tableSlot].custIDkey == 0) //if value is 0, record does not exist
   {
   	 cout << "Record does not exist" << endl; 
   }
   else if(custIDkeyPtr[tableSlot].custIDkey == custIDkey) //if record is found, delete it
   {
   	 custIDkeyPtr[tableSlot].custIDkey = 0; 
   	 custNamePtr[tableSlot].str_custName = "empty"; 
   	 custAgePtr[tableSlot].custAge = 0; 
   	 cout << "Record Deleted" << endl; 
   }
   else 
   {
   	 tableSlot = rehashFunction(custIDkey); //rehash in case of collsion 
   	 
   	 if(custIDkeyPtr[tableSlot].custIDkey == custIDkey) //delete record in database
   	 {
   	   	custIDkeyPtr[tableSlot].custIDkey = 0; 
   	   	custNamePtr[tableSlot].str_custName = "empty"; 
   	   	custAgePtr[tableSlot].custAge = 0;
	    cout << "Record Deleted" << endl;  
	 }
	 else //if record does not exist 
	 {
	 	cout << "Record does not exist" << endl; 
	 }
   }
}

int Database::searchRecords(int custIDkey, string str_custName, int int_custName, int custAge) //function to search the database records
{
   int startIndex = hashFunction(custIDkey); //call hash function 
   
   if(custIDkeyPtr[startIndex].custIDkey == 0) //if record is empty on initial hash 
   {
   	 cout << "Record does not exist" << endl; 
   }
   else if(custIDkeyPtr[startIndex].custIDkey == custIDkey) //if hash search finds correct record
   {
     cout << "Record found at key: " << custIDkeyPtr[startIndex].custIDkey << endl; //returning the data stored from the 3 structs in the array to the call function
     cout << "Customer ID: " << custIDkeyPtr[startIndex].custIDkey << endl;
     cout << "Customer Name: " << custNamePtr[startIndex].str_custName << endl;
     cout << "Customer Age: " << custAgePtr[startIndex].custAge << endl;
   }
   else	 //if colision occurs during search 
   {
     startIndex = rehashFunction(custIDkey); //rehash id 
     if(custIDkeyPtr[startIndex].custIDkey == custIDkey) //compare id value to search value
     {
     	cout << "Record found at key: " << custIDkeyPtr[startIndex].custIDkey << endl; //if found, print out values 
     	cout << "Customer ID: " << custIDkeyPtr[startIndex].custIDkey << endl; 
     	cout << "Customer Name: " << custNamePtr[startIndex].str_custName << endl; 
     	cout << "Customer Age: " << custAgePtr[startIndex].custAge << endl; 
	 }
	 else //if record is not found 
	   cout << "Record does not exist" << endl; 
   }
}

void Database::printTable() //function to display the contents of the database
{ 
   int recordNum = 1; 
   cout << "Displaying Customer ID database records:" << endl; 
   for(tableSlot = 0; tableSlot < SIZE; tableSlot++)
   {
   	 cout << "Record: " << recordNum << endl; 
	 cout << custIDkeyPtr[tableSlot].custIDkey << endl;
	 cout << custNamePtr[tableSlot].str_custName << endl; 
	 cout << custAgePtr[tableSlot].custAge << endl; 
	 recordNum++; 
   }	
}
