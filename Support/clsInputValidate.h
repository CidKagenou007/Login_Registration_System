#pragma once

#include <iostream>
#include <limits>
#include "clsDate.h"

using namespace std ;

class clsInputValidate {

public :

    template <typename T> static ReadNumber(string message) {

        T Num ;

        cout << message ;
        cin >> Num ;

        return Num ;
    }

    static string ReadString(string message) {

        string S ;

        cout << message ;
        getline(cin >> ws , S) ;

        return S ;
    }

    static char ReadCharacter(string message) {

        char C ;

        cout << message ;
        cin >> C ;

        return C ;
    }


    template <typename T> static ReadNumberWithValidation(string message1 , string message2 = "") {

        T Num = ReadNumber <T> (message1) ;

        while (cin.fail()) {

            cin.clear() ;
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n') ;

            Num = ReadNumber <T> (message2) ;
        }

        return Num ;

    }

    template <typename T> static ReadNumberBetween(T From ,
    T To , string message1 , string message2 = "") {

        T Number = ReadNumber <T> (message1) ;

        while (!IsNumberBetween <T> (Number , From , To)) {

            Number = ReadNumber <T> (message2) ;
        }

        return Number ;
    }

    template <typename T> static ReadPositiveNumber(string message) {

        T Num ;

        do {

            cout << message ;
            cin >> Num ;

        } while (Num < 0) ;

        return Num ;

    }

    template <typename T> static ReadPositiveNumberWithValidation(string message1 , string message2 = "") {

		T Number = ReadNumberWithValidation <T> (message1 , message2) ;

		while (Number < 0) 
		{
			cout << message2 ;
			Number = ReadNumberWithValidation <T> ("") ;
		}
		return Number;
	}

    template <typename T> static ReadNegativeNumber(string message) {

        T Num ;

        do {

            cout << message ;
            cin >> Num ;

        } while (Num > 0) ;

        return Num ;
    }

    template <typename T> static ReadNumberUpperThan(T Number , string message) {

        T Num ;

        do {

            cout << message ;
            cin >> Num ;

        } while (Num < Number) ;

        return Num ;
    }

    template <typename T> static ReadNumberLowerThan(T Number , string message) {

        T Num ;

        do {

            cout << message ;
            cin >> Num ;

        } while (Num > Number) ;

        return Num ;
    }

    template <typename T> static void ReadArray(T M[] , short arrLength) {

        for (short i = 0 ; i < arrLength ; i++)
            cin >> M[i] ;
        
        cout << endl ;
    }

    template <typename T> static bool IsNumberBetween(T Number , T From , T To) {

        return (Number >= From && Number <= To) ;
    }

    static bool IsDateBetween(clsDate Date, clsDate From, clsDate To) {
		//Date>=From && Date<=To
		if ((clsDate::IsDate1AfterDate2(Date, From) || clsDate::IsDate1EqualToDate2(Date, From)) 
			&&
			(clsDate::IsDate1BeforeDate2(Date, To) || clsDate::IsDate1EqualToDate2(Date, To))
		  )
			return true ;
		
		if ((clsDate::IsDate1AfterDate2(Date, To) || clsDate::IsDate1EqualToDate2(Date, To)) 
			&&
			(clsDate::IsDate1BeforeDate2(Date, From) || clsDate::IsDate1EqualToDate2(Date, From))
		   )
			
            return true ;
		

		return false;
	}

    bool IsValidDate(clsDate Date) {

        return clsDate::IsValidDate(Date) ;
    }

    template <typename T> static ReadNumberBetweenWithValidation(T From ,
    T To , string message1 , string message2 = "") {

		T Number = ReadNumberWithValidation <T> (message1 , message2) ;

		while (!IsNumberBetween <T> (Number, From,To)) 
		{
			cout << message2 ;
			Number = ReadNumberWithValidation <T> ("") ;
		}
		return Number;
	}

    static bool IsEven(int Number) {

        return Number % 2 == 0 ;
    }

    static bool IsOdd(int Number) {

        return Number % 2 != 0 ;
    }
} ;