#include <bits/stdc++.h>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
bool myfunction (string i,string j)
{
    int n=i.length();
    int m=j.length();
    if(n==m)
        return (i<j);

    return n<m;
}
int main() {
	int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<string> unsorted(n);

    for (int i = 0; i < n; i++) {
        string unsorted_item;
        getline(cin, unsorted_item);

        unsorted[i] = unsorted_item;
    }
    sort(unsorted.begin(),unsorted.end(),myfunction);
    for (int i = 0; i < unsorted.size(); i++) {
        cout<<unsorted[i];
         cout << "\n";
        }
	return 0;
}
