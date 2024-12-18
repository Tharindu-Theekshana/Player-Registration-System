

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <iomanip>
using namespace std;

const int MaxPlayers = 500;

//username:-For_User:user
//Passwords:-For_User:user123

//username:-For_Admin:admin
//Passwords:-For_Admin:admin123

struct Players {
	int registerNumber;
	string firstName;
	string lastName;
	int yearBirth;
	int monthBirth;
	int dateBirth;
	int runs;
	string teams;
};

Players players[MaxPlayers];
int numOfPlayers = 0;

void registerPlayer() {
	if (numOfPlayers >= MaxPlayers) {
		cout << "\nMaximum Number Of Players Registered! Try Again Next Year.\n" << endl;
	}
	int registerNumber;
	string firstName;
	string lastName;
	int yearBirth;
	int monthBirth;
	int dateBirth;
	int runs;
	string teams;

	cout << "\nEnter Register Number: ";
	cin >> registerNumber;
	for (int i = 0; i < numOfPlayers; i++) {
		if (players[i].registerNumber == registerNumber) {
			cout << "\nPlayer with " << registerNumber << " Register Number Already Exists. Please Enter Different Register Number.\n" << endl;
			return;
		}
	}
	cout << "\nEnter Player First Name: ";
	cin.ignore();
	getline(cin, firstName);
	cout << "\nEnter Player Last Name: ";
	
	getline(cin, lastName);
	cout << "\nEnter Player Year Of Birth: ";
	
	cin >> yearBirth;
	cout << "\nEnter Player Month Of Birth: ";	
	cin >> monthBirth;

	cout << "\nEnter Player Date Of Birth: ";
	cin >> dateBirth;

	cout << "\nEnter Runs Scored: ";
	cin >> runs;
	
	cout << "\nEnter 2 Teams From ( Colombo Stars, Kandy Giants, Dambulla Warriors, Galle Marvels, Jaffna Kings ): ";
	cin.ignore();
	getline(cin, teams);

	players[numOfPlayers].registerNumber = registerNumber;
	players[numOfPlayers].firstName = firstName;
	players[numOfPlayers].lastName = lastName;
	players[numOfPlayers].yearBirth =yearBirth;
	players[numOfPlayers].monthBirth = monthBirth;
	players[numOfPlayers].dateBirth = dateBirth;
	players[numOfPlayers].runs = runs;
	players[numOfPlayers].teams = teams;
	numOfPlayers++;

	cout << "\nPlayer Details Inserted Successfully!\n" << endl;
	cout << "\n1.Save to The Files";
	cout << "\n2.Menu\n";
	cout << "\nEnter Choice Number: ";
	int num1;
	cin >> num1;
	if (num1 == 1) {
		ofstream file("players.txt");
		if (!file) {
			cerr << "\nERROR! Unable To Open stucent.txt.\n" << endl;
		}

		for (int i = 0; i < numOfPlayers; i++) {
			file << "\nRegister Number" << setw(8) << " - " << players[i].registerNumber << "\nPlayer Name" << setw(12) << " - " << players[i].firstName << " " << players[i].lastName << "\nPlayer Date Of Birth" << setw(2) << " - " << players[i].yearBirth << "-" << players[i].monthBirth << "-" << players[i].dateBirth << "\nPlayer Runs Scored" << setw(5) << " - " << players[i].runs << "\nPlayer Teams Are" << setw(7) << " - " << players[i].teams << endl;
		}
		file.close();
		cout << "\nPlayer Registered Successfully! And Player Details Saved To the Files.\n" << endl;
	}
	else if(num1==2) {
		cout << "\nPlayer Registered Successfully! But Not Saved To The Files.\n" << endl;
	}
	else {
		cout << "\nInvalid Number! Please Try Again.\n" << endl;
	}

}

void displayPlayersInfromation() {
	if (numOfPlayers == 0) {
		cout << "\nNo Registered Players To Display!" << endl;
		return;
	}
	cout << "\nRegistered Players Are: " << endl;
	for (int i = 0; i < numOfPlayers; i++) {
		cout << "\nRegister Number"<<setw(8)<<" - " << players[i].registerNumber << "\nPlayer Name" << setw(12) << " - " << players[i].firstName << " " << players[i].lastName << "\nPlayer Date Of Birth"<<setw(2)<<" - " << players[i].yearBirth << "-" << players[i].monthBirth << "-" << players[i].dateBirth <<"\nPlayer Runs Scored" << setw(5) << " - " << players[i].runs << "\nPlayer Teams Are" << setw(7) << " - " << players[i].teams << endl;
	}

}

