#include <iostream>
#include <cassert>
#include <vector>
#include <set>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <math.h>
#include <map>
#define ll long long
#define MODD 1000000007ll
using namespace std;
 
int a[111111];
bool done[111111];
 
int minprime[111111];
 
int main() {
    
    for(int i=2;i<111111;i++)
        minprime[i]=-1;
    for(int i=2;i<111111;i++) {
        if(minprime[i]==-1) {
            for(int j=i;j<111111/i;j++) {
                minprime[i*j]=i;
            }
            minprime[i]=i;
        }
    }
    return 0;
}
  
