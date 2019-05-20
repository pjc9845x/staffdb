#ifndef PartTimeStaff_h
#define PartTimeStaff_h

#include <vector>
#include "Staff.h"
using namespace std;

//----Functions------
string PTSortCriteria(string);


class PartTimeStaff: public Staff
{
	private:
		double hours;

	public:

		PartTimeStaff(string id, string name, string occupation, double pay, double hours): Staff(id,name,occupation, pay)
		{
			this->hours=hours;
		}

        double calculatePay()
        {
            return pay*hours;
        }

		void printIndividualData()
		{
            cout<<"Name: "<<name<<"\n"<<endl
                <<"Staff Type: Part Time"<<endl
		        <<"ID: "<<id<<endl
		        <<"Occupation: "<<occupation<<endl
		        <<"Pay per hour: "<<pay<<endl
		        <<"Hours: "<<hours<<endl
		        <<"Total Pay: "<<pay*hours;
		}

		void printEntry()
		{
            cout<<left
                <<setw(14)<<"PT Staff"
                <<setw(5)<<id
                <<setw(15)<<name
                <<setw(30)<<occupation
                <<setw(10)<<pay
                <<setw(10)<<hours
                <<setw(15)<<"-"
                <<setw(10)<<calculatePay()
                <<endl;
		}

        friend ostream& operator << (ostream & os, PartTimeStaff &pt)
        {
            os<<left
                <<setw(5)<<pt.id
                <<setw(15)<<pt.name
                <<setw(30)<<pt.occupation
                <<setw(15)<<pt.pay
                <<setw(10)<<pt.hours
                <<setw(10)<<pt.calculatePay();
            return os;
        }
};


#endif
