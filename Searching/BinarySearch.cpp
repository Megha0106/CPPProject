
#include<iostream>
using namespace std;
#ifndef STUD_H
#define STUD_H
struct student{
    int rn,points[5],credit[5],sum;
    string name;
    float total,sgpa;

};
class stud{
    public:

struct student s[15];
    int n,ch,count_space,count_digit;
    stud(){
        cout<<"Enter no. of students-->";
        cin>>n;

    }

        void input();//for reading the data from user
        void output();//for displaying output
        void space(string& str);//for counting spaces in name
        void sort_roll();//for sorting roll no.
        void sort_name();//for sorting names
        void search_name();//for searching of name
        void search_sgpa();//for searching of sgpa


};
#endif



Stud.cpp(Implementation File)
#include<iostream>
#include "stud.h"
using namespace std;
int stud::space(string& str)
        {
        int count=0;
        int size=str.length();

        for(int k=0;k<size;k++)
        {
            int c=str[k];
            if(isspace(c))
            {
                count++;
            }

        }
        return count;
}

void stud::input()
{

    for(int i=0;i<n;i++)
    {
        s[i].total=0;
        s[i].sum=0;
        cout<<"____________________________________________________________________________________\n";
        cout<<"-----Student "<<i+1<<" -----"<<endl;
        cout<<"Enter Roll no.--> ";
        cin>>s[i].rn;
        cout<<"Enter Name--> ";
        cin.ignore();
        getline(cin,s[i].name);
        ch=space(s[i].name);
        while(ch<2)
        {

            cout<<"Invalid name\nEnter Again:";
            getline(cin,s[i].name);
            ch=space(s[i].name);

        }
        for(int j=0;j<5;j++)
        {
            cout<<"**Subject "<<j+1<<endl;
            cout<<"  Enter Credit of subject(1-5)-->";
            cin>>s[i].points[j];
            if(s[i].points[j]>5)
            {
                cout<<"  Enter value between range(1-5)-->";
                cin>>s[i].points[j];
            }
            cout<<"  Enter Credit Scored(1-10)-->";
            cin>>s[i].credit[j];
            if(s[i].credit[j]>10)
            {
                cout<<"  Enter value between range(1-10)-->";
                cin>>s[i].credit[j];
            }
            s[i].total+=s[i].points[j]*s[i].credit[j];
            s[i].sum+=s[i].points[j];

        }
        s[i].sgpa=s[i].total/s[i].sum;


    }
}
void stud::output()
{
    cout<<"____________________________________________________________________________________\n";
    cout<<"-----------------------------------List of Students---------------------------------\n";

    cout<<"Roll no.\t\tName\t\tTotal Credit Earned\t\tSGPA\n";
    for(int i=0;i<n;i++)
    {

        cout<<s[i].rn<<"\t\t\t"<<s[i].name<<"\t\t\t"<<s[i].total<<"\t\t\t "<<s[i].sgpa<<"\n";

    }
    cout<<"____________________________________________________________________________________\n";
}
void stud::sort_roll()
{
    bool swap;
    for(int i=0;i<n-1;i++)
    {
        swap=false;
        for(int j=0;j<n-i-1;j++)
        {

            if(s[j].rn>s[j+1].rn)
            {
                student temp=s[j];
                s[j]=s[j+1];
                s[j+1]=temp;
                swap=true;
            }

        }
        //output();
        if(swap==false)
        {
            break;
        }

    }
}
void stud::sort_name(){
    int i,j;
    student temp;
    string temp1;
    for(i=0;i<=n-1;i++)
    {
        temp=s[i];
        temp1=s[i].name;

        j=i;
        while(j>=0&&temp1<s[j-1].name)
        {
            s[j]=s[j-1];

            j--;
        }
        s[j]=temp;
        //output();
    }
}
void stud::search_name()
{
    sort_name();
    int low=0,high=n-1,mid;
    bool flag=false;
    student temp=s[0];
    string find;
    cout<<"Enter the name to be searched: ";
    cin.ignore();
    getline(cin,find);
    while(low<=high)
    {
        mid=low+(high-low)/2;
        if(s[mid].name==find)
        {
            flag=mid;
            temp=s[mid];
        }
        if(s[mid].name<find)
        {
            low=mid+1;

        }
        else
        {
            high=mid-1;
        }

    }
    if(flag==false)
    {
        cout<<"No records found!!!";
    }
    else
    {
        cout<<"____________________________________________________________________________________\n";
        cout<<"Roll no.\t\tName\t\tTotal Credit Earned\t\tSGPA\n";
        cout<<temp.rn<<"\t\t\t"<<temp.name<<"\t\t\t"<<temp.total<<"\t\t\t "<<temp.sgpa<<"\n";
        cout<<"____________________________________________________________________________________\n";
    }

}
void stud::search_sgpa()
{
    float find;
    cout<<"Enter Sgpa to be searched: ";
    cin>>find;
    cout<<"____________________________________________________________________________________\n";
    cout<<"Roll no.\t\tName\t\tTotal Credit Earned\t\tSGPA\n";
    for(int i=0;i<=n-1;i++)
    {

        if(s[i].sgpa==find)
        {

        cout<<s[i].rn<<"\t\t\t"<<s[i].name<<"\t\t\t"<<s[i].total<<"\t\t\t "<<s[i].sgpa<<"\n";

        }
    }
    cout<<"____________________________________________________________________________________\n";
}
int partition(student s[],int low,int high)
{
    student temp,temp2;
    int pivot,i;
    pivot=s[high].sgpa;
    i=low-1;
    for(int j=low;j<=high-1;j++)
    {
        if(s[j].sgpa>=pivot)
        {
            i++;
            temp=s[i];
            s[i]=s[j];
            s[j]=temp;
        }

    }
    temp=s[i+1];
        s[i+1]=s[high];
        s[high]=temp;
    return (i+1);
}
void toppers(student s[],int low,int high)
{
    if(low<high)
    {
        int mid=partition(s,low,high);
        toppers(s,low,mid-1);
        toppers(s,mid+1,high);
    }
}






















Main.cpp(Main-client File)
#include<iostream>
#include "stud.h"
#include "stud.cpp"
using namespace std;

int main()
{
    stud object;
    int ch;
    object.input();
    while (true)
    {
        cout<<"\n1.Sort Roll No.\n2.Sort Name\n3.Search Name\n4.Search SGPA\n5.Display Toppers\n6.Exit\n";
        cout<<"Enter Choice:";
        cin>>ch;
        switch (ch)
        {
        case 1:
        object.sort_roll();

        object.output();
        break;
        case 2:
        object.sort_name();
        object.output();
        break;
        case 3:
        object.search_name();
        break;
        case 4:
        object.search_sgpa();
        break;
        case 5:
        toppers(object.s,0,object.n-1);
        object.output();
        break;

        default:cout<<"Thank you for using";
            break;
        }
        if(ch>5){break;}
    }


    return 0;
}


