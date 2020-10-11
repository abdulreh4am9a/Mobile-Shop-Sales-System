#include<iostream>
#include<string>
#include<fstream>
using namespace std;
struct mobilePhone
{
	char company[30];		//////////////////////////////
	char name[30];			//////////////////////////////
	double display;			//////////////////////////////
	char processor[30];		//////////////////////////////
	int frontCamera;		//////////////////////////////
	int rareCamera;			///FEATURES OF MOBILE PHONE///
	int ram;				//////////////////////////////
	int storage;			//////////////////////////////
	int battery;			//////////////////////////////
	char os[30];			//////////////////////////////
	int price;				//////////////////////////////
};
void addMobile(const char* filename);			//Function to get input against different features from user and to store that record on file
void searchMobile(const char* filename);		//Function to ask user wether to search by company, name, display size, processor, camera resolutions, ram, storage, battery or in price range
void searchbyCompany(const char* filename);		//Search by company name
void searchbyName(const char* filename);		//Search by mobile name
void searchbyDisplay(const char* filename);		//Search by display size
void searchbyProcessor(const char* filename);	//Search by Processor
void searchbyFrontCamera(const char* filename); //Search by front camera resolution
void searchbyRareCamera(const char* filename);	//Search by rare camera resolution
void searchbyRAM(const char* filename);			//Search by ram capacity
void searchbyStorage(const char* filename);		//Search by storage capacity
void searchbyBattery(const char* filename);		//Search by battery capacity
void searchbyOS(const char* filename);			//Search by operating system type
void searchbyPrice(const char* filename);		//Search by price range
void updateMobile(const char* filename);		//Update a record
void deleteMobile(const char* filename);		//Delete a record
void displayMobile(mobilePhone m);				//Display a record
void displayFile(const char* filename);			//Display all records present in files
void systemMenu(const char* filename);			//Menu to call all functions