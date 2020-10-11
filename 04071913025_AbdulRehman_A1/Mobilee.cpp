#include"Mobile.h"
void systemMenu(const char* filename) { //filename is taken as command line argument that's why passed as const char* so that we can not change the file name accidentally
	char choice; //to find user's choice
	while (1) { //always true so that the menu gets displayed after termination of each function //it will only terminate if user wants to
		//menu display using escape characters
		cout << endl << "\tF U N C T I O N S \t M E N U :" << endl << endl;
		cout << "\t[A] : Add  a new Mobile Phone" << endl;
		cout << "\t[S] : Search a Mobile Phone" << endl;
		cout << "\t[U] : Update a Mobile Phone" << endl;
		cout << "\t[D] : Delete a Mobile Phone" << endl;
		cout << "\t[F] : Display all File Data" << endl;
		cout << "\t[Q] : Exit" << endl;
		cout << endl << "Please enter a relevant character: ";
		cin >> choice; //getting a char by user for the function he or she wants to call
		switch (choice) //the char entered by user is passed in switch statement to check different cases
		{
			case 'A':
			case'a':addMobile(filename);break;

			case'S':
			case's':searchMobile(filename);break;

			case'U':
			case'u':updateMobile(filename);break;

			case'D':
			case'd':deleteMobile(filename);break;
				
			case'F':
			case'f':displayFile(filename);break;

			case'Q':
			case'q':exit(0);break; //if user enters q the program ends

			default:cout << endl << "PLEASE ENTER THE CORRECT OPTION [A/S/U/D/F/Q]" << endl << endl;break;
				//in case of wrong option the above msg is displayed and while loop again shows the functions menu
		}
	}
}

void addMobile(const char* filename) {
	//to add a new mobile record, we open the file in append mode and if the file is open we take input against all the members of the structure
	cout << endl;
	ofstream thefile(filename, ios::binary | ios::app);
	if (thefile.is_open()) {
		thefile.seekp(0, ios::end);
		mobilePhone m;
		cout << "Enter Company Name: ";
		cin.ignore(30, '\n');
		cin.getline(m.company, 30);
		cout << "Enter Model Name: ";
		cin.getline(m.name, 30);
		cout << "Enter Display Size [Inches]: ";
		cin >> m.display;
		cout << "Enter Processor Name: ";
		cin.ignore(30, '\n');
		cin.getline(m.processor, 30);
		cout << "Enter Front Camera [MP]: ";
		cin >> m.frontCamera;
		cout << "Enter Rare Camera [MP]: ";
		cin >> m.rareCamera;
		cout << "Enter RAM Capacity [GB]: ";
		cin >> m.ram;
		cout << "Enter Storage Capacity [GB]: ";
		cin >> m.storage;
		cout << "Enter Battery Capacity [mAh]: ";
		cin >> m.battery;
		cout << "Enter Operating System [iOS/Android]: ";
		cin.ignore(30, '\n');
		cin.getline(m.os, 30);
		cout << "Enter Price [PKR]: ";
		cin >> m.price;
		cout << endl << "Record Entered!" << endl;
		//after taking all inputs from user we write the whole record on to the file and then close the file
		thefile.write((const char*)&m, sizeof(mobilePhone));
		thefile.close();
		//the record written on the file is also displayed
		displayMobile(m);
	}
	else //if the file is not opened a msg is displayed
		cout << "Couldn't Open file" << endl;
}

