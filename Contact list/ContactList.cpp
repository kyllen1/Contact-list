/* PROJECT --> Contact List
---------------------------
*/

#include <iostream>
#include <string>
#include <fstream>
using std::cout;
using std::cin;
using std::string;
using std::fstream;
using std::ios;

// Forward declaration of functions
void welcome();
void menu();
void loop();
void addContact();
void deleteContact();
void showContact();
void doNothing();
void saveReg(string data1, int data2, string data3);

int main() {
	int option;

	welcome();
	option = menu();
	loop(option);

	return 0;
}

void welcome() {
	cout << "WELCOME TO CONTACT LIST\n";
}

int menu() {
	cout << "MENU -->\n";
	cout << "1 --> Add contact\n";
	cout << "2 --> Delete contact\n";
	cout << "3 --> Show contact\n";

	int option;
	cin >> option;
	
	return option;
}

void loop(int op) {
	char repeat[1];
	do {
		switch (op) {
		case 1:
			addContact();
			cout << "Do you want to add another contact? (y/n) ";
			break;
		case 2:
			deleteContact();
			cout << "Do you want to delete another contact? (y/n) ";
			break;
		case 3:
			showContact();
			cout << "Do you want to show another contact? (y/n) ";
			break;
		default:
			doNothing();
		}
		cin >> repeat;
	} while (repeat != "y");

}

void addContact() {
	string name, email;
	int phoneNumber;
	cout << "ADD CONTACT FORM\n";
	cout << "\nName: ";
	cin >> name;
	cout << "Phone number: ";
	cin >> phoneNumber;
	cout << "Email: ";
	cin >> email;
	saveReg(name,phoneNumber,email); // Write contact on the file
}

void deleteContact()
{
}

void showContact()
{
}

void doNothing()
{
}

void saveReg(string data1,int data2,string data3) {
	fstream conctactList;
	conctactList.open("Contact_List.txt", ios::out);
	if (conctactList.is_open()) {
		conctactList << data1 << ";" << data2 << ";" << data3 << "\n";
		conctactList.close();
	}
}
