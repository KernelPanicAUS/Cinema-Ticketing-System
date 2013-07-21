/*
Student Name: Thomas J khalil.
File Name:  16547328.cpp*/

#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;


void menu();
void file_init();
void av_seats();
void seat_prices();
void ticket_sales();
void ticket_purchase();
void EXIT();



const int ARRAY_SIZE= 15; 
int Seats[ARRAY_SIZE];	  
bool Vacant[30][15];

int main()
{
	file_init();

	int choice;
	ifstream inputFile;		 
	

    
	
	do
	{
	menu();
	cin>>choice;
	
		while (choice <1 || choice > 5 )
		{
			cout<<"ERROR !!! Invalid input"<<endl;
		    cout<<"Please enter a valid choice between 1 & 5"<<endl;
			cin>>choice;
		}
		
			switch (choice)
			{
			case 1:
				 av_seats();
				break;
			case 2: 
				 seat_prices();
				break;
			case 3:
				ticket_sales();
				break;
			case 4:
				ticket_purchase();
				break;
			case 5:
				EXIT();
			}
	
		system("PAUSE");
		system("CLS");
	}while (choice !=5);
	
	
	return 0;
}


void menu()
{
	cout<<"\t\t\n\nC++ Assignment 2"<<endl;
	cout<<"\n\n1. View available Seats"<<endl;
	cout<<"2. view Seating Prices"<<endl;
	cout<<"3. View ticket Sales"<<endl;
	cout<<"4. Purchase a Ticket"<<endl;
	cout<<"5. Exit the Program"<<endl;
	cout<<"\n\nPlease enter a choice ( 1 - 5 )"<<endl;
}
void file_init()
{
	int count;
	
	ifstream inputFile;
	inputFile.open("c:\\Temp\\Seat_Prices.txt");

	for (count =0; count < ARRAY_SIZE; count++)
		inputFile >> Seats[count];

	inputFile.close();
	
	ifstream InFile("c:\\temp\\ticketsales.txt");

	for(int x = 0; x < 30; x++)
	{
		for(int y = 0; y < 15; y++)
		{
			Vacant[x][y] = 0;
		}
	}
	
	int x, y; 
	
	fstream SalesLog ("c:\\Temp\\SalesLog.txt", ios::app);

	while(! InFile.eof() )
	{
		InFile >> y >> x;
		
		Vacant[x-1][y-1] = 1;

		SalesLog <<"initialisation: ticket already sold in row " << y << " and seat " << x <<endl;
	}
	SalesLog.close();
	
	InFile.close();

}
void av_seats()
{
	for(int y = 0; y < 15; y++)
	{
		for(int x = 0; x < 30; x++)
		{
			if( Vacant[x][y] == 0)
			{
				cout << "#";
			}
			else
			{
				cout << "*";
			}
		}
		cout << endl;
	}
}
void seat_prices()
{
	int count;
	ifstream inputFile;
	inputFile.open("c:\\Temp\\Seat_Prices.txt");

	for (count =0; count < ARRAY_SIZE; count++)
		inputFile >> Seats[count];
		inputFile.close();

	for (count=0; count < ARRAY_SIZE; count++)
		cout<<Seats[count]<<endl;
		
}
void ticket_sales()
{
	double total = 0;
	int Count = 0;

	for(int x = 0; x < 30; x++)
	{
		for(int y = 0; y < 15; y++)
		{
			if(	Vacant[x][y] == 1 )
			{
				total += Seats[y];	
				Count++;
			}
		}
	}

	cout << "The total number of sales made was " << Count << " for $" << total << endl;
}

void ticket_purchase()
{
	cout<<"Please enter the row and seat number"<<endl;
	int x = 0, y = 0;

	cin >> y >> x;

	while( y < 1 || y > 15 || x < 1 || x > 30)
	{	
		cout << "Invalid row, seat combination. Enter again: " << endl;
		cin >> y >> x;
	}
	
	while( Vacant[x-1][y-1] == 1)
	{
		cout << "Seat Taken. Please enter again: " << endl;
		cin >> y >> x;
	}

	Vacant[x-1][y-1] = 1;
	
	ofstream outFile("C:\\Temp\\TicketsSold.txt");

	fstream SalesLog("C:\\temp\\SalesLog.txt", ios::app);

	for(int y=0; y<15; y++)
	{
		for (int x=0; x<30; x++)
		{
			if (Vacant[x][y]==1)
			{
				outFile << (y+1) << " " << (x+1) << endl;
				SalesLog <<"Purchase: Ticket in row " << (y+1) << " and seat " << (x+1) <<endl;
			}
		}
	}
		
	SalesLog.close();
	outFile.close();
}

void EXIT()
{
	exit(0);
}