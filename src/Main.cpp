#include <iostream>	
#include <fstream>	
#include <string>
#include <array>



template<int N>
void Symmetric_Sort(std::ifstream& input, std::array<std::string, N>& outSortedList, int itemCount) {
	int j = itemCount - 1;
	for (int i = 0; i < itemCount; i++) {
		if (i % 2 == 0) {
			input >> sortedList[i / 2];
		}
		else {
			input >> sortedList[j];
			j--;
		}
	}
}

template<int N>
void printList(std::array<std::string, N>& sortedList) {
	for (std::string s : sortedList) {
		if (s.empty()) {
			break;
		}
		std::cout << s << std::endl;
	}
}
int main(int argc, char** argv) {
	const unsigned int maxItem = 15;

	std::ifstream input;
	input.open(argv[1]);

	if (!input.is_open()) {
		std::cout << "Unable to open the file" << std::endl;	
		std::cin.get();
		return -1;
	}

	std::string line;
	
	int setCount = 0;
	int itemCount;
	do {
		input >> line;

		itemCount = std::stoi(line);
		std::array<std::string, maxItem> sortedList;

		if (itemCount != 0) {
			Symmetric_Sort<maxItem>(input, sortedList, itemCount);
			setCount++;
			std::cout << "SET " << setCount << std::endl;
			printList<maxItem>(sortedList);
		}
	} while (itemCount);

	input.close();

	std::cin.get();


	return 1;
}