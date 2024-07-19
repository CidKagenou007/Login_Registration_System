#pragma once

#include <iostream>
#include <string>
#include <cctype>
#include <vector>

using namespace std ;

class clsString {

private :

    string _Value ;

public :

    clsString() {

        _Value = "" ;
    }

    clsString(string Value) {

        _Value = Value ;
    }

    void SetValue(string Value) {

        _Value = Value ;
    }

    string Value() {

        return _Value ;
    }

    static short CountWords(string s) {

        string limit = " " ;
        short pos = 0 ;
        short counter = 0 ;
        string sWord ;

        while ((pos = s.find(limit)) != string::npos) {

            sWord = s.substr(0 , pos) ;

            if (sWord != "")
                counter++ ;
            
            s.erase(0 , pos + limit.length()) ;
        }

        if (s != "")
            counter++ ;
        
        return counter++ ;
    }

    short CountWords() {

        return CountWords(_Value) ;
    }

    static void FirstLetters(string Word) {

        bool isFirstLetter = true ;

        cout << "\nFirst letters of \" " << Word << " \" are :" << endl ;

        for (short i = 0 ; i < Word.length() ; i++) {

            if (Word[i] != ' ' && isFirstLetter)
                cout << Word[i] << "\t" ;
        
            isFirstLetter = (Word[i] == ' ' ? true : false) ;
        }

        cout << endl ;
    }

    void FirstLetters() {

        FirstLetters(_Value) ;
    }

    static string UpperFirstLetterOfEachWord(string S) {

        bool IsFirstLetter = true ;

        for (short i = 0 ; i < S.length() ; i++) {

            if (S[i] != ' ' && IsFirstLetter)
                S[i] = toupper(S[i]) ;

            IsFirstLetter = (S[i] == ' ' ? true : false) ;
        }

        return S ;
    }

    void UpperFirstLetterOfEachWord() {

        _Value = UpperFirstLetterOfEachWord(_Value) ;
    }

    static string LowerFirstLetterOfEachWord(string S) {

        bool IsFirstLetter = true ;

        for (short i = 0 ; i < S.length() ; i++) {

            if (S[i] != ' ' && IsFirstLetter)
                S[i] = tolower(S[i]) ;

            IsFirstLetter = (S[i] == ' ' ? true : false) ;
        }

        return S ;
    }

    void LowerFirstLetterOfEachWord() {

        _Value = LowerFirstLetterOfEachWord(_Value) ;
    }

    static string UpperAllString(string s) {

        for (int i = 0 ; i < s.length() ; i++) {

            s[i] = toupper(s[i]) ;
        }

        return s ;
    }

    void UpperAllString() {

        _Value =  UpperAllString(_Value) ;
    }

    static string LowerAllString(string s) {

        for (int i = 0 ; i < s.length() ; i++) {

            s[i] = tolower(s[i]) ;
        }

        return s ;
    }

    void LowerAllString() {

        _Value = LowerAllString(_Value) ;
    }

    static char InvertCharacter(char c) {

        return isupper(c) ? tolower(c) : toupper(c) ;
    }

    static string InvertAllLetters(string Word) {

        for (short i = 0 ; i < Word.length() ; i++) {

            Word[i] = InvertCharacter(Word[i]) ;
        }

        return Word ;
    }

    void InvertAllLetters() {

        _Value = InvertAllLetters(_Value) ;
    }

    enum enWhatToCount { SmallLetters = 0, CapitalLetters = 1, All = 3 };

   static short CountLetters(string S1, enWhatToCount WhatToCount = enWhatToCount::All)
   {


       if (WhatToCount == enWhatToCount::All)
       {
           return S1.length();
       }

       short Counter = 0;

       for (short i = 0; i < S1.length(); i++)
       {

           if (WhatToCount == enWhatToCount::CapitalLetters && isupper(S1[i]))
               Counter++;


           if (WhatToCount == enWhatToCount::SmallLetters && islower(S1[i]))
               Counter++;


       }

       return Counter;

   }

    static short CapitalLettersCount(string S) {

        short counter = 0 ;

        for (short i = 0 ; i < S.length() ; i++) {

            if (isupper(S[i]))
                counter++ ;
        }

        return counter ;
    }

    short CapitalLettersCount() {

        return CapitalLettersCount(_Value) ;
    }

    short SmallLettersCount(string S) {

        short counter = 0 ;

        for (short i = 0 ; i < S.length() ; i++) {

            if (islower(S[i]))
                counter++ ;
        }

        return counter ;
    }

    short SmallLettersCount() {

        return SmallLettersCount(_Value) ;
    }

    static short CounterLetter(string s , char c , bool MatchCase = true) {

        short counter = 0 ;

        for (short i = 0 ; i < s.length() ; i++) {

            if (MatchCase) {

                if (s[i] == c)
                    counter++ ;
            }

            else {

                if (tolower(s[i]) == tolower(c))
                    counter++ ;
            }
        }

        return counter ;
    }

    short CounterLetter(char YourLetter , bool MatchCase = true) {

        return CounterLetter(_Value , YourLetter , MatchCase) ;
    }

