#include<iostream>
#include<conio.h>
#include<fstream>
#include<iomanip>
#include<cstring>
using namespace std;

#define AMOUNT 10000
int start=0;

struct worker_info {
	bool is_reserved = false;
	string name;
	string workType;
	string workExperience;
	string address;
	string phone;
	string password;
};

class upWork {
public:
	worker_info workers[AMOUNT]; //defining the structure [10000]

	void main_menu(); //the main menu for employees
	void add(); //to register as a worker
	void edit(); //to edit the workers record
	void modify(int); //to modify the record
	void delete_rec(int); //to delete the record

	bool check(int); //to check status

	void hire(); //the main menu for employers
	void searchByID(); //to display the worker record
	void searchByType(); //to search workers by their id number
	void workersList(); //to display the list of workers
	void workList(); //to display the list of registered worktypes
	
};

void upWork::main_menu()
{

	int choice;
	while(choice!=3)
	{
		system("cls");
		cout<<"\n\t\t\t\t*************";
		cout<<"\n\t\t\t\t* MAIN MENU *";
		cout<<"\n\t\t\t\t*************";
		cout<<"\n\n\n\t\t\t1.Register";
		cout<<"\n\t\t\t2.Edit Profile";
		cout<<"\n\t\t\t3.Exit";
		cout<<"\n\n\t\t\tEnter Your Choice: ";
		cin>>choice;
        if (cin.fail()) {
            cout<< "Enter a valid input";
            cin.clear();
            cin.ignore(9999, '\n');
        }
		cin.ignore();
		switch(choice)
		{
			case 1: add();
			break;
			case 2: edit();
			break;
			case 3: break;
			default:
			{
			cout<<"\n\n\t\t\tWrong choice!!!";
			cout<<"\n\t\t\tPress any key to continue!!";
			getch();
			}
		}
	}
}

void upWork::add()
{
	system("cls");
	int r,flag;
	ofstream fout("Record.dat", ios::binary);
        cout<<"\n _____________________________";
	cout<<"\n    Fill the form below   :)  ";
	cout<<"\n -----------------------------";
	cout<<"\n\n Preferred ID number: ";
	cin>>r;
	cin.ignore();

	if(check(r))
		cout<<"\n Id number is already taken:(";
	else
	{
		workers[r].is_reserved = true;

		cout<<setw(22)<<" Name: ";
		getline(cin, workers[r].name);

		cout<<setw(22)<<" Address: ";
		getline(cin, workers[r].address);

		cout<<setw(22)<<" Phone No: ";
		getline(cin, workers[r].phone);

		cout<<setw(22)<<" Job type: ";
		getline(cin, workers[r].workType);

		cout<<setw(22)<<" Years of experience: ";
		getline(cin, workers[r].workExperience);

		loopPass:
		string pass1, pass2;
		
        cout<<setw(22)<<" Password: ";
        cin>>pass1;
        cout<<setw(22)<<"Confirm Password: ";
        cin>>pass2;
        if(pass1==pass2)
            workers[r].password = pass2;
        else{
            system("cls");
            cout<< "\n \aPasswords doesn't match!! Try again. \n";
            goto loopPass;
        }
		
		fout.write((char*) this, sizeof(upWork)); 
		cout<<setw(24)<<"\n *******************************";
		cout<<setw(24)<<"\n *     Congratulations         *";
		cout<<setw(24)<<"\n * Registered Successfully!! :)*";
        	cout<<setw(24)<<"\n *******************************";
	}
	cout<<"\n Press any key to continue!!";
	getch();
	fout.close();
}

void upWork::searchByID()
{
	system("cls");
	int r;
	cout<<"\n Find worker by ID number: ";
	cin>>r;
    	cin.ignore();
    if (cin.fail()) {
        cin.clear();
        cin.ignore(9999, '\n');
    }

	if (check(r)) {
		system("cls");
		cout<<"\n Worker Details";
		cout<<"\n **************";
		cout<<"\n\n s: "<<r;
		cout<<setw(8)<<"\n Name: "<< workers[r].name;
		cout<<setw(8)<<"\n Address: "<< workers[r].address;
		cout<<"\n Phone no: "<< workers[r].phone;
		cout<<"\n Job type: "<<workers[r].workType;
        	cout<<"\n Years of experience: "<<workers[r].workExperience;
	}

	else {
		cout << "\n ID number not found or vacant!!" << endl;
	}

	system("pause");
}

