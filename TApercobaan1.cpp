#include<iostream>
#include<string>
#include<conio.h>
#include<stdlib.h>

using namespace std;

int main();
void show_data(int searchkey);     //fungsi menampilkan murid
void get_data(int i);           //function used to obtain data from end-user. //fungsi mendapatkan data murid
void search_student(int searchkey);
void add_student();      //fungsi menambah murid
void edit_student(int idnumber);   //fungsi untuk mengedit data murid
void fullscreen();
int ts; //total student

struct data    //struct untuk menyimpan data murid
{ 
  int npm;
  int semester;
  string nama;
  string kelas;
  string fkp;
  string ttl;
  string alamat;
  string hp;
};

data mhs[50];  //This is basic array of defined structure to store data.
int main()
{
  system("CLS");
  system("color 80");
  int choice;   //int variable used to determine which operation user want to do.
  int idnumber;   //int variable used to record ID number whih user want to edit.
  int searchkey;  //int variable to store student roll_no by which user can search.

  cout<<"Manajemen Data Mahasiswa Pakuan\n";
  cout<<"Enter The Total Number of Student(s)- Max 50: ";
  cin>>ts;

 while(ts--)
 {
  cout<<"\n\t\tWhat do you want to do?"<<endl;
  cout<<"\t\t----------------------"<<endl;
  cout<<"\t\t1-Add student"<<endl;
  cout<<"\t\t2-Edit student"<<endl;
  cout<<"\t\t3-Search student"<<endl;
  cout<<"\t\t4-Quit Program"<<endl;
  cout<<"\t\t----------------------"<<endl;
  cout<<"Enter your choice: ";

  cin>>choice;
  switch(choice)
 {
   case 1:         //If user presses 1 then student adding module would be displayed.
    add_student();
    break;
   case 2:         //If there are no records in array then it will ask the user to input records first.
    if(mhs[0].npm==0)
   {
     cout<<"Please Add sudents first."<<endl;
     system("pause");
    main();
   }
    else         //If records are present in array then it will show table.
   { 
     cout<<endl;
     cout<<"--------------------------------------------------------------------------------"<<endl;
     cout<<"---------------------------Student record Table---------------------------------"<<endl;
     cout<<"--------------------------------------------------------------------------------"<<endl; 
     cout<<"ID\t "<<"Npm\t "<<"Nama\t "<<"Kelas\t "<<"Fakultas/Prodi\t "<<"TTL\t "<<"Alamat\t "<<"No HP\n\n";
     cout<<"--------------------------------------------------------------------------------"<<endl; 

     for(int i=0;i<=ts;i++)
    {
      show_data(i);     //funtion is called with index value to show data.
     }

     cout<<"--------------------------------------------------------------------------------"<<endl;
     cout<<"Which ID number your want to edit: ";
   
     cin>>idnumber;            //Asking the user at which ID he wants to make a change.
       
    if(idnumber>ts || idnumber<0)  //Validating the ID number.
    {      
          cout<<"\nInvalid ID Number."<<endl;
       }
       else
    {
          edit_student(idnumber);    //Passing ID number to Edit Function.
       }
   }
   break;
   
  case 3:
    if(mhs[0].npm==0)     //If no record exist then ask the user o enter records first.
   {   
     cout<<"Please Add sudents first."<<endl;
     system("pause");
     main();         //Return to main so user can input new record.
    }
    else
   {
     cout<<"Enter roll_no of student you want to search: ";
     cin>>searchkey;     //roll_no as the search key can be entered by user.
     search_student(searchkey);}
     break;
   case 4:
    return 0;        //Terminating the records.
    break;
   default:         //Default value for ivalid Input. 
    cout<<"Invalid number."<<endl;
    system("pause");
  main();
  }
 }
  return 0;
}

  
void get_data(int i)        //fungsi untuk menerima dan menambah data mahasiswa
{   
  cout<<"Masukkan NPM Mahasiswa: ";
  cin>>mhs[i].npm;
  cin.ignore();
  cout<<"Masukkan Nama Mahasiswa: ";
  getline(cin,(mhs[i].nama));
  cout<<"Masukkan Kelas Mahasiswa: ";
  cin>>mhs[i].kelas;
  cin.ignore();
  cout<<"Masukkan Fakultas dan Prodi Mahasiswa(Fakultas/Prodi): "; //e.g FMIPA/Ilmu Komputer
  getline(cin,(mhs[i].fkp));
  cout<<"Masukkan TTL Mahasiswa(dd/mm/yyyy-tempat): ";
  cin>>mhs[i].ttl;
  cin.ignore();
  cout<<"Masukkan Alamat Mahasiswa: ";
  getline(cin,(mhs[i].alamat));
  cout<<"Masukkan No HP Mahasiswa: ";
  cin>>mhs[i].hp;
}

