#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

void createAccount(vector<string> &usernames, vector<string> &passwords, vector<double> &balances);
bool login(vector<string> &usernames, vector<string> &passwords, int &userId);
void viewBalance(vector<double> &balances, int userId);
void deposit(vector<double> &balances, int userId);
void withdraw(vector<double> &balances, int userId);
void transfer(vector<string> &usernames, vector<double> &balances, int userId);
void updateAccount(vector<string> &usernames, vector<string> &passwords, int userId);
void removeAccount(vector<string> &usernames, vector<string> &passwords, vector<double> &balances, int &userId);
void uploadUserInfo(vector<string> usernames, vector<string> passwords, vector<double> balances);
void downloadUserInfo(vector<string> &usernames, vector<string> &passwords, vector<double> &balances);
void adminLogin(vector<string> &usernames, vector<string> &passwords, vector<double> &balances);

int main() {
    int userId;
    vector<string> usernames, passwords;
    vector<double> balances;
    vector<string> admin = {"admin", "admin"};

    downloadUserInfo(usernames, passwords, balances);
    
    int choice;
    while (true) {
        cout << "--- Banking System ---" << endl;
        cout << "1. Create Account\n2. Login\n3. Admin Login\n4. Exit" << endl; 
        cout << ">> ";
        cin >> choice;

        if (choice == 1) {
            createAccount(usernames, passwords, balances);
            
        } else if (choice == 2) {
            if (login(usernames, passwords, userId)) {
                cout << "\nLogged in!\n" << endl;
                int userChoice;
                while (true) {
                    cout << "--- " << usernames[userId] <<"'s Account ---" << endl;
                    cout << "1. View Balance\n2. Deposit\n3. Withdraw\n4. Transfer\n5. Update Account\n6. Delete Account\n7. Log out" << endl; 
                    cout << ">> ";
                    cin >> userChoice;

                    if (userChoice == 1)
                        viewBalance(balances, userId);
                    else if (userChoice == 2)
                        deposit(balances, userId);
                    else if (userChoice == 3)
                        withdraw(balances, userId);
                    else if (userChoice == 4)
                        transfer(usernames, balances, userId);
                    else if (userChoice == 5)
                        updateAccount(usernames, passwords, userId);
                    else if (userChoice == 6)
                        removeAccount(usernames, passwords, balances, userId);
                        if (userId == -1)
                            break;
                    else if (userChoice == 7)
                        break;
                }
                
            } else {
                cout << "\nInvalid username or password. Try again.\n" << endl;
            }

        } else if (choice == 3) {
            string adusername, adpassword;
           cout << "Enter admin username: ";
           cin >> adusername;
           cout << "Enter admin password: ";
           cin >> adpassword;

           if (adusername == admin[0] && adpassword == admin[1]) {
                cout << "\nAdmin Logged In!\n" << endl;
                adminLogin(usernames, passwords, balances);
           }
           else {
                cout << "\nInvalid admin username or passowrd. Try again.\n" << endl;
           }
        } else if (choice == 4) {
            break;
        }
    }

    uploadUserInfo(usernames, passwords, balances);
}

void createAccount(vector<string> &usernames, vector<string> &passwords, vector<double> &balances) {
    string username, password;
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;

    for (string usrname : usernames) {
        if (usrname == username) {
            cout << "\nUsername taken. Try again.\n" << endl;
            return;
        }
    }

    usernames.push_back(username);
    passwords.push_back(password);
    balances.push_back(0);

    cout << "\nAccount Created!\n" << endl;
}

bool login(vector<string> &usernames, vector<string> &passwords, int &userId) {
    string username, password;
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;

    for (int i = 0; i < usernames.size(); i++) {
        if (usernames[i] == username && passwords[i] == password) {
            userId = i;
            return true;
        }
    }
    return false;
}

void viewBalance(vector<double> &balances, int userId) {
    cout << "\nYour balance is " << balances[userId] << " birr\n" << endl;
}

void deposit(vector<double> &balances, int userId) {
    double depositAmount;
    cout << "Deposit amount: ";
    cin >> depositAmount;

    balances[userId] += depositAmount;
    cout << "\nYour current balance is " << balances[userId] << " birr\n" << endl;
}

