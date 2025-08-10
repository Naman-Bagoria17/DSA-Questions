// #include<bits/stdc++.h>
// using namespace std;
// int fib(int n){
//     if(n==0||n==1)
//         return n;
//     return fib(n - 1) + fib(n - 2);
// }
// int main(){
//     cout << fib(3);
//     return 0;
// }

// #include<bits/stdc++.h>
// using namespace std;
// int  max_ele(int arr[],int n, int idx,int &max){
//     if(idx==n-1){
//         max = arr[idx];
//         return max;
//     }
//     if(arr[idx]>max_ele(arr,n,idx+1,max)){
//         max = arr[idx];
//     }
//     return max;
// }
// int main(){
//     int arr[] = {3, 10, 3, 2, 5};
//     int max = INT_MIN;
//     max_ele(arr, 5, 0,max);
//     cout << max;
// }

// //remove all occurrences of 'a' from a string "abcax"
// #include<bits/stdc++.h>
// using namespace std;
// string remove_a(string s,int idx){
//     if(idx==s.size()){
//         return "";
//     }
//     if(s[idx]=='a')
//         return remove_a(s, idx + 1);
//     else
//         return s[idx] + remove_a(s, idx + 1);
// }
// int main(){
//     string s = "abcax";
//     cout << remove_a(s, 0);
// }

// //pw recursion sheet question 1

// //n,n-5,n-10,......0,......n-10,n-5,n
// #include<bits/stdc++.h>
// using namespace std;
// void pattern(int n){
//     if(n<=0){
//         cout << n<<" ";
//         return;
//     }
//     cout << n<<" ";
//     pattern(n - 5);
//     cout << n<<" ";
// }
// int  main(){
//     int n = 16;
//     pattern(n);
// }

// //question 2
// #include<bits/stdc++.h>
// using namespace std;
// int summation(int n,int m){
//     if(m==1){
//         return n * (n + 1) / 2;
//     }
//     return summation(summation(n, m - 1), 1);
// }
// int main(){
//     cout << summation(4, 1);
// }

// //1 to n
// #include<bits/stdc++.h>
// using namespace std;
// void print(int n){
//     if(n==1){
//         cout <<1<<" ";
//         return;
//     }
//     print(n - 1);
//     cout << n<<" ";
// }
// int main(){
//     print(4);
//     return 0;
// }

// //first k multiples of n
// #include<bits/stdc++.h>
// using namespace std;
// void f(int n,int k){
//     if(k<1)
//         return;
//     f(n, k - 1);
//     cout << n * k<<" ";
// }
// int main(){
//     f(12, 5);
// }

// //sum with alternativ sign
// #include<bits/stdc++.h>
// using namespace std;
// int f(int n){
//     if(n==1)
//         return 1;
//     if(n%2!=0)
//         return f(n-1)+n;
//     else
//         return f(n-1)-n;
// }
// int main(){
//     cout<<f(10);
//     return 0;
// }

// //gcd
// #include<bits/stdc++.h>
// using namespace std;
// void gcd(int a,int b){
//     if(0==b)
//         cout<< a;
//     if(a>b){
//         gcd(b, a % b);
//     }
//     else{
//         gcd(a, b % a);
//     }
// }
// int main(){
//     gcd(54, 72);
// }

// //frog jump
// #include<bits/stdc++.h>
// using namespace std;
// float mincost(vector<float> height,int n,int i){
//     if(i==n-1){
//         return 0;
//     }
//     if(i==n-2){
//         return abs(height[i] - height[i + 1]);
//     }
//     return min((abs(height[i] - height[i + 1]) + mincost(height, n, i + 1)), abs(height[i] - height[i + 2]) + mincost(height, n, i + 2));
// }
// int main(){
//     vector<float> heights = {10, 30, 40, 20};
//     float min_cost = mincost(heights, 4, 0);
//     cout << min_cost;
// }

// //check element exists in array or not
// #include<bits/stdc++.h>
// using namespace std;
// bool ifExists(vector<int> arr,int x,int idx){
//     if(idx==arr.size()){
//         return false;
//     }
//     return (x==arr[idx] || ifExists(arr, x, idx + 1));
// }
// int main(){
//     vector<int> arr = {10, 40, 50, 20, 30, 40};
//     bool result = ifExists(arr,50, 0);
//     cout << result;
// }

// // possible paths from top left to bottom right of grid
// #include <bits/stdc++.h>
// using namespace std;
// int possible_paths(int m, int n, int i, int j)
// {
//     if (i == m - 1 || j == n - 1)
//     {
//         return 1;
//     }
//     return possible_paths(m, n, i + 1, j) + possible_paths(m, n, i, j + 1);
// }
// int main()
// {
//     cout<<possible_paths(2, 3, 0, 0)<<endl;
//     return 0;
// }

// //subsequences of a string
// #include<bits/stdc++.h>
// using namespace std;
// void subsequences(string s,int i,string p,vector<string> &ans){
//     if(i==s.size()){
//         ans.push_back(p);
//         return;
//     }
//     subsequences(s, i + 1, p + s[i], ans);
//     subsequences(s, i + 1, p, ans);
// }
// int main(){
//     vector<string> ans;
//     subsequences("abcd", 0, "", ans);
//     for (int i = 0; i < ans.size();i++){
//         cout << ans[i] << " ";
//     }
//     cout << ans.size() << endl;
//  }

//old keypad phone(letter combinations number could represent)
#include<bits/stdc++.h>
using namespace std;
void letter_comb(const string &s,string p,int idx,vector<string> &letters,vector<string> &ans){
//letters aur s ko by reference isloye paas kiya hai qki mai unnecessary copies ni banana chahta alag alag kagah pe
    if(idx==s.size()){
        ans.push_back(p);
        return;
    }
    //convert your digit to int form
    int digit = s[idx] - '0'; // example->if s[0] is '2' then '2'-'0'=50-48 i.e 2 only
    if(digit<=1){
        letter_comb(s, p, idx + 1, letters, ans);
        return;
    }
    for (int i = 0; i < letters[digit].size();i++){
        letter_comb(s, p + letters[digit][i], idx + 1, letters, ans);
    }
}
int main(){
    vector<string> letters = {"","","abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    vector<string> ans;
    letter_comb("23", "", 0, letters, ans);//yaha pe mai string literal paas kr raha hu by regerence to uper definition me const zaroor likhna padega
    for (int i = 0; i < ans.size();i++){
        cout << ans[i] << " ";
    }
    return 0;
}

// //check a number is a palindrome
// #include<bits/stdc++.h>
// using namespace std;
// bool isPalindrome(int n,int& p){
//     if(n>0 and n<10){
//         int lastDigitofp = p % 10;
//         p/= 10;
//         return n == lastDigitofp;
//     }
//     bool res = isPalindrome(n / 10, p) and n % 10 == p % 10;
//     p /= 10;
//     return res;
// }
// int main(){
//     int n;
//     cin >> n;
//     cout << isPalindrome(n, n) << endl;
// }
