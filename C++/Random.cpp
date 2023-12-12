#include<iostream>
#include<time.h>
#include<ncurses.h>
using namespace std;
void GuessNum()
{
    srand(time(0));
    int Gen_Num;
    char ch;
    Gen_Num = rand()%100+1;
    int guess,count=0;
    cout<<"\n\n\t\t--------------------{ WELCOME TO NUMBER GUESSING GAME }--------------------\n\n";
    while(1)
    {
        cout<<"\nEnter your guess number: ";
        ch=getch();
        if(ch>=48 && ch<=57)
        {
            cin>>guess;
            count++;
            if(guess == Gen_Num)
            {
                cout<<"\n\t\tCongratulation! your number is matched in "<<count<<" tries.\n";
                break;
            }
            else if(guess > Gen_Num)
                cout<<"To high! Try again."<<endl;
            else
                cout<<"To low! Try again."<<endl;
        }
        else
            cout<<"Please enter number only";
    }
    cout<<"Press 'y' to play again: ";
    cin>>ch;
    if(ch=='y')
        GuessNum();
    else
        return ;
}
int main()
{
    GuessNum();
    return 0;
}