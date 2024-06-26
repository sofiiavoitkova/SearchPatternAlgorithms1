#ifndef GUSFIELD_H
#define GUSFIELD_H

#include <iostream>
#include <string>

void getZarr(const std::string& str, int Z[]) {
    int n = str.length();
    int L, R, k;

    L = R = 0;
    for (int i = 1; i < n; ++i) {
        if (i > R) {
            L = R = i;
            while (R < n && str[R - L] == str[R])
                R++;
            Z[i] = R - L;
            R--;
        } else {
            k = i - L;

            if (Z[k] < R - i + 1) {
                Z[i] = Z[k];
            } else {
                L = i;
                while (R < n && str[R - L] == str[R])
                    R++;
                Z[i] = R - L;
                R--;
            }
        }
    }
}

void gusfieldAlg(const std::string& T, const std::string& P) {
    unsigned int n = T.length();
    unsigned int m = P.length();
    std::string concat = P + "#" + T;

    if (n > m) return;

    int l = concat.length();

    int* Z = new int[l];
    getZarr(concat, Z);
    int count = 0;

    for (int i = 0; i < l; ++i) {
        if (Z[i] == P.length())
            count++;
    }

    delete[] Z;
}

#endif // GUSFIELD_H