void addNewPlayers() {
	const string username1 = "admin";
	const string password1 = "admin123";
	string username;
	string password;
	int choice;
	do {		
		cout << "\nAccess Have Only For Admins!\n";
		cout << "\nEnter Username: ";
		cin >> username;
		cout << "Enter Password: ";
		cin >> password;
		
		if (username == username1 && password == password1) {
			cout << "\nAdd New Players:-";
			if (numOfPlayers >= MaxPlayers) {
				cout << "\nMaximum Number Of Players Registered! Try Again Next Year.\n" << endl;
			}
			int registerNumber;
			string firstName;
			string lastName;
			int yearBirth;
			int monthBirth;
			int dateBirth;
			string teams;
			int runs;

			cout << "\nEnter Register Number: ";
			cin >> registerNumber;
			for (int i = 0; i < numOfPlayers; i++) {
				if (players[i].registerNumber == registerNumber) {
					cout << "\nPlayer with " << registerNumber << " Register Number Already Exists. Please Enter Different Register Number.\n" << endl;
					return;
				}
			}
			cout << "\nEnter Player First Name: ";
			cin.ignore();
			getline(cin, firstName);
			cout << "\nEnter Player Last Name: ";

			getline(cin, lastName);
			cout << "\nEnter Player Year Of Birth: ";

			cin >> yearBirth;
			cout << "\nEnter Player Month Of Birth: ";

			cin >> monthBirth;
			cout << "\nEnter Player Date Of Birth: ";
			cin >> dateBirth;

			cout << "\nEnter Runs Scored: ";
			cin >> runs;

			cout << "\nEnter 2 Teams From ( Colombo Stars, Kandy Giants, Dambulla Warriors, Galle Marvels, Jaffna Kings ): ";
			cin.ignore();
			getline(cin, teams);

			players[numOfPlayers].registerNumber = registerNumber;
			players[numOfPlayers].firstName = firstName;
			players[numOfPlayers].lastName = lastName;
			players[numOfPlayers].yearBirth = yearBirth;
			players[numOfPlayers].monthBirth = monthBirth;
			players[numOfPlayers].dateBirth = dateBirth;
			players[numOfPlayers].runs = runs;
			players[numOfPlayers].teams = teams;
			numOfPlayers++;

			cout << "\nPlayer Details Inserted Successfully!\n" << endl;
			cout << "\n1.Save to The Files";
			cout << "\n2.Menu\n";
			cout << "\nEnter Choice Number: ";
			int num1;
			cin >> num1;
			if (num1 == 1) {
				ofstream file("players.txt");
				if (!file) {
					cerr << "\nERROR! Unable To Open stucent.txt.\n" << endl;
				}

				for (int i = 0; i < numOfPlayers; i++) {
					file << "\nRegister Number" << setw(8) << " - " << players[i].registerNumber << "\nPlayer Name" << setw(12) << " - " << players[i].firstName << " " << players[i].lastName << "\nPlayer Date Of Birth" << setw(2) << " - " << players[i].yearBirth << "-" << players[i].monthBirth << "-" << players[i].dateBirth <<"\nPlayer Runs Scored"<< setw(5)<<" - "<< players[i].runs<< "\nPlayer Teams Are" << setw(7) << " - " << players[i].teams << endl;
				}
				file.close();
				cout << "\nPlayer Added To The System Successfully! And Player Details Saved To the Files.\n" << endl;
			}
			else if (num1 == 2) {
				cout << "\nPlayer Added To The System Successfully! But Not Saved To The Files.\n" << endl;
			}
			else {
				cout << "\nInvalid Number! Please Try Again.\n" << endl;
			}
		    

		}		
		else {
			cout << "\nInvalid Password! Try Again.\n";
			cout << "\n1.Try Again\n2.Menu\nEnter Choice Number: ";
			cin >> choice;
		}
	} while ((username != username1 || password != password1) && choice !=2);

}

