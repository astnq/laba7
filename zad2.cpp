#include <iostream>
#include <string>
using namespace std;

// Рекурсивная функция для декодирования закодированной строки
string decodeString(const string& s, size_t& idx) {
    string result = "";
    int count = 0;

    while (idx < s.size()) {
        if (isdigit(s[idx])) {
            count = count * 10 + s[idx] - '0';
        } else if (s[idx] == '[') {
            // Рекурсивный вызов для декодирования подстроки внутри квадратных скобок
            string decodedString = decodeString(s, ++idx);
            // Добавляем к результату количество раз декодированной подстроки
            for (int i = 0; i < count; ++i) {
                result += decodedString;
            }
            count = 0;
        } else if (s[idx] == ']') {
            return result; // Возвращаем результат, когда встречается ']'
        } else {
            result += s[idx]; // Добавляем символы к результату
        }
        ++idx;
    }

    return result; // Возвращаем окончательную декодированную строку
}

// Функция для декодирования закодированной строки посредством вызова вспомогательной функции
string decodeString(const string& s) {
    size_t idx = 0;
    return decodeString(s, idx);
}

int main() {
    system ("chcp 65001");
    setlocale (LC_ALL, "rus");
    string encodedString; // Закодированная строка для декодирования
    cout << "Encode string: " << encodedString;
    cin >> encodedString; // Ввод строки
    string decodedString = decodeString(encodedString); // Декодируем строку
    
    cout << "Decode string: " << decodedString << endl;

    return 0;
}
