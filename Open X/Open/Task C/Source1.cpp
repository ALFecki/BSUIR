#include <iostream> 
#include <cmath> 

using namespace std;



int main()
{
    long long a = 1, t, n, k = 1, d = 0, ch = 1;
    cin >> t;
    for (long long i0 = 0; i0 < t; i0++) {
        cin >> n;
        for (long long i = n; i > 0; i /= 10) { // count of numbers
            d++;
        }
        for (long long i = d; i > 0; i--) {
            if ((long long)(n / pow(10, i - 1)) == 9)
            {
                k += pow(5, i - 1) * 4;
            }
            else if ((long long)(n / pow(10, i - 1)) == 7) 
            {
                k += pow(5, i - 1) * 3;
            }
            else if ((long long)(n / pow(10, i - 1)) == 6) 
            {
                k += pow(5, i - 1) * 2;
            }
            else if ((long long)(n / pow(10, i - 1)) == 4)  
            {
                k += pow(5, i - 1) * 1;
            }
            else if ((long long)(n / pow(10, i - 1)) == 8) 
            {
                k += pow(5, i - 1) * 4 - 1;
                i = 0;
            }
            else if ((long long)(n / pow(10, i - 1)) == 5) 
            {
                k += pow(5, i - 1) * 2 - 1;
                i = 0;
            }
            else if ((long long)(n / pow(10, i - 1)) == 0)
            {
                ch = 0;
            }
            else 
            {
                k += pow(5, i - 1) - 1;
                i = 0;
            }
            if (ch) 
            {
                for (long long i1 = 1; i1 < i; i1++) {
                    a *= 10;
                }
                n = n % a;
            }
            ch = 1;
            a = 1;
        }
        cout << k << " ";

        k = 1;
        d = 0;
    }
    return 0;

}