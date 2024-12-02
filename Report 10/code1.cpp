#include <iostream>
#include <stack>
#include <string>

using namespace std;

struct TempVar {
    string name;
    string expression;
};

void generateThreeAddressCode(const string &postfix) {
    stack<TempVar> st;
    int tempCount = 1;

    cout << "Three-Address Code:\n";
    for (char ch : postfix) {
        if (isalpha(ch)) {
            TempVar var;
            var.name = string(1, ch);
            var.expression = var.name;
            st.push(var);
        } else if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
            if (st.size() < 2) {
                cerr << "Invalid postfix expression\n";
                return;
            }
            TempVar right = st.top();
            st.pop();
            TempVar left = st.top();
            st.pop();

            string tempName = "t" + to_string(tempCount++);
            string expr = left.name + " " + ch + " " + right.name;
            cout << tempName << " = " << expr << endl;

            TempVar result;
            result.name = tempName;
            result.expression = expr;
            st.push(result);
        } else {
            cerr << "Invalid character in expression: " << ch << endl;
            return;
        }
    }

    if (st.size() != 1) {
        cerr << "Invalid postfix expression\n";
    }
}

int main() {
    string postfix;
    cout << "Enter a postfix expression: ";
    cin >> postfix;

    generateThreeAddressCode(postfix);

    return 0;
}
