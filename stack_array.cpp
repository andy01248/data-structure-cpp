# include <iostream>
using namespace std;
#define MAX_SIZE 101
int top=-1; //the top position of stack
int stack_array[MAX_SIZE];
void push(int data){

    if (top==MAX_SIZE-1){
        cout<<"ERROR:the stack overflow";
    }
    else
    {
        top++;
        stack_array[top]=data;
    }
}
void pop(){
    if (top==-1){
        cout<<" ERROR: no element to pop";
        return;
    }
    else top--;
}
int Top(){
    return stack_array[top];
}
void print()
{
for (int i=0; i<=top;i++){
    cout<<stack_array[i]<<"\n";
}
}

int main(){

    push(5);
    push(8);
    push(9);
    print();
    pop();
    pop();
    push(6);
    print();
}