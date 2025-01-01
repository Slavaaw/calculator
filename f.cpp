#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Calculator {
public:

	Calculator(string samp) {
		sample = samp;
	}

	void calculating(int range) {
		for (double numerator = numeratorStartValue; numerator <= range; numerator++) { // числитель
			for (double denomerator = denominatorStartValue; denomerator <= range; denomerator++) {  // знаменатель
				string result = to_string(numerator / denomerator);
				string resForComp;
				if ((numerator / denomerator) < 1.0) { resForComp = result.erase(0, 2); }
				else { resForComp = result.erase(result.find(","), 1); }

				comparison(resForComp, numerator, denomerator);
			}
		}
	}

	void displayOutput() {
		for (vector<pair<double, double>>::iterator iter = vec.begin(); iter != vec.end(); iter++) {
			pair<double, double> pair = *iter;
			cout << "Числитель: " << pair.first << " Знаменатель: " << pair.second << endl;
		}
	}

private:
	int numeratorStartValue = 1;
	int denominatorStartValue = 2;
	string sample;
	string zero = "0";
	int counter = 0;
	vector<pair<double, double>> vec;

	void comparison(string value, double numerator, double denomerator) {
		int stringIndexStart = 0;

		for (int stringIndex = stringIndexStart, sampleIndex = 0; stringIndex <= 10; stringIndex++) {
			if (value[stringIndex] == sample[sampleIndex]) {
				counter++;
				sampleIndex++;
				if (sampleIndex == 4) {
					vec.push_back({ numerator, denomerator });
				}
			}
			else if (to_string(value[stringIndex]) == zero) { continue; }
			else { break; }
		}
	}
};

int main()
{
	setlocale(LC_ALL, "RU");
	Calculator calc("1488");
	calc.calculating(1000);
	calc.displayOutput();
	return 0;
}