#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "SupportOfClass/clsPerson.h"
#include "Support/clsString.h"
#include "Support/clsUtility.h"

using namespace std ;

class clsLogin_Registration_System : public clsPerson {

private :

    enum enMode {eEmpty = 0 , eUpdate = 1 , eNew = 2} ;

    string _Password ;
    string _Username ;
    enMode _Mode ;

    static string _RecordToString(clsLogin_Registration_System User , string limit = "#//#") {

        return User.FirstName() + limit + User.LastName() + limit + User.Email() + limit + User.Phone() +
        limit + clsUtility::EncryptionText(User.Password() , 7) + limit + User.Username() ;
    }

    static clsLogin_Registration_System _LineToRecord(string Line) {

        vector <string> vString = clsString::Split(Line , "#//#") ;

        return clsLogin_Registration_System(enMode::eUpdate , vString[0] , vString[1] , vString[2] ,
        vString[3] , clsUtility::DecryptionText(vString[4] , 7) , vString[5]) ;
    }

    static void _AddLineToFile(string Line) {

        fstream MyFile ;

        MyFile.open("UserInformation.txt" , ios::out | ios::app) ;

        if (MyFile.is_open()) {


            MyFile << Line << endl ;

        }

        MyFile.close() ;
    }

    static vector <clsLogin_Registration_System> _LoadDateFromFile() {

        vector <clsLogin_Registration_System> vUsers ;

        fstream MyFile ;

        MyFile.open("UserInformation.txt" , ios::in) ;

        if (MyFile.is_open()) {

            string Line ;

            while (getline(MyFile , Line)) {

                clsLogin_Registration_System User = _LineToRecord(Line) ;

                vUsers.push_back(User) ;
            }

            MyFile.close() ;
        }

        return vUsers ;
    }

    static void _SaveDateInFile(vector <clsLogin_Registration_System> vUsers) {

        fstream MyFile ;

        MyFile.open("UserInformation.txt" , ios::out) ;

        if (MyFile.is_open()) {

            string Line ;

            for (clsLogin_Registration_System &U : vUsers) {

                Line = _RecordToString(U) ;
                
                MyFile << Line << endl ;
            }

            MyFile.close() ;
        }
    }

    void _AddNew() {

        _AddLineToFile(_RecordToString(*this)) ;
    }

    void _Update() {

        vector <clsLogin_Registration_System> vUser = _LoadDateFromFile() ;

        for (clsLogin_Registration_System &U : vUser) {

            if (U.Email() == Email()) {

                U = *this ;
                break;
            }
        }

        _SaveDateInFile(vUser) ;
    }

public :

    clsLogin_Registration_System(enMode Mode , string FirstName , string LastName , string Email , string Phone ,
    string Password , string Username) : clsPerson(FirstName , LastName , Email , Phone) {

        _Mode = Mode ;
        _Password = Password ;
        _Username = Username ;

    }

    void SetPassword (string Password) {

        _Password = Password ;
    }

    string Password() {

        return _Password ;
    }

    void SetUsername(string Username) {

        _Username = Username ;
    }

    string Username() {

        return _Username ;
    }

    bool IsEmpty() {

        return _Mode == enMode::eEmpty ;
    }

    static clsLogin_Registration_System _GetEmptyObject() {

        return clsLogin_Registration_System(enMode::eEmpty , "" , "" , "" ,
        "" , "" , "") ;
    }

    static clsLogin_Registration_System FindByEmail(string Email) {

        fstream MyFile ;

        MyFile.open("UserInformation.txt" , ios::in) ;

        if (MyFile.is_open()) {
            
            string Line ;

            while (getline(MyFile , Line)) {

                clsLogin_Registration_System Search = _LineToRecord(Line) ;

                if (Search.Email() == Email) {

                    MyFile.close() ;
                    return Search ;
                }
            }

            MyFile.close() ;
        }

        return _GetEmptyObject() ;


    }

    static clsLogin_Registration_System FindByEmail(string Email , string Password) {

        fstream MyFile ;

        MyFile.open("UserInformation.txt" , ios::in) ;

        if (MyFile.is_open()) {
            
            string Line ;

            while (getline(MyFile , Line)) {

                clsLogin_Registration_System Search = _LineToRecord(Line) ;

                if (Search.Email() == Email && Search.Password() == Password) {

                    MyFile.close() ;
                    return Search ;
                }
            }

            MyFile.close() ;
        }

        return _GetEmptyObject() ;


    }

    static clsLogin_Registration_System FindByUsername(string Username) {

        fstream MyFile ;

        MyFile.open("UserInformation.txt" , ios::in) ;

        if (MyFile.is_open()) {

            string Line ;

            while (getline(MyFile , Line)) {

                clsLogin_Registration_System Search = _LineToRecord(Line) ;

                if (Search.Username() == Username) {

                    MyFile.close() ;
                    return Search ;
                }
            }

            MyFile.close() ;
        }

        return _GetEmptyObject() ;


    }

    static clsLogin_Registration_System FindByUsername(string Username , string Password) {

        fstream MyFile ;

        MyFile.open("UserInformation.txt" , ios::in) ;

        if (MyFile.is_open()) {

            string Line ;

            while (getline(MyFile , Line)) {

                clsLogin_Registration_System Search = _LineToRecord(Line) ;

                if (Search.Username() == Username && Search.Password() == Password) {

                    MyFile.close() ;
                    return Search ;
                }
            }

            MyFile.close() ;
        }

        return _GetEmptyObject() ;


    }

    static clsLogin_Registration_System GetNewObject() {

        return clsLogin_Registration_System(enMode::eNew , "" , "" , "" ,
        "" , "" , "") ;
    }

    static bool IsUserExists(string Email , string Username) {

        fstream MyFile ;

        MyFile.open("UserInformation.txt" , ios::in) ;

        if (MyFile.is_open()) {

            string Line ;

            while (getline(MyFile , Line)) {

                clsLogin_Registration_System Search = _LineToRecord(Line) ;

                if (Search.Username() == Username || Search.Email() == Email) {

                    MyFile.close() ;
                    return true ;
                }
            }

            MyFile.close() ;
        }

        return false ;
    }

    bool Save() {

        switch (_Mode) {

            case enMode::eEmpty :
                return false ;
                break;
            case enMode::eUpdate :
                _Update() ;
                break ;
            case enMode::eNew :
                if (IsUserExists(Email() , Username()))
                    return false ;
                else {
                    _AddNew() ;
                    _Mode = enMode::eUpdate ;
                }
                break;

        }

        return true ;
    }

} ;