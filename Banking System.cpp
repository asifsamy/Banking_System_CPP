#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cctype>
#include <conio.h>
#include <windows.h>

using namespace std;

class NumberAcc
{
protected:
    static int acc_num1;
public:
    static int getNumAc()
    {
        acc_num1++;
    }
};

int NumberAcc::acc_num1 = 101;

class Customer : public NumberAcc
{
protected:
    string name;
   // string acc_type;
    int acc_num;
public:
    Customer() : NumberAcc()
    {
        //acc_num = " ";
        name = " ";
       // acc_type = " ";
    }
  /*  Customer(string num, int n, string type)
    {
        acc_num = acc_num1;
        getAcc_num();
        name = n;
        acc_type = type;
    }*/
    void DeleteAccount()
    {
        this->acc_num = NULL;
        this->name = " ";
    }
    void OpenAccount()
    {
        acc_num = acc_num1;
        getNumAc();
        cout << "Enter Customer Name: ";
        cin >> name;
        fflush(stdin);
        /*cout << "Enter Account Type: ";
        cin >> acc_type;
        fflush(stdin);*/
    }
    void ShowInfo()
    {
        cout << endl;
        cout << "Account number: " << acc_num << "\t" << "Customer Name: " << name;// << "\t" << "Account Type: " << acc_type;
    }
    int getAcc_num()
    {
        return acc_num;
    }
    string getName()
    {
        return name;
    }
};

class Branch
{
protected:
    int id;
    string b_name;
    string address;
public:
    Branch()
    {
        id = 0;
        b_name = " ";
        address = " ";
    }
    Branch(int i, string bn, string ad)
    {
        id = i;
        b_name = bn;
        address = ad;
    }
    void CreateBranch()
    {
        cout << "Enter branch number(1,2,3,4,5): ";
        cin >> id;
        if (id==1)
            b_name = "Progoti Shoroni";
        else if (id==2)
            b_name = "Mouchak Branch";
        else if (id==3)
            b_name = "Agargao Branch";
        else if (id==4)
            b_name = "Motijhil Branch";
        else if (id==5)
            b_name = "Mohammadpur Branch";
        /*cout << "Enter Branch name: ";
        cin >> b_name;
        cout << "Address: ";
        cin >> address;*/
    }
    void ShowBranch()
    {
        cout << "\nBranch ID: " << id << "\t" << "Branch Name: " << b_name << endl;
        //cout << "Address: " << address << endl;
    }

};

class AccountSaving : public Customer, public Branch
{
    float sav_bal;
    string acc_type;
public:
    AccountSaving() : Customer(), Branch(), sav_bal(0.0), acc_type("savings") {}
   // AccountSaving(string num2, string n2, string type2, int i, string bn, string ad, float sb) : Customer(num2, n2, type2), Branch(i, bn, ad), sav_bal(sb) {}
   void DeleteAccount()
   {
       Customer::DeleteAccount();
       this->acc_type = " ";
       this->sav_bal = NULL;
   }
   string getAcc_typeS()
   {
       return acc_type;
   }
    void OpenAccountS()
    {
        Customer::OpenAccount();
        Branch::CreateBranch();
        sav_bal = 500.0;
    }
    void ShowAllInfo()
    {
        cout << getAcc_num() << "\t\t" << getName() << "\t\t" << acc_type << "\t\t" << sav_bal << endl;
    }
    void Show_Bal_Info()
    {
       // cout << "Branch ID: " << id << endl;
        Customer::ShowInfo();
        cout << "\tBalance: " << sav_bal << endl;
    }
    void Deposit_sav_bal()
    {
        float deposit,interest;
        cout << "Enter amount to deposit: ";
        cin >> deposit;
        sav_bal = sav_bal + deposit;
        interest = (sav_bal*2)/100;
        sav_bal = sav_bal + interest;
    }
    void Withdraw_sav_bal()
    {
        float withdraw;
        cout << "Enter amount to be withdraw: ";
        cin >> withdraw;
        sav_bal = sav_bal - withdraw;
        if (withdraw>sav_bal)
        {
            cout << "\n\nYou have to take permission to bank authority\n";
            sav_bal = sav_bal + withdraw;
        }
        else
            cout << "\nAfter withdraw your balance is: " << sav_bal << endl;
    }
    void TransferBalance(AccountSaving& payer, AccountSaving& payee)
    {
        float amount;
        cout << "\nEnter an amout of balance to be transfered: ";
        cin >> amount;
        if (payer.sav_bal>=amount)
        {
            payer.sav_bal-=amount;
            payee.sav_bal+=amount;
            cout << "\n\nCongratulation! your balance is transfered successfully\n";
        }
        else
            cout << "\n\nSorry! Insufficient Fund" << endl;
    }
    void modifySav_Account()
    {
        cout << "\nAccount no. : " << acc_num << endl;
        cout << "Modify account holder name: ";
        cin.ignore();
        cin >> name;
        fflush(stdin);
        cout << "Modify Balance: ";
        cin >> sav_bal;
    }
};

