#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
bool compareCol1(int *a, int *b)
{
    return *a < *b;
}
bool compareCol2(int *a, int *b)
{
    return *(a + 1) < *(b + 1);
}

int main()
{
    int n;
    while (cin >> n)
    {
        int **map_arr = new int *[n];
        // cout << n << endl;

        int tmp1, tmp2,start=0, end = 0, cnt = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> tmp1 >> tmp2;
            *(map_arr + i) = new int[2]{tmp1, tmp2};
        }

        sort(map_arr, map_arr + n, compareCol2);
        sort(map_arr, map_arr + n, compareCol1);
        // cout << "sort" << endl;
        // for (int i = 0; i < n; i++)
        // {
        //     cout << *(map_arr[i]) << " " << *(map_arr[i] + 1) << endl;
        // }
        // cout << "end" << endl;
        for (int i = 0; i < n; i++)
        {
            if (*(*(map_arr + i) + 1) > end){
                if (*(*(map_arr + i)) > end) end = *(*(map_arr + i));
                cnt += *(*(map_arr + i) + 1) - end;
                end = *(*(map_arr + i) + 1);
            }
        }
        cout << cnt << endl;
    }

    return 0;
}
