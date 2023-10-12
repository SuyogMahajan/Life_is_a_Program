#include<iostream>
#include<string>
#include<vector>
#include<unordered_set>
using namespace std;

void solveA() {

     int n,m;
    cin >> n >> m;
    string a,b;
    cin >> a >> b;
    

    if(a == b) {
        cout << "0" << endl;
        return;
    }

    int ans = 0;
    string t = a;

    while(n < m) {
        a += a;
        n += n;
        ans++;
    } 

    if(a.find(b) != string::npos) {
        cout << ans << endl;
        return;
    }
    a+=a;
    if(a.find(b) != string::npos) {
        cout << ans +1 << endl;
        return;
    }

    cout <<"-1" << endl;
}

bool canCut(int v[],int len) {
    int cuts = 0;
    for(int i = 0; i< 3;i++) {
        
        if(v[i]%len) {
            return false;
        }

        cuts += (v[i]/len)-1;

    }
    return cuts <= 3;
}

void solveB() {

int num[3];

for(int i = 0; i < 3;i++) {
    cin >> num[i];
}

int min_ele = num[0];
for(int i = 0; i <3;i++) min_ele = min(min_ele,num[i]);

bool a = canCut(num,min_ele);
bool c = false;

if(min_ele%2 == 0) {
    c = canCut(num,int(min_ele/2));
}

if(a || c) cout << "YES" << endl;
else
cout <<"NO"<< endl;

}

void solveC() {
    int n;
    cin >> n;

    vector<string> mat;

    for(int i= 0; i <n ;i++) {
        string x;
        cin >> x;
        mat.push_back(x);
    }

//     0 1 2 3
//   0 a b b a
//   1 b a a b
//   2 b a c b
//   3 a b c a
    int ans = 0;
    for(int i = 0; i < n;i++) {
        for(int j = i; j < (n-i-1);j++) {
            char a = mat[i][j];
            char b = mat[j][n-i-1];
            char c = mat[n-i-1][n-j-1];
            char d = mat[n-j-1][i];

            char maxc = max(a,max(b,max(c,d)));
            ans += maxc *4 -(a+b+c+d); 
        }
    }
    cout << ans << endl;

}

int main() {
int t;
cin >> t;

while(t--) {
   
    solveC();
}

return 0;
}
// 