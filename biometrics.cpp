/* Biometrics addition
 * Tanner Babcock
 * tababcock@dmacc.edu
 * October 3, 2021 */
#include <iostream>
#include <string>
#include <memory>
using namespace std;

class Biometrics {
	private:
		double heightInCm;
		double weightInKg;
	public:
		Biometrics(double cm, double kg): heightInCm(cm), weightInKg(kg) { }
		void setHeightFeetInches(double fe, double in) {
			heightInCm = (fe * 12 + in) * 2.54;
		}
		void setWeightInPounds(double po) {
			weightInKg = (po * 0.453592);
		}
		double getBmi(void) {
			return (weightInKg / heightInCm / heightInCm) * 10000;
		}
};

class Earthling : public Biometrics {
	private:
		string name;
		string country;
		int age;
		int feet;
		int inches;
		int pounds;
	public:
		Earthling(string n, string c, int a, int f, int i, int p) : Biometrics(0, 0) {
			name = n;
			country = c;
			age = a;
			feet = f;
			inches = i;
			pounds = p;
			setHeightFeetInches(f, i);
			setWeightInPounds(p);
		}
		void print(void) {
			cout << "Name: " << name << endl;
			cout << "Country: " << country << endl;
			cout << "Age: " << age << endl;
			cout << "Feet: " << feet << endl;
			cout << "Inches: " << inches << endl;
			cout << "Pounds: " << pounds << endl;
			
			double rb = getBmi();
			double a;
			/* Subtract a single BMI point for every ten years of Earthling's age */
			for (a = age; a > 9; a -= 10, rb -= 1.0)
				;

			cout << "BMI: " << fixed << rb << endl;
		}
};

int main(void) {
	int feet, inches;
	double pounds, bmi;
	cout.precision(2);

	/* Black don't crack */
	Earthling *humans[] = {
		new Earthling("Fred Hampton", "Chicago", 21, 6, 2, 300),   // murdered
		new Earthling("Huey Newton", "Louisiana", 42, 5, 1, 200),  // murdered
		new Earthling("Angela Davis", "Alabama", 77, 5, 9, 120)    // still alive
	};

	int x;
	for (x = 0; x < 3; x++) {
		humans[x]->print();
		cout << "------------------" << endl;
		delete(humans[x]);
	}

	return 0;
}

/* Output:

Name: Fred Hampton
Country: Chicago
Age: 21
Feet: 6
Inches: 2
Pounds: 300
BMI: 36.52
-------------------
Name: Huey Newton
Country: Louisiana
Age: 42
Feet: 5
Inches: 1
Pounds: 200
BMI: 33.79
-------------------
Name: Angela Davis
Country: Alabama
Age: 77
Feet: 5
Inches: 9
Pounds: 120
BMI: 10.72
-------------------
*/
