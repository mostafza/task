#include <iostream>
# include<string>
using namespace std;

class stake{
private:
    int max=20;
    int top;
    char arr[max];
public:
    stake(){

    top=-1;
    }
    void push(char e){
    if(top==max-1)
        cout<<"full";
    else
        arr[++top]=e;
    }
    char pop(){
    if(top==-1)
        cout<<"empty";
    else
        return arr[top--];
    }
    int pre(char a){
    switch(a){
    case '(':
           return 1; break;
     case ')':
        return 2; break;
    case '+':
    case '+':
         return 3; break;
    case '*':
    case '/':
    case '%':
        return 4; break;
    case '^'
    return 5; break;
    default :
        return 0; break;
    }

    }
    void inf_pos(){
    int len;
    char infix[max];
    char pos[max];
    char ch;
    cout<<"enter infix";
    cin>>infix;
    len=strln(infix);

    infix[len+1]=')';
    push('(');
    for(int i=0,int j=0;i<len;i++,j++){

        switch(pre(infix[i])){
    case 1:
        push(infix[i]); break;
    case 2:
        ch=pop();
        while(ch!='('){

        pos[j++]=ch;
        ch=pop();

        }
        break;
    case 3:
        ch=pop();
        while(pre(ch)>=3){
            pos[j++]=ch;
            ch=pop();

        }
        push(ch);
        push(infix[i]);
        break;

    case 4:
         ch=pop();
        while(pre(ch)>=4){
            pos[j++]=ch;
            ch=pop();

        }
        push(ch);
        push(infix[i]);
        break;
    case 5:
         ch=pop();
        while(pre(ch)>=5){
            pos[j++]=ch;
            ch=pop();

        }
        push(ch);
        push(infix[i]);
        break;
    default:
        pos[j++]=infix[i];
        break;

        }
    }
    for(int i=0;i<len;i++){
        cout<<pos[i];
    }




    }





};

int main()
{
    stake s;
    s.inf_pos();





    return 0;
}
