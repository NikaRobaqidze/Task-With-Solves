#include <iostream> // Import iostream library for input data from keyboard and printing data to screen.

using namespace std;

#ifndef Staque_H
#define Staque_H

typedef int dataType;

class Staque {

	class Node {
	public:
		dataType data;
		Node* next;
		Node* previouslyAdded;
		Node(dataType d, Node* n = nullptr, Node* p = nullptr) {

			this->data = d; // Data that is container for necessary data.
			this->next = n; // Pointer on next Node.
			this->previouslyAdded = p; // Pointer on Node that has added previously.
		}
	};

	Node* begin = nullptr; // Pointer on top Node of Staque.
	Node* end = nullptr; // Pointer on bottom Node of Staque.
	Node* last = nullptr; // Pointer on last added Node in Staque.
	int size = 0; // Counter of Staque Nodes.

public:
	Staque() = default;
	Staque(dataType);
	Staque(const Staque&);

	bool isEmpty() const;
	void show(ostream& out) const;

	Staque& operator=(const Staque& other);

	template <typename containerType>
	Staque(const containerType&);

	void expandBy(dataType, int);

	template <typename containerType>
	void expandBy(containerType);

	void removeFirst(int);
	void removeFirst(int, char);

	~Staque();
};

bool Staque::isEmpty() const { return this->size == 0; }

Staque::Staque(dataType d) {

	/* Set first Node in constructor.*/

	Node* n = new Node(d);

	this->begin = n;
	this->end = n;

	this->last = n; // Saving last added Node.
	this->size++; // Increasing size of queue.
}

Staque::Staque(const Staque& other_ll) {

	/* Creating new Staque class and copy all elements from other. */

	this->begin = new Node(other_ll.begin->data); // Saving other Staque top's value in the top Node of this Staque.
	this->size = 1; // Change size of queue.

	if (!other_ll.isEmpty() && other_ll.begin != other_ll.end) { // Check if is Staque empty or consist from 1 elemnt.

		Node* temp = other_ll.begin->next; // Temporary Node for saving new element.
		Node* pntr = other_ll.begin->next; // Pointer Node for moving in while loop.

		while (temp != other_ll.end) {
			temp = pntr;
			pntr = temp->next;

			temp->previouslyAdded = this->last; // Set last added elemnt as pervious new.

			if (this->begin->next == nullptr) {

				temp->previouslyAdded = this->begin; // Set pervoius node for second element.
				this->begin->next = temp; // Set next of top element new node.
			}
			else this->end->next = temp; // Set new node at next element of bottom node.

			this->end = temp; // Save new node as bottom.
			this->last = temp; // Saving last added Node.
			this->size++; // Increasing size of Staque.
		}

		temp = nullptr;
		delete temp;

		pntr = nullptr;
		delete pntr;
	}
}

template <typename containerType>
Staque::Staque(const containerType& myContainer) {

	/* Creating Staque and inserting all elemnts from container at initialization. */

	this->begin = new Node(*myContainer.begin()); // Create new Node with first value of container, setting at the top of Staque.
	this->size++; // Increasing size of Staque.

	Node* temp; // Temporary Node for saving new element.

	/* Saving all elemnts of container in Staque. */

	for (auto i = myContainer.begin() + 1; i != myContainer.end(); i++) {

		temp = new Node(*i); // Set new value at temporary Node.
		temp->previouslyAdded = this->last; // Set last added elemnt as pervious new.

		if (this->begin->next == nullptr) temp->previouslyAdded = this->begin; // Set pervoius node for second element.

		if (*i % 2 == 0) { // Checking is new value even.

			temp->next = this->begin; // Next element of new node is top node.
			this->begin = temp; // Save new node as top.
		}
		else {

			if (this->begin->next == nullptr) this->begin->next = temp; // Set next of top element new node.
			else this->end->next = temp; // Set new node at next element of bottom node.

			this->end = temp; // Save new node as bottom.
		}

		this->last = temp; // Saving last added Node.
		this->size++; // Increasing size of Staque.
	}

	/* Clearing and deleting used pointers. */

	temp = nullptr;
	delete temp;
}

