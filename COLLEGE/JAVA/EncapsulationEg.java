class BankAccount {
    private double balance;

    public void setBalance(double amount) {
      if (amount > 0)
        balance += amount;
      System.out.println("Deposited: " + amount);
    }

    public double getBalance() {
      return balance;
    }
  }
public class EncapsulationEg{
  public static void main(String[] args) {
    BankAccount myAccount = new BankAccount();
    myAccount.setBalance(2000);
    System.out.println("Balance: "+myAccount.getBalance());
  }
}