# Banking System Project

This is a simple console-based Banking System developed as a final project for the Computer Programming I course. It allows users to create accounts, login, view balances, deposit, withdraw, transfer money, update account details, and delete accounts. Additionally, it includes an admin interface for viewing and deleting user accounts.

## Features

- **Create Account:** Users can create new accounts with a unique username and password.
- **Login:** Users can login with their credentials.
- **View Balance:** Users can view their current balance.
- **Deposit:** Users can deposit money into their account.
- **Withdraw:** Users can withdraw money from their account.
- **Transfer:** Users can transfer money to other users.
- **Update Account:** Users can update their username or password.
- **Delete Account:** Users can delete their account.
- **Admin Login:** Admins can login to view and delete any user account.

## Getting Started

### Prerequisites

- C++ Compiler (e.g., GCC)
- Standard C++ Library

### Installation

1. Clone the repository:
    ```sh
    git clone https://github.com/abelgideon/Banking-System.git
    ```
2. Navigate to the project directory:
    ```sh
    cd Banking-System
    ```

### Compilation

Compile the project using a C++ compiler:
```sh
g++ -o bankingSystem bankingSystem.cpp
```

## Running

Run the compiled program:
```sh
./bankingSystem
```

## Usage

### Create Account:

- Choose the option to create a new account.
- Enter a unique username and password.

### Login:

- Choose the login option.
- Enter your username and password.

### User Menu:

- After logging in, users can view balance, deposit, withdraw, transfer money, update account, or delete account.

### Admin Login:

- Enter the admin username and password.
- View or delete user accounts.

## Admin Credentials

- Username: admin
- Password: admin

## File Structure

- main.cpp: The main source file containing all the functionalities.
- usernames.txt: Stores usernames.
- passwords.txt: Stores passwords.
- balances.txt: Stores user balances.

## Example

### Creating an Account

--- Banking System ---
1. Create Account
2. Login
3. Admin Login
4. Exit

\>\> 1

Enter username: user1

Enter password: pass1

Account Created!

### Logging in and Viewing Balance

--- Banking System ---
1. Create Account
2. Login
3. Admin Login
4. Exit

\>\> 2

Enter username: user1

Enter password: pass1

Logged in!

--- user1's Account ---
1. View Balance
2. Deposit
3. Withdraw
4. Transfer
5. Update Account
6. Delete Account
7. Log out

\>\> 1

Your balance is 0 birr

## Contributing

Contributions are welcome! Please feel free to submit a Pull Request.