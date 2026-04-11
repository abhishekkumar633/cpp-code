#include<iostream>
using namespace std;

// Function to convert an integer to a Roman numeral
string integer_to_roman(int num) {
    // Define the integer values and corresponding Roman numeral symbols
    int values[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    string symbols[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
    
    string result = "";
    
    // Iterate over the values and build the Roman numeral string
    for (int i = 0; i < 13; i++) {
        while (num >= values[i]) {
            num -= values[i];
            result += symbols[i];
        }
    }
    
    return result;
}

int main() {
    int num;
    cout << "Enter an integer: ";
    cin >> num;
    
    // Convert integer to Roman numeral and display the result
    cout << "Roman numeral: " << integer_to_roman(num) << endl;

    return 0;
}
