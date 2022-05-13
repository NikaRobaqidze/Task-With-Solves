#include <iostream> // Import iostream library for input data from keyboard and printing data to screen.
#include <iomanip> // Import library for decorating of printing data on screen.
#include <random> // Import library to get random number for variacy.

using namespace std;

#ifndef Platypus_H
#define Platypus_H

class Platypus
{
	/*-----------------Private variables-----------------*/

		/* Seting values by default to escape invalid values */
	default_random_engine generator; // Global varriable. Generator of random number.
	float weight; //weight_distribution(generator); // Platypus weight in KG. Set randomly between 0.1 and 10.
	short age; //age_distribution(generator); // Platypus age in month. Set randomly between 0 and 12.
	char name = 'A' + rand() % 26; // Platypus's name. Set randomly from A to Z.
	char gender = "MF"[rand() % 2]; // Platypus's gender. Set randomly M or F.
	bool alive = true; // Platypus's live status (is alive or not).
	bool mutant = false; // Platypus's mutant. As in instruction by default Platypus is not mutant.

	void checkWeight();

	/*--------------------------------------------------*/

public:
	Platypus();
	Platypus(char, float, short, char);

	void print() const;
	void print(ostream&) const;
	void fight(const Platypus&);

	void age_me();
	void age_me(double);

	void eat();
	void eat(double);

	void hatch(char, char);

	float getWeight() const;
	char getName() const;
	bool getAlive() const;
};

Platypus::Platypus() {

	uniform_real_distribution<float> weight_distribution(0.1, 10);
	uniform_real_distribution<double> age_distribution(0, 12);

	this->weight = weight_distribution(generator); // Platypus weight in KG. Set randomly between 0.1 and 10.
	this->age = age_distribution(generator); // Platypus age in month. Set randomly between 0 and 12.

	this->alive = false;
} // By default Platypus is death.

Platypus::Platypus(char g, float w, short a, char n) {

	uniform_real_distribution<float> weight_distribution(0.1, 10);
	uniform_real_distribution<double> age_distribution(0, 12);

	this->weight = weight_distribution(generator); // Platypus weight in KG. Set randomly between 0.1 and 10.
	this->age = age_distribution(generator); // Platypus age in month. Set randomly between 0 and 12.

	/* Constructor setted gender, name, age and weight of Platypus. */

	this->gender = g; this->name = n;
	this->age = abs(a); this->weight = abs(w); // abs() - used because this data can't be negative.
}

void Platypus::print() const {

	/* Function printing full data of Platypus in readable format. */

	cout << endl << "Platypus info:" << endl << endl;

	cout << setw(10) << "Name: " << setw(5) << this->name << endl
		<< setw(10) << "Age: " << setw(5) << this->age << " Month." << endl
		<< setw(10) << "Weight: " << setw(5) << this->weight << " Kg." << endl;

	cout << setw(10) << "Gender: ";

	switch (toupper(this->gender))
	{
	case'F':
		cout << setw(5) << "Female." << endl;
		break;
	case'M':
		cout << setw(5) << "Male." << endl;
		break;
	default:
		cout << setw(5) << "Other." << endl;
		break;
	}

	if (mutant) cout << "Platypus " << name << " is mutant." << endl;
	else cout << "Platypus " << name << " is not mutant." << endl;

	if (alive) cout << "This Platypus is alive." << endl;
	else cout << "This Platypus is death." << endl;
}

void Platypus::print(ostream& out) const {

	/* Function printing full data of Platypus in readable format. Overloaded */

	out << endl << "Platypus info:" << endl << endl;

	out << setw(10) << "Name: " << setw(5) << this->name << endl
		<< setw(10) << "Age: " << setw(5) << this->age << " Month." << endl
		<< setw(10) << "Weight: " << setw(5) << this->weight << " Kg." << endl;

	out << setw(10) << "Gender: ";

	switch (toupper(this->gender))
	{
	case'F':
		out << setw(5) << "Female." << endl;
		break;
	case'M':
		out << setw(5) << "Male." << endl;
		break;
	default:
		out << setw(5) << "Other." << endl;
		break;
	}

	if (mutant) out << "Platypus " << name << " is mutant." << endl;
	else out << "Platypus " << name << " is not mutant." << endl;

	if (alive) cout << "This Platypus is alive." << endl;
	else out << "This Platypus is death." << endl;
}

void Platypus::checkWeight() {

	/* Function checking weight of Platypus. */

	uniform_real_distribution<double> mutant_distribution(1, 51);
	int random_seed = mutant_distribution(generator); // Generating number from 1 before 50.
	this->mutant = random_seed == 7; // If Generated number is 7 (variacy 1/50) Platypus became mutant.


	if (this->weight >= 10) { // As in instruction checking if Platypus weight.

		this->alive = false; // If Platypus weight is more or equal 10. It will die.
		cout << "Platypus " << this->name << " has dead at age of " << this->age << " month." << endl;
	}
	else {

		/* Generating two random number with same range. If these numbers will be same Platypus will die. */

		double seed_max = (100 / (this->weight * 10)) + 1; // Creating range for variacy from Platypus weight.
		uniform_real_distribution<double> die_seed(1, seed_max);
		uniform_real_distribution<double> variant_die_seed(1, seed_max);

		/* First generator is for range second imitate choosing (like a human). */

		int variacy = die_seed(generator);
		int choosed_seed = variant_die_seed(generator);

		bool isAlive = variacy != choosed_seed; // Comparing two generated number.
		this->alive = isAlive; // Setting comparing result.

		if (!isAlive) cout << "Platypus " << this->name << " has dead at age of " << this->age << " month." << endl;
	}
}

