#include <iostream>
#include "clsLogin_Registration_System.h"
#include "Support/clsInputValidate.h"

using namespace std ;

enum enMainChoice {eLogin = 1 , eSign_Up = 2 , eForget_Password = 3 , eExit = 4} ;
enum enWayChoice {Email = 1 , Username = 2} ;

void ReadUserInformation(clsLogin_Registration_System &User) {

    User.SetFirstName(clsInputValidate::ReadString("\nEnter FirstName : ")) ;
    User.SetLastName(clsInputValidate::ReadString("\nEnter LastName : ")) ;
    User.SetEmail(clsInputValidate::ReadString("\nEnter Email : ")) ;
    User.SetPhone(clsInputValidate::ReadString("\nEnter Phone : ")) ;
    User.SetUsername(clsInputValidate::ReadString("\nEnter Username : ")) ;
    User.SetPassword(clsInputValidate::ReadString("\nEnter Password : ")) ;
}

bool Perform_Sign_Up_Screen() {

    clsLogin_Registration_System User = clsLogin_Registration_System::GetNewObject() ;

    ReadUserInformation(User) ;

    return User.Save() ;
}

void Sign_Up_ChoiceScreen() {

    cout << "==================<<" << "SIGN UP" << ">>=======================" << endl ;

    if (Perform_Sign_Up_Screen())
        cout << "\n...Your Information Was Add..." << endl ;
    else
        cout << "\n...Error Failed.. (We have already Informations Like this)." << endl ;
} 

bool LoginByEmail() {

    string Email = clsInputValidate::ReadString("Enter Your Email : ") ;
    string Password = clsInputValidate::ReadString("Enter Your Password : ") ;

    clsLogin_Registration_System Login = clsLogin_Registration_System::FindByEmail(Email , Password) ;
    return !(Login.IsEmpty()) ;
}

bool LoginByUsername() {

    string Username = clsInputValidate::ReadString("Enter Your Username : ") ;
    string Password = clsInputValidate::ReadString("Enter Your Password : ") ;

    clsLogin_Registration_System Login = clsLogin_Registration_System::FindByUsername(Username , Password) ;
    return !(Login.IsEmpty()) ;
}

bool PerformLoginScreen(enWayChoice Choice) {

    switch (Choice) {

        case enWayChoice::Email :
            return LoginByEmail() ;
            break;
        case enWayChoice::Username :
            return LoginByUsername() ;
            break;
    }
}

void LoginChoiceScreen() {

    cout << "==================<<" << "LOGIN" << ">>=======================" << endl ;

    cout << "With :\t\t\t" << "[1] Email or [2] Username" << endl ;

    if (PerformLoginScreen((enWayChoice)clsInputValidate::ReadNumberBetweenWithValidation <short> (1 , 2 ,
    "Enter Your Choice : " , "Invalid Choice, Chose a Number From 1 to 2 : ")))
        cout << "...Success Login...\n" << "\nWelcome Back To Your Account!" << endl ;
    else
        cout << "...Failed Login...\n" << "\nInccorect Information" << endl ;


}

bool ByEmail() {

    clsLogin_Registration_System Login = clsLogin_Registration_System::_GetEmptyObject() ;

    do {

        string Email = clsInputValidate::ReadString("\nEnter Your Email : ") ;
        Login = clsLogin_Registration_System::FindByEmail(Email) ;

    } while (Login.IsEmpty()) ;

    string Password = clsInputValidate::ReadString("Enter Your New Password : ") ;
    Login.SetPassword(Password) ;

    return Login.Save() ;

}

bool ByUsername() {

    clsLogin_Registration_System Login = clsLogin_Registration_System::_GetEmptyObject() ;

    do {

        string Username = clsInputValidate::ReadString("\nEnter Your Username : ") ;
        Login = clsLogin_Registration_System::FindByEmail(Username) ;

    } while (Login.IsEmpty()) ;

    string Password = clsInputValidate::ReadString("Enter Your New Password : ") ;
    Login.SetPassword(Password) ;

    return Login.Save() ;

}

bool PerformForget_Password_Screen(enWayChoice Choice) {

    switch (Choice) {

        case enWayChoice::Email :
            return ByEmail() ;
            break;
        case enWayChoice::Username :
            return ByUsername() ;
            break;
    }
}

void Forget_Password_Screen() {

    cout << "==================<<" << "UPDATE PASSWORD" << ">>=======================" << endl ;

    cout << "With :\t\t\t" << "[1] Email or [2] Username" << endl ;

    if (PerformForget_Password_Screen((enWayChoice)clsInputValidate::ReadNumberBetweenWithValidation 
    <short> (1 , 2 ,"Enter Your Choice : " , "Invalid Choice, Chose a Number From 1 to 2 : ")))
        cout << "...Success Updated...\n" << "\nWelcome Back To Your Account!" << endl ;
    else
        cout << "...Failed LUpdated...\n" << "\nPlease Try Again Later!" << endl ;
}

void Perform(enMainChoice Choice) {

    switch (Choice) {

        case enMainChoice::eLogin :
            LoginChoiceScreen() ;
            break;
        case enMainChoice::eSign_Up :
            Sign_Up_ChoiceScreen() ;
            break;
        case enMainChoice::eForget_Password :
            Forget_Password_Screen() ;
            break;
        case enMainChoice::eExit :
            break;
    }
}

int main() {

    system("cls") ;

    cout << "1 - Login" << endl ;
    cout << "2 - Sign-Up" << endl ;
    cout << "3 - Forget Password" << endl ;
    cout << "4 - Exit" << endl ; 
    cout << "-------------------------------------------------" << endl ;

    Perform((enMainChoice)clsInputValidate::ReadNumberBetweenWithValidation <short> (1 , 4 ,
    "Enter Your Choice : " , "Invalid Choice, Chose a Number From 1 to 4 : ")) ;
    
    
    
    
    return 0 ;
}