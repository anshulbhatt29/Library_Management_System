//***************************************************************
//                   HEADER FILE USED IN PROJECT
//****************************************************************

#include<fstream>
#include<iostream>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
#include<stdio.h>
#include<process.h>
#include<string.h>
#include<iomanip>
#include<windows.h>


//***************************************************************
//                   CLASS USED IN PROJECT
//****************************************************************
using namespace std;


class book
{
	char bno[6];
	char bname[50];
	char aname[20];
  public:
	void create_book()
	{
        cout<<"\nNEW BOOK ENTRY...\n";
        cout<<"\nEnter The book no.";
        cin>>bno;
        cin.ignore();
        cout<<"\n\nEnter The Name of The Book ";
        gets(bname);
        cout<<"\n\nEnter The Author's Name ";
        gets(aname);
        cout<<"\n\n\nBook Created..";
    }

    void show_book()
    {
        cout<<"\nBook no. : "<<bno;
        cout<<"\nBook Name : ";
        puts(bname);
        cout<<"Author Name : ";
        puts(aname);
    }

    void modify_book()
    {
        cout<<"\nBook no. : "<<bno;
        cin.ignore();
        cout<<"\nModify Book Name : ";
        gets(bname);
        cout<<"\nModify Author's Name of Book : ";
        gets(aname);
    }

    char * retbno()
    {
        return bno;
    }

    void report()
    {cout<<bno<<setw(30)<<bname<<setw(30)<<aname<<endl;}


};         //class ends here




class student
{
    char admno[6];
    char name[20];
    char stbno1[6],stbno2[6],stbno3[6],stbno4[6],stbno5[6];
    int token;
public:
    void create_student()
    {
        system("cls");
        cout<<"\nNEW STUDENT ENTRY...\n";
        cout<<"\nEnter The admission no. ";
        cin>>admno;
        cin.ignore();
        cout<<"\n\nEnter The Name of The Student ";
        gets(name);
        token=0;
        stbno1[0]='\0';
        stbno2[0]='\0';
        stbno3[0]='\0';
        stbno4[0]='\0';
        stbno5[0]='\0';
        cout<<"\n\nStudent Record Created..";
    }
    void callme()
    {
        cout<<"\nBook No issued by user is :\n";
        if(stbno1[0]!='\0')
        {
            cout<<stbno1<<endl;
        }
          if(stbno2[0]!='\0')
        {
            cout<<stbno2<<endl;
        }
          if(stbno3[0]!='\0')
        {
            cout<<stbno3<<endl;
        }
          if(stbno4[0]!='\0')
        {
            cout<<stbno4<<endl;
        }
          if(stbno5[0]!='\0')
        {
            cout<<stbno5<<endl;
        }

            getch();
    }

    void show_student()
    {
        cout<<"\nAdmission no. : "<<admno;
        cout<<"\nStudent Name : ";
        puts(name);
        cout<<"\nNo of Book issued : "<<token;
        //if(token==1)
            //cout<<"\nBook No "<<stbno;
    }

    void modify_student()
    {
        cout<<"\nAdmission no. : "<<admno;
        cin.ignore();
        cout<<"\nModify Student Name : ";
        gets(name);
    }

    char* retadmno()
    {
        return admno;
    }

    char* retstbno(int j, char xn[])
    {
        if(j==1)
        {
         if(strcmp(xn,stbno1)==0)
        {
            stbno1[0]='\0';
        }
        else if(strcmp(xn,stbno2)==0)
        {
            stbno2[0]='\0';
        }
        else if (strcmp(xn,stbno3)==0)
        {
            stbno3[0]='\0';
        }
        else if (strcmp(xn,stbno4)==0)
        {
            stbno4[0]='\0';
        }
        else if (strcmp(xn,stbno5)==0)
        {
            stbno5[0]='\0';
        }
        }
        return xn;
    }

    int rettoken()
    {
        return token;
    }

    void addtoken()
    {token++;}

    void resettoken()
    {token--;}

    void getstbno(char t[])
    {
        if(stbno1[0]=='\0')
        {
            strcpy(stbno1,t);
        }

        else if(stbno2[0]=='\0')
        {
            strcpy(stbno2,t);
        }

        else if(stbno3[0]=='\0')
        {
            strcpy(stbno3,t);
        }

        else if(stbno4[0]=='\0')
        {
            strcpy(stbno4,t);
        }

        else if(stbno5[0]=='\0')
        {
            strcpy(stbno5,t);
        }

    }


    void report()
    {cout<<"\t"<<admno<<setw(20)<<name<<setw(10)<<token<<endl;}

};         //class ends here




//***************************************************************
//        global declaration for stream object, object
//****************************************************************

fstream fp,fp1;
book bk;
student st;





//***************************************************************
//        function to write in file
//****************************************************************

