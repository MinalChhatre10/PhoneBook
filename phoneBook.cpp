#include <iostream>
#include <string>
#include "hashmap.cpp"
using namespace std;

int main(){
	hashmap myMap;
	cout<<"=================================="<<endl;
	cout<<"Phone-Book"<<endl;
	cout<<"Display Contacts (Press 1)"<<endl;
	cout<<"Add Contact (Press 2)"<<endl;
	cout<<"Delete Contact (Press 3)"<<endl;
	cout<<"Search Contact (Press 4)"<<endl;
	cout<<"=================================="<<endl;
	int n;
	cin<<n;
	switch(n){
		case 1://display
			    int mapSize = myMap.size();
			    if (mapSize == 0) {
			        cout << "Phone book is empty." << endl;
			    } else {
			        cout << "Contacts in the phone book:" << endl;
			        for (int i = 0; i < myMap.numBuckets; i++) {
			            MapNode* head = myMap.buckets[i];
			            while (head != NULL) {
			                cout << head->key << ": ";
			                for (int j = 0; j < head->value.size(); j++) {
			                    cout << head->value[j];
			                    if (j != head->value.size() - 1) {
			                        cout << ", ";
			                    }
			                }
			                cout << endl;
			                head = head->next;
			            }
			        }
			    }
		    break;
		case 2://insert
		       string name,num;
			   cout<<"Enter name";
			   cin>>name;
			   cout<<"Enter Number:"<<endl;
			   cin>>num;
			   myMap.insert(name,num);
		    break;
		case 3://delete
		    	string name;
			    cout<<"Enter name";
			    cin>>name;
			    	vector<string> numbers = myMap.remove(name);
			    	cout<<"Deleted Contact: "<<name<<": "<<endl;
			    	for (int i = 0; i < numbers.size(); ++i)
			    	{
			    		cout<<numbers[i]<<endl;
			    	}
			   
		    break;
		case 4://search
				string name;
			    cout<<"Enter name";
			    cin>>name;
			    vector<string> numbers = myMap.getValue(name);
			    if(numbers.size()==0){
			    	cout<<"No record found for contact: "<<name<<"."<<endl;
			    }
			    else{
			    	cout<<"Record found for contact: "<<name<<":"<<endl;
			    	for(int i=0;i<numbers.size();i++){
			    		cout<<numbers[i];
			    		if(i!=numbers.size()-1){
			    			cout<<", ";
			    		}
			    	}
			    	cout<<endl;
			    }
		    break;
		default:
		    cout<<"(InValid!) Enter correct option.";
	}

	return 0;
}