void searchMobile(const char* filename) {
	char choice;
	while (1) {
		//Asking user against which feature he or she wants to search a record
		cout << endl << "\tS E A R C H \t C R I E T E R I A :" << endl << endl;
		cout << "\t[C] : Search by Company" << endl;
		cout << "\t[N] : Search by Name/Model" << endl;
		cout << "\t[D] : Search by Display Size" << endl;
		cout << "\t[P] : Search by Processor" << endl;
		cout << "\t[F] : Search by Front Camera Resolution" << endl;
		cout << "\t[R] : Search by Rare  Camera Resolution" << endl;
		cout << "\t[M] : Search by RAM Capacity" << endl;
		cout << "\t[S] : Search by Storage Capacity" << endl;
		cout << "\t[B] : Search by Battery Capacity" << endl;
		cout << "\t[O] : Search by Operating System" << endl;
		cout << "\t[X] : Search in Price Range" << endl;
		cout << "\t[Q] : Go back to Main Menu" << endl;
		cout << endl << "Please enter a relevant character: ";
		cin >> choice;
		switch (choice)
		{
		case 'C':
		case'c':searchbyCompany(filename);break;

		case 'N':
		case'n':searchbyName(filename);break;

		case 'D':
		case'd':searchbyDisplay(filename);break;

		case 'P':
		case'p':searchbyProcessor(filename);break;

		case 'F':
		case'f':searchbyFrontCamera(filename);break;

		case 'R':
		case'r':searchbyRareCamera(filename);break;

		case 'M':
		case'm':searchbyRAM(filename);break;

		case 'S':
		case's':searchbyStorage(filename);break;

		case 'B':
		case'b':searchbyBattery(filename);break;

		case 'O':
		case'o':searchbyOS(filename);break;

		case 'X':
		case'x':searchbyPrice(filename);break;

		case 'Q':
		case'q':systemMenu(filename);break; //if user wants to go back to main menu he or she will press q and we will call the system menu function again

		default:cout << endl << "PLEASE ENTER THE CORRECT OPTION [C/N/D/P/F/R/M/S/B/O/X/Q]" << endl << endl;break;
		}
	}
}
//in search funtions below we read records from file one by one by opening file in read mode, and check the equal or greator then equal to conditions against respective feature and if the condition meets we will display the record
//in the end the counter will tell how many records meet the condition and are displayed
void searchbyCompany(const char* filename) {
	cout << endl;
	ifstream thefile(filename, ios::binary);
	if (thefile.is_open()) {
		char temp[30];
		cout << "Enter the name of company whose mobiles you want to search: ";
		cin.ignore(30, '\n');
		cin.getline(temp, 30);
		int i = 0;
		while (thefile.good()) {
			mobilePhone m;
			thefile.read((char*)&m, sizeof(mobilePhone));
			if (strcmp(temp, m.company) == 0) {
				if (thefile.gcount() > 0) {
					cout << endl << "Record " << ++i << ":";
					displayMobile(m);
				}
			}
		}
		if (i==0) {
			cout << endl << "Sorry! No such record found!" << endl;
		}
		else {
			cout << endl << i << " Record(s) Found!" << endl;
		}
		thefile.close();
	}
	else
		cout << "Couldn't Open file" << endl;
}

void searchbyName(const char* filename) {
	cout << endl;
	ifstream thefile(filename, ios::binary);
	if (thefile.is_open()) {
		char temp[30];
		cout << "Enter the name of mobile you want to search: ";
		cin.ignore(30, '\n');
		cin.getline(temp, 30);
		int i = 0;
		while (thefile.good()) {
			mobilePhone m;
			thefile.read((char*)&m, sizeof(mobilePhone));
			if (strcmp(temp, m.name) == 0) {
				if (thefile.gcount() > 0) {
					cout << endl << "Record " << ++i << ":";
					displayMobile(m);
				}
			}
		}
		if (i == 0) {
			cout << endl << "Sorry! No such record found!" << endl;
		}
		else {
			cout << endl << i << " Record(s) Found!" << endl;
		}
		thefile.close();
	}
	else
		cout << "Couldn't Open file" << endl;
}

void searchbyDisplay(const char* filename) {
	cout << endl;
	ifstream thefile(filename, ios::binary);
	if (thefile.is_open()) {
		double size;
		cout << "Enter the minimum size in inches of mobiles you want to search: ";
		cin >> size;
		int i = 0;
		while (thefile.good()) {
			mobilePhone m;
			thefile.read((char*)&m, sizeof(mobilePhone));
			if (m.display>=size) {
				if (thefile.gcount() > 0) {
					cout << endl << "Record " << ++i << ":";
					displayMobile(m);
				}
			}
		}
		if (i == 0) {
			cout << endl << "Sorry! No such record found!" << endl;
		}
		else {
			cout << endl << i << " Record(s) Found!" << endl;
		}
		thefile.close();
	}
	else
		cout << "Couldn't Open file" << endl;
}

