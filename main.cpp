#include <iostream>
#include <fstream>
#include <iomanip>
#include <stdlib.h>
#include <process.h>
#include <stdio.h>
#include <conio.h>
using namespace std;
class rameta
{
    int idno,contact;
    float shareamount,sharepercent,totalcont;

    char  name[30],email[30],member[30];
    string date;
public:
    rameta()
    {
        totalcont=10000;
    }
    int getidno(){return idno;}
    char* getname(){return name;}
    char* getemail(){return email;}
    int getcont(){return contact;}
    float getshare(){return shareamount;}
    float gettotal(){return totalcont;}




    void saveinfo()
    {
        cout<<"enter id number"<<endl;
        cin>>idno;
        cout<<"enter name"<<endl;
        cin>>name;
        cout<<"enter email"<<endl;
        cin>>email;
        cout<<"enter phone number"<<endl;
        cin>>contact;
        cout<<"enter share amount"<<endl;
        cin>>shareamount;
        totalcont+=shareamount;
        sharepercent=(shareamount/totalcont)*100;
    }
    void display()
    {
        cout<<"id number"<<setw(20)<<"name"<<setw(20)<<"contact"<<setw(20)<<"email"<<setw(20)<<"share amount"<<setw(20)<<"share percentage"<<endl;
        cout<<idno<<setw(20)<<name<<setw(20)<<contact<<setw(20)<<email<<setw(20)<<shareamount<<setw(20)<<sharepercent<<"%"<<endl;
    }
    void addinfo()
    {
        rameta r;
        fstream f;
        f.open("ten.csv",ios::in | ios::app);
        r.saveinfo();
        f.write((char*)&r,sizeof(rameta));
        f.close();
        cout<<"info added successfully"<<endl;
        getch();

    }
    void displayinfo()
    {
        rameta r;
        fstream i;
        i.open("ten.csv",ios::in);
        while(i.read((char*)&r,sizeof(rameta)))
        {
            r.display();
            getch();
        }
        i.close();
        getch();
    }
    void sarch()
    {
        rameta r;
        int flag=0;
        fstream k;
        k.open("ten.csv",ios::in);
        cout<<"enter id number"<<endl;
        cin>>idno;
        while(k.read((char*)&r,sizeof(rameta)))
        {
            if(idno==r.getidno())
            {
                r.display();
                flag=1;
            }
        }
        k.close();
        if(flag==0)
        {
            cout<<"FAILED"<<endl;
        }
        getch();
    }
    void modify()
    {
        rameta r;
        int flag=0,idno;
        fstream j;
        j.open("ten.csv",ios::in | ios::out);
        cout<<"enter id number"<<endl;
        cin>>idno;
        while(j.read((char*)&r,sizeof(rameta)))
        {

            if(idno==getidno())
            {
                cout<<"modify the following"<<endl;
                r.display();
                cout<<"enter new details"<<endl;
                r.saveinfo();
                int pos=-1*sizeof(r);
                j.seekg(pos, ios::cur);
                j.write((char*)&r,sizeof(100));
                flag=1;

            }
            j.close();
            if(flag==0)
            {
                cout<<"FAILED"<<endl;
            }
            getch();

        }


    }
    void cont()
    {
        fstream b;
        rameta r;
        b.open("ten.csv",ios::in);
        if(!b)
        {
            cout<<"FAILED"<<endl;
            getch();
            exit(0);
        }
        while(b.read((char*)&r,sizeof(rameta)))
        {
            cout<<r.getidno()<<setw(8)<<r.getname()<<endl;
        }


      int amt,total,ttotal,days,fine,member;
      char ch;
      do{
            cout<<"enter members id"<<endl;
      cin>>member;

        cout<<"enter the amount of contribution"<<endl;
        cin>>amt;
        cout<<"days that have passed since deadline"<<endl;
        cin>>days;
        cout<<"do you wish to continue saving[y/n]"<<endl;
        cin>>ch;
            b.open("ten.csv",ios::in);
                if(r.getidno()==member)
                {


                  fine=days*10;
                  ttotal=fine+amt;
                  cout<<"ID"<<setw(10)<<"amount"<<setw(10)<<"fine"<<setw(20)<<"total"<<endl;
                  cout<<r.getidno()<<setw(8)<<amt<<setw(8)<<fine<<setw(20)<<ttotal<<endl;
                  total+=ttotal+r.gettotal();
                  cout<<"TOTAL STANDING"<<setw(10)<<total<<endl;
                }







            b.close();



        }while(ch=='Y' || ch=='y');

        getch();


    }



