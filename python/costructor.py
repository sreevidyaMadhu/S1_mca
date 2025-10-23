class Account:
    def __init__(self, acc_no, name, ac_type, bal):
        self.acc_no= acc_no
        self.name=name
        self.ac_type= ac_type
        self.bal= bal
        
    def deposit(self,amount):
        self.bal+=amount
        print(f"deposited rs.{amount} successfully")
        
    def withdraw(self,amount):
        if amount > self.bal:
            print("insufficient balance")
            return
        self.bal -= amount
        print(f"withdrawed rs.{amount} successfully")
        
    def display(self):
        print(f"Name:\t\t{self.name}\nAccount no:\t{self.acc_no}\nAccount type:\t{self.ac_type}\nBalance:\t{self.bal}")
        
account_no=int(input("enter the account no:"))
name=input("enter the name:")
account_type=input("enter the account type:")
member=Account(account_no,name,account_type,0)

while True:
    member.display()
    transaction=int(input("enter 1 to deposit,2 to withdraw:"))
    if transaction==1:
        member.deposit(int(input("enter the amount to deposit:")))
    elif transaction==2:
        member.withdraw(int(input("enter the amount to withdraw:")))