#include <iostream>
#include <fstream>
#include "Instruction.h"
#include "contactManager.h"

using namespace std;

int main() {
    
    //initialize a variable under which to perform actions below.
    contactManager a1;
    
    char user_input;
    
    do{
        instruction();
        cin>>user_input;
        
        switch (user_input){
            case '1':
                a1.addContact();
                break;
            case '2':
                a1.deleteContact();
                break;
            case '3':
                a1.updateContact();
                break;
            case '4':
                a1.printAllContacts();
                break;
            case '5':
                a1.searchContact();
                break;
            case '6':
                cout<<"Thank you for your time!\n";
                exit(0);
            default:
                cout<<"Invalid Command..... Please Try Again\n";
        }
        
    }while( user_input != '6');
    
    
    return 0;
}
