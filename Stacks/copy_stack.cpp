// #include<bits/stdc++.h>
// using namespace std;
//time complexity is O(n+n)=O(n)-> for transferring elements two times
//space complexity is O(n)->for using the temporary stack
// int main(){
//     stack<int> s1;
//     s1.push(1);
//     s1.push(2);
//     s1.push(3);
//     s1.push(4);
//     cout << "s1 top: " << s1.top() << endl;
//     stack<int> s2;
//     stack<int> temp_stack;
//     temp_stack.push(s1.top());
//     s1.pop();
//     temp_stack.push(s1.top());
//     s1.pop();
//     temp_stack.push(s1.top());
//     s1.pop();
//     temp_stack.push(s1.top());
//     s1.pop();
//     cout<< "temp stack top: " << temp_stack.top() << endl;
//     cout << "s1 new size: " << s1.size() << endl;
//     s2.push(temp_stack.top());
//     temp_stack.pop();
//     s2.push(temp_stack.top());
//     temp_stack.pop();
//     s2.push(temp_stack.top());
//     temp_stack.pop();
//     s2.push(temp_stack.top());
//     temp_stack.pop();
//     cout << "s2 top: " << s2.top() << endl;
//     cout << "temp stack new size: " << temp_stack.size() << endl;
//     cout << "s2 size: " << s2.size() << endl;
//     return 0;
// }

// //using loops
// #include<bits/stdc++.h>
// using namespace std;
// stack<int> copy_stack(stack<int> &s){
//     stack<int> temp;
//     while(not s.empty()){
//         temp.push(s.top());
//         s.pop();
//     }
//     stack<int> s_copy;
//     while(not temp.empty()){
//         s_copy.push(temp.top());
//         temp.pop();
//     }
//     return s_copy;
// }
// int main(){
//     stack<int> s;
//     s.emplace(1);
//     s.emplace(2);
//     s.emplace(3);
//     //s-> 3(top) 2 1
//     stack<int> result = copy_stack(s);
//     while(not result.empty()){
//         cout << result.top() << endl;
//         result.pop();
//     }
// }

// //using recursion
// #include<bits/stdc++.h>
// using namespace std;
// void copy_stack(stack<int> &s,stack<int> &result){
//     if(s.empty()){
//         return;
//     }
//     int curr = s.top();
//     s.pop();
//     copy_stack(s, result);
//     result.push(curr);
// }
// int main(){
//     stack<int> s;
//     s.emplace(1);
//     s.emplace(2);
//     s.emplace(3);
//     //s-> 3 2 1
//     stack<int> result;
//     copy_stack(s,result);
//     while(not result.empty()){
//         cout << result.top() << endl;
//         result.pop();
//     }
// }