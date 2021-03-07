#include<bits/stdc++.h>
#include<string>
#include<fstream>
#include<iostream>

using namespace std;

class account {
    string account_number;
    char type;
    double balance;

    public:
        account() {
            account_number = "";
            type = ' ';
            balance = -1.0;
        }

        account(string an, char t, double b) {
            account_number = an;
            type = t;
            balance = b;
        }

        string get_account_number() {
            return account_number;
        }

        void set_account_number(string s) {
            account_number = s;
        }

        char get_type() {
            return type;
        }

        void set_type(char c) {
            type = c;
        }

        double get_balance() {
            return balance;
        }

        void set_balance(double d) {
            balance = d;
        }

        void increment_balance(double d) {
            balance += d;
        }

        void decrement_balance(double d) {
            balance -= d;
        }
};

class loan: public account {
    private: int loanamount;

    public:
        loan() {
            loanamount = 0;
        }
        loan(int amount) {
            loanamount = amount;
            cout << "\nparameterized constructor of loan invoked";
        }

        int getloanamount() {
            return loanamount;
        }
        void setloanamount(int amount) {
            loanamount = amount;
        }
        ~loan() {
            cout << "\ndestructor of loan class invoked";
        }
};

class savings: public virtual account {
    private: int creditamount;

    public:
        savings() {
            cout << "\nempty constructor of savings invoked";
        }
        savings(int amount) {
            creditamount = amount;
            cout << "\nparameterized constructor of savings invoked";
        }
        ~savings() {
            cout << "\ndestructor of savings class invoked";
        }
        void setcreditamount(int credamount) {
            creditamount = credamount;
        }
        int getcreditamount() {
            return creditamount;
        }
};

void printmessage() {
    cout << "Thanks for watching and giving a second chance";
}

//Implementing exception handling for file opening
int get_accountcount(string filename) {
    int lines = 0;
    string temp;
    ifstream f;
    f.exceptions ( ifstream::badbit );
    try {
        f.open (filename);
        while (getline(f, temp))
        lines++;
    }
    catch (const ifstream::failure& e) {
        cout << "Exception opening/reading file";
    }
    f.close();
    return lines;
}

void read_accounts(string filename, account * acclist) {
    ifstream accountsFile(filename);
    string temp;
    int index = 0;

    while (getline(accountsFile, temp, '|')) {
        acclist[index].set_account_number(temp);

        getline(accountsFile, temp, '|');
        acclist[index].set_type(temp[0]);

        getline(accountsFile, temp);

        acclist[index++].set_balance(stod(temp));
    }

    accountsFile.close();
}

void read_transactions(string filename, account * acclist, int size) {
    ifstream transactionFile(filename);
    string temp;
    int accIndex;
    char depwith;

    while (getline(transactionFile, temp, '|')) {
        for (int j = 0; j < size; j++) {
            if (acclist[j].get_account_number().compare(temp) == 0) {
                accIndex = j;
                break;
            }
        }

        getline(transactionFile, temp, '|');
        depwith = temp[0];

        getline(transactionFile, temp);

        switch (depwith) {
            case 'D':
            case 'd':

                acclist[accIndex].increment_balance(stod(temp));
                break;

            case 'W':
            case 'w':
                if (stod(temp) > acclist[accIndex].get_balance())
                    cout << "Attempted to withdraw more than the account balance" << endl;
                else
                    acclist[accIndex].decrement_balance(stod(temp));
                    break;
        }
    }

    transactionFile.close();
}

void output_accounts(string filename, account * acclist) {
    ofstream newList(filename);

    int index = 0;
    while (acclist[index].get_balance() != -1) {
        cout << "Account Name: " << acclist[index].get_account_number() << "\nAccount Type: " << acclist[index].get_type() << "\nAccount Bal: " <<
        acclist[index].get_balance() << endl << endl;
        newList << acclist[index].get_account_number() << "|" << acclist[index].get_type() << "|" << acclist[index++].get_balance() << endl;
    }

    newList.close();
}

int main() {
    vector < int > g1;
    int no = get_accountcount("accounts.txt") + 5; // keep a small buffer for future accounts
    account * acclist = new account[no];

    read_accounts("accounts.txt", acclist); // read accounts data to array
    read_transactions("transactions.txt", acclist, no); // apply transactions to accounts
    output_accounts("newaccounts.txt", acclist); // output accounts final details to file and console
    printmessage();
    //for inheritance
    loan l;
    l.setloanamount(20000);
    cout << "\nLoan amount = " << l.getloanamount();
    cout << "\n The savings made are = " << l.getloanamount() * 0.2;
    savings s;
    s.setcreditamount(20);
    cout << "\nValue obtained using getter method of savings class:" << s.getcreditamount();

    return 0;
}
