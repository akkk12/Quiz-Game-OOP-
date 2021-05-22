
#include <iostream>
#include<fstream>
#include<string.h>
using namespace std;

//class student
class student {
protected :
        string name ;
        int roll ;
        int finalscore ;
        string phone ;
    public :
        student(){
        name = "";
        roll = 0;
        finalscore = 0 ;
        phone = " ";
        }
        void setvalues2(string n , int r , string phone ) ;  // polymorphism
        void setvalues2(string n , int r  ) ;  //polymorphism
        void setvalues3(int f )  ;
        int returnFinalScore(){
        return finalscore ; }
         int returnRoll(){
        return roll ; }
         string returnPhone(){
        return phone ; }
        string returnName(){
            return name ;
        }
        void display(void) {
            cout<<"Name is :" << name <<endl;
            cout<<"Roll number is "<<roll <<endl;
            cout<<"Final Score is "<<finalscore<<endl ;
            cout<<"phone is "<<phone<<endl ;
        }

};

//class question, stores all the questions of the quiz
class question {

    string ques ;
    string opt1 ;
    string opt2 ;
    string opt3 ;
    string opt4 ;
    int answer ;
    int score ;

    public:
        question(){
            ques = " ";
            opt1 = " ";
            opt2 = " ";
            opt3 = " ";
            opt4 = " ";
            answer = 0;
            score = 0;
        }

        void setValues(string q , string o1 , string o2 , string o3 , string o4 , int a , int s ) ;
        int askQuestion();
        void display(void) ;
         int getScore(){
            return score ;
        }
        int getAnswer(){
            return answer ;
        }
};


class OperatingSystems : public question  //hierarchical inheritance
{

};

class OOPS_quiz : public question        //hierarchical inheritance
{

};

class DS_quiz : public question          //hierarchical inheritance
{

};


class toppers : public student {

    string email_id ;
    string address ;
    public :
    toppers(student &s)   //copy constructor
    {
       name = s.returnName() ;
       phone = s.returnPhone() ;
       roll = s.returnRoll() ;
       finalscore = s.returnFinalScore();
    }
    void save(){
     fstream myfile;
    myfile.open("Toppers_information.csv", ios::out | ios :: trunc );
    myfile <<"Name , Email ,Address ,Phone no. \n";
   myfile<<name <<", "<<email_id<<", "<<address  <<", "<<phone ;

    }

        void setvalues4(string s1 , string s2 )  ;
};

void toppers :: setvalues4(string s1 , string s2 ){
    email_id = s1 ;
    address = s2 ;
}


void student :: setvalues3(int f ){
   finalscore = f ;
}

void student :: setvalues2(string n , int r , string p ){
   name = n ;
   roll = r ;
   phone = p  ;
}

void student :: setvalues2(string n , int r  ){
    name = n ;
    roll = r;
    phone = " "  ;
}


int question :: askQuestion(){
    int Guess ;
    cout << ques << endl;
    cout << "1. " << opt1 << endl;
    cout << "2. " << opt2 << endl;
    cout << "3. " << opt3 << endl;
    cout << "4. " << opt4 << endl;
    cout << endl;
    cout << "What is your answer?(option number)"<< endl;
    cin >> Guess;
    if(Guess > 4 or Guess < 1){
    cout<<"\nInvalid Option ..Enter your answer again \n";
    cout << "What is your answer?(option number)"<< endl;
    cin >> Guess;

    }
    return Guess ;
}


void question :: setValues(string q , string o1 , string o2 , string o3 , string o4 , int a , int s ){
    ques = q  ;
    opt1 = o1 ;
    opt2 = o2 ;
    opt3 = o3 ;
    opt4 = o4 ;
    answer = a ;
    score = s ;

}

