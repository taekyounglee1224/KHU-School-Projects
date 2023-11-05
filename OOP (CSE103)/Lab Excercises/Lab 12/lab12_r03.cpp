#include <iostream>
using namespace std;

class Train {
public:
	Train() {}
	Train(int people) { tPeople = people; }
	~Train() {}
	virtual int station(int takeOff, int takeOn) {
		tPeople += (takeOn - takeOff);
		if (tPeople > 300) {
			cout << "정원초과입니다" << endl;
			return false;
		}
		else if (tPeople < 0) {
			cout << "정원미달입니다" << endl;
			return false;
		}
		else
			return true;
	}
protected:
	int tPeople;
};
class Ktx : public Train {
public:
	Ktx() : Train(0) {}
	Ktx(int people) : Train(people) {}
	~Ktx() {}
	int station(int takeOff, int takeOn) {
		Train::tPeople += takeOn - takeOff;
		if (Train::tPeople > 300) {
			cout << "정원초과입니다" << endl;
			return false;
		}
		else if (Train::tPeople < 0) {
			cout << "정원미달입니다" << endl;
			return false;
		}
		else
			return true;
	}
	int getPeople() {
		return Train::tPeople;
	}
};

int main() {
	Ktx k;
	int takeOff, takeOn;
	int max = 0;
	for (int i = 0; i < 5; i++) {
		cout << i + 1 << "번역: ";
		cin >> takeOff >> takeOn;
		if (!k.station(takeOff, takeOn))
			return 0;
		max < k.getPeople() ? (max = k.getPeople()) : NULL;
	}
	cout << "가장 많은 사람이 탑승 했을 때의 사람 수: " << max << endl;
	return 0;
}
