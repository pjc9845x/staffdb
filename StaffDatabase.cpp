#include <iostream>
#include <vector>
#include <sstream>
#include <iomanip>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <map>

#include "Staff.h"
#include "StaffFunctions.cpp"
#include "FullTimeStaff.h"
#include "PartTimeStaff.h"
using namespace std;

//-------Read Functions-------
bool readData(const char *);
void readCurrentData (string);
void storeCurrentData (string);
//--------Filtering Functions------
string filterCriteria (string);

//---------Printing and DIsplaying-------
void printPTData(vector<PartTimeStaff> ptList);
void storePTData(vector<PartTimeStaff> ptList);
void printFTData(vector<FullTimeStaff> ftList);
void storeFTData(vector<FullTimeStaff> ftList);
void printSData(vector<Staff>);
void storeSData(vector<Staff>);

//-------Maps and Vectors---------------
map <string, Staff*> searchList;
vector <Staff*> allList;
vector <Staff> sList;
vector <PartTimeStaff> ptList;
vector <FullTimeStaff> ftList;

int main()
{
    string currFC="Staff";

    bool cont=true;
    int choice;

    cout<<"---------------------------------------\n";
    cout<<"Staff Directory Program\n"<<endl;
    cout<<"Author: Saitama II\n"
        <<"Supervisor: Dennis Enviro500"<<endl;
    cout<<"---------------------------------------\n";

    while (cont)
    {

        cout<<"Welcome to the Staff Directory Program!\n"<<endl;

        cout<<"1 - Read data\n"
            <<"2 - Specify filtering criteria (Current: "<<currFC<<")\n"
            <<"3 - View Data\n"
            <<"4 - Store Data\n"
            <<"5 - Search Staff\n"
            <<"6 - View All Data\n"
            <<"7 - Exit\n"
            <<endl
            <<"Please enter your choice: ";
        cin>>choice;

        cout<<"---------------------------------------\n";
        switch(choice)
        {
            case 1: {
                    string fName;
                    cout<<"Please enter file name: ";
                    getchar();
                    getline(cin,fName);
                    bool test=readData(fName.c_str());
                    if(!test)
                    {
                        cout<<"File not found!\n";
                        exit(1);
                    }
                    };break;
            case 2: currFC=filterCriteria(currFC);break;
            case 3: readCurrentData (currFC);break;
            case 4: storeCurrentData(currFC);break;
            case 5: searchStaff(searchList);break;
            case 6: readAllData(allList);break;
            case 7: cont=false;break;
            default: cout<<"Invalid option.\n";
        }
        cout<<"---------------------------------------\n";
    }
    cout<<"Goodbye!\n";
}

//1 - Read Data
bool readData (const char *fileName)
{
    searchList.clear();
    allList.clear();
    sList.clear();
    ptList.clear();
    ftList.clear();

    ifstream ifs;
	ifs.open(fileName,ios::in);

    string line;
    if(!ifs.is_open())
    {
        return false;
    }else {
	while(getline(ifs,line))
    {
        Staff* staff;
        istringstream iss (line);
        string type, id, name, occupation, rPay;

        getline(iss,type,'|');
        getline(iss,id,'|');
        getline(iss,name,'|');
        getline(iss,occupation,'|');
        getline(iss,rPay,'|');
        double pay=stod(rPay.c_str());

        if(type=="S")
        {
            staff=new Staff(id,name,occupation,pay);
            Staff basicStaff=Staff(id,name,occupation,pay);
            sList.push_back(basicStaff);
        }
       else if(type=="PT")
        {
            string rHours;
            getline(iss,rHours,'|');
            int hours=stod(rHours.c_str());
            staff=new PartTimeStaff(id,name,occupation,pay,hours);
            PartTimeStaff ptStaff=PartTimeStaff(id,name,occupation,pay,hours);
            ptList.push_back(ptStaff);
        }
       else if(type=="FT")
        {
            string rAll;
            getline(iss,rAll,'|');
            int allowance=stod(rAll.c_str());
            staff=new FullTimeStaff(id,name,occupation,pay,allowance);
            FullTimeStaff ftStaff=FullTimeStaff(id,name,occupation,pay,allowance);
            ftList.push_back(ftStaff);
        }
        allList.push_back(staff);
        searchList.insert(pair<string,Staff*>(name,staff));
    }

	ifs.close();
	return true;
    }
}

//2 - Filtering Criteria
string filterCriteria(string fcO)
{
    string fc;

    bool cont=true;
    int choice;

    while (cont)
    {
        cout<<"Specify current filtering criteria (current: ("<<fcO<<")\n"<<endl
            <<"1 - Staff\n"
            <<"2 - Part Time Staff\n"
            <<"3 - Full Time Staff\n"
            <<endl;
        cin>>choice;
        switch(choice)
        {
            case 1: fc="Staff"; cont=false;break;
            case 2: fc="Part Timer"; cont=false;break;
            case 3: fc="Full Timer"; cont=false;break;
            default: cout<<"Invalid option.\n";
        }
    }
    return fc;
}