void withdraw(vector<double> &balances, int userId) {
    double withdrawAmount;
    cout << "Withdrawal amount: ";
    cin >> withdrawAmount;

    if (balances[userId] >= withdrawAmount) {
        balances[userId] -= withdrawAmount;
        cout << "\nYour current balance is " << balances[userId] << " birr\n" << endl;
    } else {
        cout << "\nInsufficent balance. Try again.\n" << endl;
    }

}
void transfer(vector<string> &usernames, vector<double> &balances, int userId) {
    string receiver;
    int receiverId = -1;
    double transferAmount;
    cout << "Enter receiver's username: ";
    cin >> receiver;

    for (int i = 0; i < usernames.size(); i++) {
        if (usernames[i] == receiver) {
            receiverId = i;
            break;
        }
    }

    if (receiverId == -1) {
        cout << "\nReceiver's username not found. Try again.\n" << endl;
        return;
    }

    cout << "Enter transfer amount: ";
    cin >> transferAmount;

    if (balances[userId] >= transferAmount) {
        balances[receiverId] += transferAmount;
        balances[userId] -= transferAmount;
        cout << "\nYour current balance is " << balances[userId] << " birr\n" << endl;
    } else {
        cout << "\nInsufficent balance. Try again.\n" << endl;
    }
}

void updateAccount(vector<string> &usernames, vector<string> &passwords, int userId) {
    int userChoice;
    string newUsername, newPassword;
    
    do {
        cout << "1. Update username\n2. Update password\n3. Back" << endl;
        cout << ">> ";
        cin >> userChoice;

        if (userChoice == 1) {
            cout << "Enter new username: ";
            cin >> newUsername;

            for (string usrname : usernames) {
                if (usrname == newUsername) {
                cout << "\nUsername taken. Try again.\n" << endl;
                return;
                }    
            }
            usernames[userId] = newUsername;
            cout << "\nUsername updated!\n" << endl;

        } else if (userChoice == 2) {
            cout << "Enter new password: ";
            cin >> newPassword;

            passwords[userId] = newPassword;
            cout << "\nPassword updated!\n" << endl;
        }
    } while (userChoice != 3);
}

void removeAccount(vector<string> &usernames, vector<string> &passwords, vector<double> &balances, int &userId) {
    char userChoice;

    cout << "Are you sure you want to delete your account(Y/N): ";
    cin >> userChoice;

    if (userChoice == 'Y') {
        usernames.erase(usernames.begin() + userId);
        passwords.erase(passwords.begin() + userId);
        balances.erase(balances.begin() + userId);
        userId = -1;

        cout << "\nYour Account has been Deleted.\n" << endl;
        return;
    }
    else if (userChoice == 'N') {
        return;
    }
}

void uploadUserInfo(vector<string> usernames, vector<string> passwords, vector<double> balances) {
    ofstream usernamesFile("usernames.txt");
    for (string usr : usernames) {
        usernamesFile << usr << "\n";
    }
    usernamesFile.close();

    ofstream passwordsFile("passwords.txt");
    for (string pass : passwords) {
        passwordsFile << pass << "\n";
    }
    passwordsFile.close();

    ofstream balancesFile("balances.txt");
    for (double balance : balances) {
        balancesFile << balance << "\n";
    }
}

void downloadUserInfo(vector<string> &usernames, vector<string> &passwords, vector<double> &balances) {
    string line;

    ifstream usernamesFile("usernames.txt");
    while (getline(usernamesFile, line)) {
        usernames.push_back(line);
    }
    usernamesFile.close();

    ifstream passwordsFile("passwords.txt");
    while (getline(passwordsFile, line)) {
        passwords.push_back(line);
    }
    passwordsFile.close();

    ifstream balancesFile("balances.txt");
    while (getline(balancesFile, line)) {
        balances.push_back(stod(line));
    }
    balancesFile.close();
}

void adminLogin(vector<string> &usernames, vector<string> &passwords, vector<double> &balances) {
    while (true) {
        int adChoice;

        cout << "1. View Accounts\n2. Delete Account\n3. Logout" << endl;
        cout << ">> ";

        cin >> adChoice;

        if (adChoice == 1) {
            for (int i = 0; i < usernames.size(); i++) {
                cout << usernames[i] << endl;
            }
        }

        else if (adChoice == 2) {
            string delUsername;
            bool found = false;
            int delUsernameId;

            cout << "Enter username: ";
            cin >> delUsername;

            for (int i = 0; i < usernames.size(); i++) {
                if (delUsername == usernames[i]) {
                    delUsernameId = i;
                    found = true;
                    break;
                }
            }

            if (found) {
                usernames.erase(usernames.begin() + delUsernameId);
                passwords.erase(passwords.begin() + delUsernameId);
                balances.erase(balances.begin() + delUsernameId);

                cout << "\nAccount Deleted.\n" << endl;
            } else {
                cout << "\nUsername not found.\n" << endl;
            }
        }

        else if (adChoice == 3) {
            break;
        }
    }
}