
#include<bits/stdc++.h>
using namespace std;
void iterative_mean(float& average, const float num, const int index)
{
    float index_1 = static_cast<float>(index + 1);
    average = average * static_cast<float>(index) / index_1 + num / index_1;
}

int main()
{
    float a[10] = {0};
    const int count = 10;
    for (int i = 0; i < count; ++i)
    {
        a[i] = i+1;
        std::cout << a[i] << " ";
    }
    std::cout << std::endl;
    float iter_mean = 0;
    float acc_mean = 0;
    for (int i = 0; i < count; ++i)
    {
        // 迭代求平均值
        iterative_mean(iter_mean, a[i], i);

        // 累加
        acc_mean += a[i];
    }
    // 累加计算平均值
    acc_mean /= count;
    std::cout << "accumulative mean: " << acc_mean << std::endl;
    std::cout << "iterative mean: " << iter_mean << std::endl;
    return 0;
}