void write_book()
{
    char ch;
    fp.open("book.dat",ios::out|ios::app);
    do
    {
        system("cls");
        bk.create_book();
        fp.write((char*)&bk,sizeof(book));
        cout<<"\n\nDo you want to add more record..(y/n?)";
        cin>>ch;
    }while(ch=='y'||ch=='Y');
    fp.close();
}

void write_student()
{
    char ch;
    fp.open("student.dat",ios::out|ios::app);
    do
    {
        st.create_student();
        fp.write((char*)&st,sizeof(student));
        cout<<"\n\ndo you want to add more record..(y/n?)";
        cin>>ch;
    }while(ch=='y'||ch=='Y');
    fp.close();
}


//***************************************************************
//        function to read specific record from file
//****************************************************************


void display_spb(char n[])
{
    cout<<"\nBOOK DETAILS\n";
    int flag=0;
    fp.open("book.dat",ios::in);
    while(fp.read((char*)&bk,sizeof(book)))
    {
        if(strcmp(bk.retbno(),n)==0)
        {
            bk.show_book();
             flag=1;
        }
    }

    fp.close();
    if(flag==0)
        cout<<"\n\nBook does not exist";
    getch();
}

void display_sps(char n[])
{
    cout<<"\nSTUDENT DETAILS\n";
    int flag=0;
    fp.open("student.dat",ios::in);
    while(fp.read((char*)&st,sizeof(student)))
    {
        if((strcmp(st.retadmno(),n)==0))
        {
            st.show_student();
            flag=1;
        }
    }

    fp.close();
    if(flag==0)
            cout<<"\n\nStudent does not exist";
     getch();
}


//***************************************************************
//        function to modify record of file
//****************************************************************


void modify_book()
{
    char n[6];
    int found=0;
    system("cls");
    cout<<"\n\n\tMODIFY BOOK REOCORD.... ";
    cout<<"\n\n\tEnter The book no. of The book";
    cin>>n;
    fp.open("book.dat",ios::in|ios::out);
    while(fp.read((char*)&bk,sizeof(book)) && found==0)
    {
        if(strcmp(bk.retbno(),n)==0)
        {
            bk.show_book();
            cout<<"\nEnter The New Details of book"<<endl;
            bk.modify_book();
            int pos=-1*sizeof(bk);
                fp.seekp(pos,ios::cur);
                fp.write((char*)&bk,sizeof(book));
                cout<<"\n\n\t Record Updated";
                found=1;
        }
    }

        fp.close();
        if(found==0)
            cout<<"\n\n Record Not Found ";
        getch();
}


void modify_student()
{
    char n[6];
    int found=0;
    system("cls");
    cout<<"\n\n\tMODIFY STUDENT RECORD... ";
    cout<<"\n\n\tEnter The admission no. of The student";
    cin>>n;
    fp.open("student.dat",ios::in|ios::out);
    while(fp.read((char*)&st,sizeof(student)) && found==0)
    {
        if(strcmp(st.retadmno(),n)==0)
        {
            st.show_student();
            cout<<"\nEnter The New Details of student"<<endl;
            st.modify_student();
            int pos=-1*sizeof(st);
            fp.seekp(pos,ios::cur);
            fp.write((char*)&st,sizeof(student));
            cout<<"\n\n\t Record Updated";
            found=1;
        }
    }

    fp.close();
    if(found==0)
        cout<<"\n\n Record Not Found ";
    getch();
}

//***************************************************************
//        function to delete record of file
//****************************************************************


void delete_student()
{
    char n[6];
    int flag=0;
    system("cls");
        cout<<"\n\n\n\tDELETE STUDENT...";
        cout<<"\n\nEnter The admission no. of the Student You Want To Delete : ";
        cin>>n;
        fp.open("student.dat",ios::in|ios::out);
        fstream fp2;
        fp2.open("Temp.dat",ios::out);
        fp.seekg(0,ios::beg);
        while(fp.read((char*)&st,sizeof(student)))
    {
        if(strcmp(st.retadmno(),n)!=0)
                 fp2.write((char*)&st,sizeof(student));
        else
               flag=1;
    }

    fp2.close();
        fp.close();
        remove("student.dat");
        rename("Temp.dat","student.dat");
        if(flag==1)
             cout<<"\n\n\tRecord Deleted ..";
        else
             cout<<"\n\nRecord not found";
        getch();
}


void delete_book()
{
    char n[6];
    system("cls");
    cout<<"\n\n\n\tDELETE BOOK ...";
    cout<<"\n\nEnter The Book no. of the Book You Want To Delete : ";
    cin>>n;
    fp.open("book.dat",ios::in|ios::out);
    fstream fp2;
    fp2.open("Temp.dat",ios::out);
    fp.seekg(0,ios::beg);
    while(fp.read((char*)&bk,sizeof(book)))
    {
        if(strcmp(bk.retbno(),n)!=0)
        {
            fp2.write((char*)&bk,sizeof(book));
        }
    }

    fp2.close();
        fp.close();
        remove("book.dat");
        rename("Temp.dat","book.dat");
        cout<<"\n\n\tRecord Deleted ..";
        getch();
}



