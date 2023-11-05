#include <iostream>
 
using namespace std;

void appleprice(int a=1000) {
	cout << "The price of an apple is " << a << endl;
}

int main() {
	
	appleprice(1500);
	appleprice(500);
	appleprice(1000);
	appleprice();
}