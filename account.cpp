/* User Profile
 * Tanner Babcock
 * tababcock@dmacc.edu
 * October 20, 2021 */
#include <iostream>
#include <string>
using namespace std;

class User {
private:
	string firstName;
	string lastName;
	string address;
	string city;
	string state;
	string phone;
	long zip;
public:
	User(string f, string l, string a, string c, string s, string p, long z):
		firstName(f),
		lastName(l),
		address(a),
		city(c),
		state(s),
		phone(p),
		zip(z) { }
	~User(void) {
		cout << "User destructor called" << endl;
		firstName = "";
		lastName = "";
		address = "";
		city = "";
		state = "";
		phone = "";
		zip = 0;
	}
	/* yawn */
	string getFirstName(void) { return firstName; }
	void setFirstName(const string &f) { firstName = f; }
	string getLastName(void) { return lastName; }
	void setLastName(const string &l) { lastName = l; }
	string getAddress(void) { return address; }
	void setAddress(const string &a) { address = a; }
	string getCity(void) { return city; }
	void setCity(const string &c) { city = c; }
	string getState(void) { return state; }
	void setState(const string &s) { state = s; }
	string getPhone(void) { return phone; }
	void setPhone(const string &p) { phone = p; }

	void printUser(void) {
		cout << "Printing user" << endl;
		cout << "Name: " << firstName << " " << lastName << endl;
		cout << "Address: " << address << endl;
		cout << "City: " << city << endl;
		cout << "State: " << state << endl;
		cout << "Phone: " << phone << endl;
		cout << "Zip Code: " << zip << endl;
	}
};

/* Account is not a derived class of User, but an associated class
 * Account object contains a User object */
class Account {
private:
	User user;
	long accNumber;
	double balance;
public:
	Account(long acc, User u):
		user(u),
		accNumber(acc),
		balance(0.0) { }
	~Account(void) {
		cout << "Account destructor called" << endl;
	}

	string getFirstName(void) { return user.getFirstName(); }
	void setFirstName(const string &f) { user.setFirstName(f); }
	string getLastName(void) { return user.getLastName(); }
	void setLastName(const string &l) { user.setLastName(l); }
	string getAddress(void) { return user.getAddress(); }
	void setAddress(const string &a) { user.setAddress(a); }
	string getCity(void) { return user.getCity(); }
	void setCity(const string &c) { user.setCity(c); }
	string getState(void) { return user.getState(); }
	void setState(const string &s) { user.setState(s); }
	string getPhone(void) { return user.getPhone(); }
	void setPhone(const string &p) { user.setPhone(p); }

	long getAccNumber(void) { return accNumber; }
	void setAccNumber(long a) { accNumber = a; }
	double getBalance(void) { return balance; }
	void setBalance(double b) { balance = b; }

	void printAccount(void) {
		user.printUser();
		cout.precision(2);
		cout << "Priting account" << endl;
		cout << "Account number: " << accNumber << endl;
		cout << "Balance: " << "$" << fixed << balance << endl;
	}
};

int main(void) {
	User guy("Carl", "Sagan", "100 Hollywood Blvd.", "Los Angeles", "California", "555-555-5555", 10090);
	guy.printUser();

	Account bank(1234, guy);
	bank.printAccount();

	return 0;
}
