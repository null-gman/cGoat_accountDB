
how much you forget your account(e-mails) or even your gaming account for steam or else ? a lot right , me ether ,
because that i created :
# accoutDB

An Account Management CLI Program that allows you to easily add new accounts and update them, using SQLite3 as the database management system (DBMS). The program runs anywhere via CMD or any terminal by adding it to the PATH variable on your computer. It also retrieves and accesses a specific database file using a Windows registry key. The program features a user-friendly interface for seamless account management.

### so how this app solve my problem ?

i'm fa-miler with cli programs like vim and even my translator [owlTranslatero](https://github.com/null-gman/Translation_owl_js) , so i open my terminal by shortcut so i use my useful programs any time any ware in my computer .

#### but where the dataBase ? 

I used sqlite3 as DBMS to store accounts in account Table in account.db , the file PATH you can modify it in windows registry at : "Computer\HKEY_CURRENT_USER\SOFTWARE\onull_accountDB" -> KEY = "DB_PATH" VALUE = "PATH" 

    note: the table will named as account !!



### program structure

accountDB
└── accountDB.exe
└── accountDB.db

## usage

1. the program will check is there DATABASE if not will create one .
2. then you can chose method to work with (type somsing and press enter to choose or type nothing and press enter to skip)
3. type ".exit" to close the methode or close the program .

#### methods 
 - read
 - └──  read all 
 - └──  read by id 
 - └──  read by category 
 - └──  rad by domain
 - add account 
 - update account
 - delete account
 - options
 - └── get directory
 - └── set  directory
 - └── create BACKUP
 - └── set BACKUP
