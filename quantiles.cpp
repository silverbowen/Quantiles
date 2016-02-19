/*

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

*/

#include <cmath>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int quantile{0},
        pairs{0},
        count{0},
        index{0},
        value{0};

    double indexCeil{0};

    cin >> quantile >> pairs;

    vector<int> intVector;

    for (int i = 0; i < pairs; ++i)
    {
        cin >> value >> count;
        for (int i = 0; i < count; ++i)
            intVector.push_back(value);
    }

    sort(intVector.begin(), intVector.end());

    for (int i = 1; i < quantile; ++i)
    {
        index = (intVector.size() * i / quantile) - 1;
        indexCeil = (ceil(intVector.size() * (double)i / quantile)) - 1;

        (index == indexCeil) ?
            cout << ((intVector[index] + intVector[index + 1]) / 2)
                 << "\n" :
            cout <<  intVector[indexCeil] << "\n";
    }

    return 0;
}
