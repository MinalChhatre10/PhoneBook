#include <iostream>
#include <string>
#include <vector>
#include "hashmap.cpp"
using namespace std;

int main()
{

	OurMap myMap;
	int choice;

	do
	{
		int mapSize = myMap.size();
		string name, num;
		vector<string> deletedNumbers;
		vector<string> numbers;
		vector<string> phoneNumber;

		cout << "=================================" << endl;
		cout << "          Phone-Book          " << endl;
		cout << "=================================" << endl;
		cout << "Display Contacts (Press 1)" << endl;
		cout << "Add Contact (Press 2)" << endl;
		cout << "Delete Contact (Press 3)" << endl;
		cout << "Search Contact (Press 4)" << endl;
		cout << "=================================" << endl;
		cout << "Enter your choice: ";
		int n;
		cin >> n;

		switch (n)
		{
		case 1: // display
			cout << "=================================" << endl;
			cout << "          Display          " << endl;
			cout << "=================================" << endl;
			if (mapSize == 0)
			{
				cout << "Phone book is empty." << endl;
			}
			else
			{
				cout << "Contacts in the phone book:" << endl;
				for (int i = 0; i < myMap.numBuckets; i++)
				{
					MapNode *head = myMap.buckets[i];
					while (head != NULL)
					{
						cout << head->key << ": ";
						for (int j = 0; j < head->value.size(); j++)
						{
							cout << head->value[j];
							if (j != head->value.size() - 1)
							{
								cout << ", ";
							}
						}
						cout << endl;
						head = head->next;
					}
				}
			}
			cout << "=================================" << endl;
			break;
		case 2: // insert
			cout << "=================================" << endl;
			cout << "          Insert          " << endl;
			cout << "=================================" << endl;
			cout << "Enter name: ";
			cin >> name;
			cout << endl;
			cout << "Enter Number: ";
			cin >> num;
			phoneNumber.push_back(num);
			myMap.insert(name, phoneNumber);
			cout << "Contact Saved" << endl;
			cout << "=================================" << endl;
			break;
		case 3: // delete
			cout << "=================================" << endl;
			cout << "          Delete          " << endl;
			cout << "=================================" << endl;
			cout << "Enter name: ";
			cin >> name;
			deletedNumbers = myMap.remove(name);
			cout << "Deleted Contact: " << name << ": " << endl;
			for (int i = 0; i < deletedNumbers.size(); ++i)
			{
				cout << deletedNumbers[i] << endl;
			}
			cout << "=================================" << endl;
			break;
		case 4: // search
			cout << "=================================" << endl;
			cout << "          Search          " << endl;
			cout << "=================================" << endl;
			cout << "Enter name: ";
			cin >> name;
			numbers = myMap.getValue(name);
			if (numbers.size() == 0)
			{
				cout << "No record found for contact: " << name << "." << endl;
			}
			else
			{
				cout << "Record found for contact- " << name << ":" << endl;
				for (int i = 0; i < numbers.size(); i++)
				{
					cout << numbers[i];
					if (i != numbers.size() - 1)
					{
						cout << ", ";
					}
				}
				cout << endl;
			}
			cout << "=================================" << endl;
			break;
		default:
			cout << "=================================" << endl;
			cout << "          (InValid!)         " << endl;
			cout << "=================================" << endl;
			cout << "Enter correct option.";
			cout << "=================================" << endl;
		}
		cout << "Do you want to continue? (press 0): ";
		cin >> choice;
	} while (choice == 0);
	return 0;
}