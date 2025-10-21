#include <iostream>
using namespace std;

class Account
{
private:
  int balance;

public:
  Account(int balance = 1000)
  {
    this->balance = balance;
  }
  void display()
  {
    cout << "Balance: " << balance;
  }
  friend class Transaction; // Friend Class
};
class Transaction
{
  int privateTransaction;
public:
  Transaction(){
    privateTransaction = 20;
  }
  void withdraw(Account &accountObj1, int amount)
  {
    if (amount <= accountObj1.balance)
    {
      accountObj1.balance -= amount;
      cout << "Updated Balance: " << accountObj1.balance;
    }
    else
    {
      cout << "Insufficient Funds";
    }
  }

  friend void deposit(Transaction &tObj); // Friend Function
};

void deposit(Transaction &tObj){ // Friend Function
  cout<<tObj.privateTransaction<<"\n";
}

int main()
{
  Account accountObj(500);
  Transaction transactionObj;

  accountObj.display();
  cout << "\n";
  transactionObj.withdraw(accountObj, 300);
  cout << "\n";
  accountObj.display();
  cout << "\n";
  deposit(transactionObj);
}