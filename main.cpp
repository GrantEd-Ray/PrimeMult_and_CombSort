#include <iostream>
#include <vector>
#include <cmath>

std::vector<int> func(int x)
{
    int K_max, L_max, M_max;
    K_max = static_cast<int>(ceil(log(x) / log(3)));
    L_max = static_cast<int>(ceil(log(x) / log(5)));
    M_max = static_cast<int>(ceil(log(x) / log(7)));

    std::vector<int> storage;
    int temp;

    for (int k = 0; k < K_max; k++)
        for (int l = 0; l < L_max; l++)
            for (int m = 0; m < M_max; m++)
            {
                temp = pow(3, k) * pow(5, l) * pow(7, m);
                if (temp <= x)
                    storage.push_back(temp);
                else
                    break;
            }
    return storage;
}

void comb_sort(std::vector<int>& storage)
{
    double factor = 1.2473309;
    int step = storage.size() - 1;

    while (step >= 1)
    {
        for (int i = 0; i + step < storage.size(); i++)
        {
            if (storage[i] > storage[i + step])
            {
                std::swap(storage[i], storage[i + step]);
            }
        }
        step /= factor;
    }
}

int main() {
    std::vector<int> v1;
    v1 = func(1000);
    comb_sort(v1);
    for (int i = 0; i < v1.size(); i++)
        std::cout << v1[i] << " ";
    return 0;
}
