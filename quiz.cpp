/****************************************
Name : Nur Ayu Amira Binti Idris
Id : 1201200722
Section : TC1V
Title : University: Student  Quiz Marks 
****************************************/

#include<iostream>
#include<iomanip>

using namespace std;

class Student //This is base class 
{
	protected:
		string StudName, StudFaculty,StudProg; //This is data members: StudName(string), StudFaculty(string)
		int StudAge,StudId;          //This is data members:  StudAge(int), StudId(int)
		
	public:
		/* This is default constructor*/
		Student()
		{
			cout << "*****************************************" << endl;
            cout << "           Student MMU Information       " << endl;
            cout << "*****************************************" << endl;
            cout<<endl;
		}
};

class Keyin //This is base class
{
	protected:
		//Data members : subject(string), mark(float), grade(char)
		string subject[3];
		float mark[3];
		char grade;
		
	public:
		void mark_key()
		{
			//Data members: tot(int), avg(float)
			int tot=0;
			float avg;
			
			for(int i=0; i<3; i++) //using for loop , for get user input for subject array and marks array
			{
				fflush(stdin);
				cout<<setw(31)<<"Enter Name Subject"<<" : ";
				getline(cin,subject[i]);
				
				fflush(stdin);
				cout<<"Enter  Quiz Marks (Between 1-5) : ";
				cin>>mark[i];
				
				tot=tot+mark[i];
			}
			
			avg=tot/3;
			set_grd(avg); //call function from 	void set_grd(float avg)
		}
		
		  void set_grd(float avg) 
        {
            if(avg >= 4.00)
            {
                grade = 'A';
            }
            else if(avg >= 3.00 && avg < 4)
            {
                grade = 'B';
            }
            else if(avg < 3.00)
            {
                grade = 'E';
            }
        }
};

class Outcome: public Student, public Keyin //This is derived classes that inherit from the base class
{
	private:
		string gift;
		
	public:
		
		void setdetail()
		{
			cout<<left;
			
			fflush(stdin);
			cout<<setw(20)<<"Enter Student Name"<<" : ";
			getline(cin,StudName);
			
			fflush(stdin);
			cout << setw(20) << "Enter Student Id" << " : ";
            cin >> StudId;
            
            fflush(stdin);
			cout << setw(20) << "Enter Student Age" << " : ";
            cin >> StudAge;
            
            fflush(stdin);
			cout << "Enter Student Faculty: ";
           	getline(cin,StudFaculty);
           	
            fflush(stdin);
            cout << "Enter Student Program: ";
            getline(cin,StudProg);
		}
		
		void display()
		{
			cout<<setw(11)<<"Student Name"<<"    : "<<StudName<<endl;
			cout<<setw(11)<<"Id Student  "<<"    : "<<StudId<<endl;
			cout<<setw(11)<<"Student Age"<<"     : "<<StudAge<<endl;
			cout<<"Student Faculty :"<<StudFaculty<<endl;
			cout<<"Student Program :"<<StudProg<<endl;
			cout<<endl;
			
			cout << "Subject 1 : " << subject[0] << endl;
			cout << "Marks 1   : " << mark[0] << endl;
			cout << "Subject 2 : " << subject[1] << endl;
            cout << "Marks 2   : " << mark[1] << endl;
            cout << "Subject 3 : " << subject[2] << endl;
            cout << "Marks 3   : " << mark[2] << endl;
            cout << setw(8) << "Grade" << "  : " << grade << endl;
            cout<<endl;
            
            if(grade == 'A')
            {
            	gift = "RM 100 Machine Voucher + 3 Months Free Spotify Subscribe";
			}
			else
			{
				gift= "Tupperware bottle";
			}
			 cout << "Congratulation, "<< StudName <<"  you can claim your " + gift << " at MMU STAD office!" << endl;
		}
};

/*This is base class.This main objective of the base class is 
to provide the traits to the derived classes and to create the
base pointer used for achieving the runtime polymorphism*/
class Last 
{  
    public:  
    //This is virtual function. It serves as a placeholder
    virtual void disp() = 0;  
};  

class Output: public Last ////This is derived classes that inherit from the base class
{  
    public:  
    //This is virtual function
    void disp()  
    {  
        std::cout << " *** STAY MOTIVATED AND STUDY HARD FOR YOUR FUTURE ***" << std::endl;  
    }  
}; 

int main()
{
		cout<<"############################################ "<<endl;
		cout<<" 	WELCOME TO MMU KEY IN QUIZ SYSTEM       "<<endl;
		cout<<"############################################ "<<endl;
		string StudName;
		int StudNum;
	
		cout<<endl;
		cout<<"Enter number of students : ";
		cin>>StudNum;
		cout<<endl;
	
		//This is virtual function
		Last *lst;
		Output op; //Object for Output Class
		lst = &op;
		
		//This is dynamic memory allocation using keyword new
		Outcome *student1 = new Outcome [StudNum];
		
		for(int x =0; x<StudNum; x++)
		{
			student1[x].setdetail(); //array of objects for one of the class
			
			cout << endl;
	        cout << "*****************************************" << endl;
	        cout << "           KEY IN QUIZ MARKS             " << endl;
	        cout << "*****************************************" << endl;
	        student1[x].mark_key(); //array of objects for one of the class
	        
	        cout << endl;
	        cout << "*****************************************" << endl;
	        cout << "              RESULT SLIP QUIZ           " << endl;
	        cout << "*****************************************" << endl;
	        student1[x].display(); //array of objects for one of the class
	        cout <<endl;
		}
		
		lst->disp();//This is virtual function
   		delete[] student1;// Delete object

    return 0;
}