void manageTeams() {
	const string username1 = "admin";
	const string password1 = "admin123";
	string username;
	string password;
	int choice;
	do {
		cout << "\nAccess Have Only For Admins!\n";
		cout << "\nEnter Username: ";
		cin >> username;
		cout << "Enter Password: ";
		cin >> password;
		if (username == username1 && password == password1) {
			cout << "\nManage Teams:- \n";
			cout << "1.Update Player Details\n2.Delete Player\nEnter Choice Number: ";
			int choice;
			cin >> choice;
			switch (choice) {
			case 1: {
				

				cout << "\nUpdate Player Details:-";
				cout << "\n1.Update Name\n2.Update Date Of Birth\n3.Update Runs Scored\n4.Update Selected Team\nEnter Choice Number: ";
				int choice1;
				cin >> choice1;
				switch (choice1) {
				case 1: {
					int registerNumber;
					cout << "\nEnter Player Register Number: ";
					cin >> registerNumber;

					bool found = false;
					for (int i = 0; i < numOfPlayers; i++) {
						if (players[i].registerNumber == registerNumber) {
							cout << "\nEnter New First Name: ";
							cin.ignore();
							getline(cin, players[i].firstName);
							cout << "\nEnter New Last Name: ";

							getline(cin, players[i].lastName);
							found = true;

							cout << "\n1.Save To Files\n2.Menu\nEnter Choice Number: ";
							int choice2;
							cin >> choice2;
							if (choice2 == 1) {
								ofstream file("players.txt");
								if (!file) {
									cerr << "\nERROR! Unable To Open stucent.txt.\n" << endl;
								}

								for (int i = 0; i < numOfPlayers; i++) {
									file << "\nRegister Number" << setw(8) << " - " << players[i].registerNumber << "\nPlayer Name" << setw(12) << " - " << players[i].firstName << " " << players[i].lastName << "\nPlayer Date Of Birth" << setw(2) << " - " << players[i].yearBirth << "-" << players[i].monthBirth << "-" << players[i].dateBirth << "\nPlayer Runs Scored" << setw(5) << " - " << players[i].runs << "\nPlayer Teams Are" << setw(7) << " - " << players[i].teams << endl;
								}
								file.close();
								cout << "\nPlayer Details Updated Successfully! And Player Details Saved To the Files.\n" << endl;
							}
							else if (choice2 == 2) {
								cout << "\nPlayer Details Updated Successfully But Not Saved To The Files\n";
							}
							else {
								cout << "\nInvalid Number Please Try Again!\n";
							}
						}
					}
					if (!found) {
						cout << "\nNo Registered Players With Register Number Of " << registerNumber << "\n";
					}
					
				}break;
				case 2: {
					int registerNumber;
					cout << "\nEnter Player Register Number: ";
					cin >> registerNumber;

					bool found = false;
					for (int i = 0; i < numOfPlayers; i++) {
						if (players[i].registerNumber == registerNumber) {
							cout << "\nEnter Year Of Birth: ";
							cin.ignore();
							cin >> players[i].yearBirth;
							cout << "\nEnter Month Of Birth: ";
							cin >> players[i].monthBirth;
							cout << "\nEnter Date Of Birth: ";
							cin >> players[i].dateBirth;
							found = true;

							cout << "\n1.Save To Files\n2.Menu\nEnter Choice Number: ";
							int choice2;
							cin >> choice2;
							if (choice2 == 1) {
								ofstream file("players.txt");
								if (!file) {
									cerr << "\nERROR! Unable To Open stucent.txt.\n" << endl;
								}

								for (int i = 0; i < numOfPlayers; i++) {
									file << "\nRegister Number" << setw(8) << " - " << players[i].registerNumber << "\nPlayer Name" << setw(12) << " - " << players[i].firstName << " " << players[i].lastName << "\nPlayer Date Of Birth" << setw(2) << " - " << players[i].yearBirth << "-" << players[i].monthBirth << "-" << players[i].dateBirth << "\nPlayer Runs Scored" << setw(5) << " - " << players[i].runs << "\nPlayer Teams Are" << setw(7) << " - " << players[i].teams << endl;
								}
								file.close();
								cout << "\nPlayer Details Updated Successfully! And Player Details Saved To the Files.\n" << endl;
							}
							else if (choice2 == 2) {
								cout << "\nPlayer Details Updated Successfully! But Not Save To The Files.\n";
							}
							else {
								cout << "\nInvalid Number Please Try Again!\n";
							}
						}
					}
					if (!found) {
						cout << "\nNo Registered Players With Register Number Of " << registerNumber << "\n";
					}
				}break;
				case 3: {
					int registerNumber;
					cout << "\nEnter Player Register Number: ";
					cin >> registerNumber;

					bool found = false;
					for (int i = 0; i < numOfPlayers; i++) {
						if (players[i].registerNumber == registerNumber) {
							cout << "\nEnter New Runs Scored: ";
							cin.ignore();
							cin >> players[i].runs;

							found = true;

							cout << "\n1.Save To Files\n2.Menu\nEnter Choice Number: ";
							int choice2;
							cin >> choice2;
							if (choice2 == 1) {
								ofstream file("players.txt");
								if (!file) {
									cerr << "\nERROR! Unable To Open stucent.txt.\n" << endl;
								}

								for (int i = 0; i < numOfPlayers; i++) {
									file << "\nRegister Number" << setw(8) << " - " << players[i].registerNumber << "\nPlayer Name" << setw(12) << " - " << players[i].firstName << " " << players[i].lastName << "\nPlayer Date Of Birth" << setw(2) << " - " << players[i].yearBirth << "-" << players[i].monthBirth << "-" << players[i].dateBirth << "\nPlayer Runs Scored" << setw(5) << " - " << players[i].runs << "\nPlayer Teams Are" << setw(7) << " - " << players[i].teams << endl;
								}
								file.close();
								cout << "\nPlayer Details Updated Successfully! And Player Details Saved To the Files.\n" << endl;
							}
							else if (choice2 == 2) {
								cout << "\nPlayer Details Updated Successfully But Not Saved To The Files\n";
							}
							else {
								cout << "\nInvalid Number Please Try Again!\n";
							}
						}
					}
					if (!found) {
						cout << "\nNo Registered Players With Register Number Of " << registerNumber << "\n";
					}
				}break;
				case 4: {
					int registerNumber;
					cout << "\nEnter Player Register Number: ";
					cin >> registerNumber;

					bool found = false;
					for (int i = 0; i < numOfPlayers; i++) {
						if (players[i].registerNumber == registerNumber) {
							cout << "\nEnter New 2 Teams From ( Colombo Stars, Kandy Giants, Dambulla Warriors, Galle Marvels, Jaffna Kings ): ";
							cin.ignore();
							getline(cin, players[i].teams);

							found = true;

							cout << "\n1.Save To Files\n2.Menu\nEnter Choice Number: ";
							int choice2;
							cin >> choice2;
							if (choice2 == 1) {
								ofstream file("players.txt");
								if (!file) {
									cerr << "\nERROR! Unable To Open stucent.txt.\n" << endl;
								}

								for (int i = 0; i < numOfPlayers; i++) {
									file << "\nRegister Number" << setw(8) << " - " << players[i].registerNumber << "\nPlayer Name" << setw(12) << " - " << players[i].firstName << " " << players[i].lastName << "\nPlayer Date Of Birth" << setw(2) << " - " << players[i].yearBirth << "-" << players[i].monthBirth << "-" << players[i].dateBirth << "\nPlayer Runs Scored" << setw(5) << " - " << players[i].runs << "\nPlayer Teams Are" << setw(7) << " - " << players[i].teams << endl;
								}
								file.close();
								cout << "\nPlayer Details Updated Successfully! And Player Details Saved To the Files.\n" << endl;
							}
							else if (choice2 == 2) {
								cout << "\nPlayer Details Updated Successfully But Not Saved To The Files\n";
							}
							else {
								cout << "\nInvalid Number Please Try Again!\n";
							}
						}
					}
					if (!found) {
						cout << "\nNo Registered Players With Register Number Of " << registerNumber << "\n";
					}
				}break;
				default: {
					cout << "\nInvalid Number! Please Try Again.\n";
				}
			}
				
			}break;
			case 2: {
				int registerNumber;
				cout << "\nEnter Register Number To Delete Details: ";
				cin >> registerNumber;

				bool found = false;
				for (int i = 0; i < numOfPlayers; i++) {
					if (players[i].registerNumber == registerNumber) {
						for (int j = i; j < numOfPlayers - 1; j++) {
							players[j] = players[j + 1];
						}
						numOfPlayers--; 
						found = true;
						break; 
					}
				}

				if (!found) {
					cout << "\nPlayer with Register Number " << registerNumber << " not found!\n";
				}
				else {
					
					ofstream file("players.txt");
					if (!file) {
						cerr << "\nERROR! Unable To Open players.txt.\n";
					}
					else {
						for (int i = 0; i < numOfPlayers; i++) {
							file << "\nRegister Number" << setw(8) << " - " << players[i].registerNumber
								<< "\nPlayer Name" << setw(12) << " - " << players[i].firstName << " "
								<< players[i].lastName
								<< "\nPlayer Date Of Birth" << setw(2) << " - " << players[i].yearBirth
								<< "-" << players[i].monthBirth << "-" << players[i].dateBirth
								<< "\nPlayer Runs Scored" << setw(5) << " - " << players[i].runs
								<< "\nPlayer Teams Are" << setw(7) << " - " << players[i].teams << endl;
						}
						file.close();
						cout << "\nPlayer Details Deleted Successfully!\n";
					}
				}
				break;
			
			}break;
			default: {
				cout << "\nInvalid Number! Please Try Again.\n";
			}
			}
		

		}
		else {
			cout << "\nInvalid Password! Try Again.\n";
			cout << "\n1.Try Again\n2.Menu\nEnter Choice Number: ";
			cin >> choice;
		}
	}while ((username != username1 || password != password1) && choice != 2);
}
void searchPlayer() {
	int registerNumber;
	cout << "\nEnter Player Register Number To Search: ";
	cin >> registerNumber;
	bool found = false;
	for (int i = 0; i < numOfPlayers; i++) {
		if (players[i].registerNumber == registerNumber) {
			cout <<"\nPlayer With Register Number " << players[i].registerNumber <<":- "<< "\nPlayer Name" << setw(21) << " - " << players[i].firstName << " " << players[i].lastName << "\nPlayer Date Of Birth" << setw(12) << " - " << players[i].yearBirth << "-" << players[i].monthBirth << "-" << players[i].dateBirth << "\nPlayer Runs Scored" << setw(14) << " - " << players[i].runs << "\nPlayer Teams Are" << setw(16) << " - " << players[i].teams << endl;
			found = true;
			break;
		}
	}
	if (!found) {
		cout << "\nNo Registered Players With Register Number Of " << registerNumber << "\n";
	}
}
void loadPlayers() {
	ifstream file("players.txt");
	if (!file) {
		cerr << "ERROR! Unable to open players.txt." << endl;
		return;
	}

	while (!file.eof() && numOfPlayers < MaxPlayers) {
		string line;
		getline(file, line);  

		getline(file, line, '-');  
		file >> players[numOfPlayers].registerNumber;
		file.ignore();  

		getline(file, line, '-');  
		getline(file, players[numOfPlayers].firstName, ' ');
		getline(file, players[numOfPlayers].lastName);

		getline(file, line, '-');  
		file >> players[numOfPlayers].yearBirth;
		file.ignore();  
		file >> players[numOfPlayers].monthBirth;
		file.ignore();  
		file >> players[numOfPlayers].dateBirth;

		getline(file, line, '-');  
		file >> players[numOfPlayers].runs;

		getline(file, line, '-');  
		getline(file, players[numOfPlayers].teams);

		numOfPlayers++;
	}

	file.close();
	
}