void Platypus::age_me() {

	/* Function increasing age of Platypus. */

	if (this->alive) { // Checking if Platypus is alive. Death Platypus's age can't be changed.

		uniform_real_distribution<double> grow_distribution(1, 11); // Generating number from 1 before 11.
		this->age += grow_distribution(generator); // Increasing age of Platypus on generated number.

		checkWeight(); // Checking weight as in instruction.

	}
	else cout << "Platypus " << this->name << " is death. Can't change age." << endl;
}

void Platypus::age_me(double age_month) {

	/* Function setting age of Platypus. */

	if (this->alive) { // Checking if Platypus is alive. Death Platypus's age can't be changed.

		this->age = abs(age_month); // Setting age of Platypus.
		checkWeight(); // Checking weight as in instruction.
	}
	else cout << "Platypus " << this->name << " is death. Can't change age." << endl;
}

float Platypus::getWeight() const { return this->weight; } // Getting weight of Platypus.

char Platypus::getName() const { return this->name; } // Getting name of Platypus.

bool Platypus::getAlive() const { return this->alive; } // Getting live status of Platypus.

void Platypus::fight(const Platypus& other_platypus) {

	/* Function imitate fight between two Platypus. */

	bool check = this == &other_platypus;

	if (this->alive && this == &other_platypus) { // Checking if this and other Platypuses's memory address to escape fight with itself.

		cout << "Platypuse " << this->name << " can't fight with itself." << endl;
	}
	else if (this->alive) { // Checking if this Platypus is alive. Death Platypus's can't fight.

		cout << "Platypuse " << this->name << " calling to fight with " << other_platypus.getName() << '.' << endl;

		if (other_platypus.getAlive()) { // Checking if other Platypus is alive. Death Platypus's can't fight.

			/* As in instruction comparing this Platypus's weight and getted weight of other Platypus. */

			float weight_compare = (this->weight / other_platypus.getWeight()) * 50;
			uniform_real_distribution<double> compare_distribution(1, 100); // Generating random number from 1 before 100 for comparing.

			cout << "In this fight won ";

			if (weight_compare > compare_distribution(generator))
				cout << "calling Platypuse: " << this->name << '.' << endl;
			else if (weight_compare < compare_distribution(generator))
				cout << "other Platypuse: " << other_platypus.getName() << '.' << endl;
			else cout << "Friendship." << endl;

			/* Result of fight will print on screen. */

		}
		else cout << "But Platypuse " << other_platypus.getName() << " is death and can't fight." << endl;

	}
	else cout << "Platypuse " << this->name << " is death and can't fight with " << other_platypus.getName() << '.' << endl;
}

void Platypus::eat() {

	/* Function imitate eating and increasing weight of Platypus. */

	if (this->alive) { // Checking if This Platypus is alive. Death Platypus's can't eat.

		/* Generating number (from 0.1 before 5) for procent. On this procent of weight will be increase.*/

		uniform_real_distribution<double> eat_distribution(0.1, 5);
		double changed_procent = eat_distribution(generator);
		this->weight = (this->weight * (changed_procent + 100)) / 100; // Setting new weight.

		cout << "Platypus " << this->name << " has ate and weight increased on " << changed_procent << "%." << endl;
	}
	else cout << "Platypus " << this->name << " is death and can't eat." << endl;
}

void Platypus::eat(double eat_kg) {

	/* Function imitate eating and increasing weight of Platypus by hand. */

	if (this->alive) { // Checking if This Platypus is alive. Death Platypus's can't eat.

		/* Checking mass of getting food mass.*/

		double min_food_kg = (this->weight * 0.1) / 100; // 0.1% of Platypus weight (kg).
		double max_food_kg = (this->weight * 5) / 100; // 5% of Platypus weight (kg).

		/* Mass should be between 0.1% and 5% of Platypus weight (kg)*/

		if (eat_kg >= min_food_kg && eat_kg <= max_food_kg) { // Checking food mass.

			this->weight += eat_kg; // Increasing weight of Platypus.
			cout << "Platypus " << this->name << " has ate and weight increased on " << eat_kg << " kg." << endl;
		}
		else {

			cout << "Platypus " << this->name << " don't eat food that is ";

			if (eat_kg < min_food_kg) cout << "smaller than " << min_food_kg << " kg." << endl;
			else if (eat_kg > max_food_kg) cout << "greater than " << max_food_kg << " kg." << endl;
		}

		/* Result of eating will be print on screen. */
	}
	else cout << "Platypus " << this->name << " is death and can't eat." << endl;
}

void Platypus::hatch(char newName = 'A' + rand() % 26, char newGender = "MF"[rand() % 2]) {

	/* Function imitate hatching of Platypus. */

	/* As in instruction setting new values for Platypus.

	   Now Platypus is:
	*/
	this->alive = true; // Alive.
	this->age = 0; // Age is 0 month.
	this->mutant = false; // not mutant.
	this->gender = newGender; // New gender. Will set automatically if user will not fill.

	uniform_real_distribution<double> hatch_weight_distribution(0.1, 1.0); // Generating number between 0.1 and 1.0.
	this->weight = hatch_weight_distribution(generator); // Setting generating number as weight of Platypus in KG.

	this->name = newName; // Setting new name. Will set automatically if user will not fill.
	cout << endl << "Platypus " << newName << " has hatched." << endl;

	/* Result of hatching will print on screen. */
}

ostream& operator<<(ostream& out, const Platypus& p)
{
	/* Function printing full data of Platypus in readable format. Overloaded operator. */

	p.print(out);
	return out;
}

#endif