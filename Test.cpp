#include <iostream>
#include <string>

using namespace std;

class Calculator {

private:
	int range;
	string result = "1488";
	double res = 0;
	int total = 0;
	int count = 0;
	int index = 0;
	string a{ "0," };
	char zero = a[0];
	char zap = a[1];

public:

	Calculator(int range) {
		this->range = range;
	}

	void calculating() {
		for (double firstNum = 1; firstNum <= this->range; firstNum++) {
			for (double secondNum = 1; secondNum <= this->range; secondNum++) {

				res = firstNum / secondNum;
				string newRes{ to_string(res) };

				for (int indexForResult = 0; indexForResult <= 9; indexForResult++) {

					if (count == 4) {
						total++;
						count = 0;
						index = 0;
						cout << "FirstNum = " << firstNum << " SecondNum = " << secondNum << endl;
						break;
					}

					else if ((result[index] == newRes[indexForResult] && count == 0) || (result[index] == newRes[indexForResult] && count == 1) || (result[index] == newRes[indexForResult] && count == 2) || (result[index] == newRes[indexForResult] && count == 3)) {
						count++;
						index++;
					}
					else if ((newRes[indexForResult] != zero) && (newRes[indexForResult] != zap)) {
						index = 0;
						count = 0;
						break;
					}
				}
			}

		}
	}

	~Calculator() {
		cout << total << endl;
	}
};



int main()
{
	setlocale(LC_ALL, "RU");
	Calculator calc(1000);
	calc.calculating();

	return 0;
}