class Loan : public Customer, public Branch
{
protected:
    float lon;
public:
    Loan() : Customer(), Branch(), lon(0.0)
    { }
   // Loan(string an, string n, string ap, int i, string bn, string ad, float l) : Customer(an, n, ap), Branch(i, bn, ad), lon(l)
   // { }
    void OpenAccount()
    {
        Customer::OpenAccount();
        Branch::CreateBranch();
        lon = 0.0;
    }
    void getLoan()
    {
        float amount;
        if (lon==0.0)
        {
            cout << "\n\nEnter amount for loan: ";
            cin >> amount;
            lon = amount + (amount * 0.10);
            cout << "\nYou have to paid with interest " << lon << " tk" << " within 1 year" << endl;
        }
        else
            cout << "\nSorry! You have previous loan" << endl;
    }

    void payLoan()
    {
       int payment;
       if(lon==0.0)
           cout << "\n\n\t You have no loan.";
       else
       {
           cout << "\n\n\t You have to pay " << lon;
           cout << "\n\nEnter your payment";
           cin >> payment;
           lon = lon - payment;
           if(lon<=0.0)
           {
               cout << "\n\nyour loan is paid.";
               lon=0.0;
           }
           else
               cout << "loan to be paid = " << lon;
       }
    }
    void ShowLoan()
    {
        Customer::ShowInfo();
        //Branch::ShowBranch();
        cout << "\tYour Loan is: " << lon << " tk" << endl;
    }
};

class AccountCurrent : public Loan
{
    string acc_type;
    float cur_bal;
public:
    AccountCurrent() : Loan(), cur_bal(0.0), acc_type("current") {}
 //  AccountCurrent(string num2, string n2, string type2, int i, string bn, string ad, float l, float cb) : Loan(num2, n2, type2, i, bn, ad, l), cur_bal(cb) {}
    void DeleteAccount()
    {
       Customer::DeleteAccount();
       this->acc_type = " ";
       this->cur_bal = NULL;
    }
    void OpenAccountC()
    {
        Loan::OpenAccount();
        cur_bal = 1000.0;
    }
    void Show_Bal_Info()
    {
       // Loan::ShowLoan();
        Customer::ShowInfo();
       // cout << "Branch ID: " << id << endl;
        cout << "\tBalance: " << cur_bal;
    }
    void ShowAllInfo()
    {
        cout << getAcc_num() << "\t\t" << getName() << "\t\t" << acc_type << "\t\t" << cur_bal << endl;
    }
    void Deposit_cur_bal()
    {
        float deposit;
        cout << "Enter amount to deposit: ";
        cin >> deposit;
        cur_bal = cur_bal + deposit;
    }
    void Witdraw_cur_bal()
    {
        float withdraw,penalty;
        cout << "Enter amount to be withdraw: ";
        cin >> withdraw;
        cur_bal = cur_bal - withdraw;
        if (cur_bal<500)
        {
            penalty = (500 - cur_bal)/10;
            cur_bal = cur_bal - penalty;
            cout << "\n\nBalance after deducting penalty: " << cur_bal;
        }
        else if (withdraw>cur_bal)
        {
            cout << "\n\nYou have to take permission to the authority\n";
            cur_bal = cur_bal + withdraw;
        }
        else
            cout << "\nAfter withdraw your balance is: " << cur_bal << endl;
    }
    void TransferBalance(AccountCurrent& payer, AccountCurrent& payee)
    {
        float amount;
        cout << "\nEnter an amout of balance to be transfered: ";
        cin >> amount;
        if (payer.cur_bal>=amount)
        {
            payer.cur_bal-=amount;
            payee.cur_bal+=amount;
            cout << "\n\nCongrates! your balance is transfered\n";
        }
        else
            cout << "\n\nSorry! Insufficient Fund" << endl;
    }
    void modify_Cur_Account()
    {
        cout << "\nAccount no. : " << acc_num << endl;
        cout << "Modify account holder name: ";
        cin.ignore();
        cin >> name;
        fflush(stdin);
        cout << "Modify Balance: ";
        cin >> cur_bal;
    }
};


