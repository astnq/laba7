#include <iostream>
#include <string>
using namespace std;

string decodeString(const string& s, size_t& i) {
    string res = "";

    while (i < s.length() && s[i] != ']') {
        if (!isdigit(s[i])) {
            res += s[i];
            i++;
        }
        else {
            int k = 0;
            while (i < s.length() && isdigit(s[i])) {
                k = k * 10 + (s[i] - '0');
                i++;
            }

            i++; // Пропускаем '['
            string decodedStr = decodeString(s, i);
            i++; // Пропускаем ']'

            for (int j = 0; j < k; j++) {
                res += decodedStr;
            }
        }
    }

    return res;
}

string decodeString(const string& s) {
    size_t i = 0;
    return decodeString(s, i);
}

int main() {
    setlocale(LC_ALL, "Rus");
    cout << "Введите: " << endl;
    string s;
    cin >> s;
    cout << "Вывод: " << decodeString(s) << endl;

    return 0;
}