    static bool IsVowel(char c) {

        c = tolower(c) ;

        return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') ;
    }

    static short CountVowelsInString(string s) {

        short counter = 0 ;

        for (short i = 0 ; i < s.length() ; i++) {

            if (IsVowel(s[i]))
                counter++ ;
        }

        return counter ;
    }

    short CountVowelsInString() {

        return CountVowelsInString(_Value) ;
    }

    static void PrintAllVowelsInString(string s) {

        cout << "\n Vowels in \" " << s << " \" are : " ;

        for (short i = 0 ; i < s.length() ; i++) {

            if (IsVowel(s[i]))
                cout << s[i] << "\t" ;
        }

        cout << endl ;
    }

    void PrintAllVowelsInString() {

        PrintAllVowelsInString(_Value) ;
    }

    static void PrintEachWordInString(string s) {

        string limit = " " ;
        string sWord ;

        cout << "\n The Words In \" " << s << " \" are : \n" << endl ;

        short pos = 0 ;

        while ((pos = s.find(limit)) != std::string::npos) {

            sWord = s.substr(0 , pos) ;

            if (sWord != "")
                cout << sWord << endl ;

            s.erase(0 , pos + limit.length()) ;    
        }

        if (s != "")
            cout << s << endl ;
    }

    void PrintEachWordInString() {

        PrintEachWordInString(_Value) ;
    }

    static short NumberOfWordsInString(string s) {

        short counter = 0 ;
        short pos = 0 ;
        string limit = " " ;
        string sWord ;

        while ((pos = s.find(limit)) != std::string::npos) {

         sWord = s.substr(0 , pos) ;

            if (sWord != "")
                counter++ ;

            s.erase(0 , pos + limit.length()) ;
        }

        if (s != "")
            counter++ ;
    
        return counter ;
    }

    short NumberOfWordsInString() {

        return NumberOfWordsInString(_Value) ;
    }

    static vector <string> Split(string s , string limit) {

        vector <string> vString ;
        short pos = 0 ;
        string sWord ;

        while ((pos = s.find(limit)) != std::string::npos) {

            sWord = s.substr(0 , pos) ;

            if (sWord != "")
                vString.push_back(sWord) ;

            s.erase(0 , pos + limit.length()) ;

        }

        if (s != "")
            vString.push_back(s) ;

        return vString ;
    }

    vector <string> Split(string limit = " ") {

        return Split(_Value , limit) ;
    }

    static string TrimLeft(string s) {

        for (short i = 0 ; i < s.length() ; i++) {

            if (s[i] != ' ')
                return s.substr(i , s.length() - i) ;
        }

        return "" ;
    }

    void TrimLeft() {

        _Value = TrimLeft(_Value) ;
    }   

    static string TrimRight(string s) {

        for (short i = s.length() - 1 ; i >= 0 ; i--) {

            if (s[i] != ' ')
                return s.substr(0 , i + 1) ;
        }

        return "" ;
    }

    void TrimRight() {

        _Value = TrimRight(_Value) ;
    }

    static string Trim(string s) {

        return (TrimLeft(TrimRight(s))) ;
    }

    void Trim() {

        _Value = Trim(_Value) ;
    }

    static string JoinString(vector <string> vString , string limit = " ") {

        string s = "" ;

        for (string &remainder : vString)
            s = s + remainder + limit ;

        return s.substr(0 , s.length() - limit.length()) ;
    }

    static string JoinString(string arr[] , short arrLength , string limit = " ") {

        string s = "" ;

        for (short i = 0 ; i < arrLength ; i++)
            s = s + arr[i] + limit ;

        return s.substr(0 , s.length() - limit.length()) ;
    }

    static string ReverseWordsInString(string s , string limit = " ") {

        vector <string> vString = Split(s , limit) ;
        string s1 = "" ;

        vector <string> :: iterator iter = vString.end() ;

        while (iter != vString.begin()) {

            --iter ;
            s1 += *iter + " " ;
        }

        s1 = s1.substr(0 , s1.length() - 1) ;

        return s1 ;
    }

    void ReverseWordsInString(string limit = " ") {

        _Value =  ReverseWordsInString(_Value , limit) ;
    }

    static string ReplaceWordInString(string s , string WordUpdate , string WordTo) {

        short pos = s.find(WordUpdate) ;

        while (pos != std::string::npos) {

            s = s.replace(pos , WordUpdate.length() , WordTo) ;
            pos = s.find(WordUpdate) ;
        }

        return s ;
    }

    void ReplaceWordInString(string WordUpdate , string WordTo) {

        _Value = ReplaceWordInString(_Value , WordUpdate , WordTo) ;
    }

    static string RemovePunctuationInString(string s) {

        string S = "" ;

        for (int i = 0 ; i < s.length() ; i++) {

            if (!ispunct(s[i]))
                S += s[i] ;
        }

        return S ;
    }

    void RemovePunctuationInString() {

        _Value = RemovePunctuationInString(_Value) ;
    }

    static short Length(string s) {

        return s.length() ;
    }

    short Length() {

        return _Value.length() ;
    }


} ;