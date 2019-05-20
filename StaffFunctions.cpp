#include <vector>
#include <map>
#include "Staff.h"
#include "FullTimeStaff.h"
#include "PartTimeStaff.h"
#include <string.h>
using namespace std;

//7 - View ALl Data
//7 - View All Data
void readAllData(vector <Staff*> allList)
{
	Staff *staff1, *staff2, *staff3;


	cout<<left
        <<setw(14)<<"Type"
        <<setw(5)<<"ID"
        <<setw(15)<<"Name"
        <<setw(30)<<"Occupation"
        <<setw(10)<<"Pay"
        <<setw(10)<<"PTHours"
        <<setw(15)<<"FTAllowance"
        <<setw(10)<<"Total Pay"
        <<endl;

    cout<<"--------------------------------------------------------------------------------------------------------------\n";
    for (int i=0;i<allList.size();++i)
    {
        allList[i]->printEntry();
    }
}

void searchStaff (map <string, Staff*>searchList)
{
    bool cont=true;

    char c;

    while(cont)
    {
        string name;

        cout<<"Enter a name to search (Records: "<<searchList.size()<<"): ";
        getchar();
        getline(cin,name);
        cout<<"--------------------------------------------\n";
        map<string,Staff*>::iterator it;
        it=searchList.find(name);

        if(it==searchList.end())
        {
            cout<<"Name not found!\n";
        }else
        {
            it->second->printIndividualData();
            cout<<endl;
        }
        cout<<"--------------------------------------------\n";
        bool yOn=true;
        while(yOn)
        {
            cout<<"Continue? Y/y/N/n: ";
            cin>>c;

            switch(c)
            {
            case 'Y':
            case 'y': yOn=false;break;
            case 'N':
            case 'n': cont=false;yOn=false;break;
            default: cout<<"Invalid option. Try again.\n";
            }
        }
        cout<<"--------------------------------------------\n";
    }
}