void show_data(int searchkey)      //Function for showing data on the screen.
{    
  int i=searchkey;
  cout<<i<<"    ";
  cout<<mhs[i].npm<<"\t";
  cout<<mhs[i].nama<<"\t";
  cout<<mhs[i].kelas<<"\t";
  cout<<mhs[i].fkp<<"\t";
  cout<<mhs[i].ttl<<"\t";
  cout<<mhs[i].alamat<<"\t";
  cout<<mhs[i].hp<<"\n\n";
}

void search_student(int searchkey)
{
  for(int i=0;i<=ts;i++)       //Loop thrugh complete array.
 { 
   if(mhs[i].npm==searchkey)    //If roll number matches to search term.
  {   
    cout<<"ID\t "<<"Npm\t "<<"Nama\t "<<"Kelas\t "<<"Fakultas/Prodi\t "<<"TTL\t "<<"Alamat\t "<<"No HP\n\n";
    show_data(i);       //A function is used inside another function.
   }
  } 
}

void add_student()         //This function is used to add record of new student.
{    
  for(int i=0;i<=ts;i++)
 {
    get_data(i);          //Loop was processed 5 times to get input for 5 students.
  }
  system("CLS");
  cout<<endl;

  cout<<"--------------------------------------------------------------------------------"<<endl;
  cout<<"---------------------------Student record Table---------------------------------"<<endl;
  cout<<"--------------------------------------------------------------------------------"<<endl;
  cout<<"ID\t "<<"Npm\t "<<"Nama\t "<<"Kelas\t "<<"Fakultas/Prodi\t "<<"TTL\t "<<"Alamat\t "<<"No HP\n\n";
  cout<<"--------------------------------------------------------------------------------"<<endl;

  for(int i=0;i<=ts;i++)
 {
    show_data(i);        //Loop was processed for 5 times to show obtained records.
  }
  cout<<"--------------------------------------------------------------------------------"<<endl;
  cout<<"---------------------------------FINISH-----------------------------------------"<<endl;
  cout<<"--------------------------------------------------------------------------------"<<endl;
  system("pause");

  main();          //Return to main function to again show menu.
}

void edit_student(int idnumber)     //function is used to edit existing record.
{  
  for(int i=0;i<=ts;i++)       //Loop is started.
 {  
   if(idnumber==i)       //Through loop every value is compared with search term.
  {         
    cout<<"\nExisted information about this record.\n\n";
    cout<<"--------------------------------------------------------------------------------"<<endl;
    cout<<"ID\t "<<"Npm\t "<<"Nama\t "<<"Kelas\t "<<"Fakultas/Prodi\t "<<"TTL\t "<<"Alamat\t "<<"No HP\n\n";
    cout<<"--------------------------------------------------------------------------------"<<endl;
    show_data(i);       //Load information for existing record.
    cout<<"\n\nEnter new data for above shown record.\n\n";
    get_data(i);         //Inputing data for that specific record.
    cout<<"\n\nRecord updated successfully."<<endl;
    system("pause");
    main();           //Return to main function.
   }
  }
}