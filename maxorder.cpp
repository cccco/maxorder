#include <iostream>
#include <vector>
#include <map>
#include <stdlib.h>

using namespace std;

int main()
{
    string strN;
    cin >> strN;

    const char *c_strN = strN.c_str();

    unsigned int k = 0;
    if (*c_strN == '+') {
        k = 1;
    }

    for (; k < strN.length(); k++) {
        if (c_strN[k] != '1' && c_strN[k] != '2' && c_strN[k] != '3' && c_strN[k] != '4' && c_strN[k] != '5' &&
            c_strN[k] != '6' && c_strN[k] != '7' && c_strN[k] != '8' && c_strN[k] != '9' && c_strN[k] != '0') {

            cout << "[error]" << endl;
            return 0;
        }
    }

    unsigned long long int N = strtoull(c_strN, NULL, 10);

    if (N < 2) {
        cout << "[error]" << endl;
        return 0;
    }

    vector<long double> order;
    long double num;

    while (order.size() < N && cin >> num) {
        order.push_back(num);
    }

    if (order.size() < N) {
        cout << "[error]" << endl;
        return 0;
    }

    map<unsigned long long int, unsigned long long int> orderMap;
    unsigned long long int L = 1, i = 0;
    orderMap.insert(pair<unsigned long long int, unsigned long long int>(i, L));

    for (unsigned long long int j = 0; j < N - 1; j++) {
        if (order[j] <= order[j + 1]) {
            L++;
        } else {
            i = j + 1;
            L = 1;
        }
        orderMap[i] = L;
    }

    L = 1;
    for (map<unsigned long long int, unsigned long long int>::iterator omi = orderMap.begin(); omi != orderMap.end(); omi++) {
        if ((*omi).second > L) {
            L = (*omi).second;
            i = (*omi).first;
        }
    }

    if (L == 1) {
        cout << 0 << endl;
    } else {
        cout << L << ' ' << ++i << endl;
    }

    return 0;
}
