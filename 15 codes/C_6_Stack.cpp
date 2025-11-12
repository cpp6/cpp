/*
C-6
In any language program mostly syntax error occurs due to unbalancing delimiter such as (), {}, 
Write a program using stack to check whether a given expression is well parenthesized or not.
*/

#include<iostream>
using namespace std;
class stack
{
    char exp[20],s[20],s1[20];
     int top, max;
public:
  stack()
    {
    top = -1;
    max = 20;
    }
char gettop();
bool isfull();
void expr();
bool isempty();
void push(char);
char pop();
void check(stack);
};

bool stack::isempty()
{
    if (top == -1)
    return 1;
    else
    return 0;
}
bool stack::isfull()
{
     if (top == max-1)
        return 1;
    else
       return 0;
}
char stack::gettop()
{
    if (!isempty())
        return s[top];
    return '\0';
}
void stack::push(char ex)
{
if (isfull())
    cout << "stack overflow";
    else
    {
    s[++top] = ex;
        }
}
char stack::pop()
{

    if (isempty()) {
        cout << "stack under flow";
        return '\0';
    } else
        return s[top--];
}
void stack::expr()
{
    cout << "Enter the Expression: =>";
    cin >> exp;
    cout << exp<<"\n";
}

void stack::check(stack st)
{
    char ex, ch;
    stack e;
    bool flag = true;

    for (int i = 0; st.exp[i] != '\0'; ++i)
    {
        ex = st.exp[i];
        if (ex == '(' || ex == '{' || ex == '[')
        {
            e.push(ex);
        }
        else if (ex == ')' || ex == '}' || ex == ']')
        {
            if (e.isempty())
            {
                flag = false;
                break;
            }
            ch = e.gettop();
            if ((ex == ')' && ch == '(') ||
                (ex == ']' && ch == '[') ||
                (ex == '}' && ch == '{'))
            {
                e.pop();
            }
            else
            {
                flag = false;
                break;
            }
        }
    }

    if (flag && e.isempty())
        cout << "Equation is well balanced/parenthesized\n";
    else
        cout << "Equation is not well balanced/parenthesized\n";
}

int main()
{
    stack s;
    s.expr();
    s.check(s);
    return 0;

}

/*
Algo:
Start
Create a class stack with:
Array s for stack elements
Array exp for expression
top to track the top index
Initialize stack (top = -1).
Input Expression from user using expr().
For each character in the expression:
If it is an opening bracket (, {, [, → push() it on the stack.
If it is a closing bracket ), }, ] →
If stack is empty → expression is unbalanced.
Else, check top element:
If it matches the correct opening bracket → pop() it.
Else → expression is unbalanced.
After the loop:
If stack is empty → expression is well parenthesized.
Else → not well parenthesized.
Stop
*/
