#include <iostream>
#include <string>
#include "hashmap.cpp"
using namespace std;

int main(){
	hashmap myMap;
	cout<<"=================================="<<endl;
	cout<<"Phone-Book"<<endl;
	cout<<"Add Contact (Press 1)"<<endl;
	cout<<"Display Contacts (Press 2)"<<endl;
	cout<<"Delete Contact (Press 3)"<<endl;
	cout<<"Search Contact (Press 4)"<<endl;
	cout<<"=================================="<<endl;
	int n;
	cin<<n;
	switch(n){
		case 1://insert
			string name,num;
		    cout<<"Enter name";
		    cin>>name;
		   	cout<<"Enter Number:"<<endl;
		   	cin>>num;
		   	myMap.insert(name,num);
		    break;
		case 2://display
		    int mapSize = myMap.size();
		    break;
		case 3://delete
		    
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