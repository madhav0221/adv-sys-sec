#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
using namespace std;

int main(){
    int a, i=0;
    string text, old, password1, password2, pass, name, password0, age,mo,email, user, word, word1;
    string creds[2], cp[2];
    cout<< "      Security System"<<endl;
    cout<<"_______________________________"<<endl;
    cout<<"|         1.Register           |"<<endl;
    cout<<"|         2.Login              |"<<endl;
    cout<<"|         3.Change Password    |"<<endl;
    cout<<"|_________4.End Program________|"<<endl<<endl;

    do{
        cout<<endl<<endl<<"Enter your choice:-";
        cin>>a;
        switch (a)
          {
             case 1: {
                      cout<<"________________________"<<endl;
                      cout<<"|-------Register--------|"<<endl;
                      cout<<"|_______________________|"<<endl<<endl;
                      cout<<"Please enter username:-";
                      cin>> name;
                      cout<<"Please enter the password:-";
                      cin>>password0;
                      cout<<"please enter your age:-";
                      cin>>age;
                      cout<<"please enter your mobile number:-";
                      cin>>mo;
                      cout<<"please enter your email id:-";
                      cin>>email;

                      ofstream of1;
                      of1.open("file.txt");
                      if(of1.is_open())
                      {
                        of1<<name<<"\n";
                        of1<<password0;
                        cout<<"Registration successful"<<endl;
                      }

                     break;
                     }
              case 2: {
                i=0;
                cout<<"________________________"<<endl;
                cout<<"|--------Login----------|"<<endl;
                cout<<"|_______________________|"<<endl<<endl;
                ifstream of2;
                of2.open("file.txt");
                cout<<"Please enter the username:-";
                cin>> user;
                cout<<"Please enter the password:-";
                cin>>pass;

                     if(of2.is_open())
                    {
                      while(!of2.eof())
                      {
                        while(getline(of2,text)){
                         istringstream iss(text);
                           iss>>word;
                           creds[i]=word;
                           i++;  
                        }
                        if(user==creds[0]&& pass==creds[1])
                        {
                            cout<<"---Log in successful---"<<endl<<endl;
                            cout<<"Details:"<<endl;
                            cout<<"Username:"+ name<<endl;
                            cout<<"Password:"+ pass<<endl;
                            cout<<"Age:" +age<<endl;
                            cout<<"Mobile number:" +mo<<endl;
                            cout<<"Email:" + email<< endl;
                        }
                        else
                        {
                            cout<<endl<<endl<<"Incorrect Credentials"<<endl;
                            cout<<"        1.Press 2 to login        "<<endl;
                            cout<<"        2.Press 3 to change password   "<<endl;
                            break;
                        }
                     }
                    }
                     break;
            }
            case 3:{
                i=0;
                cout<<"-------Change password-------"<<endl;
                
                ifstream of0;
                of0.open("file.txt");
                cout<<"   Enter the old password:-  ";
                cin>>old;
                if(of0.is_open())
                {
                        while(getline(of0,text)){
                         istringstream iss(text);
                           iss>>word1;
                           cp[i]=word1;
                           i++;  
                        }
                        if(old==cp[1]){
                            of0.close();
                            ofstream of1;
                            of1.open("file.txt");
                            if(of1.is_open())
                            {
                            cout<<"Enter your new password:-";
                            cin>>password1;
                            cout<<"Enter your password again:-";
                            cin>>password2;

                            if (password1==password2)
                            {
                                of1<<cp[0]<<"\n";
                                of1<<password1;
                                cout<<"Password changed successfully"<<endl;
                            }
                            else
                            {
                                of1<<cp[0]<<"\n";
                                of1<<old;
                                cout<<"Passwords do not match"<<endl;
                            }
                            }
                        }
                        else
                        {
                           cout<<" Please enter the valid password"<<endl;
                           break;
                        }
            }
            break;
            }
            case 4: 
            {
                cout<<  " Thank You!";
                break;
            }
        default:
        cout<<"Enter a valid input";
            break;
        }
    }
    while(a!=4);
    return 0;
}