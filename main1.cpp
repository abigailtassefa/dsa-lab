#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <cctype>

// Struct to mimic Python's multi-value (tuple) return for search functions
struct SearchResult {
    std::vector<int> array;
    int index;
    int target;
};

// Function prototypes to allow arbitrary calling order
void cli(bool error = false);
std::vector<int> acceptNumbers();
int acceptTarget();
void presentArray(const std::vector<int>& array);
void presentAnswer(const SearchResult& result);
void responseProcessor(const std::string& response);
std::vector<int> simpleSort(std::vector<int> array = {});
std::vector<int> bubbleSort(std::vector<int> array = {});
SearchResult linearSearch(std::vector<int> array = {}, int n = -1, bool promptForTarget = true);
SearchResult binarySearch(std::vector<int> array = {}, int n = -1, int l = 0, int r = -2, bool promptForTarget = true);

// Helper function to trim whitespace from strings
std::string trim(const std::string& str) {
    size_t first = str.find_first_not_of(" \t\r\n");
    if (first == std::string::npos) return "";
    size_t last = str.find_last_not_of(" \t\r\n");
    return str.substr(first, (last - first + 1));
}

void cli(bool error) {
    std::string response;
    if (error) {
        std::cout << "Invalid Entry! Please enter a valid key \n";
        std::getline(std::cin, response);
        responseProcessor(response);
    } else {
        std::cout << "Welcome brother, what would you like to do today\n";
        std::cout << "For linear search press A\n";
        std::cout << "For binary search press B\n";
        std::cout << "For simple sort, press C\n";
        std::cout << "For bubble sort press D \n";
        std::getline(std::cin, response);
        responseProcessor(response);
    }
}

std::vector<int> acceptNumbers() {
    std::cout << "Enter the list of numbers you want to process (comma-separated): ";
    std::string inputStr;
    std::getline(std::cin, inputStr);

    std::vector<int> array;
    std::stringstream ss(inputStr);
    std::string item;
    
    while (std::getline(ss, item, ',')) {
        item = trim(item);
        if (!item.empty()) {
            array.push_back(std::stoi(item));
        }
    }

    std::cout << "[";
    for (size_t i = 0; i < array.size(); ++i) {
        std::cout << array[i] << (i == array.size() - 1 ? "" : ", ");
    }
    std::cout << "]\n";

    return array;
}

int acceptTarget() {
    std::cout << "Enter the number you want to search for: ";
    std::string inputStr;
    std::getline(std::cin, inputStr);
    return std::stoi(trim(inputStr));
}

void presentArray(const std::vector<int>& array) {
    std::cout << "The sorted array is [";
    for (size_t i = 0; i < array.size(); ++i) {
        std::cout << array[i] << (i == array.size() - 1 ? "" : ", ");
    }
    std::cout << "]\n";
}

void presentAnswer(const SearchResult& result) {
    std::cout << "The array is [";
    for (size_t i = 0; i < result.array.size(); ++i) {
        std::cout << result.array[i] << (i == result.array.size() - 1 ? "" : ", ");
    }
    std::cout << "]\n";

    if (result.index == -1) {
        std::cout << result.target << " was not found in the array\n";
    } else {
        std::cout << result.target << " was found at index " << result.index << " in the array\n";
    }
}

void responseProcessor(const std::string& response) {
    std::string choice = trim(response);
    std::transform(choice.begin(), choice.end(), choice.begin(), ::toupper);

    if (choice == "A") {
        presentAnswer(linearSearch());
    } else if (choice == "B") {
        presentAnswer(binarySearch());
    } else if (choice == "C") {
        presentArray(simpleSort());
    } else if (choice == "D") {
        presentArray(bubbleSort());
    } else {
        cli(true);
    }
}

std::vector<int> simpleSort(std::vector<int> array) {
    if (array.empty()) {
        array = acceptNumbers();
    }
    if (array.empty()) return array;

    for (size_t i = 0; i < array.size() - 1; ++i) {
        size_t min_idx = i;
        for (size_t j = i; j < array.size(); ++j) {
            if (array[j] < array[min_idx]) {
                min_idx = j;
            }
        }
        int temp = array[i];
        array[i] = array[min_idx];
        array[min_idx] = temp;
    }
    return array;
}

std::vector<int> bubbleSort(std::vector<int> array) {
    if (array.empty()) {
        array = acceptNumbers();
    }
    int wall = array.size();

    while (wall > 1) {
        for (int i = 0; i < wall - 1; ++i) {
            if (array[i + 1] < array[i]) {
                int temp = array[i + 1];
                array[i + 1] = array[i];
                array[i] = temp;
            }
        }
        wall--;
    }
    return array;
}

SearchResult linearSearch(std::vector<int> array, int n, bool promptForTarget) {
    if (array.empty()) {
        array = acceptNumbers();
    }
    if (promptForTarget && n == -1) {
        n = acceptTarget();
    }

    for (size_t i = 0; i < array.size(); ++i) {
        if (array[i] == n) {
            return {array, static_cast<int>(i), n};
        }
    }
    return {array, -1, n};
}

SearchResult binarySearch(std::vector<int> array, int n, int l, int r, bool promptForTarget) {
    if (array.empty()) {
        array = acceptNumbers();
        array = bubbleSort(array);
    }
    if (promptForTarget && n == -1) {
        n = acceptTarget();
    }
    if (r == -2) {
        r = static_cast<int>(array.size()) - 1;
    }

    if (l > r) {
        return {array, -1, n};
    }

    int m = (l + r) / 2;

    if (array[m] == n) {
        return {array, m, n};
    } else if (array[m] < n) {
        return binarySearch(array, n, m + 1, r, false);
    } else {
        return binarySearch(array, n, l, m - 1, false);
    }
}

int main() {
    cli();
    return 0;
}
