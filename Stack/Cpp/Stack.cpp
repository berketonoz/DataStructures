#include <iostream>
#include <string>
#include <vector>
#include "Stack.h"

using namespace std;

int main(){
    Stack<string> stack = Stack<string>();
    vector<string> sampleVec = {"This","is","a","sample","vector"};
    cout << stack.isEmpty() << endl;
    for (int i = 0; i < sampleVec.size(); i++)
    {
        cout << "Push: " << sampleVec[i] << endl;
        stack.push(sampleVec[i]);
    }
    while (!stack.isEmpty())
    {
        cout << stack.pop() << endl;
    }
    
    return 0;
}