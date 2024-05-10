#include<iostream>
#include<fstream>
#include<string>
using namespace std;
struct student
{
    int roll;
    string name;
    string div;
    string address;
};
void addstudent(){
    ofstream outf;
    student s;
    outf.open("Student",ios::app);
    cout<<"ENter your name :";
    cin>>s.name;
    cout<<"Enter you roll no. :";
    cin>>s.roll;
    cout<<"Enter your division :";
    cin>>s.div;
    cin.ignore();
    cout<<"Entre your address : ";
    getline(cin,s.address);
    outf.write((char*)(&s),sizeof(student));
    outf.close();
}
void display(int roll){
    int flag = 0;
    ifstream fin;
    fin.open("Student");
    student s;
    while(fin){
        fin.read((char*)(&s),sizeof(student));
        if(roll == s.roll){
            cout<<"Data is found "<<endl;
            cout<<"Name is :"<<s.name<<endl;
            cout<<"Roll no is : "<<s.roll<<endl;
            cout<<"Division is"<<s.div<<endl;
            cout<<"Address is :"<<s.address<<endl;
            flag = 1;
            break;
        }
    }
    fin.close();
     if(flag == 0){
        cout<<"Roll is not present Bhai dusra number search kr!!!"<<endl;
    }
}
void deleteStudent(int roll){
    student s;
    ifstream fin;
    ofstream outf;
    fin.open("Student");
    outf.open("temp");
    while(fin){
        fin.read((char*)(&s),sizeof(student));
        if(roll != s.roll){
            outf.write((char*)(&s),sizeof(student));
        }
    }
    fin.close();
    outf.close();

    remove("Student");
    rename("temp","Student");
}
int main(){
    int ch;
    while(1){
        cout<<"---------MENU---------"<<endl;
        cout<<"Enter 1 for addstudent :"<<endl;
        cout<<"Entre 2 for search :"<<endl;
        cout<<"Enter 3 for delete : "<<endl;
        cout<<"Enter your choice :";
        cin>>ch;
        switch (ch)
        {
        case 1:    
            addstudent();
            break;
        
        case 2:
            int roll;
            cout<<"Enter roll do you want to search :";
            cin>>roll;
            display(roll);
            break;
        
        case 3:
            int roll2;
            cout<<"Enter roll do you want to delete :";
            cin>>roll2;
            deleteStudent(roll2);
            break;
        
        default:
            cout<<"Invalid choice re-enter again"<<endl;
            break;
        }
    }

    return 0;
}