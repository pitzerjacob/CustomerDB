#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include "db.h"

using namespace std;

int main(void)
{ //variable declarations
  Database db1; //initialize instance of database object 
  ifstream ipt; //initialize input stream 
  int custIDkeyTemp; //input file variable for customer ID
  int custIDkey; //variable for customer ID
  string str_custNameTemp; //input file variable for customer Name
  string str_custName; //variable for customer name as a string (before atoi conversion)
  int int_custName; //variable for customer name as an int (after atoi conversion)
  int custAgeTemp; //input file variable for customer Age
  int custAge; //variable for customer age
  int choice; //switch case selection variable
  bool fail; //bad data error checking variable
  bool quit = false; //exiting program loop variable
  
  ipt.open("input.txt"); //open input text file
  if(ipt.fail()) //error checking for in/output files
  { 
  	cout << "Error Opening File" << endl;
  	exit (1);
  } 
  
   do //loop for reading input file data
   {
     ipt >> custIDkeyTemp; 
	 ipt >> str_custNameTemp; 
	 ipt >> custAgeTemp;
	 db1.addRecord(custIDkeyTemp,str_custNameTemp,custAgeTemp);  //add input values into database
   } while(!ipt.eof()); //read in initial values from file
	
  ipt.close(); //close input file
  
  cout << "Welcome to the Database" << endl; //welcome message and main menu
  cout << "Main Menu:" << endl; 
  
  do
  { //display main menu 
  	cout << "1. Add a new record to the database" << endl; 
  	cout << "2. Delete current record from the database" << endl; 
  	cout << "3. Search for a specific record" << endl; 
  	cout << "4. Display contents of the database" << endl; 
  	cout << "5. Quit the program" << endl; //end main menu 

    do 
	{
     cin >> choice; //read in choice
	 bool fail = cin.fail();
     if(fail) //error checking if the input fails (bad data was read)
	 {
       cin.clear(); //clear bad input flag
       cin.ignore(1000, '\n'); //discards bad input
     }
	} while(fail);
	
	switch(choice) //begin swtich case
  	 {
		case 1: //add record to database option
			cout << "Enter key of the record to be added:" << endl;  
			do 
			{
     		 cin >> custIDkey;
			 if(custIDkey < 0000 || custIDkey > 9999) //checking for 4 digit ID number range
			 {  
     		   cout << "Invalid ID number, please Re-Enter" << endl; //error check if invalid response
	 		   cin.clear(); //clear bad input flag
       		   cin.ignore(1000, '\n'); //discards bad input
     		 }
			} while(custIDkey < 0000 || custIDkey > 9999);
			
			cout << "Enter name of the record to be added:" << endl;  
			do 
			{
     		 cin >> str_custName;
			 if(str_custName.length() > 25) //checking for names up to 25 characters
			 {
       		   cout << "Invalid name, please Re-Enter" << endl; //error check if invalid response
			   cin.clear(); //clear bad input flag
       		   cin.ignore(1000, '\n'); //discards bad input
     		 }
			} while(str_custName.length() > 25);
			
			cout << "Enter age of the record to be added:" << endl;  
			do 
			{
     		 cin >> custAge;
			 if(custAge < 18 || custAge > 120) //checking for ages in the 18 to 120 range
			 {
       		   cout << "Invalid age range, please Re-Enter" << endl; //error check if invalid response
			   cin.clear(); //clear bad input flag
       		   cin.ignore(1000, '\n'); //discards bad input
     		 }
			} while(custAge < 18 || custAge > 120);
			db1.addRecord(custIDkey, str_custName, custAge); //call addRecord function
			cout << "Record added to the database" << endl;
			break; 
		
		case 2: //delete record from database option
			cout << "Enter key of the record to be deleted:" << endl;  
			do 
			{
     		 cin >> custIDkey;
			 if(custIDkey < 0 || custIDkey > 9999) //checking for 4 digit ID number range
			 {  
     		   cout << "Invalid ID number, please Re-Enter" << endl; //error check if invalid response
	 		   cin.clear(); //clear bad input flag
       		   cin.ignore(1000, '\n'); //discards bad input
     		 }
			} while(custIDkey < 0 || custIDkey > 9999);
			db1.deleteRecord(custIDkey, str_custName, custAge); //call deleteRecord function
			break; 
		
		case 3: //search database option
			cout << "Enter key of the record to be searched for:" << endl;  
			do 
			{
     		 cin >> custIDkey;
			 if(custIDkey < 0000 || custIDkey > 9999) //checking for 4 digit ID number range
			 {  
     		   cout << "Invalid ID number, please Re-Enter" << endl; //error check if invalid response
	 		   cin.clear(); //clear bad input flag
       		   cin.ignore(1000, '\n'); //discards bad input
     		 }
			} while(custIDkey < 0000 || custIDkey > 9999);
            cout << db1.searchRecords(custIDkey, str_custName, int_custName, custAge) << endl; //call searchRecords function
			break; 
		
		case 4: //print hash table database option 
			db1.printTable(); //call printTable function
			break; 
		
		case 5: //quit program option
			cout << "Ending program..." << endl;  //end program
			quit = true; 
			break; 	
		
		default: //invalid input error check, default case
			cout << "Invalid input, please Re-Enter" << endl; //error check if invalid response
			break; 
  	 }
  } while(quit != true); //end loop 

    system("PAUSE");
    return EXIT_SUCCESS;
}//end main 


