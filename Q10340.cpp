#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int LCS(const string &a,const string&b);

int main()
{
    string a,b;
    while(cin >> a >> b){
        if(a.length() == LCS(a,b)){
            cout << "Yes\n";
        }else{
            cout << "No\n";
        }

    }
    return 0;
}


int LCS(const string &a,const string&b){
    const int al=a.length();
    const int bl=b.length();
    vector<vector<int> > map(al+1,vector<int>(bl+1,0));
    for(int i=1;i<=al;++i){
        for(int j=1;j<=bl;++j){
            if(a[i - 1] == b[j - 1]){
                map[i][j] = map[i-1][j-1] +1;
            }else{
                map[i][j] = max(map[i][j-1],map[i][j-1]);
            }
        }
    }
    return map[al][bl];
}
