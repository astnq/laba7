
#include <iostream>
#include <vector>

    using namespace std;

    bool canFit(vector<int>&containers, vector<int>&items, int containerIndex) {
        if (containerIndex == containers.size()) {
            return true; // Все контейнеры обработаны успешно
        }

        for (int i = 0; i < items.size(); ++i) {
            if (items[i] <= containers[containerIndex]) {
                int itemHeight = items[i];
                containers[containerIndex] -= itemHeight;
                if (canFit(containers, items, containerIndex + 1)) {
                    return true;
                }
                containers[containerIndex] += itemHeight; // Откат изменений
            }
        }

        return false;
    }

    int main() {
        setlocale(LC_ALL, "Rus");
        int N;
        cout << "Введите количество контейнеров: ";
        cin >> N;

        vector<int> containers(N);
        cout << "Введите высоту каждого контейнера:\n";
        for (int i = 0; i < N; ++i) {
            cin >> containers[i];
        }

        int M;
        cout << "Введите количество предметов: ";
        cin >> M;

        vector<int> items(M);
        cout << "Введите высоту каждого предмета:\n";
        for (int i = 0; i < M; ++i) {
            cin >> items[i];
        }

        if (canFit(containers, items, 0)) {
            cout << "Предметы можно разместить в контейнерах так\n";
        }
        else {
            cout << "Невозможно разместить предметы в контейнерах без выступа груза\n";
        }

        return 0;
    }
    