//***************************************************************
//        function to display all students list
//****************************************************************

void display_alls()
{
    system("cls");
         fp.open("student.dat",ios::in);
         if(!fp)
         {
               cout<<"ERROR!!! FILE COULD NOT BE OPEN ";
               getch();
               return;
         }

    cout<<"\n\n\t\tSTUDENT LIST\n\n";
    cout<<"==================================================================\n";
    cout<<"\tAdmission No."<<setw(10)<<"Name"<<setw(20)<<"Book Issued\n";
    cout<<"==================================================================\n";

    while(fp.read((char*)&st,sizeof(student)))
    {
        st.report();
    }

    fp.close();
    getch();
}


//***************************************************************
//        function to display Books list
//****************************************************************

void display_allb()
{
    system("cls");
    fp.open("book.dat",ios::in);
    if(!fp)
    {
        cout<<"ERROR!!! FILE COULD NOT BE OPEN ";
               getch();
               return;
         }

    cout<<"\n\n\t\tBook LIST\n\n";
    cout<<"=========================================================================\n";
    cout<<"Book Number"<<setw(20)<<"Book Name"<<setw(25)<<"Author\n";
    cout<<"=========================================================================\n";

    while(fp.read((char*)&bk,sizeof(book)))
    {
        bk.report();
    }
         fp.close();
         getch();
}



//***************************************************************
//        function to issue book
//****************************************************************

void book_issue()
{
    char sn[6],bn[6];
    int found=0,flag=0;
   system("cls");
    cout<<"\n\nBOOK ISSUE ...";
    cout<<"\n\n\tEnter The student's admission no.";
    cin>>sn;
    fp.open("student.dat",ios::in|ios::out);
        fp1.open("book.dat",ios::in|ios::out);
        while(fp.read((char*)&st,sizeof(student)) && found==0)
           {
        if(strcmp(st.retadmno(),sn)==0)
        {
            found=1;
            if(st.rettoken()<5)
            {

                      cout<<"\n\n\tEnter the book no. ";
                  cin>>bn;
                while(fp1.read((char*)&bk,sizeof(book))&& flag==0)
                {
                       if(strcmp(bk.retbno(),bn)==0)
                    {
                        bk.show_book();
                        flag=1;
                        st.addtoken();
                        st.getstbno(bk.retbno());
                               int pos=-1*sizeof(st);
                        fp.seekp(pos,ios::cur);
                        fp.write((char*)&st,sizeof(student));
                        cout<<"\n\n\t Book issued successfully\n\nPlease Note: Write current date in backside of book and submit within 15 days fine Rs. 1 for each day after 15 days period";
                    }
                    }
                  if(flag==0)
                        cout<<"Book no does not exist";
            }
                else
                  cout<<"You have not returned the last book ";

        }
    }
          if(found==0)
        cout<<"Student record not exist...";
    getch();
      fp.close();
      fp1.close();
}

//***************************************************************
//        function to deposit book
//****************************************************************

void book_deposit()
{
    char sn[6],bn[6],xn[6];
    int found=0,flag=0,day,fine;
   system("cls");
    cout<<"\n\nBOOK DEPOSIT ...";
    cout<<"\n\n\tEnter The Student admission no.";
    cin>>sn;
    fp.open("student.dat",ios::in|ios::out);
    fp1.open("book.dat",ios::in|ios::out);
    while(fp.read((char*)&st,sizeof(student)) && found==0)
       {
        if(strcmp(st.retadmno(),sn)==0)
        {
            found=1;
            if(st.rettoken()!=0)
            {
               cout<<"Enter the book no of the book you want to return \n";
               cin>>xn;

            while(fp1.read((char*)&bk,sizeof(book))&& flag==0)
            {
               if(strcmp(bk.retbno(),st.retstbno(0,xn))==0)
            {
                bk.show_book();
                flag=1;
                cout<<"\n\nBook deposited in no. of days";
                cin>>day;
                if(day>15)
                {
                   fine=(day-15)*1;
                   cout<<"\n\nFine has to deposited Rs. "<<fine;
                }
                    st.resettoken();
                    char *t=st.retstbno(1,xn);
                    int pos=-1*sizeof(st);
                    fp.seekp(pos,ios::cur);
                    fp.write((char*)&st,sizeof(student));
                    cout<<"\n\n\t Book deposited successfully";
            }
            }
          if(flag==0)
            cout<<"Book no does not exist";
              }
         else
            cout<<"No book is issued..please check!!";
        }
       }
      if(found==0)
    cout<<"Student record not exist...";
    getch();
  fp.close();
  fp1.close();
}


