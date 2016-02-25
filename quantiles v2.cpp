/*

This version uses parallel arrays for value/amount and sorts them
using a bubble sort, then assigns the sorted "compressed" values
to a "expanded" array.

This program displays the quantile values for a collection
of numbers. The input must be in the format:

Quantiles
Number of pairs
pair: value of integer, number of times integer appears in collection
[more pairs, one per line]

An input could look like this:

4
3
3 5
1 2
6 4

This would mean: divide into 4 chunks, 1 1 3 3 3 3 3 6 6 6 6

Output is size of collection * each value from 1 to N / N
If the value is a fraction, you must average the floor value
and the ceiling value - ie 1.3 - average index 1 and 2 (-1, of course)

For example above, output should be:

2
3
6
6

*/

#include <cmath>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int quantile {0},
        pairs {0},
        total {0},
        index {0};

    float indexCeil {0};

    cin >> quantile >> pairs;

    int valueArray[pairs],
        amountArray[pairs];

    for (int i = 0; i < pairs; ++i)
    {
        cin >> valueArray[i] >> amountArray[i];
        total += amountArray[i];
    }

    vector<int> intVector(total);

    total = 0;

    for (int i = 0; i < pairs; ++i)
    {
        if (amountArray[i] > amountArray[i + 1])
        {
            swap(amountArray[i], amountArray[i + 1]);
            swap(valueArray[i], valueArray[i + 1]);
            i = 0;
        }
    }

    for (int i = 0; i < pairs; ++i)
    {
        for (int j = 0; j < amountArray[i]; ++j)
            intVector[j + total] = valueArray[i];
        total += amountArray[i];
    }

    for (int i = 1; i < quantile; ++i)
    {
        index = ((total * i) / quantile) - 1;
        indexCeil = (ceil((float)(total * i) / (float)quantile)) - 1;

        (index == indexCeil) ?
        cout << ((intVector[index] + intVector[index + 1]) / 2)
             << "\n" :
             cout <<  intVector[indexCeil] << "\n";
    }

    return 0;
}