void searchbyProcessor(const char* filename) {
	cout << endl;
	ifstream thefile(filename, ios::binary);
	if (thefile.is_open()) {
		char temp[30];
		cout << "Enter the name of processor installed in mobiles you want to search: ";
		cin.ignore(30, '\n');
		cin.getline(temp, 30);
		int i = 0;
		while (thefile.good()) {
			mobilePhone m;
			thefile.read((char*)&m, sizeof(mobilePhone));
			if (strcmp(temp, m.processor) == 0) {
				if (thefile.gcount() > 0) {
					cout << endl << "Record " << ++i << ":";
					displayMobile(m);
				}
			}
		}
		if (i == 0) {
			cout << endl << "Sorry! No such record found!" << endl;
		}
		else {
			cout << endl << i << " Record(s) Found!" << endl;
		}
		thefile.close();
	}
	else
		cout << "Couldn't Open file" << endl;
}

void searchbyFrontCamera(const char* filename) {
	cout << endl;
	ifstream thefile(filename, ios::binary);
	if (thefile.is_open()) {
		int temp;
		cout << "Enter the minimum resolution in MP of front camera of mobiles you want to search: ";
		cin >> temp;
		int i = 0;
		while (thefile.good()) {
			mobilePhone m;
			thefile.read((char*)&m, sizeof(mobilePhone));
			if (m.frontCamera >= temp) {
				if (thefile.gcount() > 0) {
					cout << endl << "Record " << ++i << ":";
					displayMobile(m);
				}
			}
		}
		if (i == 0) {
			cout << endl << "Sorry! No such record found!" << endl;
		}
		else {
			cout << endl << i << " Record(s) Found!" << endl;
		}
		thefile.close();
	}
	else
		cout << "Couldn't Open file" << endl;
}

void searchbyRareCamera(const char* filename) {
	cout << endl;
	ifstream thefile(filename, ios::binary);
	if (thefile.is_open()) {
		int temp;
		cout << "Enter the minimum resolution in MP of rare camera of mobiles you want to search: ";
		cin >> temp;
		int i = 0;
		while (thefile.good()) {
			mobilePhone m;
			thefile.read((char*)&m, sizeof(mobilePhone));
			if (m.rareCamera >= temp) {
				if (thefile.gcount() > 0) {
					cout << endl << "Record " << ++i << ":";
					displayMobile(m);
				}
			}
		}
		if (i == 0) {
			cout << endl << "Sorry! No such record found!" << endl;
		}
		else {
			cout << endl << i << " Record(s) Found!" << endl;
		}
		thefile.close();
	}
	else
		cout << "Couldn't Open file" << endl;
}


void searchbyRAM(const char* filename) {
	cout << endl;
	ifstream thefile(filename, ios::binary);
	if (thefile.is_open()) {
		int temp;
		cout << "Enter the minimum RAM capacity in GB of mobiles you want to search: ";
		cin >> temp;
		int i = 0;
		while (thefile.good()) {
			mobilePhone m;
			thefile.read((char*)&m, sizeof(mobilePhone));
			if (m.ram >= temp) {
				if (thefile.gcount() > 0) {
					cout << endl << "Record " << ++i << ":";
					displayMobile(m);
				}
			}
		}
		if (i == 0) {
			cout << endl << "Sorry! No such record found!" << endl;
		}
		else {
			cout << endl << i << " Record(s) Found!" << endl;
		}
		thefile.close();
	}
	else
		cout << "Couldn't Open file" << endl;
}


void searchbyStorage(const char* filename) {
	cout << endl;
	ifstream thefile(filename, ios::binary);
	if (thefile.is_open()) {
		int temp;
		cout << "Enter the minimum storage capacity in GB of mobiles you want to search: ";
		cin >> temp;
		int i = 0;
		while (thefile.good()) {
			mobilePhone m;
			thefile.read((char*)&m, sizeof(mobilePhone));
			if (m.storage >= temp) {
				if (thefile.gcount() > 0) {
					cout << endl << "Record " << ++i << ":";
					displayMobile(m);
				}
			}
		}
		if (i == 0) {
			cout << endl << "Sorry! No such record found!" << endl;
		}
		else {
			cout << endl << i << " Record(s) Found!" << endl;
		}
		thefile.close();
	}
	else
		cout << "Couldn't Open file" << endl;
}