    void menu()
    {

        rameta r;
    int sel;
    do{

    cout<<"*****************************************"<<endl;
    cout<<"           1.add info" << endl;
    cout<<"           2.display info" << endl;
    cout<<"           3.search info" << endl;
    cout<<"           4.modify info" << endl;
    cout<<"           5.main menu"<<endl;
    cout<<"           6.exit"<<endl;
    cout<<"*****************************************"<<endl;
    cout<<"select [1-6]"<<endl;
    cin>>sel;

      if(sel==1)
    {
        r.addinfo();
    }
    else if(sel==2)
    {
        r.displayinfo();
    }
    else if(sel==3)
    {
        r.sarch();
    }
    else if(sel==4)
    {
        r.modify();
    }
    else if(sel==5)
    {
        break;
    }
    else if(sel==6)
    {
        exit(0);
    }
    else{cout<<"invalid choice"<<endl;}
    }while(sel==1 || sel==2 || sel==3 || sel==4 || sel==5);

    }
    void b_menu()
    {
         rameta r;
    int se;
    do{

    cout<<"*****************************************"<<endl;
    cout<<"           1.display members  info" << endl;
    cout<<"           2.search members info" << endl;
    cout<<"           3.modify members info" << endl;
    cout<<"           4.main menu"<<endl;
    cout<<"           5.exit"<<endl;
    cout<<"*****************************************"<<endl;
    cout<<"select [1-6]"<<endl;
    cin>>se;

      if(se==1)
    {
        r.displayinfo();
    }
    else if(se==2)
    {
        r.sarch();
    }
    else if(se==3)
    {
        r.modify();
    }
    else if(se==4)
    {
        break;
    }
    else if(se==5)
    {
        cout<<"exiting the program"<<endl;
        exit(0);
    }
    else{r.b_menu();cout<<"invalid choice"<<endl;}
    }while(se==1 || se==2 || se==3 || se==4 || se==5);
    }
    void menu_c()
    {
        int select;
        rameta r;
        cout<<"================================================"<<endl;
        cout<<"************************************************"<<endl;
        do{
        cout<<"      1.RECORD CONTRIBUTION"<<endl;
        cout<<"      2.BACK TO MAIN MENU"<<endl;
        cout<<"      3.exit"<<endl;
        cout<<"select option[1-4]"<<endl;
        cin>>select;
        cout<<"=================================================="<<endl;
        if(select==1)
        {
            r.cont();
        }

        else if(select==2)
        {
            break;
        }
        else if(select==3)
        {
            exit(0);
        }
        else{cout<<"INVALID CHOICE"<<endl;}
        }while(select==1 || select==2 || select==3);
    }
};

int main()
{
    rameta r;
        int opt;
        cout<<"================================================"<<endl;
        cout<<"************************************************"<<endl;
        cout<<"*                                              *"<<endl;
        cout<<"*     WELCOME TO RAMETA SCHOLARS SACCO         *"<<endl;
        cout<<"*                                              *"<<endl;
        cout<<"************************************************"<<endl;
        cout<<"================================================"<<endl;
        do{
            cout<<"        1.TREASURER"<<endl;
            cout<<"        2.MEMBERS"<<endl;
            cout<<"        3.CONTRIBUTION"<<endl;
            cout<<"        4.EXIT"<<endl;
            cout<<"select option[1-2]"<<endl;
            cin>>opt;
            if(opt==1)
            {
                r.menu();
            }
            else if(opt==2)
            {
                r.b_menu();
            }
            else if(opt==3)
            {
                r.menu_c();
            }
            else if(opt==4)
            {
                cout<<"exiting the program"<<endl;
                exit(0);
            }
            else{cout<<"invalid choice"<<endl;}
            }while(opt==1 || opt==2 || opt==3 || opt==4);



    return 0;
}
