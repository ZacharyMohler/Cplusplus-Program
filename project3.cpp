#include <Python.h>
#include <iostream>
#include <Windows.h>
#include <cmath>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

/*
Description:
	To call this function, simply pass the function name in Python that you wish to call.
Example:
	callProcedure("printsomething");
Output:
	Python will print on the screen: Hello from python!
Return:
	None
*/
void CallProcedure(string pName)
{
	char* procname = new char[pName.length() + 1];
	std::strcpy(procname, pName.c_str());

	Py_Initialize();
	PyObject* my_module = PyImport_ImportModule("Pythonfile");
	PyErr_Print();
	PyObject* my_function = PyObject_GetAttrString(my_module, procname);
	PyObject* my_result = PyObject_CallObject(my_function, NULL);
	Py_Finalize();

	delete[] procname;
}

/*
Description:
	To call this function, pass the name of the Python functino you wish to call and the string parameter you want to send
Example:
	int x = callIntFunc("PrintMe","Test");
Output:
	Python will print on the screen:
		You sent me: Test
Return:
	100 is returned to the C++
*/
int callIntFunc(string proc, string param)
{
	char* procname = new char[proc.length() + 1];
	std::strcpy(procname, proc.c_str());

	char* paramval = new char[param.length() + 1];
	std::strcpy(paramval, param.c_str());


	PyObject* pName, * pModule, * pDict, * pFunc, * pValue = nullptr, * presult = nullptr;
	// Initialize the Python Interpreter
	Py_Initialize();
	// Build the name object
	pName = PyUnicode_FromString((char*)"Pythonfile");
	// Load the module object
	pModule = PyImport_Import(pName);
	// pDict is a borrowed reference 
	pDict = PyModule_GetDict(pModule);
	// pFunc is also a borrowed reference 
	pFunc = PyDict_GetItemString(pDict, procname);
	if (PyCallable_Check(pFunc))
	{
		pValue = Py_BuildValue("(z)", paramval);
		PyErr_Print();
		presult = PyObject_CallObject(pFunc, pValue);
		PyErr_Print();
	}
	else
	{
		PyErr_Print();
	}
	//printf("Result is %d\n", _PyLong_AsInt(presult));
	Py_DECREF(pValue);
	// Clean up
	Py_DECREF(pModule);
	Py_DECREF(pName);
	// Finish the Python Interpreter
	Py_Finalize();

	// clean 
	delete[] procname;
	delete[] paramval;


	return _PyLong_AsInt(presult);
}

/*
Description:
	To call this function, pass the name of the Python functino you wish to call and the string parameter you want to send
Example:
	int x = callIntFunc("doublevalue",5);
Return:
	25 is returned to the C++
*/
int callIntFunc(string proc, int param)
{
	char* procname = new char[proc.length() + 1];
	std::strcpy(procname, proc.c_str());

	PyObject* pName, * pModule, * pDict, * pFunc, * pValue = nullptr, * presult = nullptr;
	// Initialize the Python Interpreter
	Py_Initialize();
	// Build the name object
	pName = PyUnicode_FromString((char*)"Pythonfile");
	// Load the module object
	pModule = PyImport_Import(pName);
	// pDict is a borrowed reference 
	pDict = PyModule_GetDict(pModule);
	// pFunc is also a borrowed reference 
	pFunc = PyDict_GetItemString(pDict, procname);
	if (PyCallable_Check(pFunc))
	{
		pValue = Py_BuildValue("(i)", param);
		PyErr_Print();
		presult = PyObject_CallObject(pFunc, pValue);
		PyErr_Print();
	}
	else
	{
		PyErr_Print();
	}
	//printf("Result is %d\n", _PyLong_AsInt(presult));
	Py_DECREF(pValue);
	// Clean up
	Py_DECREF(pModule);
	Py_DECREF(pName);
	// Finish the Python Interpreter
	Py_Finalize();

	// clean 
	delete[] procname;

	return _PyLong_AsInt(presult);
}


//This is a supplimentary function to print the main menu 
//and get the next user choice. It also validates menu choice
//input.
int printMainMenu()
{
	int userInput;

	cout << "1 -- Print items and quantities" << endl;
	cout << "2 -- Get item quantity (will ask for item name)" << endl;
	cout << "3 -- Write items and quantities to a file and print histogram" << endl;
	cout << "4 -- Quit" << endl;

	cin >> userInput;

	//validate input
	while (cin.fail())
	{
		cout << "Please enter an integer" << endl;
		cin.clear(); //clear input stream
		cin.ignore(256, '\n');
		cin >> userInput;
	}

	return userInput;
}


void main()
{
	////////////////////////////////////////////////////////////////
	//this is provided sample code

	//CallProcedure("printsomething");
	//cout << callIntFunc("PrintMe", "House") << endl;
	//cout << callIntFunc("SquareValue", 2);

	///////////////////////////////////////////////////////////////

	int userInput;

	//print main menu and get input
	userInput = printMainMenu();

	//run the program until the user inputs the quit option
	while (userInput != 4)
	{

		switch (userInput)
		{

				//print word and frequency data from python
			case 1:

				cout << "1 was picked" << endl;

				cout << endl;

				CallProcedure("printFrequency");

				cout << endl;

				//new main-menu input
				userInput = printMainMenu();

				break;

				//get word from user and get its frequency from python
				//then print from C++ 
			case 2:
			{ //scope is declared for variable searchword

				string searchWord; //declared for user's argument

				cout << "2 was picked" << endl;
				cout << "Item name: " << endl;
				cin >> searchWord;
				cout << endl; //spacing
				cout << "Item picked: " << searchWord << endl;
				cout << "Frequency: " << callIntFunc("returnFrequency", searchWord) << endl; // requrements suggest making this a function but that seems pointless when we can just cout the value directly
				cout << endl;

				//clear input stream in case they entered multiple args
				cin.clear();
				cin.ignore(256, '\n');

				//new main-menu input
				userInput = printMainMenu();
			}
			break;

			//prompt python to create a histogram with words and a-
			//special char representing the number of purchases of
			//said item and write that to a new file (all in python)
			case 3:
			{
				cout << "3 was picked" << endl;

				cout << endl;

				cout << "Writing to file..." << endl;
				CallProcedure("writeHistogram");

				cout << endl;

				cout << "Reading file..." << endl;;
				cout << endl;

				//read file that was just created by python
				ifstream toRead("frequency.dat");
				stringstream substr; //for parsing line by line
				string line; //full line from file
				string subElement; //substring from line
				int position = 1; //position of substring in line


				//confirm file opened correctly
				if (toRead.is_open())
				{
					while (getline(toRead, line))
					{
						substr << line;
						while (getline(substr, subElement, ' '))
						{
							if (position % 2 == 0)
							{
								for (int i = 0; i < stoi(subElement); i++)
								{
									cout << '#';
								}
								cout << endl;
							}
							else
							{
								cout << subElement << " ";
							}
							position += 1;
						}
						substr.clear();
					}
				}

				else
				{
					cout << "Error opening file" << endl;
				}

				cout << endl;
				//new main-menu input
				userInput = printMainMenu();

			}
					break;

				//non-valid option case
				default:

					cout << "that wasn't an option, try again" << endl;
					cin >> userInput;
		
					break;

		}//switch

	}//main-menu while 

	cout << "quitting...";

}// main