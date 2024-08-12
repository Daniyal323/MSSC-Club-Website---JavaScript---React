#include <iostream>
#include <string>
#include <fstream>
#include<stdlib.h>
#include<conio.h>
using namespace std;

const int MAX = 20;

char option;  //  FOR Registration Menu

class Passenger  //   FOR Passenger Details
{
protected:
    string psg_Name, psg_Cnic, psg_Phone, psg_Train, psg_Destination, psg_Class;
    int psg_Seats;

public:
    Passenger()
    {
        psg_Name = "NULL";
        psg_Cnic = "0000000000000";
        psg_Phone = "00000000000";
        psg_Train = "Null";
        psg_Seats = 0;
        psg_Destination = "NULL";
        psg_Class = "NULL";
    }

    Passenger(string name, string cnic, string phone, string train, string dest, string clss, int seats)
    {
        psg_Name = name;
        psg_Cnic = cnic;
        psg_Phone = phone;
        psg_Train = train;
        psg_Seats = seats;
        psg_Destination = dest;
        psg_Class = clss;
    }

    friend Passenger PSG_Input(Passenger PASSenger);
    friend void read_data(Passenger PASSEnger);
    friend int get_seats(Passenger PASSENGER);
    friend string get_Train(Passenger PASSENGEr);
    friend string get_class(Passenger PASSENGer);

};
Passenger PSG_Input(Passenger psg)
{
    int train_choice, cabin_choice; // train choice for selecting train switch and cabin for cabin switch
    cout << "\n-> Passenger DETAILS............... " << endl;
    cout << "() Enter your Name :   ";
    cin >> psg.psg_Name;

    cout << "() Enter your Contact_no :   ";
    cin >> psg.psg_Phone;

    cout << "() Enter your CNIC :   ";
    cin >> psg.psg_Cnic;

    cout << "() Enter your Destination :   ";
    cin >> psg.psg_Destination;

    cout << "() SELECT your Respective Train :   " << endl;
    cout << "<-----Press 1 For SHALIMAR EXPRESS----->" << endl
        << "------Press 2 For GREEN LINE----->" << endl
        << "....--Press 3 For JINNAH EXPRESS----->." << endl
        << ".....-Press 4 For ORANGE LINE----->." << endl;
    cout << "......Enter your option: ";
    cin >> train_choice;

    switch (train_choice)
    {
    case 1:
        psg.psg_Train = "Shalimar_Express";
        break;
    case 2:
        psg.psg_Train = "Green_Line";
        break;
    case 3:
        psg.psg_Train = "Jinnah_Express";
        break;
    case 4:
        psg.psg_Train = "Orange_Line";
        break;
    default:
        cout << "You have Entered invalid Input:)" << endl
            << "Please Try AGAIN" << endl;

    }

    cout << "() SELECT your Cabin Class :   " << endl;
    cout << "<-----Press 1 For FIRST CLASS----->" << endl
        << "------Press 2 For BUSSINESS CLASS----->" << endl
        << "....--Press 3 For ECONOMY CLASS----->." << endl;
    cout << "......Enter your option: ";

    cin >> cabin_choice;
    switch (cabin_choice)
    {
    case 1:
        psg.psg_Class = "first";
        break;
    case 2:
        psg.psg_Class = "Bussiness";
        break;
    case 3:
        psg.psg_Class = "Economy";
        break;
    default:
        cout << "You have Entered invalid Input:)" << endl
            << "Please Try AGAIN OR PRESS X FOR EXIT" << endl;
        break;

    }

    cout << "() Enter your no of seats for Reservation :   ";
    cin >> psg.psg_Seats;

    ofstream fout;
    fout.open("PSG_DETAILS.txt");
    /*cout << "\n--->  Your NAME :   " << psg.psg_Name << endl
        << "--->  Your CNIC :   " << psg.psg_Cnic << endl
        << "--->  Your CONTACT_NO :   " << psg.psg_Phone << endl
        << "--->  Your Destination : " << psg.psg_Destination << endl
        << "--->  Your Train  :   " << psg.psg_Train << endl
        << "--->  Your Cabin Class  :   " << psg.psg_Class << endl
        << "--->  Your reserved seats are :   " << psg.psg_Seats << endl;*/
    fout << psg.psg_Name << endl
        << psg.psg_Cnic << endl
        << psg.psg_Phone << endl
        << psg.psg_Destination << endl
        << psg.psg_Train << endl
        << psg.psg_Class << endl
        << psg.psg_Seats << endl;
    fout.close();

    return psg;
}

void read_data()
{
    ifstream fin;
    fin.open("PSG_DETAILS.txt");
    string str;
    getline(fin, str, '\n');
    cout << "\n--->  Your NAME :   " << str << endl;
    getline(fin, str, '\n');
    cout << "--->  Your CNIC :   " << str << endl;
    getline(fin, str, '\n');
    cout << "--->  Your CONTACT_NO :   " << str << endl;
    getline(fin, str, '\n');
    cout << "--->  Your Destination : " << str << endl;
    getline(fin, str, '\n');
    cout << "--->  Your Train  :   " << str << endl;
    getline(fin, str, '\n');
    cout << "--->  Your Cabin Class  :   " << str << endl;
    getline(fin, str, '\n');
    cout << "--->  Your reserved seats are :   " << str << endl;
    getline(fin, str, '\n');
    fin.close();
}
int get_seats(Passenger PASSENGER) // Friend function as a Getter function...... 
{
    return PASSENGER.psg_Seats;
}

string get_Train(Passenger PASSENGEr)
{
    return PASSENGEr.psg_Train;
}

string get_class(Passenger PASSENGer)
{
    return PASSENGer.psg_Class;
}


