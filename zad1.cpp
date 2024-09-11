#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool Skobki(const string& str, int pos = 0, int opened = 0) {
    if (pos == str.size()) {
        return opened == 0;  // Проверяем, что все скобки были закрыты
    }

    if (str[pos] == '(') {
        return Skobki(str, pos + 1, opened + 1);
    } else if (str[pos] == ')') {
        if (opened > 0) {
            return Skobki(str, pos + 1, opened - 1);
        } else {
            return false;  // Найдена лишняя закрывающая скобка
        }
    } else {
        return Skobki(str, pos + 1, opened);  // Пропускаем символы, отличные от скобок
    }
}

int main() {
    setlocale (LC_ALL, "rus");
    system ("chcp 65001");
    string input;
    cout << "Введите строку со скобками: ";
    cin >> input;

    if (Skobki(input)) {
        cout << "Скобки расставлены правильно." << endl;
    } else {
        cout << "Скобки расставлены неправильно." << endl;
    }

    return 0;
}
