#include <iostream>
using namespace std;

// Lab 8 Task 1

class Account{

protected:
    int accNum;
    float bal;

public:

    Account()
    {
        accNum = 0;
        bal = 0;
    }

    Account(int acNo, float balance)
    {
        accNum = acNo;
        bal = balance;
    }

    virtual void setAccNum()
    {
        cout << "\nSet an Account Number: ";
        cin >> accNum;
    }

    int getAccNum(){return accNum;}

    float getBalance(){return bal;}

    virtual float deposit()
    {
        float dep;

        cout << "Enter Amount to Deposit: ";
        cin >> dep;

        bal += dep;

        return bal;
    }

    virtual float withdraw()=0;

    virtual void display()
    {
        cout << "\nAccount Number: " << accNum << endl;
        cout << "Balance: $" << bal << endl;
    }
};

class checkingAccount: public Account{

private:
    int intRate;
    float minBal;
    float servCharges;

public:
    checkingAccount():Account()
    {
        bal = 1000;
        intRate = 0;
        minBal = 0;
        servCharges = 0;
    }

    checkingAccount(int acNo, float balance ,int rate, float minbalance, float service):Account(acNo, balance)
    {
        intRate = rate;
        minBal = minbalance;
        servCharges = service;
    }

    void setInterestRate()
    {
        cout << "\nSet Interest Rate to: ";
        cin >> intRate;
    }

    int getInterestRate(){return intRate;}

    void setMinBal()
    {
        cout << "\nSet Minimum Balance to: $";
        cin >> minBal;
    }

    float getMinBal(){return minBal;}

    bool verifyBal()
    {
        if(bal < minBal)
        {
            cout << "\nYour Balance is below the Minimum Balance hence Service Charges to be deducted" << endl;

            return false;
        }
        else   
            cout << "\nSufficent Balance" << endl;
            return true;
    }

    void setServCharges()
    {
        cout << "\nSet Service Charges to: $";
        cin >> servCharges;
    }

    float getServCharges()
    {
        bal -= servCharges;

        return bal;
    }

    void postInterest()
    {
        bal += bal/100 * (intRate);

        cout << "Post Interest Balance: $" << bal << endl;
    }


    float withdraw()
    {
        float wd;

        cout << "\nEnter Amount to Withdraw: $";
        cin >> wd;

        bal -= wd;

        return bal;
    }

    void writeCheck()
    {
        if(bal > minBal)
        {
            float check;

            cout << "\nEnter Amount of the Check: $";
            cin >> check;

            bal -= check;

            cout << "Balance Remaining: $" << bal << endl;
        }
        else{
            cout << "\nInsufficent Balance to Write a Check" << endl;
        }
    }

    void display()
    {
        Account::display();
        cout << "Interest Rate: " << intRate << "%" << endl;
        cout << "Minimum Balance: $" << minBal << endl;
        cout << "Service Charges: $" << servCharges << endl;
    }
};

class savingsAccount: public Account{

private:
    int intRate;

public:

    savingsAccount(): Account()
    {
        intRate = 0;
    }

    savingsAccount(int acNo, float balance ,int rate) : Account(acNo, balance)
    {
        intRate = rate;
    }

    void setInterestRate()
    {
        cout << "\nSet Interest Rate to: ";
        cin >> intRate;
    }

    int getInterestRate(){return intRate;}

    void postInterest()
    {
        bal += bal/100 * (intRate);
        
        cout << "Post Interest Balance: $" << bal << endl;
    }

    float deposit()
    {
        float dep;

        cout << "\nEnter Amount to Deposit: $";
        cin >> dep;

        bal += dep;

        return bal;
    }
    
    float withdraw()
    {
        float wd;

        cout << "\nEnter Amount to Withdraw: $";
        cin >> wd;

        bal -= wd;

        return bal;
    }

    void display()
    {
        Account::display();
        cout << "Interest Rate: " << getInterestRate() << "%" << endl;
    }
};

bool cont()
{
    char in;
    cout << "\nPress any key to continue: ";
    cin >> in;

    return true;
}

int main()
{
    checkingAccount ca1;
    savingsAccount sa1;

    int menu;
    bool loop = true;
    bool running = true;
    char CorS;
    
    while (loop)
    {
        cout << "\n********** Banking System **********\n\n";
        cout << "Enter C to Open a Checking Account or S to Open a Savings Account: ";
        cin >> CorS;

        if (CorS == 'C' || CorS == 'c')
        {
            ca1.setAccNum();

            while (running)
            {
                cout << "\nEnter 1 to Set a Minimum Balance" << endl;
                cout << "Enter 2 to Set the Interest Rate and Check Post-Interest Balance" << endl;
                cout << "Enter 3 to Check whether or not to Pay Service Charges" << endl;
                cout << "Enter 4 to Make a Withdrawal" << endl;
                cout << "Enter 5 to Display Account Information" << endl;
                cout << "Enter 6 to Write a Check" << endl;
                cout << "Enter 7 to Exit" << endl;
                cout << "\n\nEnter Option: ";
                cin >> menu;

                switch (menu)
                {
                    case 1:
                        ca1.setMinBal();
                        running = cont();
                        break;

                    case 2:      
                        ca1.setInterestRate();
                        ca1.postInterest();
                        running = cont();
                        break;

                    case 3:     
                        if (ca1.verifyBal() == false)
                        {
                            ca1.setServCharges();
                            ca1.getServCharges();
                        }
                        running = cont();
                        break;

                    case 4:     
                        ca1.withdraw();
                        running = cont();
                        break;

                    case 5:     
                        ca1.display();
                        running = cont();
                        break;

                    case 6:     
                        ca1.writeCheck();
                        running = cont();
                        break;

                    case 7:
                        running = false;
                        loop = false;
                        break;

                    default:
                        cout << "\nInvalid Input\n";
                        break;
                }
            }
        }

        else if (CorS == 'S' || CorS == 's')
        {
            sa1.setAccNum();

            while (running)
            {
                cout << "\nEnter 1 to Make a Deposit" << endl;
                cout << "Enter 2 to Make a Withdrawal" << endl;
                cout << "Enter 3 to Set the Interest Rate and Check Post-Interest Balance" << endl;
                cout << "Enter 4 to Display Account Information" << endl;
                cout << "Enter 5 to Exit" << endl;
                cout << "\n\nEnter Option: ";
                cin >> menu;

                switch (menu)
                {
                    case 1:      
                        sa1.deposit();
                        running = cont();
                        break;

                    case 2:     
                        sa1.withdraw();
                        running = cont();
                        break;

                    case 3:     
                        sa1.setInterestRate();
                        sa1.postInterest();
                        running = cont();
                        break;

                    case 4:     
                        sa1.display();
                        running = cont();
                        break;

                    case 5:
                        running = false;
                        loop = false;
                        break;

                    default:
                        cout << "\nInvalid Input\n";
                        break;
                }
            }
        }

        else
            cout << endl << "Invalid Input" << endl;
    }

    return 0;
}
