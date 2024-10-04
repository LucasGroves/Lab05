// My partners name is Lucas Groves

// Preprocessor Directives
#include <iostream>
#include "StringData.h"

// Namespace to simplify std library code
using namespace std;

// Forward declaration of functions
int linearSearch(vector<string> container, string element);
int binarySearch(vector<string> container, string element);

// Main entry point of the program
int main() {
    // Initialize vector of possible strings from StringData.h
    vector<string> possible_words = getStringData();

    // Linear search for "not_here"
    auto start_time = chrono::system_clock::now();
    linearSearch(possible_words, "not_here");
    auto end_time = chrono::system_clock::now();

    // Record time
    auto linear_search_word1_time = chrono::duration_cast<chrono::nanoseconds>(end_time - start_time);

    // Binary search for "not_here"
    start_time = chrono::system_clock::now();
    binarySearch(possible_words, "not_here");
    end_time = chrono::system_clock::now();

    // Record time
    auto binary_search_word1_time = chrono::duration_cast<chrono::nanoseconds>(end_time - start_time);

    // Linear search for "mzzzz"
    start_time = chrono::system_clock::now();
    linearSearch(possible_words, "mzzzz");
    end_time = chrono::system_clock::now();

    // Record time
    auto linear_search_word2_time = chrono::duration_cast<chrono::nanoseconds>(end_time - start_time);

    // Binary search for "mzzzz"
    start_time = chrono::system_clock::now();
    binarySearch(possible_words, "mzzzz");
    end_time = chrono::system_clock::now();

    // Record time
    auto binary_search_word2_time = chrono::duration_cast<chrono::nanoseconds>(end_time - start_time);

    // Linear search for "aaaaa"
    start_time = chrono::system_clock::now();
    linearSearch(possible_words, "aaaaa");
    end_time = chrono::system_clock::now();

    // Record time
    auto linear_search_word3_time = chrono::duration_cast<chrono::nanoseconds>(end_time - start_time);

    // Binary search for "aaaaa"
    start_time = chrono::system_clock::now();
    binarySearch(possible_words, "aaaaa");
    end_time = chrono::system_clock::now();

    // Record time
    auto binary_search_word3_time = chrono::duration_cast<chrono::nanoseconds>(end_time - start_time);

    // Display times
    cout << "Linear search for 'not_here': " << linear_search_word1_time.count() << " nanoseconds" << endl;
    cout << "Binary search for 'not_here': " << binary_search_word1_time.count() << " nanoseconds" << endl;
    cout << "Linear search for 'mzzzz': " << linear_search_word2_time.count() << " nanoseconds" << endl;
    cout << "Binary search for 'mzzzz': " << binary_search_word2_time.count() << " nanoseconds" << endl;
    cout << "Linear search for 'aaaaa': " << linear_search_word3_time.count() << " nanoseconds" << endl;
    cout << "Binary search for 'aaaaa': " << binary_search_word3_time.count() << " nanoseconds" << endl;

}


// Linear search algorithm
int linearSearch(vector<string> container, string element) {

    // Iterate through every element until element is found
    for (int i = 0; i < container.size(); i++) {
        if (container[i] == element) {
            return i;
        }
        return -1; // Return if element is not found
    }
}


// Binary search algorithm
int binarySearch(vector<string> container, string element) {

    // Initialize high and low values
    int low_end = 0;
    int high_end = container.size() - 1;

    // When there are still elements in the vector constantly cut vector in half
    while (low_end <= high_end) {
        int mid = (low_end + high_end) / 2;

        if (container[mid] == element) {
            return mid;
        }
        else if (container[mid] < element) {
            low_end = mid + 1;
        }
        else {
            high_end = mid - 1;
        }

    }
    return -1; // Return if element is found
}