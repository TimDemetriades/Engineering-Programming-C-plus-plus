#include <iostream>
#include <string>
#include <map>

using namespace std;

int main() {
	// Creating a empty map
	//  key     value
	map<string, double> stockPrice;

	// Adding elements to the map
	stockPrice["TSLA"] = 290;
	stockPrice["IBM"] = 132;
	stockPrice["MSFT"] = 73.5;
	stockPrice["AAPL"] = 205;
	
	// Reading values using keys from a map
	cout << stockPrice["AAPL"] << "\n";
	cout << stockPrice["XXY"] << '\n';

#if 0
	string x = "xxx";
	char digits[10];

	for (int i = 1; i < 100000; i++) {
		string sym = x + std::to_string(i);
		if (stockPrice[sym] != 0) {
			cout << stockPrice[sym] << '\n';
		}
	}
#endif

	// Iterating through elements
	for (map<string, double>::iterator i = stockPrice.begin();
			 i != stockPrice.end(); ++i) {
		cout << i->first  << " ==> " << i->second << '\n';		// first is the key, second is the value
	}
	
	cout << endl;

	// You can also iterate using the 'auto' keyword
	for (auto x : stockPrice) { // this really uses map<string,double>::const_iterator 
		cout << x.first << " ==> " << x.second << '\n';
	}
	
	//	if (stockPrice.contains("XXY")) {
	//cout << stockPrice["XXY"]
	//	}
	

    // to check if a value is in a map
    map<string, double>::iterator i = stockPrice.find("AAPL");
    if(i == stockPrice.end()) {
        cout << "not there";
    }
    else {
        // this is executed if AAPL is found
		cout << "found it!" << endl;
    }
}