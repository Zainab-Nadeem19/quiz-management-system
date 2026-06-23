#include<iostream>
#include<string>
#include<windows.h>
#include<limits>
using namespace std;

// strcture
struct Student {
    string name;
    string subject;
    int score;
    Student* next;
};

// ===== FUNCTION DECLARATIONS =====
char getvalidchoice();
int takequiz(string subject);
void insertrecord(Student*& head,string name,string subject,int score);
void displayall(Student* head);
Student* searchIterative(Student* head, string name);
void selectionSort(Student*& head);

// ===== MAIN FUNCTION =====
int main() {
    Student* head = NULL;
    int n;

    cout << "\t\t========================\n";
    cout << "\t\t QUIZ MANAGEMENT SYSTEM\n";
    cout << "\t\t========================\n";

    cout << "How many students want to take quiz? ";
    cin >> n;

    for (int i = 1; i <= n; i++) {
        string name, subject;
        int choice, score, rollno;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        system("CLS");
        cout << "\nEnter student " << i << " name: ";
        getline(cin, name);
        cout << "Enter roll no: ";
        cin >> rollno;
        system("CLS");
		cout<<"\n=====quiz for"<<name<<"(Roll No: "<<rollno<< ")=====\n";
		
        cout<<"1. C++\n2. Java\n3. HTML\nChoice: ";
        cin>>choice;
        if (choice == 1) subject = "C++";
        else if (choice == 2) subject = "Java";
        else subject = "HTML";

        score = takequiz(subject);
        insertrecord(head, name, subject, score);
    }
    system("CLS");
	cout<<"____________result__________";
    int menu;
    do {
        cout<<"\n1. Display Records";
        cout<<"\n2. Search Student";
        cout<<"\n3. Sort by Score";
        cout<<"\n4. Exit";
        cout<<"\nEnter choice: ";
        cin>>menu;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        if (menu == 1) {
            displayall(head);
        }
        else if (menu == 2) {
            string key;
            cout<<"Enter name to search: ";
            getline(cin, key);

            Student* s =searchIterative(head, key);
            if (s)
                cout<<s->name<<"|"<<s->subject<< " | "<<s->score<<"/3\n";
            else
                cout << "Record not found!\n";
        }
        else if (menu == 3) {
            selectionSort(head);
            cout << "Sorted successfully!\n";
            displayall(head); 
        }

    } while (menu != 4);
    return 0;
}

// valid option(a,b,c,d)

char getvalidchoice() {
    char ch;
    while(true){
        cout<<"Enter A/B/C/D: ";
        cin>>ch;

        if (ch>='a'&&ch<='z')
            ch-=32;
        if (ch=='A'||ch=='B'||ch=='C'||ch=='D')
            return ch;
        cout<<"Invalid choice!\n";
    }
}

