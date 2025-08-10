//check two strings are anagram of each other
//hello and lohe are not anagrams

// //By using sort function
// #include<bits/stdc++.h>
// using namespace std;
// int main(){
//     string s1, s2;
//     cout<<"Enter the strings: ";
//     cin >> s1 >> s2;
//     sort(s1.begin(),s1.end());
//     sort(s2.begin(),s2.end());
//     if(s1==s2){
//         cout << "Strings are anagram!!";
//     }
//     else{
//         cout << "Strings are not anagram!!";
//     }
// }

// //By using two separte maps for two strings
// #include<bits/stdc++.h>
// using namespace std;
// int main(){
//     string s1, s2;
//     unordered_map<char,int> m1;
//     unordered_map<char,int> m2;
//     cout<<"Enter the strings: ";
//     cin >> s1 >> s2;
//     for(auto ch:s1){
//         m1[ch]++;
//     }
//     for(auto ch:s2){
//         m2[ch]++;
//     }
//     if(m1==m2){
//         cout << "Strings are anagram!!";
//     }
//     else{
//         cout << "Strings are not anagram!!";
//     }
// }


// //By using using single map
// //first make freq map of all the characters of one string
// //Then iterate through second string and as you find the character in the map
// //decrease its freq by 1 and if you not find then strings are not anagrams and exit the program
// //Then Traverse through your map and if any freq is not zero then strings are not anagrams and exit the program
// #include<bits/stdc++.h>
// using namespace std;
// int main(){
//     string s1, s2;
//     cout<<"Enter the strings: ";
//     unordered_map<char, int> m;
//     cin >> s1 >> s2;
//     for(auto ch: s1){
//         m[ch]++;
//     }
//     for(auto ch: s2){
//         if(m.find(ch)!=m.end()){
//             m[ch]--;
//         }
//         else{
//             cout << "Strings are not anagrams!!";
//             exit(0);
//         }
//     }
//     for(auto pair: m){
//         if(pair.second!=0){
//             cout << "Strings are not anagrams!!";
//             exit(0);
//         }
//     }
//     cout << "Strings are anagrams!!";
//     //TC-O(m+n) where m and n are lengths of s1 and s2 respectively
//     //SC-O(m)
// }


