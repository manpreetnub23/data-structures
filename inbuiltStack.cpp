// #include<iostream>
// #include<stack>
// using std::stack;
// int main()
// {
//     stack<int> mystack;
//     mystack.push(1);
//     mystack.push(2);
//     mystack.push(3);
//     mystack.push(4);
//     mystack.push(7);
//     mystack.push(6);
//     mystack.push(5);
//     std::cout<<mystack.top();
// }
#include<bits/stdc++.h>
void reverse()
{
    char ch;
    std::cin.get(ch);
    if(ch!='\n')
    {
        reverse();
        std::cout.put(ch);
    }
}
int main()
{
    reverse();
}