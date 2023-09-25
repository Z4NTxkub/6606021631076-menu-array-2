#include<iostream>
#include<string>
#include<iomanip>
using namespace std;
void Input(int &numS,int Quiz[10],int Mid[10],int Final[10]);
void ViewAll(int &numS,int Quiz[10],int Mid[10],int Final[10], int Sum[10]);
void ViewID(int &numS,int Quiz[10],int Mid[10],int Final[10]);
void Sortscore(int numS,int Sum[10]);
int main()
{    int numS =0;
    int Quiz[10],Mid[10],Final[10],Sum[10];
    char menu;
    do{
        cout<<"==========================="<<endl;
        cout<<"             MENU            "<<"\n";
        cout<<"==========================="<<"\n";
        cout<<"     1.Input student records"<<"\n";
        cout<<"     2.View all student records"<<"\n";
        cout<<"     3.Show a student by ID "<<"\n";
        cout<<"     4.Sort Sum Score "<<"\n";
        cout<<"     5.Exit "<<"\n";
        cout<<"Select menu : ";
        cin>>menu;
        if(menu=='1')
        {   Input(numS,Quiz,Mid,Final);
        }else if (menu =='2')
        {   ViewAll(numS,Quiz,Mid,Final,Sum);
        }else if(menu =='3')
        {    ViewID(numS,Quiz,Mid,Final);
        }else if(menu =='4')
        {    Sortscore(numS,Sum);
        }else return(0);
    }while(menu !='5');
    system("pause");
    return(0);
}// end main
void Input(int &numS,int Quiz[10],int Mid[10],int Final[10])
{    cout<<"Input Number of Student :";
    cin>>numS;
    for(int i = 0;i<numS;i++)
    {    cout<<"Number "<<i+1<<endl;
        cout<<" Input Quiz :";
        cin>>Quiz[i];
        cout<<" Input Midterm :";
        cin>>Mid[i];
        cout<<" Input Final:";
        cin>>Final[i];
        cout<<endl;
    }
}
void ViewAll(int &numS,int Quiz[10],int Mid[10],int Final[10],int Sum[10])
{    float TQuiz =0.0, TMid = 0.0 ,TFinal = 0.0, sum = 0 ;
    cout<<"--------------------------------------"<<endl;
    cout<<"StdID   Quiz    Midterm     Final     Sum"<<endl;
    cout<<"--------------------------------------"<<endl;
    for(int i = 0;i<numS;i++)
    {    Sum[i] = Quiz[i]+Mid[i]+Final[i];
        cout<<i+1<<setw(9)<<Quiz[i]<<setw(9)<<Mid[i]<<setw(9)<<Final[i]<<setw(9)<<Sum[i]<<endl;
        TQuiz  = TQuiz + Quiz[i];
        TMid   = TMid + Mid[i];
        TFinal = TFinal + Final[i];
    }
    cout<<"--------------------------------------"<<endl;
    cout<<"Total"<<setw(5)<<TQuiz<<setw(9)<<TMid<<setw(9)<<TFinal<<endl;
    cout<<"--------------------------------------"<<endl;

}
void ViewID(int &numS,int Quiz[10],int Mid[10],int Final[10])
{    int id;
    cout<<"Input ID : ";
    cin>>id;
    for(int i =0; i<numS; i++)
    {    if(id == i+1)
        {    cout<<"--------------------------------------"<<endl;
            cout<<"StdID   Quiz    Midterm     Final"<<endl;
            cout<<"--------------------------------------"<<endl;
            cout<<i+1<<setw(9)<<Quiz[i]<<setw(9)<<Mid[i]<<setw(9)<<Final[i]<<endl;
            cout<<"--------------------------------------"<<endl;
        }else
        {    cout<<"Your ID is not found "<<endl;
        }
    }
}
void Sortscore(int numS,int Sum[10])
{    for (int i = 0; i < numS - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < numS; j++) {
            if (Sum[j] < Sum[minIndex]) {
                minIndex = j;
            }
        }
        int temp = Sum[i];  
        Sum[i] = Sum[minIndex];
        Sum[minIndex] = temp;
    }
    cout<<"-------------------"<<endl;
    cout<<"NO. Sort_Sum_Score   "<<endl;
    cout<<"-------------------"<<endl;
    for (int i = 0; i < numS; i++) {
         cout <<i+1<<setw(15)<< Sum[i] << endl;
    }
    cout<<"-------------------"<<endl;
}