int main()
{
	loadPlayers();
	int choice;
	do {
		cout << "UPCOUNTRY WARRIORS" << endl;
		cout << "\n1.User Login\n";
		cout << "2.Exit\n";
		cout << "\nEnter Choice Number: ";		
		cin >> choice;

		switch (choice) {
		case 1: {
			const string username1 = "user";
			const string password1 = "user123";
			string username;
			string password;
			int choice3;
			do {
				//cout << "\nUsername - user\nPassword - player123\n";

				cout << "\nEnter Username: ";
				cin >> username;
				cout << "Enter Password: ";
				cin >> password;
				if (username == username1 && password == password1) {
					int choice1;
					do {
						cout << "\n MENU\n";
						cout << "\n1.Register\n";
						cout << "2.Display Players Information\n";
						cout << "3.Add New Players\n";
						cout << "4.Manage Teams\n";
						cout << "5.Search Players\n";
						cout << "6.Logout\n";
						cout << "\nEnter Choice Number: ";						
						cin >> choice1;
						switch (choice1) {
						case 1: {
							registerPlayer();


						}break;
						case 2: {
							displayPlayersInfromation();

						}break;
						case 3: {
							addNewPlayers();

						}break;
						case 4: {
							manageTeams();

						}break;
						case 5: {
							searchPlayer();

						}break;
						case 6: {
							cout << "Logout Successfully!\n";

						}break;
						default: {
							cout << "Invalid Number! , Please Enter Number Between 1 And 6.\n";
						}


						}





					} while (choice1 != 6);



				}
				else {
					cout << "\nInvalid Password! Try Again.";
					cout << "\n1.Try Again\n2.Back\nEnter Choice Number: ";
					cin >> choice3;
				}
			} while ((username != username1 || password != password1) && choice3 != 2);

		}break;
		case 2: {
			cout << "Successfully Exited From The Program!" << endl;

		}break;
		default: {
			cout << "\nInvalid Number Please Enter Number Between 1 And 2.\n";
		}

		}

	} while (choice != 2);

	return 0;
}



