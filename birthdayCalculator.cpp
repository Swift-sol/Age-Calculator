#include <iostream>
#include <chrono>
#include <ctime>
using namespace std;

int main()
{

    char nexT;
    int yr, mon, bd;
    int month,birtH,d,m,y;
    int remainder;

    time_t now = time(0);
    tm *ltm = localtime(&now);
    do
    {

        cout<<"Time: "<<ltm->tm_hour<<":";
        cout<<1+ltm->tm_min<<":";
        cout<<1+ltm->tm_sec<<"\n";
        cout<<"Today is: "<<ltm->tm_mday<<"/"<<1+ltm->tm_mon<<"/"<<1900+ltm->tm_year<<"\n";
        d = ltm->tm_mday;
        m = 1+ltm->tm_mon;
        y = 1900+ltm->tm_year; //current time

        cout<<"Please Enter your birthday: "<<"\n";
        cout<<"Enter Year: ";
        cin>>yr;
        do
        {
            if (1870>yr || yr> 1900+ltm->tm_year){//check within 150 year old
                cout<<"Impossible birthday.\n";
                cout<<"Enter your birthday year again:";
                cin>>yr;
            }
        }while (1870>yr || yr>1900+ltm->tm_year);
        cout<<"Enter Month: ";
        cin>>mon;
        do
        {

            if (1>mon || mon>12){ //check within 12 months
                cout<<"Impossible birthday.\n";
                cout<<"Enter your birthday month again:";
                cin>>mon;
            }
        }while (1>mon || mon>12);
        remainder = yr % 4; //check leap year
        if (mon==2 && remainder==0) { //birthday number should be between 1&29 within leap year
            cout<<"Enter Date: ";
            cin>>bd;
            do
            {
                if (1>bd || bd>29){
                    cout<<"Impossible birthday.\n";
                    cout<<"Enter your birthday again:";
                    cin>>bd;
                }
            }while (1>bd || bd>29);
        }
        if (mon==2 && remainder>0) { //not leap year birthday number should be between 1&28
            cout<<"Enter Date: ";
            cin>>bd;
            do
            {
                if (1>bd || bd>28){
                    cout<<"Impossible birthday.\n";
                    cout<<"Enter your birthday again:";
                    cin>>bd;
                }
            }while (1>bd || bd>28);
        }
        if (mon==4 || mon==6 ||  mon==9 ||  mon==11) { //check months within 1&30
            cout<<"Enter Date: ";
            cin>>bd;
            do
            {
                if (1>bd || bd>30){
                    cout<<"Impossible birthday.\n";
                    cout<<"Enter your birthday again:";
                    cin>>bd;
                }
            }while (1>bd || bd>30);
        }
        if (mon==1 || mon==3 ||  mon==5 ||  mon==7 || mon==8 || mon==10 ||  mon==12) {//check months within 1&31
            cout<<"Enter Date: ";
            cin>>bd;
            do
            {
                if (1>bd || bd>31){
                    cout<<"Impossible birthday.\n";
                    cout<<"Enter your birthday again:";
                    cin>>bd;
                }
            }while (1>bd || bd>31);
        }
        cout<<"\nyour birthday is:" <<bd <<" /"<<mon<<" /" <<yr<<endl;
        if (mon==m) {//calculate days
            cout << "\nWow...This is your birthday month:";
            if (bd<d) {
                birtH = d-bd;
                cout << "\nNow you are " << "'" << y - yr  << "' years and '"<<birtH<<"' days old.";
            }
            if (bd>d) { //calculate days
                birtH = bd-d;
                cout << "you need to wait '"<< birtH<<"' Days to celebrate your '"<<y-yr<<"'th Birthday.\n";
            }
        }
        if (mon<m) {//calculate months

            cout << "Now you are " << "'" << y - yr << "' years and '" << m - mon << "' months old.";
        }
        if (mon>m){
            month = 12-mon;
            cout <<"\nNow you are "<<"'"<<y-yr-1<<"' years and '"<<m+month<< "' months old.";
        }
        cout<<"\n\nWant to check more ? (y/n).. "; //asking want to check again or quit
        cin>>nexT;
        cout<<"\n";
    }while(nexT=='y');
    return 0;
}
