#include <iostream>
#include<string>
#include<vector>
#include<fstream>
#include<stdlib.h>
using namespace std;

//Function Prototype to input animal sounds
vector<string> addSound(string input, vector<string> v) {
	//Add the string input to the vector with the sound
	v.push_back(input);
	return v;
}

vector<string> Textsound(vector<string> vec) {
	fstream soundFromFile;
	soundFromFile.open("Add_animal_Sound.txt");
	string line;
	while (getline(soundFromFile, line)) {//read the line from text file
		//add the sound to vector
		vec.push_back(line);
	}
	soundFromFile.close();
	return vec;
}

/* Create a function called searchSound, that searches for an animal in the vector of sounds.
If it finds the animal in the vector, it should return the sound.
If it doesn't, it should say no sound was found.
*/
void searchSound(string search, vector<string> v) {
	//
	int found = -1;// means NOT found
	//Check the string search to see if it's in the vector
	for (int i = 0; i < v.size(); i++) {
		string output = v[i]; //set the string output = element at the vector
		//stringvar.find(stringToSearch)
		found = output.find(search);// return the index that the string is found
		// 
		if (found != string::npos) {
			cout << v[i] << endl;
			break;
		}
	}
	if (found == string::npos) {
		cout << "There was no sound found. " << endl;
	}
}
int main()
{	//Declare variables 
	string user_input;

	//Store animal sounds from user input into a string vector
	vector<string> vect = { {"The cat goes \"meow\"."}, {"The dog goes \"goof\"."},
							{"The cow goes \"moo\"."},{"The fox goes \"ding ding\"."},
							{"The lion goes \"roar roar\"."} };

	//Call the function Textsound()
	vect = Textsound(vect);

	bool errorInput = false;
	while (!errorInput) {
		// Step 1: Update user input by repeating step 1 to ask for user input again
		cout << "What sound would you like? ";
		getline(cin, user_input); //to include when we press enter.

		//Declare random animal sounds
		int ranNum;
		srand(time(NULL));
		//set user_input equal to random number, user can access any of the sound
		if (user_input == "yes" || user_input == "") {
			user_input = to_string(ranNum = rand() % vect.size() + 1); 
		}
		//When the user enter add---> call the function---> ask what sound do you want to add?-->get the user input for a string to the vector.
		if (user_input == "add") {
			//Declare string variable
			string sound;
			//Get the user_input for a string to the vector.
			cout << "What sound do you want to add? ";
			getline(cin, sound);

			//call the function addSound()
			vect = addSound(sound, vect);
		}

		// When the user want to search for a sound
		if (user_input == "find") {
			//Declare a string variable to find 
			string found;
			cout << "What sound do you want to find? ";
			getline(cin, found);
			//Call the function searchSound()
			searchSound(found, vect); //b.c searchSound is void 
		}
		// Store animal sounds into an array.
		string arr_Sound[5];
		//Fill or Set the sound of each animal to coresponding to the index of array.
		arr_Sound[0] = "The cat goes \"meow\".";
		arr_Sound[1] = "The dog goes \"goof\".";
		arr_Sound[2] = "The cow goes \"moo\".";
		arr_Sound[3] = "The fox goes \"ding ding\".";
		arr_Sound[4] = "The lion goes \"roar roar\".";

		//Print out the sounds by checking if the sounds are in range
		if (user_input != "add" && user_input != "find" && stoi(user_input) >= 1 && stoi(user_input) <= vect.size()) {
			cout << vect[stoi(user_input) - 1] << endl; //Print out vector instead of array.
		}
		//if the user enter outside of range
		//Hint: To make sure the user_input is within the range from 1-5, 
		//Test program
		cout << endl;

		//Check if the user does not enter from 1-5, "yes" or nothing-----> end the program
		//Update while loop
		if (user_input != "add" && user_input != "find" && (stoi(user_input) < 1 || stoi(user_input) > vect.size())) {// check if the sounds are out of range

			errorInput = true; // set errorInput to true

		}
		else {
			cout << "Would you like to play a sound again? " << endl;
		}
	}
	cout << "Thank you, see you again! " << endl;
	//Test the new sound being added
	cout << vect.back() << endl; //return the last element in the vector
}

