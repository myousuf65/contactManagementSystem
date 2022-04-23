#ifndef contactManager_h
#define contactManager_h

#include <stdio.h>
#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;

class contactManager{
    
private:

    vector<string> BigOne;
    
    string _firstName;
    string _lastName;
    string _contactNumber;
    string _email;

public:
    
//--------------methods-----------------
    void addContact(){
        cout<<"Please Input firstName....";
        
        cin>>_firstName;
        transform(_firstName.begin(), _firstName.end(), _firstName.begin(), ::toupper);
        cout<<"\nPlease input lastName....";
        
        cin>>_lastName;
        transform(_lastName.begin(), _lastName.end(), _lastName.begin(), ::toupper);
        cout<<"\nPlease input the contactNumber....";
        
        cin>>_contactNumber;
        transform(_contactNumber.begin(), _contactNumber.end(), _contactNumber.begin(), ::toupper);
        cout<<"\nPlease input the email....";
        
        cin>>_email;
        transform(_email.begin(), _email.end(), _email.begin(), ::toupper);
        cout<<"\n.....Contact has been added....."<<endl;
    
        
        fstream myFile;
        myFile.open("contacts.txt", ios::app);
        if(myFile.is_open()){
            myFile<<_firstName<<" "<<_lastName<<" "<<_contactNumber<<" "<<_email<<endl;
            }
        
    }
    
    void deleteContact(){
        vector<string> deletion;
        
        string input;
        cout<<"Please input a keyword....";
        cin>>input;
        transform(input.begin(), input.end(), input.begin(), ::toupper);
        
        fstream myFile;
        myFile.open("contacts.txt", ios::in);
        if(myFile.is_open()){
            
            string line;
            while (!myFile.eof()) {
              
                getline(myFile, line);
                deletion.push_back(line);
                
            }myFile.close();
        }
        

        for(int i = 0; i<deletion.size();i++){
            stringstream str(deletion[i]);
            string word;
            while (str >> word) {
                if(input == word){
                    cout<<"Contact details are listed:"<<endl;
                    cout<<"================================="<<endl;
                    cout<<deletion[i]<<endl;
                    deletion.erase(deletion.begin()+i);

                    myFile.open("contacts.txt", ios::out);
                    if(myFile.is_open()){
                        for (int i = 0; i< (deletion.size()-1); i++) {
                            myFile<<deletion[i]<<endl;
                        }
                    }
                }
            }
        
        }cout<<"....Contact has been deleted....."<<endl;
        
    }
    
    void updateContact(){
        vector<string> updatingVec;
        
        fstream myFile;
        myFile.open("contacts.txt", ios::in);
        if(myFile.is_open()){
            
            string line;
            while (!myFile.eof()) {
              
                getline(myFile, line);
                updatingVec.push_back(line);
                
            }myFile.close();
        }
       
    //----------
        string input;
        cout<<"Please input any keyword....";
        cin>>input;
        transform(input.begin(), input.end(), input.begin(), ::toupper);
        
        for(int i = 0; i<updatingVec.size();i++){
            stringstream str(updatingVec[i]);
            string word;
            while (str >> word) {
                if(input == word){
                    cout<<"\nContact details are listed:"<<endl;
                    cout<<"================================="<<endl;
                    cout<<updatingVec[i]<<endl;
                    
                    cout<<"Please Input firstName....";
                    cin>>_firstName;
                    transform(_firstName.begin(), _firstName.end(), _firstName.begin(), ::toupper);
                    
                    cout<<"\nPlease input lastName....";
                    cin>>_lastName;
                    transform(_lastName.begin(), _lastName.end(), _lastName.begin(), ::toupper);
                    
                    cout<<"\nPlease input the contactNumber....";
                    cin>>_contactNumber;
                    transform(_contactNumber.begin(), _contactNumber.end(), _contactNumber.begin(), ::toupper);
                    
                    cout<<"\nPlease input the email....";
                    cin>>_email;
                    transform(_email.begin(), _email.end(), _email.begin(), ::toupper);
                    
                    updatingVec[i] = _firstName+" "+_lastName+" "+_contactNumber+" "+_email;
                    
                    cout<<"\nUpdated profile: "<<endl;
                    cout<<updatingVec[i]<<endl;
                    
                    //storing data back to the txt file
                    fstream myFile;
                    myFile.open("contacts.txt", ios::out);
                    if(myFile.is_open()){
                        for (int i = 0; i< (updatingVec.size()-1); i++) {
                            myFile<<updatingVec[i]<<endl;
                        }
                    cout<<"\n.....Contact has been updated....."<<endl;
                        break;
                        
                    }
                    
                }}
            
            }
        //erase all data
        for(int i = 0; i <updatingVec.size();i++){
            updatingVec.erase(updatingVec.begin()+i);
        }

    }
    void searchContact(){
        vector<string> searchingVec;
        
        string input;
        cout<<"Please input any keyword....";
        cin>>input;
        transform(input.begin(), input.end(), input.begin(), ::toupper);
        
        fstream myFile;
        myFile.open("contacts.txt", ios::in ); //read-only mode
        if(myFile.is_open()){
            
            string line;
            while (!myFile.eof()) {
              
                //get data, store it in BigOne vector
                getline(myFile, line);
                searchingVec.push_back(line);
                
            }
        }

        //scan the array for relative data
        for(int i = 0; i<searchingVec.size();i++){
            stringstream str(searchingVec[i]);
            string word;
            while (str >> word) {
                
                if(input == word){
                    cout<<searchingVec[i]<<endl;
                }
            }
        }
        
        //empty the vector from all values
        for (int i = 0; i< searchingVec.size(); i++) {
            searchingVec.erase(searchingVec.begin()+i);
        }
    }
    
    
    void printAllContacts(){
        
        fstream myFile;
        myFile.open("contacts.txt", ios::in );//read
        if(myFile.is_open()){
            
            string line;
            while (getline(myFile, line)) {
                cout<< line <<endl;
                
            }myFile.close();
            
        }
    
        }
    


};

#endif /* contactManager_h */
