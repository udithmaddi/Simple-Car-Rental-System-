#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <unistd.h> // for sleep function

using namespace std;

class Customer
{
public:
  string customerName;
  string carModel;
  string carNumber;
};

class Rent : public Customer
{
public:
  int days = 0;
  int rentalFee = 0;

  void getData()
  {
    cout << "\tPlease Enter your Name: ";
    cin >> customerName;
    cout << endl;

    do
    {
      cout << "\t======== Car Rental System ======== \n\n"
           << endl;
      cout << "\tPlease Select a Car" << endl;
      cout << "\tEnter 'A' for Tesla 2023." << endl;
      cout << "\tEnter 'B' for Hyundai 2020." << endl;
      cout << "\tEnter 'C' for Ford 2022." << endl;
      cout << endl;
      cout << "\tChoose a Car from the above options: ";
      cin >> carModel;
      cout << endl;

      if (carModel == "A")
      {
        system("clear"); // use "CLS" for Windows
        cout << "You have chosen Tesla model 2023" << endl;
        ifstream inA("A.txt");
        char str[200];
        while (inA.getline(str, 200))
        {
          cout << str << endl;
        }
        sleep(2);
      }
      else if (carModel == "B")
      {
        system("clear");
        cout << "You have chosen Hyundai model 2020" << endl;
        ifstream inB("B.txt");
        char str[200];
        while (inB.getline(str, 200))
        {
          cout << str << endl;
        }
        sleep(2);
      }
      else if (carModel == "C")
      {
        system("clear");
        cout << "You have chosen Ford model 2022" << endl;
        ifstream inC("C.txt");
        char str[200];
        while (inC.getline(str, 200))
        {
          cout << str << endl;
        }
        sleep(2);
      }
      else
      {
        cout << "Invalid Car Model. Please try again!" << endl;
      }
    } while (carModel != "A" && carModel != "B" && carModel != "C");

    cout << "--------------------------------------------------------------------------" << endl;
    cout << "Please provide the following information: " << endl;
    cout << "Please select a Car No.: ";
    cin >> carNumber;
    cout << "Number of days you wish to rent the car: ";
    cin >> days;
    cout << endl;
  }

  void calculate()
  {
    sleep(1);
    system("clear");
    cout << "Calculating rent. Please wait......" << endl;
    sleep(2);
    if (carModel == "A" || carModel == "a")
      rentalFee = days * 56;
    else if (carModel == "B" || carModel == "b")
      rentalFee = days * 60;
    else if (carModel == "C" || carModel == "c")
      rentalFee = days * 75;
  }

  void showRent()
  {
    cout << "\n                       Car Rental - Customer Invoice                  " << endl;
    cout << "	///////////////////////////////////////////////////////////" << endl;
    cout << "	| Invoice No. :" << "------------------|" << setw(10) << "#BnC92243" << " |" << endl;
    cout << "	| Customer Name:" << "-----------------|" << setw(10) << customerName << " |" << endl;
    cout << "	| Car Model :" << "--------------------|" << setw(10) << carModel << " |" << endl;
    cout << "	| Car No. :" << "----------------------|" << setw(10) << carNumber << " |" << endl;
    cout << "	| Number of days :" << "---------------|" << setw(10) << days << " |" << endl;
    cout << "	| Your Rental Amount is :" << "--------|" << setw(10) << rentalFee << " |" << endl;
    cout << "	| Caution Money :" << "----------------|" << setw(10) << "0" << " |" << endl;
    cout << "	| Advanced :" << "---------------------|" << setw(10) << "0" << " |" << endl;
    cout << "	 ________________________________________________________" << endl;
    cout << "\n";
    cout << "	| Total Rental Amount is :" << "-------|" << setw(10) << rentalFee << " |" << endl;
    cout << "	 ________________________________________________________" << endl;

    system("PAUSE");
    system("clear");

    ifstream inf("thanks.txt");
    char str[300];
    while (inf.getline(str, 300))
    {
      cout << str << endl;
    }
  }
};

class Welcome
{
public:
  void welcomeMessage()
  {
    ifstream in("welcome.txt");
    if (!in)
    {
      cout << "Cannot open input file.\n";
      return;
    }
    char str[1000];
    while (in.getline(str, 1000))
    {
      cout << str << endl;
    }
    sleep(1);
    cout << "\nStarting the program please wait....." << endl;
    sleep(1);
    cout << "\nLoading up files....." << endl;
    sleep(1);
    system("clear");
  }
};

int login()
{
  string pass = "";
  char ch;
  cout << "\n\n\n\n\n\n\n\n\tCAR RENTAL SYSTEM \n\n";
  cout << "\t------------------------------";
  cout << "\n\tLOGIN \n";
  cout << "\t------------------------------\n\n";
  cout << "\tEnter Password: ";
  ch = getchar();
  while (ch != '\n')
  {
    pass.push_back(ch);
    cout << '*';
    ch = getchar();
  }
  if (pass == "admin")
  {
    cout << "\n\n\n\tAccess Granted! \n";
    system("PAUSE");
    system("clear");
  }
  else
  {
    cout << "\n\n\tAccess Aborted...\n\tPlease Try Again\n\n";
    system("PAUSE");
    system("clear");
    login();
  }
  return 0;
}

int main()
{
  Welcome obj1;
  obj1.welcomeMessage();

  Rent obj2;
  obj2.getData();
  obj2.calculate();
  obj2.showRent();

  return 0;
}
