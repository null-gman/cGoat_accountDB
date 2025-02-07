how much you forget your account(e-mails) or even your gaming account for steam or else ? a lot right , me ether , because that i created :

# accoutDB

An Account Management CLI Program that allows you to easily add new accounts and update them, using SQLite3 as the database management system (DBMS). The program runs anywhere via CMD or any terminal by adding it to the PATH variable on your computer. It also retrieves and accesses a specific database file using a Windows registry key. The program features a user-friendly interface for seamless account management.

### so how this app solve my problem ?

i'm fa-miler with cli programs like vim and even my translator [owlTranslatero](https://github.com/null-gman/Translation_owl_js) , so i open my terminal by shortcut so i use my useful programs any time any ware in my computer .

### but where the dataBase ?

I used sqlite3 as DBMS to store accounts in account Table in account.db , the file PATH you can modify it in windows registry at : "Computer\HKEY_CURRENT_USER\SOFTWARE\onull_accountDB" -> KEY = "DB_PATH" VALUE = "PATH"

note: the table will named as account !!
### Database Structure

The **accountDB** program uses a single database table called `account` to store all your account information. Here's what each field represents:


| **Field**   | **Type**       | **Description**                                                      |
| ----------- | -------------- | -------------------------------------------------------------------- |
| `id`  (int) | Auto-increment | A unique ID automatically generated for each account entry.          |
| `username`  | Text (255)     | The username associated with the account.                            |
| `email`     | Text (255)     | The email address for the account.                                   |
| `domain`    | Text (255)     | The domain of the account (e.g.,`gmail.com`, `steam.com`).           |
| `category`  | Text (255)     | A category to organize accounts (e.g.,`gaming`, `work`, `personal`). |
| `password`  | Text (255)     | The password for the account.                                        |
| `note`      | Text (255)     | Optional notes for additional details like recovery info, etc.       |

---

### program structure

MAIN FOLDER THAT IN REGISTRY
└── accountDB.exe
└── accountDB.db
└── BACKUP_ACCOUNTDB.db

## usage

1. On startup, the program checks for the existence of a database. If it doesn’t exist, it creates one automatically.
2. Choose a method to interact with the database (type an option and press Enter).
   - To skip a method, just press Enter without typing anything.
3. Use `.exit` to exit a method or close the program.
4. single ' quotes or double " are not allowed

### methods

- read
  └── read all
  └── read by id
  └── read by category
  └── rad by domain
- add account
- update account
- delete account
- options
  └── get directory
  └── create BACKUP
  └── set BACKUP

### notes

- The program uses the **HKEY_CURRENT_USER** registry under `SOFTWARE`.
- The registry key is named **onull_accountDB**.
- The registry value **DB_PATH** specifies the database directory.

### compilation 

1. run `node compileMain.js` This compiles `main.c` into `app.exe`.
2. run `node compileInstall.js`  This compiles `install.c` into `installApp.exe`.
