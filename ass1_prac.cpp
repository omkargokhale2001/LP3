#include <iostream>
using namespace std;

int generate_fibo_iter(int n)
{
    int a = 0;
    int b = 1;
    int N = n - 2;
    int i = 0;
    for (i = 0; i < N; i++)
    {
        int temp = a + b;
        a = b;
        b = temp;
    }
    return b;
}

int fibo_recur(int n)
{
    if (n == 1 || n == 0)
    {
        return n;
    }
    else
    {
        return fibo_recur(n - 1) + fibo_recur(n - 2);
    }
}

int main()
{
    int n;
    cout << "Enter the number term to be displayed:" << endl;
    cin >> n;
    int solution = generate_fibo_iter(n);
    cout << "The term is:" << solution << endl;
    int rec = fibo_recur(n - 1);
    cout << "Recursive ans is:" << rec << endl;
    return 0;
}