// quiz function
int takequiz(string subject) {
    int score = 0;
    char ans;

    if (subject == "C++") {
    	cout<<"\nQ1. Which of the following is an OOP concept?\n";
		cout<<"A.Polymorphism\n";
		cout<<"B.Macro\n";
		cout<<"C.Pointer\n";
		ans=getvalidchoice();
		if(ans=='A') {
    	cout<<"Correct ?\n";
    	score++;
	} else {
    cout << "Wrong Correct answer is: A. Polymorphism\n";
	}
	cout<<"\nQ2. Which concept binds data and functions together?\n";
	cout<<"B. Inheritance\n";
	cout<<"C. Encapsulation\n";
	cout<<"D. Object\n";
	ans=getvalidchoice();
	if(ans=='C') {
    cout<<"Correct?\n";
    score++;
	} else {
    cout<<"Wrong ? Correct answer is: C. Encapsulation\n";
	}
	cout << "\nQ3. Runtime polymorphism is achieved by?\n";
	cout << "A. Template\n";
	cout << "B. Overloading\n";
	cout << "C. Overriding\n";
	cout << "D. Constructor\n";
	ans = getvalidchoice();
	if (ans == 'C') {
    cout << "Correct ?\n";
    score++;
	} else {
    cout << "Wrong ?Correct answer is: C. Overriding\n";
	}
 
    }
    //java 
    else if(subject=="Java"){
    cout<<"\n1. Java is?\n";
    cout<<"A. Procedural\n";
    cout<<"B. OOP\n";
    cout<<"C. Markup\n";
    cout<<"D. Low-level\n";
    ans = getvalidchoice();
    if (ans == 'B') {
    	cout << "Correct ?\n";
	score++;
	}
	else {
    cout<<"Wrong ? Correct answer is: b. oop\n";
	}

    cout<< "\n2. JVM stands for?\n";
    cout<< "A. Java Virtual Machine\n";
    cout<< "B. Java View\n";
    cout<< "C. Java Value\n";
    cout<< "D. Java Visual\n";
    ans=getvalidchoice();
    if(ans=='A'){
    	cout << "Correct ?\n"; 
	score++;
	}
	else {
    cout<<"Wrong ? Correct answer is a.java virtual machine\n";
	}

    cout <<"\n3. Which keyword is used to create an object?\n";
    cout<<"A. make\n";
    cout<<"B. new\n";
    cout<<"C. create\n";
    cout<<"D. obj\n";
    ans=getvalidchoice();
    if(ans=='B'){
    	cout << "Correct ?\n";
	score++;
	}
	else {
    cout<<"Wrong ? Correct answer is: b.new\n";
	}
	}
	//html
	else {
    cout << "\n1. Full form of HTML?\n";
    cout << "A. Hyper Text Markup Language\n";
    cout << "B. High Text\n";
    cout << "C. Tool\n";
    cout << "D. None\n";
    ans = getvalidchoice();
    if (ans =='A') {
        cout << "Correct!\n";
        score++;
    } else {
        cout<<"Incorrect! Correct answer is A. Hyper Text Markup Language\n";
    }
    cout << "\n2. <br> tag is used for?\n";
    cout << "A. Bold\n";
    cout << "B. Break (new line)\n";
    cout << "C. Line\n";
    cout << "D. Color\n";
    ans = getvalidchoice();
    if (ans == 'B') {
        cout << "Correct!\n";
        score++;
    } else {
        cout << "Incorrect! Correct answer is B. Break (new line)\n";
    }
    cout << "\n3. File extension of HTML files?\n";
    cout << "A. .html\n";
    cout << "B. .ht\n";
    cout << "C. .web\n";
    cout << "D. .txt\n";
    ans = getvalidchoice();
    if (ans=='A') {
        cout << "Correct!\n";
        score++;
    } else {
        cout << "Incorrect! Correct answer is A. .html\n";
    }
}

return score;

}

// insert record
void insertrecord(Student*& head,string name,string subject,int score){
    Student* temp = new Student;
    temp->name = name;
    temp->subject = subject;
    temp->score = score;
    temp->next = NULL;

    if (!head)
        head = temp;
    else {
        Student* p = head;
        while (p->next)
            p = p->next;
        p->next = temp;
    }
}

// display all result

void displayall(Student* head) {
    cout << "\n--- STUDENT RECORDS ---\n";
    while (head) {
        cout << head->name << " | " << head->subject
             << " | " << head->score << "/3\n";
        head = head->next;
    }

}

// search by name
Student* searchIterative(Student* head, string name) {
    while (head) {
        if (head->name == name)
            return head;
        head = head->next;
    }
    return NULL;
}

// sort

void selectionSort(Student*& head) {
    if (!head || !head->next) return; // 0 or 1 node

    for (Student* i = head; i != NULL; i = i->next) {
        Student* maxNode = i;

        // Find node with max score in the remaining list
        for (Student* j = i->next; j != NULL; j = j->next) {
            if (j->score > maxNode->score) {
                maxNode = j;
            }
        }

        // Swap data of i and maxNode
        if (maxNode != i) {
            swap(i->name, maxNode->name);
            swap(i->subject, maxNode->subject);
            swap(i->score, maxNode->score);
        }
    }
}