void Staque::expandBy(dataType d, int quant = 1) {

	/* Adding new values in Staque. */

	Node* temp; // Temporary Node for saving new element.

	for (int i = 0; i < abs(quant); i++) { // We use a loop to add the value as many times as we want.

		temp = new Node(d); // Set new value at temporary Node.
		if (this->begin->next == nullptr) temp->previouslyAdded = this->begin; // Set pervoius node for second element.
		temp->previouslyAdded = this->last; // Set last added elemnt as pervious new.

		if (d % 2 == 0) { // Checking is new value even.

			temp->next = this->begin; // Next element of new node is top node.
			this->begin = temp; // Save new node as top.
		}
		else {

			if (this->begin->next == nullptr) this->begin->next = temp; // Set next of top element new node.
			else this->end->next = temp; // Set new node at next element of bottom node.

			this->end = temp; // Save new node as bottom.
		}

		this->last = temp; // Saving last added Node.
		this->size++; // Increasing size of Staque.
	}

	/* Clearing and deleting used pointers. */

	temp = nullptr;
	delete temp;
}

template <typename containerType>
void Staque::expandBy(containerType myContainer) {

	/* Adding all elemnts from container in Staque. */

	Node* temp; // Temporary Node for saving new element.

	for (auto i = myContainer.begin(); i != myContainer.end(); i++) {

		temp = new Node(*i); // Set new value at temporary Node.
		//if (this->begin->next == nullptr) temp->previouslyAdded = this->begin; // Set pervoius node for second element.
		temp->previouslyAdded = this->last; // Set last added elemnt as pervious new.

		if (*i % 2 == 0) { // Checking is new value even.

			temp->next = this->begin; // Next element of new node is top node.
			this->begin = temp; // Save new node as top.
		}
		else {

			if (this->begin->next == nullptr) this->begin->next = temp; // Set next of top element new node.
			else this->end->next = temp; // Set new node at next element of bottom node.

			this->end = temp; // Save new node as bottom.
		}

		this->last = temp; // Saving last added Node.
		this->size++; // Increasing size of Staque.
	}

	/* Clearing and deleting used pointers. */

	temp = nullptr;
	delete temp;
}

void Staque::removeFirst(int quantity = 1) {

	/* Deleting some quantity of numbers from Staque. Deleting by LiFO (Last In First Out) rules. */

	if (isEmpty()) std::cout << "Can't remove any from staque, because it is empty." << endl;

	/* Checking is entered qunatity of numbers greater then Staque size to get error message. */

	else if (abs(quantity) > this->size) std::cout << "Can't remove " << abs(quantity) << " element from, because staque size is " << this->size << "." << endl;

	else {

		Node* last_pntr = this->last; // Pointer Node for moving in while loop.
		Node* last_temp = this->last; // Temporary Node for saving element of Staque.

		for (int i = 0; i < abs(quantity); i++) {

			last_temp = last_pntr;
			last_pntr = last_pntr->previouslyAdded;

			/* Checking is top element of Staque number that has added last. */

			if (last_temp == this->begin) this->begin = this->begin->next; // Set second element at top of Staque.

			else {

				// Deleting node from top of Staque.

				Node* exst_pntr = this->begin; // Pointer Node for moving in while loop.
				Node* exst_temp = exst_pntr; // Temporary Node for saving element of Staque.

				for (int j = 0; j < size; j++) {

					exst_temp = exst_pntr;
					exst_pntr = exst_pntr->next;

					if (exst_temp->next == last_temp && last_temp == this->end) { // Checking is this Node penultimate.

						exst_temp->next = nullptr; // Removing pointer on next Node.
						this->end = exst_temp; // Set this element at bottom of Staque.
					}
				}

				/*---Clearing and deleting used pointers.---*/

				exst_pntr = nullptr;
				delete exst_pntr;

				exst_temp = nullptr;
				delete exst_temp;

				/* ---------------------------------------- */
			}

			this->last = last_temp;
			delete last_temp; // Praqtikulze garkveva!!!
			this->size--;
		}

		this->last = this->last->previouslyAdded;

		/* Clearing and deleting used pointers. */

		last_pntr = nullptr;
		delete last_pntr;

		last_temp = nullptr;
		delete last_temp;
	}
}