int main()
{
    AccountSaving S[100];
    AccountCurrent C[100];
    int ac_num, pa_num, py_num;
    char pasword[10], ch, press;
    int i, j, key, cntS = 0, cntC = 0;
    char pass[] = "asifsamy";
    jump: cout << "\n\n\n\n\n\n\n\n\t\t\t" << "Password: ";



    for(i=0;i<8;i++)
    {
       ch = getch();
       pasword[i] = ch;
       ch = '*' ;
       cout << ch;
    }
    pasword[i] = '\0';

    if (strcmp(pasword, pass)==0)
    {
        //cout << "\nsomething";
        system("cls");
        do
        {
            cout << "\n\n\nBanking System";
            cout << "\n\n\tMain Menu";
            cout << "\n\t01. OPEN AN ACCOUNT";
            cout << "\n\t02. DEPOSIT MONEY";
            cout << "\n\t03. WITHDRAW MONEY";
            cout << "\n\t04. TRANSFER MONEY";
            cout << "\n\t05. BALANCE INQUAIRY";
            cout << "\n\t06. ALL ACCOUNT HOLDER'S LIST";
            cout << "\n\t07. MODIFY AN ACOOUNT INFORMATION";
            cout << "\n\t08. CLOSE AN ACCOUNT";
            cout << "\n\t09. Loan Information";
            cout << "\n\t10. Branch INFORMATION";
            cout << "\n\t11. EXIT";

            cout << "\n\nSelect Your Option (1-11): ";
            cin >> key;
            system("cls");
            switch (key)
            {
            case 1:
                cout << "Press 's' for saving account or 'c' for current account: ";
                cin >> press;
                if (press=='s')
                {
                    S[cntS].OpenAccountS();
                    cntS++;
                }
                else if (press=='c')
                {
                    C[cntC].OpenAccountC();
                    cntC++;
                }
                else
                    cout << "\nInvalid input";
                break;

            case 2:
                cout << "Press 's' for saving account or 'c' for current account: ";
                cin >> press;
                if (press=='s')
                {
                    cout << "\nEnter Account Number: ";
                    cin >> ac_num;
                    for (i=0;i<cntS;i++)
                    {
                        if (ac_num == S[i].getAcc_num())
                        {
                            S[i].Deposit_sav_bal();
                            break;
                        }
                    }
                    if (ac_num!=S[i].getAcc_num())
                        cout << "Invalid Account number!!!!" << endl;
                }
                else if (press=='c')
                {
                    cout << "\nEnter Account Number: ";
                    cin >> ac_num;
                    for (i=0;i<cntC;i++)
                    {
                        if (ac_num == C[i].getAcc_num())
                        {
                            C[i].Deposit_cur_bal();
                            break;
                        }
                    }
                    if (ac_num!=C[i].getAcc_num())
                        cout << "Invalid Account number!!!!" << endl;
                }
                else
                    cout << "\nInvalid input";
                break;

            case 3:
                cout << "Press 's' for saving account or 'c' for current account: ";
                cin >> press;
                if (press=='s')
                {
                    cout << "\nEnter Account Number: ";
                    cin >> ac_num;
                    for (i=0;i<cntS;i++)
                    {
                        if (ac_num == S[i].getAcc_num())
                        {
                            S[i].Withdraw_sav_bal();
                            break;
                        }
                    }
                    if (ac_num!=S[i].getAcc_num())
                        cout << "Invalid Account number!!!!" << endl;
                }
                else if (press=='c')
                {
                    cout << "\nEnter Account Number: ";
                    cin >> ac_num;
                    for (i=0;i<cntC;i++)
                    {
                        if (ac_num == C[i].getAcc_num())
                        {
                            C[i].Witdraw_cur_bal();
                            break;
                        }
                    }
                    if (ac_num!=C[i].getAcc_num())
                        cout << "Invalid Account number!!!!" << endl;
                }
                else
                    cout << "\nInvalid input";
                break;

            case 4:
                cout << "Press 's' for saving account or 'c' for current account: ";
                cin >> press;
                if (press=='s')
                {
                    cout << "\nEnter Account Number of Payer: ";
                    cin >> pa_num;
                    cout << "\nEnter Account Number of Payee: ";
                    cin >> py_num;
                    int m=0,n=0;
                    for (i=0;i<cntS;i++)
                    {
                        if (pa_num == S[i].getAcc_num())
                        {
                            m = i;
                            break;
                        }
                    }
                    for (j=0;j<cntS;j++)
                    {
                        if (py_num == S[j].getAcc_num())
                        {
                            n = j;
                            break;
                        }
                    }
                    S[i].TransferBalance(S[m], S[n]);
                }
                else if (press=='c')
                {
                    cout << "\nEnter Account Number of Payer: ";
                    cin >> pa_num;
                    cout << "\nEnter Account Number of Payee: ";
                    cin >> py_num;
                    int p=0,q=0;
                    for (i=0;i<cntS;i++)
                    {
                        if (pa_num == C[i].getAcc_num())
                        {
                            p = i;
                            //S[i].TransferBalance(S[i], S[j]);
                            break;
                        }
                    }
                    for (j=0;j<cntS;j++)
                    {
                        if (py_num == C[j].getAcc_num())
                        {
                            q = j;
                            break;
                        }
                    }
                    C[i].TransferBalance(C[p], C[q]);
                }
                else
                    cout << "\nInvalid input";
                break;

            case 5:
                cout << "Press 's' for saving account or 'c' for current account: ";
                cin >> press;
                if (press =='s')
                {
                    cout << "\nEnter Account Number: ";
                    cin >> ac_num;
                    for (i=0;i<cntS;i++)
                    {
                        if (ac_num == S[i].getAcc_num())
                        {
                            S[i].Show_Bal_Info();
                            break;
                        }
                    }
                    if (ac_num!=S[i].getAcc_num())
                        cout << "Invalid Account number!!!!" << endl;
                }
                else if (press =='c')
                {
                    cout << "\nEnter Account Number: ";
                    cin >> ac_num;
                    for (i=0;i<cntC;i++)
                    {
                        if (ac_num == C[i].getAcc_num())
                        {
                            C[i].Show_Bal_Info();
                            break;
                        }
                    }
                    if (ac_num!=C[i].getAcc_num())
                        cout << "Invalid Account number!!!!" << endl;
                }
                else
                    cout << "\nInvalid input";
                break;

            case 6:
                cout<<"\n\n\t\tACCOUNT HOLDER LIST\n\n";
                cout<<"=========================================================\n";
                cout<<"A/c no.         NAME            Type            Balance\n";
                cout<<"=========================================================\n";
                for (i=0;i<cntS;i++)
                {
                    S[i].ShowAllInfo();
                }
                for (j=0;j<cntC;j++)
                {
                    C[j].ShowAllInfo();
                }
                break;

            case 7:
                cout << "Press 's' for saving account or 'c' for current account: ";
                cin >> press;
                if (press =='s')
                {
                    cout << "\nEnter Account Number: ";
                    cin >> ac_num;
                    for (i=0;i<cntS;i++)
                    {
                        if (ac_num == S[i].getAcc_num())
                        {
                            S[i].modifySav_Account();
                            break;
                        }
                    }
                    if (ac_num!=S[i].getAcc_num())
                        cout << "Invalid Account number!!!!" << endl;
                }
                else if (press =='c')
                {
                    cout << "\nEnter Account Number: ";
                    cin >> ac_num;
                    for (i=0;i<cntC;i++)
                    {
                        if (ac_num == C[i].getAcc_num())
                        {
                            C[i].modify_Cur_Account();
                            break;
                        }
                    }
                    if (ac_num!=C[i].getAcc_num())
                        cout << "Invalid Account number!!!!" << endl;
                }
                else
                    cout << "\nInvalid input";
                break;

            case 8:
                cout << "Press 's' for saving account or 'c' for current account: ";
                cin >> press;
                if (press =='s')
                {
                    cout << "\nEnter Account Number: ";
                    cin >> ac_num;
                    for (i=0;i<cntS;i++)
                    {
                        if (ac_num == S[i].getAcc_num())
                        {
                            S[i].DeleteAccount();
                            break;
                        }
                    }
                    if (ac_num!=S[i].getAcc_num())
                        cout << "Invalid Account number!!!!" << endl;
                }
                else if (press =='c')
                {
                    cout << "\nEnter Account Number: ";
                    cin >> ac_num;
                    for (i=0;i<cntC;i++)
                    {
                        if (ac_num == C[i].getAcc_num())
                        {
                            C[i].DeleteAccount();
                            break;
                        }
                    }
                    if (ac_num!=C[i].getAcc_num())
                        cout << "Invalid Account number!!!!" << endl;
                }
                else
                    cout << "\nInvalid input";
                break;

            case 9:
                char g;
                cout << "Get Loan, Pay Loan or Show Loan(g or p or s): ";
                cin >> g;
                if (g=='g')
                {
                    cout << "\nEnter Account Number: ";
                    cin >> ac_num;
                    for (i=0;i<cntC;i++)
                    {
                        if (ac_num == C[i].getAcc_num())
                        {
                            C[i].getLoan();
                            break;
                        }
                    }
                    if (ac_num!=C[i].getAcc_num())
                        cout << "Invalid Account number!!!!" << endl;
                }
                else if (g=='p')
                {
                    cout << "\nEnter Account Number: ";
                    cin >> ac_num;
                    for (i=0;i<cntC;i++)
                    {
                        if (ac_num == C[i].getAcc_num())
                        {
                            C[i].payLoan();
                            break;
                        }
                    }
                    if (ac_num!=C[i].getAcc_num())
                        cout << "Invalid Account number!!!!" << endl;
                }
                else
                {
                    cout << "\nEnter Account Number: ";
                    cin >> ac_num;
                    for (i=0;i<cntC;i++)
                    {
                        if (ac_num == C[i].getAcc_num())
                        {
                            C[i].ShowLoan();
                            break;
                        }
                    }
                    if (ac_num!=C[i].getAcc_num())
                        cout << "Invalid Account number!!!!" << endl;
                }
                break;


            case 10:
                cout << "Press 's' for saving account or 'c' for current account: ";
                cin >> press;
                if (press =='s')
                {
                    cout << "\nEnter Account Number: ";
                    cin >> ac_num;
                    for (i=0;i<cntS;i++)
                    {
                        if (ac_num == S[i].getAcc_num())
                        {
                            S[i].ShowBranch();
                            break;
                        }
                    }
                    if (ac_num!=S[i].getAcc_num())
                        cout << "Invalid Account number!!!!" << endl;
                }
                else if (press =='c')
                {
                    cout << "\nEnter Account Number: ";
                    cin >> ac_num;
                    for (i=0;i<cntC;i++)
                    {
                        if (ac_num == C[i].getAcc_num())
                        {
                            C[i].ShowBranch();
                            break;
                        }
                    }
                    if (ac_num!=C[i].getAcc_num())
                        cout << "Invalid Account number!!!!" << endl;
                }
                else
                    cout << "\nInvalid input";
                break;


            }
        }while(key!=11);

    }

    else{
        system("cls");
        cout << "\n\n\n\n\n\n\n\t\t\tWrong password";
        goto jump;
    }
    return 0;
}