//3 - Display On Screen
void readCurrentData (string currFC)
{
    if(currFC=="Staff")
        printSData(sList);
    else if(currFC=="Part Timer")
        printPTData(ptList);
    else if(currFC=="Full Timer")
        printFTData(ftList);
}

//4 - Store Data
void storeCurrentData (string currFC)
{
    cout<<"Storing "<<currFC<<" data into a text file...\n";
    if(currFC=="Staff")
        storeSData(sList);
    else if(currFC=="Part Timer")
        storePTData(ptList);
    else if(currFC=="Full Timer")
        storeFTData(ftList);
    cout<<"File creation complete!\n";
}

//Part Timer
void printPTData(vector<PartTimeStaff> ptList)
{
    vector<PartTimeStaff>::iterator it;

    cout<<left
        <<setw(5)<<"ID"
        <<setw(15)<<"Name"
        <<setw(30)<<"Occupation"
        <<setw(15)<<"Hourly Pay"
        <<setw(10)<<"Hours"
        <<setw(10)<<"Total Pay"
        <<endl;
    cout<<"----------------------------------------------------------------------------------\n";
    for(it=ptList.begin();it!=ptList.end();++it)
    {
        cout<<(*it)<<endl;
    }
}

void storePTData(vector<PartTimeStaff> ptList)
{
    vector<PartTimeStaff>::iterator it;

    ofstream ofs;
    ofs.open("PartTimeStaff.txt",ios::trunc);

    ofs<<left
        <<setw(5)<<"ID"
        <<setw(15)<<"Name"
        <<setw(30)<<"Occupation"
        <<setw(15)<<"Hourly Pay"
        <<setw(10)<<"Hours"
        <<setw(10)<<"Total Pay"
        <<endl;
    ofs<<"----------------------------------------------------------------------------------\n";
    for(it=ptList.begin();it!=ptList.end();++it)
    {
        ofs<<(*it)<<endl;
    }
    ofs.close();
}

//Regular Staff
void printSData(vector<Staff> sList)
{
    vector<Staff>::iterator it;

    cout<<left
        <<setw(5)<<"ID"
        <<setw(15)<<"Name"
        <<setw(30)<<"Occupation"
        <<setw(10)<<"Pay"
        <<setw(10)<<"Total Pay"<<endl;
    cout<<"---------------------------------------------------------------\n";
    for(it=sList.begin();it!=sList.end();++it)
    {
        cout<<(*it)<<endl;
    }
}

void storeSData(vector<Staff> sList)
{
    vector<Staff>::iterator it;

    ofstream ofs;
    ofs.open("Staff.txt",ios::trunc);

    ofs<<left
        <<setw(5)<<"ID"
        <<setw(15)<<"Name"
        <<setw(30)<<"Occupation"
        <<setw(10)<<"Pay"
        <<setw(10)<<"Total Pay"<<endl;
    ofs<<"---------------------------------------------------------------\n";
    for(it=sList.begin();it!=sList.end();++it)
    {
        ofs<<(*it)<<endl;
    }

    ofs.close();
}

//Full Timer
void printFTData(vector<FullTimeStaff> ftList)
{
    vector<FullTimeStaff>::iterator it;

    cout<<left
        <<setw(5)<<"ID"
        <<setw(15)<<"Name"
        <<setw(30)<<"Occupation"
        <<setw(15)<<"Monthly Pay"
        <<setw(15)<<"Allowance"
        <<setw(10)<<"Total Pay"
        <<endl;
    cout<<"----------------------------------------------------------------------------------------------\n";
    for(it=ftList.begin();it!=ftList.end();++it)
    {
        cout<<(*it)<<endl;
    }
}

void storeFTData(vector<FullTimeStaff> ftList)
{
    vector<FullTimeStaff>::iterator it;

    ofstream ofs;
    ofs.open("FullTimeStaff.txt",ios::trunc);

    ofs<<left
        <<setw(5)<<"ID"
        <<setw(15)<<"Name"
        <<setw(30)<<"Occupation"
        <<setw(15)<<"Monthly Pay"
        <<setw(15)<<"Allowance"
        <<setw(10)<<"Total Pay"
        <<endl;
    ofs<<"----------------------------------------------------------------------------------------------\n";
    for(it=ftList.begin();it!=ftList.end();++it)
    {
        ofs<<(*it)<<endl;
    }
    ofs.close();
}