class Train //Trains DEtails i.e. name,capacity,class 
{
protected:
    char** Train_Name;
    char** Train_class;
    int* Train_Capacity;
    int* Train_price;

public:

    Train(char** trn, char** clss, int* trn_cpcty, int* trn_prce)
    {
        Train_Name = trn;
        Train_Capacity = trn_cpcty;
        Train_class = clss;
        Train_price = trn_prce;
    }

    void Trains_list_display()
    {
        cout << "\n////////////TRAINS Details are as follows///////////////" << endl;
        for (int i = 0; *Train_Name != nullptr && i < 4; i++)
        {
            cout << "Train Name :   " << Train_Name[i] << endl << endl;
            cout << "            First Class Price                Bussiness Class Price                   Economy Class Price" << endl;
            cout << "Prices:      " << Train_price[0] << "                            " << Train_price[1] << "                                \t" << Train_price[2] << endl;
            switch (i)
            {
            case 0:
                cout << "Capacity:    " << Train_Capacity[i] << "                               " << Train_Capacity[i + 1] << "                                   \t " << Train_Capacity[i + 2] << endl << endl;
                break;
            case 1:
                cout << "Capacity:    " << Train_Capacity[i+2] << "                               " << Train_Capacity[i + 3] << "                                   \t " << Train_Capacity[i + 4] << endl << endl;
                break;
            case 2:
                cout << "Capacity:    " << Train_Capacity[i+4] << "                               " << Train_Capacity[i + 5] << "                                   \t " << Train_Capacity[i + 6] << endl << endl;
                break;
            case 3:
                cout << "Capacity:    " << Train_Capacity[i+6] << "                               " << Train_Capacity[i + 7] << "                                   \t " << Train_Capacity[i + 8] << endl << endl;
                break;
            }
        }
    }

    void Revised_Trains_Details(Passenger passenger)
    {
        for (int i = 0; Train_Name[i] != nullptr; i++)
        {
            for (int j = 0; Train_class[j] != nullptr;j++)
            {
                
                if ((Train_Name[i] == get_Train(passenger)) && (Train_class[j] == get_class(passenger)))
                {
                    switch (i)
                    {
                    case 0:
                        if(Train_Capacity[j]-=get_seats(passenger) >= 0) // condition to check whether the seats are avaliable or not///
                            {Train_Capacity[j]-=get_seats(passenger);}
                        else
                        {
                            cout<<"\nOOPs Sorry Seats are not available a the moment, Try some other train"<<endl;
                        }
                        break;
                    case 1:
                        if(Train_Capacity[j+3]-=get_seats(passenger) >= 0) // condition to check whether the seats are avaliable or not///
                            {Train_Capacity[j]-=get_seats(passenger);}
                        else
                        {
                            cout<<"\nOOPs Sorry Seats are not available a the moment, Try some other train"<<endl;
                        }
                        break;
                    case 2:
                        if(Train_Capacity[j+6]-=get_seats(passenger) >= 0) // condition to check whether the seats are avaliable or not///
                            {Train_Capacity[j]-=get_seats(passenger);}
                        else
                        {
                            cout<<"\nOOPs Sorry Seats are not available a the moment, Try some other train"<<endl;
                        }
                        break;
                    case 3:
                        if(Train_Capacity[j+9]-=get_seats(passenger) >= 0) // condition to check whether the seats are avaliable or not///
                            {Train_Capacity[j]-=get_seats(passenger);}
                        else
                        {
                            cout<<"\nOOPs Sorry Seats are not available a the moment, Try some other train"<<endl;
                        }
                        break;
                    }
                }
            }
        }
    }
};

void Seat_resevation(Train* Ptr, char** Trname)              // for Reservation 
{
    Ptr->Trains_list_display();

    Passenger pssngr;
    

    Ptr->Revised_Trains_Details(PSG_Input(pssngr));
    Ptr->Trains_list_display();

    ofstream fin;
    fin.open("Train.txt");
    for (int i = 0; i < 42; i++)
    {
        fin << Trname[i];
    }
    fin.close();

}

void Registration_Menu(Train* PTr, char** TRname)
{
    do
    {
        cout << "<-----------------Pakistan Railway----------------->" << endl;
        cout << "<--------------Train Reservation System------------>" << endl << endl
            << "...............Press 'B' Booking..........." << endl
            << "...............Press 'C' Cancellation..........." << endl
            << "...............Press 'A' Train Availability..........." << endl
            << "...............Press 'S' Ticket Status................." << endl
            << "...............Press 'X' EXIT Registration..........." << endl;
        cout << "Enter your option: ";

        option = getchar();
        switch (option)
        {
        case 'B':
        {
            Seat_resevation(PTr, TRname);
            cin.ignore();
            break;
        }
        case 'C':
        {
            ofstream fout;
            fout.open("PSG_DETAILS.txt");
            fout.close();
            cout<<"\n Your Ticket has been cancelled :) "<<endl;
            break;
        }
        case 'X':
        {
            break;
        }
        case 'S':
        {
            read_data();
            break;
        }
        case 'A':
            PTr->Trains_list_display();
            break;

        default:
        {
            cout << "\n-------------You Have Entered an invalid input------------:)\n\n" << endl;
        }
        }
    } while (option != 'X');
}

int main()
{
    char* trname[100] = { "Shalimar_Express", "Green_Line", "Jinnah_Express","Orange_Line",nullptr };
    char* trclass[30] = { "first","Bussiness","Economy",nullptr };
    int trcapacity[50] = { 50,80,150,50,80,150,50,80,150,50,80,150 };
    int trnprice[5] = { 8000,5000,3000 };

    Train* ptr = new Train(trname, trclass, trcapacity, trnprice);
    Registration_Menu(ptr, trname);
}