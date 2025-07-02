//https://codeforces.com/problemset/problem/1931/E

#include <bits/stdc++.h>
using namespace std;

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t--) {
        int n, m;
        cin >> n >> m;// n = number of integers , m = sasha win if final number > = 10^n

        vector<int> trailing_zeros(n);//store trailing zeros for each number
        int total_digits = 0;

        for (int i = 0; i < n;++i) {
            string s;
            cin >> s; //read number as string


            total_digits += s.size();//count total digit

            int tz = 0;
            for (int j = s.size() - 1; j >= 0 && s[j] == '0'; --j){
                ++tz;
            }
            trailing_zeros[i] = tz;
        }
        sort(trailing_zeros.begin(), trailing_zeros.end(), greater<int>());

// Anna plays first, and then every second turn (i = 0, 2, 4, ...)
        for (int i = 0; i < n; i+=2 ){
            total_digits -= trailing_zeros[i];

            //4 (5000) + 2 (30) + 3 (123) + 2 (40) = 11

            //11 - (3 + 1) = 7 digits left
            //Then you check if 7 > m → Sasha wins
            //Else → Anna wins

        }
        cout << (total_digits > m ? "Sasha\n" : "Anna\n");
    }
    return 0;
}

            //input
            //4 5
            //5000 123 30 4
            /*
            Count Trailing Zeros (tz)
For "5000":
sql
Copy
Edit
Index:        0    1    2    3
Character:   '5'  '0'  '0'  '0'
                       ↑
Start checking from the **end**:
- '0' → tz = 1
- '0' → tz = 2
- '0' → tz = 3
- '5' → stop

Result: tz = 3 ✅
For "30":
'0' → tz = 1

'3' → stop

Result: tz = 1 ✅

For "123":
'3' → stop immediately

Result: tz = 0 ✅

For "40":
'0' → tz = 1

'4' → stop

Result: tz = 1 ✅

trailing_zeros = [3, 1, 0, 1]
trailing_zeros → sort descending → [3, 1, 1, 0]

4 (5000) + 2 (30) + 3 (123) + 2 (40) = 11
11 - (3 + 1) = 7 digits left
            */