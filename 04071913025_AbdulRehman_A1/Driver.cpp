#include"Mobile.h"
int main(int argc, char* argv[]) { //we have to pass the name of the binary file as a command line argument so that the file can be used through out the program
	cout << "\tM O B I L E \t S H O P \t S A L E S \t S Y S T E M" << endl;
	systemMenu(argv[1]); //we pass the name of file taken as a command line argument to this function so that all the functions called inside this function can use it and evaluate it in their own way wether to open in read or write, app, truncate or in or out mode
	return 0;
}