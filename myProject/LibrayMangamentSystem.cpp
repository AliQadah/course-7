#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <time.h>
using namespace std;

struct stBook
{
    int ID;
    string Title;
    string Author;
    string Category;
    int year;
    int TotalCopies;
    int AvailableCopies;
};

struct stMember
{
    int ID;
    string Name;
    string Phone;
    string Email;
};

struct stLoan
{
    int LoanID;
    int BookID;
    int MemberID;
    string BorrowDate;
    string DueDate;
    string ReturnDate;
    string Status;
};

vector<stBook> books;
vector<stMember> members;
vector<stLoan> loans;
string nowTime()
{
    time_t rawTime;
    time(&rawTime);
    string CurrentTime = ctime(&rawTime);
    CurrentTime.pop_back();
    return CurrentTime;
}
// book
void AddBook()
{
    stBook NewBook;
    cout << "please enter Book ID" << endl;
    cin >> NewBook.ID;
    cout << "please enter Book Title" << endl;
    getline(cin >> ws, NewBook.Title);
    cout << "please enter Book Author" << endl;
    getline(cin, NewBook.Author);
    cout << "please enter Book Category" << endl;
    getline(cin, NewBook.Category);
    cout << "please enter Book year" << endl;
    cin >> NewBook.year;
    cout << "please enter Total Copies" << endl;
    cin >> NewBook.TotalCopies;
    NewBook.AvailableCopies = NewBook.TotalCopies;
    for (int i = 0; i < books.size(); i++)
    {
        if (books[i].ID == NewBook.ID)
        {
            cout << "Book ID already Exists!" << endl;
            return;
        }
    }
    books.push_back(NewBook);
}
void EditBook()
{
    int Id = 0;
    bool isfound = false;
    cout << "plese enter book ID " << endl;
    cin >> Id;
    for (int i = 0; i < books.size(); i++)
    {

        if (books[i].ID == Id)
        {
            isfound = true;
            cout << "Enter New Title " << endl;
            getline(cin >> ws, books[i].Title);
            cout << "Enter New Author " << endl;
            getline(cin, books[i].Author);
            cout << "Enter New Year " << endl;
            cin >> books[i].year;

            cout << "Book updated Succesfully" << endl;
            break;
        }
    }
    if (!isfound)
    {
        cout << "book not found" << endl;
    }
}
void DeletBook()
{
    int id;
    cout << "please enter book id to delete" << endl;
    cin >> id;
    bool find = false;
    for (int i = 0; i < books.size(); i++)
    {
        if (books[i].ID == id)
        {
            books.erase(books.begin() + i);
            find = true;
            break;
        }
    }
    if (!find)
    {
        cout << "book not found" << endl;
    }
}
void DisplayAllBooks()
{
    if (books.size() == 0)
    {
        cout << "No books available" << endl;
        return;
    }
    for (int i = 0; i < books.size(); i++)
    {

        cout << "Book No." << i + 1 << ":" << endl;
        cout << "Id is : " << books[i].ID << endl;
        cout << "Title is :" << books[i].Title << endl;
        cout << "Author is :" << books[i].Author << endl;
        cout << "Category is :" << books[i].Category << endl;
        cout << "Copies is :" << books[i].TotalCopies << endl;
        cout << "Available Copies is :" << books[i].AvailableCopies << endl;
    }
}
void SearchBook()
{
    int id = 0;
    bool isfound = false;
    cout << "please enter id" << endl;
    cin >> id;
    for (int i = 0; i < books.size(); i++)
    {
        if (books[i].ID == id)
        {
            isfound = true;
            cout << "the book is found " << endl;
            cout << "ID:" << books[i].ID << endl;
            cout << "Title:" << books[i].Title << endl;
            cout << "Author:" << books[i].Author << endl;
            cout << "Category:" << books[i].Category << endl;
            cout << "Year:" << books[i].year << endl;
            cout << "Total Copies:" << books[i].TotalCopies << endl;
            cout << "Available Copies" << books[i].AvailableCopies << endl;
            break;
        }
    }

    if (!isfound)
    {
        cout << "book Not Found!" << endl;
    }
}
void Books()
{
    short Choose;
    do
    {
        cout << "===============BOOkS=================" << endl;
        cout << "\n\n";
        cout << "1. Add Book" << endl;
        cout << "2. Edit Book" << endl;
        cout << "3. Delete Book" << endl;
        cout << "4. Display All Book" << endl;
        cout << "5. Search Book" << endl;
        cout << "0. Back" << endl;
        cin >> Choose;

        switch (Choose)
        {
        case 1:
            AddBook();
            break;
        case 2:
            EditBook();
            break;
        case 3:
            DeletBook();
            break;
        case 4:
            DisplayAllBooks();
            break;
        case 5:
            SearchBook();
            break;
        case 0:
            break;
        default:
            cout << "your choose not found please try again";
            break;
        }
    } while (Choose != 0);
}
// members
void AddMember()
{
    stMember Member;
    cout << "please enter Member ID:" << endl;
    cin >> Member.ID;
    cout << "please enter Member Name" << endl;
    getline(cin >> ws, Member.Name);
    cout << "please enter Member Phone" << endl;
    getline(cin, Member.Phone);
    cout << "please enter Member Email" << endl;
    getline(cin, Member.Email);
    for (int i = 0; i < members.size(); i++)
    {
        if (members[i].ID == Member.ID)
        {
            cout << "Member ID already Exists!" << endl;
            return;
        }
    }
    members.emplace_back(Member);
}
void EditMember()
{
    int ID;
    bool isfound = false;
    cout << "please Enter Member ID" << endl;
    cin >> ID;
    for (int i = 0; i < members.size(); i++)
    {

        if (members[i].ID == ID)
        {
            isfound = true;

            cout << "Enter New Member Name" << endl;
            getline(cin >> ws, members[i].Name);
            cout << "Enter New Member Phone" << endl;
            getline(cin, members[i].Phone);
            cout << "Enter New Email" << endl;
            getline(cin >> ws, members[i].Email);
            cout << "The Edit Success" << endl;
            break;
        }
    }
    if (!isfound)
    {
        cout << "Member NOT Found" << endl;
    }
}
void DeletMember()
{
    int ID;
    cout << "please Enter Member ID" << endl;
    cin >> ID;
    bool isFound = false;
    for (int i = 0; i < members.size(); i++)
    {

        if (members[i].ID == ID)
        {
            members.erase(members.begin() + i);
            isFound = true;
            break;
        }
    }
    if (!isFound)
    {
        cout << "Members NOT FOUND" << endl;
    }
}
void DisplayAllMembers()
{
    if (members.size() == 0)
    {
        cout << "NO Members Available" << endl;
        return;
    }
    for (int i = 0; i < members.size(); i++)
    {
        cout << "Members ID is :" << members[i].ID << endl;
        cout << "Members Name is :" << members[i].Name << endl;
        cout << "Members Phone is :" << members[i].Phone << endl;
        cout << "Members Email is :" << members[i].Email << endl;
    }
}
void SearchMember()
{
    int ID;
    bool isfound = false;
    cout << "please Enter Member ID" << endl;
    cin >> ID;
    for (int i = 0; i < members.size(); i++)
    {
        if (members[i].ID == ID)
        {
            isfound = true;
            cout << "Members Name is " << members[i].Name << endl;
            cout << "Members Phone is " << members[i].Phone << endl;
            cout << "Members Email is " << members[i].Email << endl;
            break;
        }
    }
    if (!isfound)
    {
        cout << "Member NOT FOUND" << endl;
    }
}
void Members()
{
    short Choose;
    do
    {
        cout << "================MEMEBERS=============" << endl;
        cout << "\n\n";

        cout << "1. Add Members" << endl;
        cout << "2. Edit Member" << endl;
        cout << "3. Delete Member" << endl;
        cout << "4. Display All Members" << endl;
        cout << "5. Search Member" << endl;
        cout << "0. Back" << endl;

        cout << "please enter number" << endl;
        cin >> Choose;
        switch (Choose)
        {
        case 1:
            AddMember();
            break;
        case 2:
            EditMember();
            break;
        case 3:
            DeletMember();
            break;
        case 4:
            DisplayAllMembers();
            break;
        case 5:
            SearchMember();
            break;
        case 0:
            break;
        default:
            cout << "your choose not found please try again " << endl;
            break;
        }
    } while (Choose != 0);
}
// Loans
bool NewLoan(int MemberID, int BookID)
{
    stLoan NewLoan;
    cout << "please Enter Loan ID:" << endl;
    cin >> NewLoan.LoanID;
    cout << "Your BookID:" << endl;
    NewLoan.MemberID = MemberID;
    NewLoan.BookID = BookID;
    cout << NewLoan.BookID << endl;
    cout << "Borrow Date:" << endl;
    getline(cin >> ws, NewLoan.BorrowDate);
    cout << "please enter Due Date:" << endl;
    getline(cin, NewLoan.DueDate);
    cout << "Status is: ";
    NewLoan.Status = "Active";
    cout << NewLoan.Status << endl;
    for (int i = 0; i < loans.size(); i++)
    {
        if (loans[i].LoanID == NewLoan.LoanID)
        {
            cout << "Loan ID is Already Exists!" << endl;
            return false;
        }
    }
    loans.push_back(NewLoan);
    return true;
}
void BorrowBook()
{
    int MemberID = 0;
    int BookID = 0;
    cout << "please Enter Book ID:" << endl;
    cin >> BookID;
    cout << "Please Enter Member ID:" << endl;
    cin >> MemberID;
    bool isFoundMember = false;
    for (int i = 0; i < members.size(); i++)
    {
        if (members[i].ID == MemberID)
        {
            isFoundMember = true;
            break;
        }
    }
    if (!isFoundMember)
    {
        cout << "Member Not Found" << endl;
        return;
    }
    for (int i = 0; i < books.size(); i++)
    {
        if (books[i].ID == BookID)
        {
            if (books[i].AvailableCopies <= 0)
            {
                cout << "No Available Copies for this book" << endl;
                return;
            }

            if (NewLoan(MemberID, BookID))
            {
                books[i].AvailableCopies--;
                cout << "Book borrowed successfully" << endl;
            }
            return;
        }
    }
    cout << "Book Not Found" << endl;
}
void ReturnBook()
{
    int nLoan = 0;
    cout << "please enter Loan ID:" << endl;
    cin >> nLoan;
    bool isFound = false;
    for (int i = 0; i < loans.size(); i++)
    {
        if (loans[i].LoanID == nLoan)
        {
            isFound = true;
            if (loans[i].Status != "Active")
            {
                cout << "This loan was already returned" << endl;
                return;
            }
            loans[i].Status = "Returned";
            loans[i].ReturnDate = nowTime();

            for (int j = 0; j < books.size(); j++)
            {
                if (books[j].ID == loans[i].BookID)
                {
                    books[j].AvailableCopies += 1;
                    cout << "Book returned successfully" << endl;
                    return;
                }
            }
            cout << "Book for this loan not found" << endl;
            return;
        }
    }
    if (!isFound)
    {
        cout << "Loan not found" << endl;
    }
}
void ActiveLoans()
{
    for (int i = 0; i < loans.size(); i++)
    {
        if (loans[i].Status == "Active")
        {
            cout << "Loan ID = " << loans[i].LoanID << endl;
            cout << "Book ID = " << loans[i].BookID << endl;
            cout << "Member ID = " << loans[i].MemberID << endl;
            cout << "status = " << loans[i].Status << endl;
        }
    }
}
void LoanHistory()
{
    for (const auto &s : loans)
    {
        cout << "Loan ID = " << s.LoanID << endl;
        cout << "Book ID = " << s.BookID << endl;
        cout << "Member ID = " << s.MemberID << endl;
        cout << "status = " << s.Status << endl;
    }
}
void Loans()
{
    short choose = 0;
    do
    {

        cout << "==================LOANS==========" << endl;
        cout << "\n";
        cout << "1. Borrow Book" << endl;
        cout << "2. Return Book" << endl;
        cout << "3. Active Loans" << endl;
        cout << "4. Loan History" << endl;
        cout << "0. Back" << endl;

        cout << "\nplease Choose Number" << endl;
        cin >> choose;

        switch (choose)
        {
        case 1:
            BorrowBook();
            break;
        case 2:
            ReturnBook();
            break;
        case 3:
            ActiveLoans();
            break;
        case 4:
            LoanHistory();
            break;
        case 0:
            break;
        default:
            cout << "your choose not found please try again " << endl;
            break;
        }
    } while (choose != 0);
}
// Reports
void Reports()
{
    int totalCopies = 0;
    int availableCopies = 0;
    int ActiveLoans = 0;
    cout << "================Reports============" << endl;
    cout << "\n";
    cout << "1. Total Book = " << books.size() << endl;
    cout << "2. Total Members = " << members.size() << endl;
    for (int i = 0; i < books.size(); i++)

    {
        totalCopies += books[i].TotalCopies;
    }
    for (int i = 0; i < books.size(); i++)

    {
        availableCopies += books[i].AvailableCopies;
    }
    for (int i = 0; i < loans.size(); i++)

    {
        if (loans[i].Status == "Active")
        {
            ActiveLoans++;
        }
    }
    cout << "3. Total Copies = " << totalCopies << endl;
    cout << "4. Avalable Copies = " << availableCopies << endl;
    cout << "5. Active Loans = " << ActiveLoans << endl;
    cout << "0. Back" << endl;
}
void MainMenu()
{
    short choose;
    do
    {
        cout << "=======================================================" << endl;
        cout << "\t\tLIBRARY MANAGMENT SYSTEM" << endl;
        cout << "=======================================================" << endl;

        cout << "\n";
        cout << "1. Books" << endl;
        cout << "2. Members" << endl;
        cout << "3. Loans" << endl;
        cout << "4. Reports" << endl;
        cout << "0. Exit" << endl;
        cout << "\n\nChoose:" << endl;
        cin >> choose;
        switch (choose)
        {
        case 1:
            Books();
            break;
        case 2:
            Members();
            break;
        case 3:
            Loans();
            break;
        case 4:
            Reports();
            break;
        case 0:
            break;
        default:
            cout << "your choose not found please try again";
            break;
        }
    } while (choose != 0);
}
int main()
{
    MainMenu();
}
