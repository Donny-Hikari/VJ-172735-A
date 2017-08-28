#include <iostream>
#include <string>
#include <set>
#include <fstream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

const int MAXS = 500;
int D[3][MAXS];
int DD[MAXS * MAXS];

int main()
{
    ifstream cin("IN.txt");
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T = 0;
    int L, N, M, S, X;
    while (cin >> L >> N >> M)
    {
        for (int i = 0; i < L; ++i)
            cin >> D[0][i];
        for (int i = 0; i < N; ++i)
            cin >> D[1][i];
        for (int i = 0; i < M; ++i)
            cin >> D[2][i];
        int LN = L * N;
        for (int i = 0; i < L; ++i)
            for (int j = 0; j < N; ++j)
            {
                DD[i * N + j] = D[0][i] + D[1][j];
            }
        sort(DD, DD + LN);
        cout << "Case " << ++T << ":" << endl;
        cin >> S;
        while (S--)
        {
            cin >> X;
            bool bS = false;
            for (int i = 0; i < M; ++i)
            {
                int sup = X-D[2][i];
                if (upper_bound(DD, DD + LN, sup) - lower_bound(DD, DD + LN, sup) > 0)
                {
                    bS = true;
                    break;
                }
            }
            cout << ((bS) ? ("YES") : ("NO")) << endl;
        }
    }

    return 0;
}
