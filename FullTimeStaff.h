#ifndef FULLTIMESTAFF_h
#define FULLTIMESTAFF_h

#include "Staff.h"
#include <sstream>
#include <iomanip>
using namespace std;

class FullTimeStaff: public Staff
{
	private:
		double allowance;

	public:

		FullTimeStaff(string id, string name, string occupation, double pay, double allowance): Staff(id,name,occupation, pay)
		{
			this->allowance=allowance;
		}

        double calculatePay()
        {
            return pay+allowance;
        }

		void printIndividualData()
		{
            cout<<"Name: "<<name<<"\n"<<endl
                <<"Staff Type: Full Time"<<endl
		        <<"ID: "<<id<<endl
		        <<"Occupation: "<<occupation<<endl
		        <<"Monthly pay: "<<pay<<endl
		        <<"Allowance: "<<allowance<<endl
		        <<"Total Pay: "<<pay+allowance;
		}

		void printEntry()
		{
            cout<<left
                <<setw(14)<<"FT Staff"
                <<setw(5)<<id
                <<setw(15)<<name
                <<setw(30)<<occupation
                <<setw(10)<<pay
                <<setw(10)<<"-"
                <<setw(15)<<allowance
                <<setw(10)<<calculatePay()
                <<endl;
		}

		friend ostream & operator << (ostream &os, FullTimeStaff & ft)
		{
		    os<<left
		      <<setw(5)<<ft.id
		      <<setw(15)<<ft.name
		      <<setw(30)<<ft.occupation
		      <<setw(15)<<ft.pay
		      <<setw(15)<<ft.allowance
		      <<setw(10)<<ft.calculatePay();

		      return os;
		}

};

#endif