//Driver Code
int main(){
int subject ;
system("COLOR B0");
cout<<"---------------------------------------------------------------------------------\n";
cout<<"                            Welcome to our Quiz!                                 \n";
cout<<"---------------------------------------------------------------------------------\n";
cout<<"Enter the subject in which you want to take quiz (1/2/3)?\n";
cout<<"1.Operating System\n";
cout<<"2.Object Oriented Programming \n";
cout<<"3.Data Structures \n";
cin>>subject ;

 if(subject == 1){
    OperatingSystems arr1[5];
    arr1[0].setValues("Question 1 : Which of the following is not an operating system?  ", "Windows", "Linux", "Oracle", "DOS", 3, 20);
    arr1[1].setValues("Question 2 : When does page fault occur? ", "The page is present in memory","The deadlock occurs", "The page does not present in memory.","The buffering occurs", 3, 20);
    arr1[2].setValues("Question 3 : Banker's algorithm is used? ", "To prevent deadlock", "To deadlock recovery", "To solve the deadlock","None of these ", 1, 20);
    arr1[3].setValues("Question 4 : Which is the Linux operating system? ", "Private operating system","Windows operating system", "Open-source operating system","None of these", 3, 20);
    arr1[4].setValues("Question 5 : If the page size increases, the internal fragmentation is also?", "Decreases","Increases ", "Remains constant", "None of these", 2, 20);

    student arr2[5];
     arr2[0].setvalues2("Anamya Singh  ", 1, "8574445236");
     arr2[1].setvalues2("Binwant Kaur ", 2 ,"36987452368");
     arr2[2].setvalues2("Mayank Kumar ", 3);
     arr2[3].setvalues2("Rhea Singh ", 4, "7632145896");
     arr2[4].setvalues2("Tania Verma ", 5, "3365214785");
    int high = 0 ;
    int ihigh = 0 ;
    int shigh = 0 ;
    int ishigh = 0 ;
    fstream MyExcelFile;
    MyExcelFile.open("OperatingSystem.csv", ios::out | ios :: trunc );
    MyExcelFile << "First Name,Roll number , Score " << endl;

    for(int i = 0 ; i < 5 ; i ++ )  { // student
        int max_score = 0  ;
        cout<<"---------------------------------------------------------------------------------\n";
        cout<<"                           Quiz starts for student "<< i + 1 <<"                   "<<endl;
        cout<<"---------------------------------------------------------------------------------\n";

        for(int j = 0 ; j < 5; j ++ ){
            int a1 = arr1[j].askQuestion();
            int pt = arr1[j].getAnswer() ;
            if(a1 == pt ) max_score += arr1[j].getScore() ;
        }

        arr2[i].setvalues3(max_score);



        if(max_score > high ){
            high = max_score ;
            ihigh = i  ;
        }

        else if(max_score > shigh ){
            shigh = max_score ;
            ishigh = i ;
        }

            MyExcelFile << arr2[i].returnName() <<", "<<arr2[i].returnRoll()<<", "<<arr2[i].returnFinalScore()<< endl;
    }


    MyExcelFile.close();
    toppers t1 = arr2[ihigh] ;   // copy constructor
    toppers t2 = arr2[ishigh] ;    // copy constructor
    cout<<"\nCONGRATULATIONS \n";

    cout <<"The topper is : " << endl ;
    cout <<"Name : " << t1.returnName() << endl ;
    cout <<"Roll : " << t1.returnRoll() << endl ;
    cout <<"Score : " <<  t1.returnFinalScore() << endl ;

    string s1 , s2 , s3 , s4 ;

    cout <<"Please enter your email id "  ;
    cin >>  s1  ;
    cout <<"Please enter your residential address "  ;
    cin >>  s2  ;

    t1.setvalues4(s1 , s2 ) ;
    t1.save();
    cout <<"The goodies will be sent to you shortly! "  ;}

 else if(subject == 2){

    OOPS_quiz arr1[5];
    arr1[0].setValues("Question 1 : Which of the following is not an OOPS concept?  ", "Encapsulation", "Polymorphism", "Exception", "Abstraction", 3, 20);
    arr1[1].setValues("Question 2 : Which feature of OOPS described the reusability of code? ", "Abstraction","Encapsulation", "Polymorphism","Inheritance", 4, 20);
    arr1[2].setValues("Question 3 : Which feature of OOPS derives the class from another class? ", "Inheritance", "Data Hiding", "Encapsulation","Polymorphism ", 1, 20);
    arr1[3].setValues("Question 4 : Which of the following OOP concept binds the code and data together and keeps them secure from the outside world? ", "Polymorphism","Inheritance", "Abstraction","Encapsulation", 4, 20);
    arr1[4].setValues("Question 5 : Which function best describe the concept of polymorphism in programming languages? ", "Class member function","Virtual function", "Inline function", "Undefined function", 2, 20);

    student arr2[5];

     arr2[0].setvalues2("Anamya Singh  ", 1, "8574445236");
     arr2[1].setvalues2("Binwant Kaur ", 2 ,"36987452368");
     arr2[2].setvalues2("Mayank Kumar ", 3);
     arr2[3].setvalues2("Rhea Singh ", 4, "7632145896");
     arr2[4].setvalues2("Tania Verma ", 5, "3365214785");
    int high = 0 ;
    int ihigh = 0 ;
    int shigh = 0 ;
    int ishigh = 0 ;
    ofstream MyExcelFile2;

    MyExcelFile2.open("OOPS.csv"  );
    MyExcelFile2 << "First Name,Roll number, Score " << endl;

    for(int i = 0 ; i <5; i ++ )  { // student
        int max_score = 0  ;

         cout<<"---------------------------------------------------------------------------------\n";
        cout<<"                           Quiz starts for student "<< i + 1 <<"                   "<<endl;
        cout<<"---------------------------------------------------------------------------------\n";
        for(int j = 0 ; j < 5; j ++ ){
            int a1 = arr1[j].askQuestion();
            int pt = arr1[j].getAnswer() ;
            if(a1 == pt ) max_score += arr1[j].getScore() ;
        }

        arr2[i].setvalues3(max_score);
        MyExcelFile2 << arr2[i].returnName() <<", "<<arr2[i].returnRoll()<<", "<<arr2[i].returnFinalScore()<< endl;

        if(max_score > high ){
            high = max_score ;
            ihigh = i  ;
        }

        else if(max_score > shigh ){
            shigh = max_score ;
            ishigh = i ;
        }
    }
 toppers t1 = arr2[ihigh] ;   // copy constructor
    toppers t2 = arr2[ishigh] ;    // copy constructor
    cout<<"\nCONGRATULATIONS \n";

    cout <<"The topper is : " << endl ;
    cout <<"Name : " << t1.returnName() << endl ;
    cout <<"Roll : " << t1.returnRoll() << endl ;
    cout <<"Score : " <<  t1.returnFinalScore() << endl ;

    string s1 , s2 , s3 , s4 ;

    cout <<"Please enter your email id "  ;
    cin >>  s1  ;
    cout <<"Please enter your residential address "  ;
    cin >>  s2  ;

    t1.setvalues4(s1 , s2 ) ;
    t1.save();
    cout <<"The goodies will be sent to you shortly! "  ;}


  else if(subject == 3){

    DS_quiz arr1[5];
    arr1[0].setValues("Question 1 : Which one of the following is the process of inserting an element in the stack?  ", "Insert", "Add", "Push", "None of the above" , 3, 20);
    arr1[1].setValues("Question 2 : Which one of the following is not the application of the stack data structure? ", "String reversal","Recursion", "Backtracking","Asynchronous data transfer", 4, 20);
    arr1[2].setValues("Question 3 : Which data structure is mainly used for implementing the recursive algorithm? ", "Queue", "Stack", "Binary tree","Linked list ", 2, 20);
    arr1[3].setValues("Question 4 : Which data structure is required to convert the infix to prefix notation? ", "Queue", "Stack", "Binary tree","Linked list ", 2, 20);
    arr1[4].setValues("Question 5 : Which of the following is the prefix form of A+B*C?", "A+(BC*)","+AB*C", "ABC+*", "+A*BC", 4, 20);

    student arr2[5];

     arr2[0].setvalues2("Anamya Singh  ", 1, "8574445236");
     arr2[1].setvalues2("Binwant Kaur ", 2 ,"36987452368");
     arr2[2].setvalues2("Mayank Kumar ", 3);
     arr2[3].setvalues2("Rhea Singh ", 4, "7632145896");
     arr2[4].setvalues2("Tania Verma ", 5, "3365214785");

    int high = 0 ;
    int ihigh = 0 ;
    int shigh = 0 ;
    int ishigh = 0 ;
    ofstream MyExcelFile3;
    MyExcelFile3.open("DataStructures.csv"  );
    MyExcelFile3 << "First Name,Roll number , Score " << endl;

    for(int i = 0 ; i < 5; i ++ )  { // student
        int max_score = 0  ;

        cout<<"---------------------------------------------------------------------------------\n";
        cout<<"                           Quiz starts for student "<< i + 1 <<"                   "<<endl;
        cout<<"---------------------------------------------------------------------------------\n";

        for(int j = 0 ; j < 5; j ++ ){
            int a1 = arr1[j].askQuestion();
            int pt = arr1[j].getAnswer() ;
            if(a1 == pt ) max_score += arr1[j].getScore() ;
        }

        arr2[i].setvalues3(max_score);

        MyExcelFile3 << arr2[i].returnName() <<", "<<arr2[i].returnRoll()<<", "<<arr2[i].returnFinalScore()<< endl;

        if(max_score > high ){
            high = max_score ;
            ihigh = i  ;
        }

        else if(max_score > shigh ){
            shigh = max_score ;
            ishigh = i ;
        }
    }
    MyExcelFile3.close();
    toppers t1 = arr2[ihigh] ;   // copy constructor
    toppers t2 = arr2[ishigh] ;    // copy constructor
    cout<<"\nCONGRATULATIONS \n";


    cout <<"The topper is : " << endl ;
    cout <<"Name : " << t1.returnName() << endl ;
    cout <<"Roll : " << t1.returnRoll() << endl ;
    cout <<"Score : " <<  t1.returnFinalScore() << endl ;

    string s1 , s2 , s3 , s4 ;

    cout <<"Please enter your email id "  ;
    cin >>  s1  ;
    cout <<"Please enter your residential address "  ;
    cin >>  s2  ;

    t1.setvalues4(s1 , s2) ;
    t1.save();
    cout <<"The goodies will be sent to you shortly! "  ;

   }
}


