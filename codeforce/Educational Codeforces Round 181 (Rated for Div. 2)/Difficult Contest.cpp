#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Check if "FFT" or "NTT" exists
bool is_difficult(const string& s) {
    for (int i = 0; i + 2 < (int)s.size(); ++i) {
        if (s[i] == 'F' && s[i + 1] == 'F' && s[i + 2] == 'T') return true;
        if (s[i] == 'N' && s[i + 1] == 'T' && s[i + 2] == 'T') return true;
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;

        // If already safe, print it
        if (!is_difficult(s)) {
            cout << s << '\n';
            continue;
        }

        // Frequency array
        vector<int> freq(26, 0);
        for (char c : s)
            freq[c - 'A']++;

        string result;

        // Add all safe characters (not F, N, T) first
        for (int i = 0; i < 26; ++i) {
            if (i + 'A' == 'F' || i + 'A' == 'N' || i + 'A' == 'T') continue;
            result.append(freq[i], i + 'A');
        }

        // Then add F, N, T in an order that avoids "FFT" or "NTT"
        // Safest order: T, F, N (avoids both patterns)
        result.append(freq['T' - 'A'], 'T');
        result.append(freq['F' - 'A'], 'F');
        result.append(freq['N' - 'A'], 'N');

        cout << result << '\n';
    }

    return 0;
}
