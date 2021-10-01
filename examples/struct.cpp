/* Struct example
 * Tanner Babcock
 * tababcock@dmacc.edu
 * September 30, 2021 */
#include <iostream>
#include <string>
#include <ctime>

#define STATE_KY 12

typedef struct {
    std::string name;
    int birthYear;
    int birthMonth;
    int birthDay;
    std::string address;
    std::string city;
    int state;
    int zip;
    // Insurance? Is that a string? Or a bool “This patient has no insurance”
} Patient;

int getAge(Patient *z) {
	std::time_t t = std::time(nullptr);
	std::tm *const i = std::localtime(&t);
	int currentYear = (1900 + i->tm_year);

	std::cout << "Current year is " << currentYear << std::endl;
	return (currentYear - z->birthYear);
}

int main(void) {
	Patient p = {
    	.name = "John Doe",
    	.birthYear = 1995,
    	.birthMonth = 4,
    	.birthDay = 20,
    	.address = "10 SW 2nd Ave.",
    	.city = "Lexington",
    	.state = STATE_KY,
    	.zip = 40502
	};

	int age = getAge(&p);
	std::cout << "This patient is " << age << " years old" << std::endl;

	return 0;
}