void upWork::searchByType()
{
	system("cls");
	string typeOfWork, spannedYr;

    	cout<<setw(22)<<" Job type: ";
    	getline(cin, typeOfWork);
    	cout<<setw(22)<<" Minimum year of experience: ";
    	getline(cin, spannedYr);
	cout<<"\n\t\t\tList Of Registered Workers With the given specification";
	cout<<"\n\t\t\t*******************************************************";
	cout<<"\n\n ID No.\t\tName\t\tAddress\t\tPhoneNo.\tWork Type\tWork Experience\n";

	for (int i=0; i<AMOUNT; i++)
	{
		if (workers[i].workType == typeOfWork && workers[i].workExperience >= spannedYr) {
			cout<<"\n\n "<< i <<"\t\t"<< workers[i].name;
			cout<<"\t\t"<<workers[i].address<<"\t\t"<< workers[i].phone<<"\t\t"<<workers[i].workType<<"\t\t"<<workers[i].workExperience;
		}
	}
	cout<<"\n\n\n\t\t\tPress any key to continue!!";
	getch();
    }

void upWork::workersList()
{
	system("cls");
	cout<<"\n\t\t\tList Of Registered Workers";
	cout<<"\n\t\t\t**************************";
	cout<<"\n\n ID No.\t\tName\t\tAddress\t\tPhoneNo.\tWork Type\tWork Experience\n";

	for (int i=0; i<AMOUNT; i++)
	{
		if (check(i)) {
			cout<<"\n\n "<< i <<"\t\t"<< workers[i].name;
			cout<<"\t\t"<<workers[i].address<<"\t\t"<< workers[i].phone<<"\t\t"<<workers[i].workType<<"\t\t"<<workers[i].workExperience;
		}
	}
	cout<<"\n\n\n\t\t\tPress any key to continue!!";
	getch();
}

void upWork::workList()
{
	system("cls");
	cout<<"\n\t\t\tWorks available";
	cout<<"\n\t\t\t```````````````\n\n";

	for (int i=0, j=0; i<AMOUNT; i++)
	{
		if (check(i)) {
                j++;
			cout<<"\n\n ";
			cout<<j<<". "<<workers[i].workType;
		}
	}
	cout<<"\n\n\n\t\t\tPress any key to continue!!";
	getch();
}

void upWork::edit()
{
	system("cls");
	int choice,r;
	cout<<"\n EDIT RECORD";
	cout<<"\n ***********";
	cout<<"\n\n 1.Modify Your Record";
	cout<<"\n 2.Delete Your Record";
	cout<<"\n Enter Your Choice: ";
	cin>>choice;
	cin.ignore();
    if (cin.fail()) {
        cin.clear();
        cin.ignore(9999, '\n');
    }
	system("cls");

	cout<<"\n Enter Your ID: ";
	cin>>r;
    if (cin.fail()) {
        cin.clear();
        cin.ignore(9999, '\n');
    }
	cin.ignore();
	switch(choice)
	{
		case 1: modify(r);
		break;
		case 2: delete_rec(r);
		break;
		default: cout<<"\n Wrong Choice!!";
	}
	cout<<"\n Press any key to continue!!!";
	getch();
}

bool upWork::check(int r)
{
	return workers[r].is_reserved;
}

