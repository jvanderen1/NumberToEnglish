/*******************************************************************************************************************************************
 * Joshua Van Deren
 * General Programming
 * Program NumberToEnglish
 *
 * Program to translate any integer into an English word.
 */

/******************* #include DIRECTIVES **************************************************************************************************/
#include <cmath>
#include <iostream>

using namespace std;

/******************* Constants ************************************************************************************************************/
const string ONES_AND_TEENS_DIGIT []   { "", "one ", "two ", "three ", "four ", "five ", "six ", "seven ", "eight ", "nine ", "ten ", \
                                         "eleven ", "twelve ", "thirteen ", "fourteen ", "fifteen ", "sixteen ", "seventeen ", \
                                         "eighteen ", "nineteen " };

const string TENS_DIGIT []             { "", "", "twenty ", "thirty ", "forty ", "fifty ", "sixty ", "seventy ", "eighty ", "ninety "};

const string ORDER []                  { "", "thousand ", "million ", "billion ", "trillion "};

/******************* function Prototypes **************************************************************************************************/
string translateNumber(int number);

/******************************************************************************************************************************************/
int main(void) {
    long userInteger;
    double digitTester;
    unsigned short digits = 0, iterations;
    string printout = "";

    cout << "What integer would you like translated?: ";
    cin >> userInteger;

    if (userInteger == 0) {
        cout << "0 -> zero " << endl;
        return 0;
    }

    else if (userInteger < 0) {
        printout = "negative ";
        userInteger *= -1;
    }

    digitTester = userInteger;

    while (digitTester >= 1) {
        digitTester = digitTester / 10;
        digits++;
    }

    cout << userInteger << " -> ";
    iterations = (unsigned short)ceil((float)digits / 3);

    while (iterations > 0) {

        if (userInteger != 0)
            printout += translateNumber((int) (userInteger / (long) pow(10, 3 * (iterations - 1) ) )) + ORDER[iterations - 1];

        userInteger -= (userInteger / (long) pow(10, 3 * (iterations - 1)) * (long) pow(10, 3 * (iterations - 1) ));
        iterations--;
    }

    cout << printout << endl;

    return 0;
}

string translateNumber(int number) {
/*** Function used to translate each group of numbers into their proper English translation. **********************************************/

    string translation = "";

    if (number >= 100) {
        translation = ONES_AND_TEENS_DIGIT[number / 100];

        if ((number / 100) != 0)
            translation += "hundred ";

        number -= (number / 100) * 100;
    }

    if (number >= 20) {
        translation += TENS_DIGIT[number / 10];
        number -= (number / 10) * 10;
    }

    else if (number >= 10) {
        translation += ONES_AND_TEENS_DIGIT[number];
        number = 0;
    }

    if (number >= 1)
        translation += ONES_AND_TEENS_DIGIT[number];

    return translation;
}