void Staque::removeFirst(int quantity, char whichNum) {

	/* Deleting some quantity Even or Odd numbers from Staque. Deleting by LiFO (Last In First Out) rules. */

	if (isEmpty()) std::cout << "Can't remove any from staque, because it is empty." << endl;

	/* Checking is entered qunatity of numbers greater then Staque size to get error message. */

	else if (abs(quantity) > this->size) std::cout << "Can't remove " << abs(quantity) << " element from, because staque size is " << this->size << "." << endl;

	/* Checking is entered type of number for deleting. Function can delete only E - Even or O - Odd numbers from Staque. */

	else if (whichNum != 'E' && whichNum != 'O') std::cout << "User can remove only (E)ven or (O)dd number." << endl;

	else {

		/* Calculating count of even and odd numbers. */

		Node* pntr = this->begin; // Pointer Node for moving in while loop.
		Node* temp = this->begin; // Temporary Node for saving element of Staque.

		int evenCount = 0; // Even numbers counter.

		/* At first calculating count of even numbers.
		* Then we count the number of odd numbers by calculating the Staque size from the number of even numbers.
		*/

		while (temp != this->end) {

			temp = pntr;
			pntr = temp->next;

			if (temp->data % 2 == 0) evenCount++; // Even numbers counting.
			else break;
		}

		/* Reusing Node for other loop. */

		pntr = this->last;
		temp = this->last;

		int oddCount = size - evenCount; // Odd numbers counter.

		/* Checking is Staque consist same quantity of numbers that been entered. */

		if (whichNum == 'E' && abs(quantity) > evenCount) std::cout << "User cann't remove more then " << evenCount << " even numbers." << endl;
		else if (whichNum == 'O' && abs(quantity) > oddCount) std::cout << "User cann't remove more then " << oddCount << " odd numbers." << endl;

		else if (whichNum == 'E') {

			/* Deleting Even numbers. Moving from top and deleting Nodes. */

			Node* last_pntr = this->begin; // Pointer Node for moving in while loop.
			Node* last_temp = this->begin; // Temporary Node for saving element of Staque.

			for (int i = 0; i < abs(quantity); i++) {

				last_temp = last_pntr;
				last_pntr = last_pntr->next;

				this->begin = this->begin->next; // Setting second elemnet at the top of Staque.
				if (this->last == last_temp) this->last = last_temp->previouslyAdded; // If this last added element will set previously added element of Staque.

				//delete last_temp; // Deleting Node. // Praqtikulze garkveva!!!
				this->size--; // Decreasing size of Staque.
			}

			/*---Clearing and deleting used pointers.---*/

			last_pntr = nullptr;
			delete last_pntr;

		}
		else if (whichNum == 'O') {

			/* Deleting Even numbers. Moving by pervious from bottom and deleting Nodes. */

			if (abs(quantity) == oddCount) {

				/* If user deleting all odd numbers bottom numbers must be even. */

				Node* temp = this->begin; // Temporary Node for deleting old element.
				Node* pntr = this->begin; // Pointer Node for while loop.

				Node* last_even = this->begin; // Node where will be save last even number.

				/* Finding last even number. Moving by pervious from bottom. */

				while (temp != this->end) {

					temp = pntr;
					pntr = temp->next;

					if (temp->data % 2 == 0) last_even = temp; // Saving node to set it at bottom of Staque.
					else temp = nullptr; // Deleting node of Staque.
				}

				last_even->next = nullptr; // Removing pointer on next element, because it will be last/
				this->end = last_even; //Set at bottom of Staque.

				/*---Clearing and deleting used pointers.---*/

				temp = nullptr;
				delete temp;

				pntr = nullptr;
				delete pntr;

				last_even = nullptr;
				delete last_even;
			}
			else {

				Node* last_pntr = this->last; // Pointer Node for while loop.
				Node* last_temp = this->last; // Temporary Node for deleting old element.

				int thisSize = abs(quantity); // Counter of nodes which need to delete.

				/* Deleting node while counter will not equal to 0. */

				while (thisSize) {

					last_temp = last_pntr;
					last_pntr = last_pntr->previouslyAdded;

					/* Finding last added odd number. */

					if (last_temp->data % 2 != 0) {

						/* Finding odd number, which has added before last of it. */

						for (int i = 1; i <= oddCount; i++) {

							temp = pntr;
							pntr = temp->previouslyAdded;

							if (temp->data % 2 != 0 && temp != last_temp) { // Checking is number odd and not last added number of it.

								temp->next = nullptr; // Deleting pointer on next element, because it will be last.
								this->end = temp; // Set at the bottom of Staque.
								break;
							}
						}

						if (this->last == last_temp) this->last = last_temp->previouslyAdded;
						delete last_temp; // Deleting Node. // Praqtikulze garkveva!!!
						this->size--; // Decreasing size of Staque.
						thisSize--; // // Decreasing counter of nodes which need to delete.
					}
				}

				/*---Clearing and deleting used pointers.---*/

				last_pntr = nullptr;
				delete last_pntr;
			}
		}

		/* Clearing and deleting used pointers. */

		pntr = nullptr;
		delete pntr;

		temp = nullptr;
		delete temp;
	}
}

