#include <iostream>
#include <string>
using namespace std;

int findans(char c, string s) {
    int pos;
    int len = s.length();
    for(int i = 0; i < len; i++) 
        if(s[i] == c) {
            pos = i;
            break;
        }
    int ans = 0;
    for(int i = pos; i >= 0; i = i - 4) 
        if(s[i] != c && s[i] == '!') ans++;
    for(int i = pos; i < len; i = i + 4)
        if(s[i] != c && s[i] == '!') ans++;
    return ans;
}

int main() {
    string s;
    cin >> s;
    int r = findans('R', s);
    int b = findans('B', s);
    int y = findans('Y', s);
    int g = findans('G', s);
    cout << r << " " << b << " " << y << " " << g << endl;
    return 0;
}
