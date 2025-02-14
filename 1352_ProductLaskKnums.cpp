#include<bits/stdc++.h>
using namespace std;
class ProductOfNumbers {
    private:
        vector<long long>a;
        int size=0;
    public:
        ProductOfNumbers() {
            a.push_back(1);
            size=0;
        }
        
        void add(int num) {
            if(num==0){
                a={1};
                size=0;
                return;
            }
            a.push_back(num*a[size]);
            size++;
            return;
        }
        
        int getProduct(int k) {
            if(k>size) return 0;
            return a[size]/a[size-k];
        }
    };