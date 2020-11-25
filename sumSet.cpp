#include <iostream>
#include <vector>
#include <set>
#include <cmath>

int main() {

	int n = 0;
	int countUnit = 0;
	std::set<int> tempSet;
	std::set<int> :: iterator it;
	std::vector<std::set<int>> v;
	
	std::cout << "Enter number of set: ";
	std::cin >> n;
	std::cout << "Enter numbers in the sets: ";
	std::cin >> countUnit;

	for(int i = 0; i < n; i++) {
		for(int j = 0; j < countUnit; j++) {
			int elementSet;
			std::cin >> elementSet;
			tempSet.insert(elementSet);
		}
		v.push_back(tempSet);
		tempSet.clear();
	}

	int temp = pow(countUnit, n) / countUnit;
	int theRepeat = 0;
	int temp_i = 0;

	for(int i = 0; i < n; i++) {
		//перегнал элементы множества в вектор
		//потому что через итераторы это еще +4 строки кода
		it = v[i].begin();
		std::vector<int> tempV;
		for(int k = 0; k < countUnit; k++) {
			tempV.push_back(*it);
			it++;
		}
		for(int j = 0; j < pow(countUnit, n); j++) {
			if(theRepeat == temp) {
				theRepeat = 0;
				temp_i++;
				if(temp_i == countUnit)
					temp_i = 0;
			}
			std::cout << tempV[temp_i]<< " ";
			theRepeat++;
		}
		std::cout << std::endl;
		temp /= countUnit;
		theRepeat = 0;
		temp_i = 0;
	}
	return 0;
}