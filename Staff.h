#ifndef STAFF_h
#define STAFF_h

#include <sstream>
#include <iostream>
#include <iomanip>
using namespace std;

class Staff
{
	protected:
		string id;
		string name;
		string occupation;
		double pay;
	public:
		Staff(string id, string name, string occupation, double pay)
		{
			this->id=id;
			this->name=name;
			this->occupation=occupation;
			this->pay=pay;
		}


		string returnID()
		{
		    return id;
		}

		string returnName()
		{
		    return name;
		}

		string returnOccupation()
		{
		    return occupation;
		}

		double returnPay()
		{
		    return pay;
		}

        virtual double calculatePay()
        {
            return pay;
        }

		virtual void printIndividualData()
		{
		    cout<<"Name: "<<name<<"\n"<<endl
                <<"Staff Type: Basic"<<endl
		        <<"ID: "<<id<<endl
		        <<"Occupation: "<<occupation<<endl
		        <<"Pay: "<<pay;
		}

		virtual void printEntry()
		{
            cout<<left
                <<setw(14)<<"Staff"
                <<setw(5)<<id
                <<setw(15)<<name
                <<setw(30)<<occupation
                <<setw(10)<<pay
                <<setw(10)<<"-"
                <<setw(15)<<"-"
                <<setw(10)<<calculatePay()
                <<endl;
		}

        virtual void printStaff()
		{
            cout<<left
                <<setw(5)<<id
                <<setw(15)<<name
                <<setw(30)<<occupation
                <<setw(10)<<pay
                <<setw(10)<<calculatePay();
		}

		friend ostream & operator << (ostream& os, Staff &s)
		{
		    os<<left
                <<setw(5)<<s.id
                <<setw(15)<<s.name
                <<setw(30)<<s.occupation
                <<setw(10)<<s.pay
                <<setw(10)<<s.calculatePay();
            return os;
		}
};

//----Functions-----



#endif
