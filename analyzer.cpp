//My partner's name was Rahul Sai Boggavarapu
#include <iostream>
#include <vector>
#include "stringData.h"
using namespace std;
int linearSearch(vector <string> container, string element) {
    for (int i = 0; i < container.size(); i++) {
        if (container[i] == element) {
            return i;
        }
    }
    return -1;
}

int binarySearch(vector <string> container, string element) {
    int low = 0;
    int high = container.size() - 1;
    int mid = (low + high) / 2;
    while (low <= high) {
        if (container[mid] == element) {
            return mid;
        }
        else if (container[mid] < element) {
            low = mid + 1;
            mid = (high + low) / 2;
        }
        else {
            high = mid - 1;
            mid = (low + high) / 2;
        }
    }
    return -1;
}

void print(vector <string> container, string type, string element) {
    cout << "The " << type << " search algorithm is being tested with the string \"" << element << "\"." << endl;
    int index = -1;
    auto begin = chrono::system_clock::now();
    auto end = begin;
    if (type == "linear"){
        begin = chrono::system_clock::now();
        index = linearSearch(container, element);
        end = chrono::system_clock::now();
        }
    else {
        begin = chrono::system_clock::now();
        index = binarySearch(container, element);
        end = chrono::system_clock::now();
    }
    auto elapsed = end - begin;

    cout << "An index of " << index << " was found." << endl;
    cout << "Python returned a time of " << elapsed << "." << endl;
    cout << endl;
}

int main() {
    vector <string> container = getStringData();

    print(container, "linear", "not_here");
    print(container, "binary", "not_here");

    print(container, "linear", "mzzzz");
    print(container, "binary", "mzzzz");

    print(container, "linear", "aaaaa");
    print(container, "binary", "aaaaa");

    return 0;
}