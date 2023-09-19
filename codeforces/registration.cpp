#include <iostream>
#include <math.h>
#include <set>

using namespace std;

multiset<long long> database;

long long hsh(string word) {
    long long hsh = 0;
    for (int i = 1; i <= word.size(); i++) {
        hsh += (word.c_str()[i] - 'A') * i * pow(-1, i);
    }
    return hsh;
}

int n;

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        string word; 
        cin >> word;
        long long num = hsh(word);
        if (database.find(num) == database.end()) {
            database.insert(num);
            cout << "OK" << endl;
            continue;
        }

        string replacement = word + (char)(database.count(num)+48);
        int j = 0;

        while (database.find(hsh(replacement)) != database.end()) {
            ++j;
            replacement = word + (char)(database.count(num)+j + 48);
        }

        cout << replacement << endl;
        database.insert(num);
        database.insert(hsh(replacement));
    }
}
