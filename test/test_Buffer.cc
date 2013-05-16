

#include <iostream>
#include "Buffer.h"

using namespace std;

int main (int argc, char** argv)
{

    Buffer buf;

    int variable_int_1 = 100;
    char variable_char_1 = 'Z';
    short variable_short_1 = 500;

    long variable_long_1 = 1000;
    long long variable_ll_1 = 2000L;

    buf << variable_int_1;
    buf << variable_char_1;
    buf << variable_short_1;
    buf << variable_long_1;
    buf << variable_ll_1;

    int variable_int_2;
    char variable_char_2;
    short variable_short_2;

    long variable_long_2;
    long long variable_ll_2;

    buf >> variable_int_2;
    buf >> variable_char_2;
    buf >> variable_short_2;

    buf >> variable_long_2;
    buf >> variable_ll_2;

    cout << "variable_int_2 = " << variable_int_2 << endl;
    cout << "variable_char_2 = " << variable_char_2 << endl;
    cout << "variable_short_2 = " << variable_short_2 << endl;
    cout << "variable_long_2 = " << variable_long_2 << endl;
    cout << "variable_ll_2 = " << variable_ll_2 << endl;

    return (0);
}