Staque::~Staque() {

	/* Delete nodes */

	if (!isEmpty() && this->begin != this->end) { // Check if is Staque empty or consist from 1 elemnt.

		Node* temp = this->begin; // Temporary Node for deleting old element.
		Node* pntr = this->begin; // Pointer Node for while loop.

		while (temp != this->end) {

			temp = pntr;
			pntr = temp->next;
			//cout << "Del " << temp->data << " "; // Praqtikulze garkveva!!!
			delete temp; // Deleting node of Staque.
		}
	}

	/* Empty begin, end and last pointers of queue. */

	this->begin = nullptr;
	this->end = nullptr;
	this->last = nullptr;

	/* Deleting begin, end and last pointers of queue. */

	delete this->begin;
	delete this->end;
	delete this->last;

	this->size = 0; // Change size of queue.
	delete this; // Deleting pointer of this object.
}

void Staque::show(ostream& out) const {

	/* Printing all element's data of Staque. */

	if (isEmpty()) out << "Staque is empty." << endl;

	else {

		out << "Staque: ";

		if (this->begin != this->end) {

			Node* temp = this->begin;
			Node* pntr = this->begin;

			while (temp != this->end)
			{
				temp = pntr;
				pntr = temp->next;
				out << temp->data << " ";
			}

			out << endl;

			/*---Clearing and deleting used pointers.---*/

			temp = nullptr;
			delete temp;

			pntr = nullptr;
			delete pntr;

			/*------------------------------------------*/

		}
		else out << this->begin->data << endl;
	}
};

ostream& operator<<(ostream& out, Staque& ll) {

	ll.show(out);
	return out;
}

Staque& Staque::operator=(const Staque& other_ll) {

	/* Creating new Staque class and copy all elements from other. By = operator. */

	if (this != &other_ll) {

		Node* temp = this->begin; // Temporary Node for deleting old element.
		Node* pntr = this->begin; // Pointer Node for while loop.

		while (temp != this->end) {

			temp = pntr;
			pntr = temp->next;
			//cout << "Del " << temp->data << " "; // Praqtikulze garkveva!!!
			delete temp; // Deleting node of Staque.
		}

		this->begin = new Node(other_ll.begin->data); // Saving other Staque top's value in the top Node of this Staque.
		this->size = 1; // Change size of queue.

		if (!other_ll.isEmpty() && other_ll.begin != other_ll.end) { // Check if is Staque empty or consist from 1 elemnt.

			temp = other_ll.begin->next; // Temporary Node for saving new element.
			pntr = other_ll.begin->next; // Pointer Node for moving in while loop.

			while (temp != other_ll.end) {

				temp = pntr;
				pntr = temp->next;

				temp->previouslyAdded = this->last; // Set last added elemnt as pervious new.

				if (this->begin->next == nullptr) {

					temp->previouslyAdded = this->begin; // Set pervoius node for second element.
					this->begin->next = temp; // Set next of top element new node.
				}
				else this->end->next = temp; // Set new node at next element of bottom node.

				this->end = temp; // Save new node as bottom.
				this->last = temp; // Saving last added Node.
				this->size++; // Increasing size of Staque.
			}

			temp = nullptr;
			delete temp;

			pntr = nullptr;
			delete pntr;
		}
	}

	return *this;
}

#endif