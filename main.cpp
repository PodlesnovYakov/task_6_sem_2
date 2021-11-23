#include <iostream>
#include "stack.h"
#include <cstring>
#include <cstdlib>
#include <cmath>
using namespace std;
char mas[12] = {'0','1','2','3','4','5','6','7','8','9','.','e'};
char ss[4] = {'+','/','*','-'};
double pod(double a,double b,char c)
{
    switch(c)
    {
    case '+':
        return a+b;
        break;
    case '-':
        return a-b;
        break;
    case '*':
        return a*b;
        break;
    case '/':
        return a / b;
        break;

    }


}
int prior(char k,char kk)
{
    int temp_1,temp_2;
    temp_1 = temp_2 = 0;
    char mass[6] = {'=','(','+','-','*','/'};
    int masss[6] = {0,1,2,2,3,3};
    for(int i = 0; i < 6; i++)
    {
        if(k == mass[i])
        {
            temp_1 = masss[i];
        }
        if(kk == mass[i])
        {
            temp_2 = masss[i];
        }
    }

    if (temp_1 >= temp_2) return 1;
    else return 0;

}
int inch(char k)
{
    for(int i = 0; i < 4; i++)
    {
        if(k == ss[i]) return 1;

    }
    return 0;
}
int in(char k)
{
    for(int i = 0; i < 12; i++)
    {
        if(k == mas[i]) return 1;
    }
    return 0;

}
int main()
{
    stack<char> *Y;
    stack<double> *X;
    stack<char> *Z;
    stack_init(Y);
    stack_init(Z);
    stack_init(X);
    char s[100];
    char h[100];
    int temp = 0;
    for(int i = 0; i < 100; i++)
    {
        h[i] = 'q';
    }
    char b[100];
    for(int i = 0; i < 100; i++)
    {
        b[i] = 'q';
    }
    cin >>s;
    int i = 0;
    int m = 0;
    int t = 0;
    int j = 0;
    while(i < strlen(s))
    {
        if(s[0] == '-' && temp == 0)
        {
            i++;
            m++;
            temp = 1;
            h[0] = '-';
            j = 1;
        }
        if(s[i] == '-' && s[i-1] == '(')
        {
            i++;
            m++;
            h[j] = '-';
            j++;
        }
        if(in(s[m]))
        {

            while(in(s[m]))
            {
                if(s[m] == 'e') m+=4;
                else m++;
            }

            for(int y = i; y < m; y++)
            {
                b[t] = s[y];
                h[j] = s[y];
                j++;
                t++;
            }
            double r=atof(b);
            if(s[0] == '-' && temp == 1)
            {
                r = -r;
                temp = 2;
            }
            if(s[i-1] == '-' && s[i-2] == '(')
            {
                r = -r;
            }
            push(X,r);
            t = 0;
            for(int y = i; y < m; y++)
            {
                b[t] = 'q';
                t++;
            }

            t = 0;
            i = m;
        }
        else
        {
            if(stack_is_empty(Y))
            {
                push(Y,s[i]);
                m++;
                i++;
            }

            else
            {
                if(prior(s[i],top(Y)))
                {
                    push(Y,s[i]);
                    m++;
                    i++;
                }
                else
                {
                    if(inch(s[i]))
                    {
                        while(!stack_is_empty(Y) && top(Y) != '(')
                        {
                            if (top(X) == 0 && top(Y) == '/')
                            {
                                cout << "Error." << endl;
                                return 0;

                            }
                            else
                            {

                                double rr = pod(X->next->id,top(X),top(Y));
                                pop(X);
                                pop(X);
                                push(X,rr);
                                h[j] = top(Y);
                                j++;

                                pop(Y);
                            }

                        }
                        push(Y,s[i]);
                        i++;
                        m++;
                    }
                    else if(s[i] == '(')
                    {
                        push(Y,s[i]);
                        i++;
                        m++;
                    }
                    else if(s[i] == ')')
                    {
                        i++;
                        m++;
                        if (top(X) == 0 && top(Y) == '/')
                        {
                            cout << "Error." << endl;
                            return 0;

                        }
                        else
                        {
                            while(top(Y) != '(')
                            {

                                double rr = pod(X->next->id,top(X),top(Y));

                                pop(X);
                                pop(X);
                                push(X,rr);
                                h[j] = top(Y);
                                j++;
                                pop(Y);
                            }
                            pop(Y);
                        }

                    }
                    else
                    {

                        while(!stack_is_empty(Y))
                        {
                            if (top(X) == 0 && top(Y) == '/')
                            {
                                cout << "Error." << endl;
                                return 0;

                            }
                            else
                            {

                                double rr = pod(X->next->id,top(X),top(Y));
                                pop(X);
                                pop(X);
                                push(X,rr);
                                h[j] = top(Y);
                                j++;
                                pop(Y);
                            }
                        }

                    }

                }
            }

        }
    }

    for(int i = 0; i < j; i++)
    {
        cout<<h[i];
    }
    cout<<endl;
    cout << top(X) << endl;
    return 0;
}