void searchbyBattery(const char* filename) {
	cout << endl;
	ifstream thefile(filename, ios::binary);
	if (thefile.is_open()) {
		int temp;
		cout << "Enter the minimum battery capacity in mAh of mobiles you want to search: ";
		cin >> temp;
		int i = 0;
		while (thefile.good()) {
			mobilePhone m;
			thefile.read((char*)&m, sizeof(mobilePhone));
			if (m.battery >= temp) {
				if (thefile.gcount() > 0) {
					cout << endl << "Record " << ++i << ":";
					displayMobile(m);
				}
			}
		}
		if (i == 0) {
			cout << endl << "Sorry! No such record found!" << endl;
		}
		else {
			cout << endl << i << " Record(s) Found!" << endl;
		}
		thefile.close();
	}
	else
		cout << "Couldn't Open file" << endl;
}

void searchbyOS(const char* filename) {
	cout << endl;
	ifstream thefile(filename, ios::binary);
	if (thefile.is_open()) {
		char temp[30];
		cout << "Enter the name of OS [iOS/Android] installed in mobiles you want to search: ";
		cin.ignore(30, '\n');
		cin.getline(temp, 30);
		int i = 0;
		while (thefile.good()) {
			mobilePhone m;
			thefile.read((char*)&m, sizeof(mobilePhone));
			if (strcmp(temp, m.os) == 0) {
				if (thefile.gcount() > 0) {
					cout << endl << "Record " << ++i << ":";
					displayMobile(m);
				}
			}
		}
		if (i == 0) {
			cout << endl << "Sorry! No such record found!" << endl;
		}
		else {
			cout << endl << i << " Record(s) Found!" << endl;
		}
		thefile.close();
	}
	else
		cout << "Couldn't Open file" << endl;
}