//***************************************************************
//        INTRODUCTION FUNCTION
//****************************************************************
void gotoxy(int x,int y)
{

    static HANDLE h=NULL;
    if(!h)
        h=GetStdHandle(STD_OUTPUT_HANDLE);
    COORD c={x,y};
    SetConsoleCursorPosition(h,c);
}
void intro()
{
  system("cls");
    gotoxy(35,11);
    cout<<"LIBRARY";
    gotoxy(35,14);
    cout<<"MANAGEMENT";
    gotoxy(35,17);
    cout<<"SYSTEM";
    cout<<"\n\nMADE BY : Anshul Bhatt";
    getch();
}


void display_bnos()
{
    system("cls");
    char sn[6];
    cout<<"\t\tEnter the admission no of student\n";
    cout<<"\t\t";
    cin>>sn;
     fp.open("student.dat",ios::in|ios::out);
       while(fp.read((char*)&st,sizeof(student)) )
           {
        if(strcmp(st.retadmno(),sn)==0)
        {
            st.callme();

        }
           }
           fp.close();
}



//***************************************************************
//        ADMINISTRATOR MENU FUNCTION
//****************************************************************

void admin_menu()
{
   system("cls");
   {
    int ch2;
    cout<<"\n\n\n\tADMINISTRATOR MENU";
    cout<<"\n\n\t1.CREATE STUDENT RECORD";
    cout<<"\n\n\t2.DISPLAY ALL STUDENTS RECORD";
    cout<<"\n\n\t3.DISPLAY SPECIFIC STUDENT RECORD ";
    cout<<"\n\n\t4.MODIFY STUDENT RECORD";
    cout<<"\n\n\t5.DELETE STUDENT RECORD";
    cout<<"\n\n\t6.CREATE BOOK ";
    cout<<"\n\n\t7.DISPLAY ALL BOOKS ";
    cout<<"\n\n\t8.DISPLAY SPECIFIC BOOK ";
    cout<<"\n\n\t9.MODIFY BOOK ";
    cout<<"\n\n\t10.DELETE BOOK ";
    cout<<"\n\n\t11.DISPLAY BOOK NO STUDENT ";
    cout<<"\n\n\t12.BACK TO MAIN MENU";
    cout<<"\n\n\tPlease Enter Your Choice (1-12) ";
    cin>>ch2;
    switch(ch2)
    {
            case 1:system("cls");
                write_student();break;
            case 2: display_alls();break;
            case 3:
                   char num[6];
                 system("cls");
                   cout<<"\n\n\tPlease Enter The Admission No. ";
                   cin>>num;
                   display_sps(num);
                   break;
              case 4: modify_student();break;
              case 5: delete_student();break;
        case 6:system("cls");
            write_book();break;
        case 7: display_allb();break;
        case 8: {
                   char num[6];
                   system("cls");
                   cout<<"\n\n\tPlease Enter The book No. ";
                   cin>>num;
                   display_spb(num);
                   break;
            }
              case 9: modify_book();break;
              case 10: delete_book();break;
             case 11: display_bnos();break;
             case 12:return;
              default:cout<<"\a";
       }
       admin_menu();
   }

}


//***************************************************************
//        THE MAIN FUNCTION OF PROGRAM
//****************************************************************


int main()
{
    char ch;
    int i=0;
    string user, password;
    intro();
    do
    {
        system("cls");
        cout<<"\n\n\n\tMAIN MENU";
        cout<<"\n\n\t 1. BOOK ISSUE";
        cout<<"\n\n\t 2. BOOK DEPOSIT";
        cout<<"\n\n\t 3. ADMINISTRATOR MENU";
        cout<<"\n\n\t 4. EXIT";
        cout<<"\n\n\tPlease Select Your Option (1-4) ";
          ch=getche();
          switch(ch)
          {
            case '1':system("cls");
                 book_issue();
                    break;
              case '2':book_deposit();
                     break;
              case '3':
                 system("cls");
                 if(i>0)
                 {
                   cin.ignore();
                 }
                 else{i++;}
                    cout<<"\n\n\tENTER YOUR USER NAME : ";
                    getline(cin,user);
                    cout<<"\n\n\tENTER YOUR PASSWORD   : ";
                    getline(cin,password);
                    system("cls");
                    if(user=="admin"&&password=="admin")
                      admin_menu();
                    else
                      cout<<" \n\n\n\t WRONG USER NAME OR PASSWORD\n\n\t";
                    getch();
                    break;

              case '4':
                  exit(0);

              default :cout<<"\a";
        }
        }while(ch!='4');
}

//***************************************************************
//                END OF PROJECT
//***************************************************************