void upWork::modify(int r)
{
	if (!check(r)) {
		cout << "\n Couldn't find a vacant with this ID!!";
		return ;
	}
    string pass;
    cout<<"\n Password: ";
	cin>>pass;
	cin.ignore();
	if(pass == workers[r].password){
    	ofstream file("Record.dat",ios::binary);

	cout<<"\n Enter New Details";
	cout<<"\n *****************";
	cout<<"\n Name: ";
	getline(cin, workers[r].name);
	cout<<" Address: ";
	getline(cin, workers[r].address);
	cout<<" Phone no: ";
	getline(cin, workers[r].phone);
	cout<<" Job type: ";
    	getline(cin, workers[r].workType);
    	cout<<" Years of experience: ";
    	getline(cin, workers[r].workExperience);

	file.write((char*) this, sizeof(upWork));
	file.close();
	cout<<"\n Record is modified!!";
	}
	else{
	cout<< "\n \a Wrong Password!! - Try again later :(";}
}

void upWork::delete_rec(int r)
{
	if (!check(r)) {
		cout<<"\n Couldn't find a vacant with this ID!!";
		return;
	}
    string pass;
    cout<<"\n Password: ";
	cin>>pass;
	if(pass == workers[r].password){
	char ch;
	cout<<"\n Name: "<< workers[r].name;
	cout<<"\n Address: "<< workers[r].address;
	cout<<"\n Phone No: "<< workers[r].phone;
	cout<<"\n\n Do you want to delete this record(y/n): ";
	cin>>ch;
	cin.ignore();
	if(ch=='y') {
		workers[r].is_reserved = false;
		ofstream fout("Record.dat", ios::binary);
		fout.write((char*) this, sizeof(upWork));
		fout.close();
        	cout<<endl<<setw(20)<< "Deleted successfully!!";
     }
    }
    cout<< "\n \a Wrong Password!! - Try again later :(";
}

void upWork::hire() {
    int choice;
	while(choice!=5)
	{
		system("cls");
		cout<<"\n\t\t\t*************";
		cout<<"\n\t\t\t*   HIRE    *";
		cout<<"\n\t\t\t*************";
		cout<<"\n\n\n\t\t\t1.Find by ID";
		cout<<"\n\t\t\t2.Find by work type";
		cout<<"\n\t\t\t3.Available Workers List";
       		cout<<"\n\t\t\t4.List Of Registered Work Types ";
		cout<<"\n\t\t\t5.Exit";
		cout<<"\n\n\t\t\tEnter Your Choice: ";
		cin>>choice;
        if (cin.fail()) {
            cout<< "Enter a valid input";
            cin.clear();
            cin.ignore(9999, '\n');
        }
		cin.ignore();
		switch(choice)
		{
			case 1: searchByID();
			break;
			case 2: searchByType();
			break;
			case 3: workersList();
			break;
			case 4: workList();
			break;
			case 5: break;
			default:
			{
			cout<<"\n\n\t\t\tWrong choice!!!";
			cout<<"\n\t\t\tPress any key to continue!!";
			getch();
			}
		}
	}
}

int main(){

	upWork h;  //calling the class upWork
	ifstream record("Record.dat", ios::binary); //input filestream
	if (record.good()) {
		record.read( (char*) &h, sizeof(upWork));
	 	record.close();
	}
    	cout<<"\n\t\t\t\t********************************";
	cout<<"\n\t\t\t\t* (: WELCOME TO MINI UPWORK :) *";
	cout<<"\n\t\t\t\t********************************";
	cout<<"\n\n\n\t\t\t1.Find work";
	cout<<"\n\t\t\t2.Hire";
	cout<<"\n\t\t\t3.Exit";
    int x;
    menu:

            cout<<"\n\n\t\t\tEnter Your Choice: ";
            cin>>x;
             if (cin.fail()) { //if entered a data type other than int
            cout<< "Enter a valid key \a";
            cin.clear(); //clear the failed state
            cin.ignore(9999, '\n'); //clear the buffer
             }
        switch(x){
            case 1:
                system("cls");
                h.main_menu();
                break;
            case 2:
                system("cls");
                h.hire();
                break;
            case 3:
                exit(0);
                break;
            default:
                cout<<"wrong input!!try again\n";
                system("cls");
                goto menu;
                break;
            }

	return 0;
}