void searchbyPrice(const char* filename) {
	cout << endl;
	ifstream thefile(filename, ios::binary);
	if (thefile.is_open()) {
		int min, max;
		cout << "Enter the Price Range in PKR of mobiles you want to search"<<endl;
		cout << "MIN: ";
		cin >> min;
		cout << "MAX: ";
		cin >> max;
		int i = 0;
		while (thefile.good()) {
			mobilePhone m;
			thefile.read((char*)&m, sizeof(mobilePhone));
			if (m.price >= min && m.price <= max) {
				if (thefile.gcount() > 0) {
					cout << endl << "Record " << ++i << ":";
					displayMobile(m);
				}
			}
		}
		if (i == 0) {
			cout << endl << "Sorry! No such record found!" << endl;
		}
		else {
			cout << endl << i << " Record(s) Found!" << endl;
		}
		thefile.close();
	}
	else
		cout << "Couldn't Open file" << endl;
}
//this function simply takes a variable of structure and displays its all features
void displayMobile(const mobilePhone m) {
	cout << endl;
	cout << "\t" << m.company << " " << m.name << endl;
	cout << "\tDisplay: " << m.display << "\"" << endl;
	cout << "\tProcessor: " << m.processor << endl;
	cout << "\tFront Camera:	" << m.frontCamera <<"MP" << endl;
	cout << "\tRare Camera: " << m.rareCamera <<"MP" << endl;
	cout << "\tRAM: " << m.ram << "GB" << endl;
	cout << "\tStorage: " << m.storage << "GB" << endl;
	cout << "\tBattery: " << m.battery << "mAh" << endl;
	cout << "\tOS: " << m.os << endl;
	cout << "\tPrice: " << m.price << "PKR" << endl;
}
//to update a record in a file we take a temporary file, open the main file in read mode and temporary file in write mode
//read a record one by one from the main file and if it does matches with the record we want to update, we simply write it on to the new file
//in case if the records matches, we first update it and then write it on the temp file
//when the end of file triggers the temp file contains the updated data hence we remove the main file after closing it and rename the temp file by the name of main file after closing it
//now there is no temp file and the main file now contains the updated data
void updateMobile(const char* filename) {
	cout << endl;
	ifstream thefile(filename, ios::binary);
	ofstream newfile("tempfile.bin", ios::binary);
	if (thefile.is_open()) {
		if (newfile.is_open()) {
			char temp[30];
			bool found = 0;
			cout << "Enter the name of mobile you want to update: ";
			cin.ignore(30, '\n');
			cin.getline(temp, 30);
			while (thefile.good()) {
				mobilePhone m;
				thefile.read((char*)&m, sizeof(mobilePhone));
				if (thefile.gcount() > 0) {
					if (strcmp(temp, m.name) == 0) {
						cout << endl << "Previous Credentials: " <<endl;
						displayMobile(m);
						cout << "Enter NEW Company Name: ";
						//cin.ignore(30, '\n');
						cin.getline(m.company, 30);
						cout << "Enter NEW Model Name: ";
						//cin.ignore(30, '\n');
						cin.getline(m.name, 30);
						cout << "Enter NEW Display Size [Inches]: ";
						cin >> m.display;
						cout << "Enter NEW Processor Name: ";
						cin.ignore(30, '\n');
						cin.getline(m.processor, 30);
						cout << "Enter NEW Front Camera [MP]: ";
						cin >> m.frontCamera;
						cout << "Enter NEW Rare Camera [MP]: ";
						cin >> m.rareCamera;
						cout << "Enter NEW RAM Capacity [GB]: ";
						cin >> m.ram;
						cout << "Enter NEW Storage Capacity [GB]: ";
						cin >> m.storage;
						cout << "Enter NEW Battery Capacity [mAh]: ";
						cin >> m.battery;
						cout << "Enter NEW Operating System [iOS/Android]: ";
						cin.ignore(30, '\n');
						cin.getline(m.os, 30);
						cout << "Enter NEW Price [PKR]: ";
						cin >> m.price;
						cout << endl << "Record Updated!" << endl;
						displayMobile(m);
					}
					newfile.write((const char*)&m, sizeof(mobilePhone));
				}
			}
			newfile.close();
			thefile.close();
			remove(filename);
			rename("tempfile.bin", filename);
		}
	}
	else {
		cout << "Couldn't Open file" << endl;
	}
}
//to delete a record in a file we take a temporary file, open the main file in read mode and temporary file in write mode
//read a record one by one from the main file and if it does matches with the record we want to delete, we simply write it on to the new file
//in case if the records matches, we don't write it on the temp file
//when the end of file triggers the temp file contains all the data except the record we want to delete, hence we remove the main file after closing it and rename the temp file by the name of main file after closing it
//now there is no temp file and the main file now doesn't contain the deleted data
void deleteMobile(const char* filename) {
	cout << endl;
	ifstream thefile(filename, ios::binary);
	ofstream newfile("tempfile.bin", ios::binary);
	if (thefile.is_open()) {
		if (newfile.is_open()) {
			char temp[30];
			bool found = 0;
			cout << "Enter the name of mobile you want to delete: ";
			cin.ignore(30, '\n');
			cin.getline(temp, 30);
			while (thefile.good()) {
				mobilePhone m;
				thefile.read((char*)&m, sizeof(mobilePhone));
				if (thefile.gcount() > 0) {
					if (!strcmp(temp, m.name) == 0) {
						newfile.write((const char*)&m, sizeof(mobilePhone));
					}
					else {
						cout << "Record Deleted!" << endl;
					}
				}
			}
			newfile.close();
			thefile.close();
			remove(filename);
			rename("tempfile.bin", filename);
		}
	}
	else {
		cout << "Couldn't Open file" << endl;
	}
}
//this function simply reads the record by file one by one, after opening it in read mode, and displays all of their features
//the counter i counts the number of records
void displayFile(const char* filename) {
	cout << endl;
	int i = 0;
	ifstream thefile(filename, ios::binary);
	if (thefile.is_open()) {
		while (!thefile.eof())
		{
			mobilePhone m;
			thefile.read((char*)&m, sizeof(mobilePhone));
			if (thefile.gcount() > 0) {
				cout << endl << "Record " << ++i << ":";
				displayMobile(m);
			}
		}
		if (i == 0) {
			cout << endl << "Sorry! The file is empty!" << endl;
		}
		else {
			cout << endl << i << " Record(s) Found!" << endl;
		}
		thefile.close();
	}
	else
	{
		cout << "Couldn't open file!" << endl;
	}
}