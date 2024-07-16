#include <iostream>
#include <queue>
#include <string>
// #include <about.cpp>
#include <vector>

using namespace std;

class Doctor
{
public:
    string Doc_name;
    string Doc_qualification;
    string Doc_department;
    bool isavailable;
    int Doc_experience;
    int Doc_Id;
    Doctor()
    {
        this->Doc_name = Doc_name;
        this->Doc_qualification = Doc_qualification;
        this->Doc_department = Doc_department;
        this->isavailable = true;
        this->Doc_experience = Doc_experience;
        this->Doc_Id = Doc_Id;
    }
};
class Event
{
public:
    int Event_Id;
    string Event_name;
    string Event_date;
    string Event_time;
    string Event_Details;
    Event()
    {
        this->Event_Id = Event_Id;
        this->Event_name = Event_name;
        this->Event_date = Event_date;
        this->Event_time = Event_time;
        this->Event_Details = Event_Details;
    }
};
class registration
{
public:
    string reg_name;
    long long reg_cont_no;
    int E_id;
    int isdel;

    registration()
    {
        this->reg_name = reg_name;
        this->reg_cont_no = reg_cont_no;
        this->E_id = E_id;
        this->isdel = 0;
    }
};
class Linkedlist
{
public:
    // int data;
    Doctor D;
    Event E;
    Linkedlist *next;

    Linkedlist()
    {
        next = nullptr;
    }

    Linkedlist(Doctor D)
    {
        this->D = D;
        this->next = nullptr;
    }
    Linkedlist(Event E)
    {
        this->E = E;
        this->next = nullptr;
    }
};
class review
{
public:
    string nam;
    string data;
    bool isblock;

    review()
    {
        this->nam = nam;
        this->data = data;
        isblock = false;
    }
};
class appointment
{
public:
    string pat_name;
    int pat_age;
    string doc_name;
    string app_time;
    string mob_no;
    bool iscancel;

    appointment()
    {
        this->pat_name = pat_name;
        this->pat_age = pat_age;
        this->doc_name = doc_name;
        this->app_time = app_time;
        this->mob_no = mob_no;
        this->iscancel = false;
    }
};

// ***********Doctor********
void insertNode(Linkedlist *head1, Doctor D)
{
    Linkedlist *newNode = new Linkedlist(D);
    if (head1 != nullptr)
    {
        Linkedlist *temp = head1;

        while (temp->next != nullptr)
        {
            temp = temp->next;
        }
        temp->next = newNode;

        return;
    }
    head1 = newNode;
    return;
};
void printList(Linkedlist *head1)
{
    Linkedlist *temp = head1;

    if (head1 == nullptr)
    {
        cout << "List empty" << endl;
        return;
    }
    temp = temp->next;
    while (temp != nullptr)
    {
        cout << "Doctor Name : " << temp->D.Doc_name << endl;
        cout << "Qualification : " << temp->D.Doc_qualification << endl;
        cout << "Department : " << temp->D.Doc_department << endl;
        cout << "Experiance : " << temp->D.Doc_experience << endl;
        cout << "Doc ID : " << temp->D.Doc_Id << endl
             << endl;
        temp = temp->next;
    }
}
void printlist_dept(Linkedlist *head1, string dept)
{
    Linkedlist *temp = head1;

    if (head1 == nullptr)
    {
        cout << "List empty" << endl;
        return;
    }
    temp = temp->next;
    while (temp != nullptr)
    {
        if (temp->D.Doc_department == dept)
        {
            cout << "Doctor Name : " << temp->D.Doc_name << endl;
            cout << "Qualification : " << temp->D.Doc_qualification << endl;
            cout << "Experiance : " << temp->D.Doc_experience << endl;
        }
        temp = temp->next;
    }
}
void insert(Linkedlist *list, int n)
{
    if (n == 1)
    {
        Doctor D1;
        D1.Doc_name = "Dr Rahul Bais";
        D1.Doc_qualification = "MS";
        D1.Doc_department = "Cardiology";
        D1.Doc_experience = 8;
        D1.Doc_Id = 1001;

        Doctor D2;
        D2.Doc_name = "Dr Neeta Khondalla";
        D2.Doc_qualification = "MS";
        D2.Doc_department = "Gynacology";
        D2.Doc_experience = 10;
        D2.Doc_Id = 1002;

        Doctor D3;
        D3.Doc_name = "Dr Sakshi Wankhede";
        D3.Doc_qualification = "MBBS";
        D3.Doc_department = "Child";
        D3.Doc_experience = 8;
        D3.Doc_Id = 1003;

        Doctor D4;
        D4.Doc_name = "Dr Gautam Kulkarni";
        D4.Doc_qualification = "MD";
        D4.Doc_department = "Dermatology";
        D4.Doc_experience = 17;
        D4.Doc_Id = 1004;

        Doctor D5;
        D5.Doc_name = "Dr Vikas Linga";
        D5.Doc_qualification = "MS";
        D5.Doc_department = "Gastrology";
        D5.Doc_experience = 7;
        D5.Doc_Id = 1005;

        Doctor D6;
        D6.Doc_name = "Dr Ravichandra Shinde";
        D6.Doc_qualification = "MD";
        D6.Doc_department = "General Consultant";
        D6.Doc_experience = 7;
        D6.Doc_Id = 1006;

        insertNode(list, D1);
        insertNode(list, D2);
        insertNode(list, D3);
        insertNode(list, D4);
        insertNode(list, D5);
        insertNode(list, D6);
    }
    else
    {
        while (true)
        {
            Doctor D;
            cout << "Enter Doctor Name : " << endl;
            cin.ignore();
            getline(cin, D.Doc_name);

            cout << "Enter Qualification : " << endl;
            cin.ignore();
            getline(cin, D.Doc_qualification);

            cout << "Enter Department : " << endl;
            cin.ignore();
            getline(cin, D.Doc_department);

            cout << "Enter Experiance : in years or 0 for fresher/intern" << endl;
            cin >> (D.Doc_experience);

            cout << "Enter Id : " << endl;
            cin >> (D.Doc_Id);

            insertNode(list, D);

            cout << "Do You Want To Add more ?" << endl;
            cout << "Press : 1 : continue | 0 : Exit" << endl;
            int conti;
            cin >> conti;
            if (conti == 0)
            {
                return;
            }
        }
    }
}
void Delete(Linkedlist *head1, int id)
{
    Linkedlist *temp = head1;
    Linkedlist *prev = nullptr;

    if (head1 == nullptr)
    {
        cout << "List empty" << endl;
        return;
    }

    while (temp != nullptr && temp->D.Doc_Id != id)
    {
        prev = temp;
        temp = temp->next;
    }
    if (temp == nullptr)
    {
        cout << "No record found" << endl;
        return;
    }
    if (temp == head1)
    {
        head1 = head1->next;
        return;
    }
    prev->next = temp->next;
};

//***********Event********
void insertNodeOfEvent(Linkedlist *head2, Event E)
{
    Linkedlist *newNode = new Linkedlist(E);
    if (head2 != nullptr)
    {
        Linkedlist *temp = head2;

        while (temp->next != nullptr)
        {
            temp = temp->next;
        }
        temp->next = newNode;
        return;
    }
    head2 = newNode;
    return;
};
void insertEvent(Linkedlist *Eventlist, int n)
{
    if (n == 1)
    {
        Event E1;
        E1.Event_Id = 1;
        E1.Event_name = ("Blood Donation Camp");
        E1.Event_date = ("5 May, 2024");
        E1.Event_time = ("11AM to 2PM");
        E1.Event_Details = ("Blood Donation camp will be conducted offline and registration is must, details will be conveyed through register mobile number");

        Event E2;
        E2.Event_Id = 2;
        E2.Event_name = ("Free health care Checkup");
        E2.Event_date = ("10 May, 2024");
        E2.Event_time = ("9AM to 4PM");
        E2.Event_Details = ("Free health care Checkup will be conducted offline and registration is must, details will be conveyed through register mobile number");

        insertNodeOfEvent(Eventlist, E1);
        insertNodeOfEvent(Eventlist, E2);
    }

    else
    {
        while (true)
        {
            Event E;
            cout << "Enter Event Id : " << endl;
            cin >> E.Event_Id;

            cout << "Enter Event Name : " << endl;
            cin.ignore();
            getline(cin, (E.Event_name));

            cout << "Enter Event Date : " << endl;
            cin.ignore();
            getline(cin, (E.Event_date));

            cout << "Enter Event Time : " << endl;
            cin.ignore();
            getline(cin, (E.Event_time));

            cout << "Enter Event Details : " << endl;
            cin.ignore();
            getline(cin, (E.Event_Details));

            insertNodeOfEvent(Eventlist, E);
            int conti;
            cout << "Do You Want To Add more Events ?" << endl;
            cout << "Press : 1 : continue | 0 : Exit" << endl;

            cin >> conti;
            if (conti == 0)
            {
                return;
            }
        }
    }
}
void printEvent(Linkedlist *head2)
{
    Linkedlist *temp = head2;

    if (head2 == NULL)
    {
        cout << "List empty" << endl;
        return;
    }
    temp = temp->next;
    while (temp != NULL)
    {
        cout << "Event Name : " << temp->E.Event_name << endl;
        cout << "Event Date : " << temp->E.Event_date << endl;
        cout << "Event Time : " << temp->E.Event_time << endl;
        cout << "Event Details : " << temp->E.Event_Details << endl
             << endl;
        temp = temp->next;
    }
}
void DeleteEvent(Linkedlist *head2, int id)
{
    Linkedlist *temp = head2;
    Linkedlist *prev = nullptr;

    if (head2 == nullptr)
    {
        cout << "List empty" << endl;
        return;
    }

    while (temp != nullptr && temp->E.Event_Id != id)
    {
        prev = temp;
        temp = temp->next;
    }
    if (temp == nullptr)
    {
        cout << "No record found" << endl;
        return;
    }
    if (temp == head2)
    {
        head2 = head2->next;
        return;
    }
    prev->next = temp->next;
};

// Registration
void display_only_event(Linkedlist *Eventlist)
{
    Linkedlist *temp = Eventlist;
    cout << endl;

    if (Eventlist == NULL)
    {
        cout << "No Event Available" << endl;
        return;
    }
    temp = temp->next;
    while (temp != NULL)
    {
        cout << "Event Name : " << temp->E.Event_name << endl;
        cout << "Event Id : " << temp->E.Event_Id
             << endl;
        temp = temp->next;
    }
}
void regis_insert(vector<registration> &reg_list, Linkedlist *Eventlist, int n)
{
    if (n == 1)
    {
        registration r1;
        r1.reg_name = "Vishal Jatra";
        r1.reg_cont_no = 1234567891;
        r1.E_id = 1;
        reg_list.push_back(r1);

        registration r2;
        r2.reg_name = "Vivek do";
        r2.reg_cont_no = 5514227668;
        r2.E_id = 1;
        reg_list.push_back(r2);

        registration r3;
        r3.reg_name = "Vikas Singh";
        r3.reg_cont_no = 6625447892;
        r3.E_id = 1;
        reg_list.push_back(r3);
    }
    else
    {
        while (true)
        {
            registration R;
            cout << "Enter Name To Registration: " << endl;
            cin.ignore();
            getline(cin, R.reg_name);

            cout << "Enter Contact No. : " << endl;
            cin >> R.reg_cont_no;

            cout << "Enter Event Id From below List : " << endl;
            display_only_event(Eventlist);
            cin >> R.E_id;
            reg_list.push_back(R);
            cout << "******** Register Successfully ********" << endl;

            cout << "Do You Want To Add more ?" << endl;
            cout << "Press : 1 : continue | 0 : Exit from registration" << endl;
            int conti;
            cin >> conti;
            if (conti == 0)
            {
                return;
            }
        }
    }
}
void regis_Display(vector<registration> &reg_list)
{
    if (reg_list.size() == 0)
    {
        cout << "No registration available" << endl;
    }
    else
    {
        for (auto reg : reg_list)
        {
            if (reg.isdel == 0)
            {
                cout << reg.reg_name << "  -- " << reg.reg_cont_no << "  Event Id " << reg.E_id << endl;
            }
        }
        cout << " End" << endl;
    }
}

// reveiws
void insert_review(vector<review> &review_list, int n)
{
    if (n == 1)
    {
        review r1;
        r1.nam = "Aniket Kapse";
        r1.data = "this is the best hospital";

        review r2;
        r2.nam = "Vishal batra";
        r2.data = "this is no. one hospital";

        review r3;
        r3.nam = "Om arrora";
        r3.data = "Best medical facilities";

        review_list.push_back(r1);
        review_list.push_back(r2);
        review_list.push_back(r3);
    }
    else
    {
        while (true)
        {
            review r;
            cout << "Enter Your Name Please" << endl;
            cin.ignore();
            getline(cin, r.nam);

            cout << "Type Review" << endl;
            getline(cin, r.data);
            review_list.push_back(r);

            cout << "Do You Want To Add more ?" << endl;
            cout << "Press : 1 : continue | 0 : Exit from review" << endl;
            int conti;
            cin >> conti;
            if (conti == 0)
            {
                return;
            }
        }
    }
}
void display_review(vector<review> &review_List)
{
    if (review_List.size() == 0)
    {
        cout << "No review available" << endl;
    }
    else
    {
        for (auto rev : review_List)
        {
            if (rev.isblock == 0)
            {
                cout << rev.nam << " --> " << rev.data << endl;
            }
        }
        cout << " End" << endl;
    }
}

// appointment
bool check(Linkedlist *doc_list, string doc_name)
{
    Linkedlist *curr = doc_list;
    curr = curr->next;
    while (curr != nullptr)
    {
        if (curr->D.Doc_name == doc_name)
        {
            return true;
        }
        curr = curr->next;
    }
    return false;
}
bool avail(Linkedlist *doc_list, string doc_name)
{
    Linkedlist *curr = doc_list;
    curr = curr->next;
    while (curr != nullptr)
    {
        if (curr->D.Doc_name == doc_name)
        {
            if (curr->D.isavailable == true)
                return true;
            else
                return false;
        }
        curr = curr->next;
    }
    return false;
}
void diplay_time_slot(vector<appointment> &appo_list, string doc_name)
{
    for (auto a : appo_list)
    {
        if (a.iscancel == false && a.doc_name == doc_name)
        {
            cout << a.pat_name << " -- " << a.app_time << endl;
        }
    }
}
void insert_appointment(vector<appointment> &appo_list, Linkedlist *doc_list, int n)
{
    if (n == 1)
    {
        appointment a1;
        a1.pat_name = "Mr. Gulshan Bhatt";
        a1.pat_age = 38;
        a1.doc_name = "Dr Rahul Bais";
        a1.app_time = "10:15 am ";
        a1.mob_no = "9517558645";

        appointment a2;
        a2.pat_name = "Mr. Ashish Vohra";
        a2.pat_age = 29;
        a2.doc_name = "Dr Gautam Kulkarni";
        a2.app_time = "10:15 am";
        a2.mob_no = "9517558645";

        appointment a3;
        a3.pat_name = "Mr. Shanti Boss";
        a3.pat_age = 45;
        a3.doc_name = "Dr Neeta Khondalla";
        a3.app_time = "10:15 am";
        a3.mob_no = "9517558645";

        appo_list.push_back(a1);
        appo_list.push_back(a2);
        appo_list.push_back(a3);
    }
    else
    {
        while (true)
        {
            appointment a;
            cout << "Enter Patient Name : " << endl;
            cin.ignore();
            getline(cin, a.pat_name);

            cout << "Enter Patient age : " << endl;
            cin >> a.pat_age;

            cout << "Enter Doctor Name : " << endl;
            cin.ignore();
            getline(cin, a.doc_name);

            while (check(doc_list, a.doc_name) == false)
            {
                cout << "No record found for " << a.doc_name << endl;
                cout << "Re_enter Doctor Name" << endl;
                getline(cin, a.doc_name);
            }

            if (avail(doc_list, a.doc_name) == false)
            {
                cout << "Doctor is unavailable " << endl;
            }

            diplay_time_slot(appo_list, a.doc_name);
            cout << "Enter time slot according to avail time slot" << endl;
            getline(cin, a.app_time);

            cout << "Enter contact no." << endl;
            getline(cin, a.mob_no);

            appo_list.push_back(a);
            cout << "Do You Want To Add more ?" << endl;
            cout << "Press : 1 : continue | 0 : Exit from appointment" << endl;
            int conti;
            cin >> conti;
            if (conti == 0)
            {
                return;
            }
        }
    }
}
void display_appointment(vector<appointment> &appo_list, string doc = "all")
{
    cout << "all apointments " << endl;
    if (doc == "all")
    {
        for (auto &a : appo_list)
        {
            if (a.iscancel == false)
            {
                cout << "Patient Name: " << a.pat_name << endl
                     << " age: " << a.pat_age << endl
                     << " Doctor :" << a.doc_name << endl
                     << "  -- " << a.app_time << endl
                     << " -- " << a.mob_no << endl;
                cout << endl;
            }
        }
    }
    else
    {
        for (auto a : appo_list)
        {
            if (a.iscancel == false && doc == a.doc_name)
            {
                cout << "Patient Name: " << a.pat_name << endl
                     << " age: " << a.pat_age << endl
                     << "  -- " << a.app_time << endl
                     << " - " << a.mob_no << endl;
                cout << endl;
            }
        }
    }
}
void cancel_appoint(vector<appointment> &appo_list, string pat_nam)
{
    for (auto &temp : appo_list)
    {
        if (temp.pat_name == pat_nam)
        {
            cout << 1;
            temp.iscancel = true;
        }
    }
    cout << "Appointment is Cancelled" << endl;
}

int main()
{
    cout << "\n******* WELCOME ********" << endl;
    int ch = 0;
    Linkedlist *list = new Linkedlist();
    Linkedlist *Eventlist = new Linkedlist();
    vector<registration> reg_list;
    vector<review> review_list;
    vector<appointment> appo_list;

    int n = 1;
    insert(list, n);
    insertEvent(Eventlist, n);
    regis_insert(reg_list, Eventlist, n);
    insert_review(review_list, n);
    insert_appointment(appo_list, list, n);

    do
    {
        cout << "------LOGIN AS -------" << endl;
        cout << "\t\t1.ADMIN\n\t\t2.USER" << endl;
        cout << "Enter Your Choice : " << endl;
        cin >> ch;
        switch (ch)
        {
        case 1:
        {
            cout << "******* Menu *******" << endl;
            cout << "\t 1. Home" << endl;
            cout << "\t 2. About Us" << endl;
            cout << "\t 3. Doctors" << endl;
            cout << "\t 4. Services" << endl;
            cout << "\t 5. Reviews" << endl;
            cout << "\t 6. Appointment" << endl
                 << endl;
            do
            {
                cout << "Enter Your Choice " << endl;
                cin >> ch;
                switch (ch)
                {
                    // Home
                case 1:
                {
                    cout << "\n\t\t  WELCOME to";
                    cout << "\tAks Multi-Speacility Hospital " << endl;
                    cout << "Making Health Care Better TOgether " << endl;
                    cout << "\tFrom preventive Care and Checkups, to immuunizations and exams, ";
                    cout << "\tour primary care physicians and provides work to keep you and ";
                    cout << "\tyour whole family healthy and strong each and every day.";
                    cout << "\n=============================================================================" << endl;
                    break;
                }
                // About us
                case 2:
                {
                    cout << "about" << endl;
                    // about();
                    cout << "\n=============================================================================" << endl;
                    break;
                }
                // Doctor
                case 3:
                {
                    int conti;
                    do
                    {
                        cout << "\n\t\t\t\tDOCTORS ";
                        cout << "\n\t\t*************** MENU ***************";
                        cout << "\n\t\t\t 1.INSERT DOCTOR INFORMATION";
                        cout << "\n\t\t\t 2.DISPLAY DOCTORS RECORD";
                        cout << "\n\t\t\t 3.DELETE DOCTOR RECORD" << endl;

                        int chh;
                        cout << "ENTER YOUR CHOICE : " << endl;
                        cin >> chh;
                        switch (chh)
                        {
                        case 1:
                        {
                            insert(list, 0);
                            break;
                        }
                        case 2:
                        {
                            printList(list);
                            break;
                        }
                        case 3:
                        {
                            int id;
                            cout << "enter doctor Id";
                            cin >> id;
                            Delete(list, id);
                            break;
                        }
                        default:
                        {
                            cout << "break ";
                            break;
                        }
                        }
                        cout << "1Do You Want To Continue as admin ?" << endl;
                        cout << "Press : 1 : continue | 0 : Exit" << endl;
                        cin >> conti;
                        if (conti == 0)
                        {
                            cout << "Thankyou" << endl;
                        }
                    } while (conti == 1);

                    cout << "\n=============================================================================" << endl;
                    break;
                }
                // Services
                case 4:
                {
                    // Services
                    int conti = 0;
                    while (true)
                    {
                        cout << "\n=============================================================================" << endl;
                        cout << "\t\t\tServices" << endl;
                        cout << "\t********************Menu***********************" << endl;
                        cout << "\t\t1.Enter Events Details" << endl;
                        cout << "\t\t2.Display Event Details" << endl;
                        cout << "\t\t3.Display The Registration For Free CheckUp" << endl;
                        cout << "\t\t4.Medical Facilities" << endl;
                        cout << "\t\t5.Delete Events " << endl;
                        cout << "Enter Your Choices From Services" << endl;
                        int c2;
                        cin >> c2;
                        switch (c2)
                        {
                        case 1:
                        {
                            cout << "Enter Events Details" << endl;
                            n = 0;
                            insertEvent(Eventlist, n);
                            break;
                        }
                        case 2:
                        {
                            cout << "Display Event Details" << endl;
                            printEvent(Eventlist);
                            break;
                        }
                        case 3:
                        {
                            cout << "Display The Registration For Free CheckUp";
                            regis_Display(reg_list);
                            break;
                        }
                        case 4:
                        {
                            cout << "Medical Facilities";

                            break;
                        }
                        case 5:
                        {
                            cout << "Delete Events";
                            int id;
                            cout << "enter event Id";
                            cin >> id;
                            DeleteEvent(Eventlist, id);
                            break;
                        }
                        default:
                            break;
                        }
                        cout << "press 1 to-continue and 0 to exit from services";
                        cin >> conti;
                        if (conti != 1)
                        {
                            break;
                        }
                    }
                    cout << "\n=============================================================================" << endl;

                    break;
                }
                // Reviews
                case 5:
                {
                    cout << " ALL Reviews" << endl;
                    display_review(review_list);
                    break;
                }
                // Appointment
                case 6:
                {
                    cout << "***********Appointment**********" << endl;
                    while (true)
                    {
                        cout << "*************Menu************" << endl;
                        cout << "\t 1.Book Appointment" << endl;
                        cout << "\t 2.Show all appointment" << endl;
                        cout << "\t 3.Cancel Appointment" << endl;
                        cout << "\t 4.Doctor Appointment" << endl;
                        cout << "\t 5.Doctor Availability" << endl;
                        int choice = 0;
                        cout << "Enter your choice" << endl;
                        cin >> choice;
                        cout << endl;
                        switch (choice)
                        {
                        case 1:
                        {
                            insert_appointment(appo_list, list, 0);
                            break;
                        }
                        case 2:
                        {
                            display_appointment(appo_list);
                            break;
                        }
                        case 3:
                        {
                            string pat_nam;
                            cout << "To cancel appointment enter correct name" << endl;
                            cin.ignore();
                            getline(cin, pat_nam);
                            cancel_appoint(appo_list, pat_nam);
                            break;
                        }
                        case 4:
                        {
                            cout << "Doctor Appointment" << endl;
                            string doc_nam;
                            cout << "Insert doctor name " << endl;
                            cin.ignore();
                            getline(cin, doc_nam);
                            display_appointment(appo_list, doc_nam);
                            break;
                        }
                        case 5:
                        {
                            cout << "Doctor Availability" << endl;
                            string doc_nam;
                            cout << "Insert doctor name " << endl;
                            cin.ignore();
                            getline(cin, doc_nam);
                            if (avail(list, doc_nam))
                            {
                                cout << "Dr is available" << endl;
                            }
                            else
                            {
                                cout << "Dr is not available" << endl;
                            }
                            break;
                        }
                        default:
                            break;
                        }
                        int conti;
                        cout << "1Do You Want To Continue as in appointment ?" << endl;
                        cout << "Press : 1 : continue | 0 : Exit" << endl;
                        cin >> conti;
                        if (conti == 0)
                        {
                            break;
                        }
                    }
                    break;
                }
                default:
                    break;
                }
            } while (ch == 1);
            break;
        }
        case 2:
        {
            int conti1;
            do
            {
                cout << "******* Menu *******" << endl;
                cout << "\t 1. Home" << endl;
                cout << "\t 2. About Us" << endl;
                cout << "\t 3. Doctors" << endl;
                cout << "\t 4. Services ans Events" << endl;
                cout << "\t 5. Reviews" << endl;
                cout << "\t 6. Book Appointment" << endl
                     << endl;

                cout << "Enter your choice" << endl;
                int ch1;
                cin >> ch;
                switch (ch)
                {
                // home
                case 1:
                {
                    cout << "home" << endl;
                    cout << "\n\t\t  WELCOME to";
                    cout << "\tAks Multi-Speacility Hospital " << endl;
                    cout << "Making Health Care Better TOgether " << endl;
                    cout << "\tFrom preventive Care and Checkups, to immuunizations and exams, ";
                    cout << "\tour primary care physicians and provides work to keep you and ";
                    cout << "\tyour whole family healthy and strong each and every day.";
                    cout << "\n=============================================================================" << endl;
                    break;
                    break;
                }
                // about us
                case 2:
                {
                    cout << "about us" << endl;
                    break;
                }
                // Doctors
                case 3:
                {
                    int conti;
                    do
                    {
                        cout << "\n\t\t\t\tDOCTORS ";
                        cout << "\n\t\t*************** MENU ***************";
                        cout << "\n\t\t\t DISPLAY DOCTORS RECORD DEPARTMENT WISE" << endl;
                        cout << " 1.Dermatology\n 2. Child(0 to 13yr)\n 3.Cardiologist(heart)\n 4.Gastroenterologists\n 5.Gynacologist\n 6.General Consultant" << endl;
                        cout << endl
                             << "" << endl;
                        int chh;
                        cout << "ENTER YOUR CHOICE : " << endl;
                        cin >> chh;
                        switch (chh)
                        {
                        case 1:
                        {
                            // Dermatology
                            printlist_dept(list, "Dermatology");
                            break;
                        }
                        case 2:
                        {
                            // Child(0 to 13yr)
                            printlist_dept(list, "Child");
                            break;
                        }
                        case 3:
                        {
                            // Cardiologist(heart)
                            printlist_dept(list, "Cardiology");
                            break;
                        }
                        case 4:
                        {
                            // Gastrology
                            cout << "Gastrology" << endl;
                            printlist_dept(list, "Gastrology");
                            break;
                        }
                        case 5:
                        {
                            // Gynacologist
                            printlist_dept(list, "Gynacology");
                            break;
                        }
                        case 6:
                        {
                            // General Consultant
                            printlist_dept(list, "General Consultant");
                            break;
                        }
                        default:
                        {
                            cout << "break ";
                            break;
                        }
                        }
                        cout << "1Do You Want To Continue in doctor ?" << endl;
                        cout << "Press : 1 : continue | 0 : Exit" << endl;
                        cin >> conti;
                        if (conti == 0)
                        {
                            cout << "Thankyou" << endl;
                        }
                    } while (conti == 1);

                    cout << "\n=============================================================================" << endl;
                    break;
                }
                // Services
                case 4:
                {
                    cout << "Services" << endl;
                    int conti = 0;
                    while (true)
                    {
                        cout << "\n=============================================================================" << endl;
                        cout << "\t\t\tService's and Event's" << endl;
                        cout << "\t********************Menu***********************" << endl;
                        cout << "\t\t1.Display Event Details" << endl;
                        cout << "\t\t2.Registration For Free CheckUp/ Event" << endl;
                        cout << "\t\t3.Medical Facilities" << endl;
                        cout << "Enter Your Choices From Services" << endl;
                        int c2;
                        cin >> c2;
                        switch (c2)
                        {
                        case 1:
                        {
                            cout << "Display Event Details" << endl;
                            printEvent(Eventlist);
                            break;
                        }
                        case 2:
                        {
                            cout << "Registration For Free CheckUp/ Event" << endl;
                            regis_insert(reg_list, Eventlist, 0);
                            break;
                        }
                        case 3:
                        {
                            cout << "*******Medical Facilities********" << endl;
                            cout << "1. Ambulatory surgical centers" << endl;
                            cout << "2. Birth centers" << endl;
                            cout << "3. Blood banks" << endl;
                            cout << "4. Clinics and medical offices" << endl;
                            cout << "5. Diabetes education centers" << endl;
                            cout << "6. Dialysis Centers" << endl;
                            cout << "7. Hospice homes" << endl;
                            cout << "8. Research and analysis pannel with experienced faculty" << endl;
                            cout << "9. Imaging and radiology centers" << endl;
                            cout << "10. Mental health and addiction treatment centers" << endl;
                            cout << "11. Nursing homes" << endl;
                            cout << "12. Orthopedic and other rehabilitation centers" << endl;
                            cout << "13. Urgent care" << endl;
                            cout << "And so much more..." << endl;
                            break;
                        }
                        default:
                            break;
                        }
                        cout << "press 1 to-continue and 0 to exit from service's";
                        cin >> conti;
                        if (conti != 1)
                        {
                            break;
                        }
                    }
                    cout << "\n=============================================================================" << endl;

                    break;
                }
                // Reviews
                case 5:
                {
                    cout << "1.Past Reviews" << endl;
                    cout << "2.Insert Reveiws" << endl;
                    int o1;
                    cout << "insert choice" << endl;
                    cin >> o1;
                    if (o1 == 1)
                    {
                        display_review(review_list);
                    }
                    else if (o1 == 2)
                    {
                        insert_review(review_list, 0);
                    }
                    else
                    {
                        break;
                    }
                    break;
                }
                // Appointment
                case 6:
                {
                    cout << "***********Appointment**********" << endl;
                    cout << "You Can Book appointment on call " << endl;
                    cout << "Contact no : 1234567891" << endl;
                    while (true)
                    {
                        cout << "*************Menu************" << endl;
                        cout << "\t 1.Book Appointment" << endl;
                        cout << "\t 2.Cancel Appointment" << endl;
                        cout << "\t 3.Doctor Availability" << endl;
                        int choice = 0;
                        cout << "Enter your choice" << endl;
                        cin >> choice;
                        cout << endl;
                        switch (choice)
                        {
                        case 1:
                        {
                            insert_appointment(appo_list, list, 0);
                            break;
                        }
                        case 2:
                        {
                            string pat_nam;
                            cout << "To cancel appointment enter correct name" << endl;
                            cin.ignore();
                            getline(cin, pat_nam);
                            cancel_appoint(appo_list, pat_nam);
                            break;
                        }
                        case 3:
                        {
                            cout << "Doctor Availability" << endl;
                            string doc_nam;
                            cout << "Insert doctor name " << endl;
                            cin.ignore();
                            getline(cin, doc_nam);
                            if (avail(list, doc_nam))
                            {
                                cout << "Dr is available" << endl;
                            }
                            else
                            {
                                cout << "Dr is not available" << endl;
                            }
                            break;
                        }
                        default:
                            break;
                        }
                        int conti;
                        cout << "1Do You Want To Continue as in appointment ?" << endl;
                        cout << "Press : 1 : continue | 0 : Exit" << endl;
                        cin >> conti;
                        if (conti == 0)
                        {
                            break;
                        }
                    }
                    break;
                }

                default:
                    break;
                }
                cout << "do you want to coninue as user " << endl;
                cout << "1 for continue or 0 for exit" << endl;
                cin >> conti1;
            } while (conti1 == 1);
        }

        default:
            cout << "Re-Enter Correct Choice" << endl;
            break;
        }
        cout << "Do You Want login page" << endl;
        cout << "1 for Continue and  0 for Exit" << endl;
        cin >> ch;
    } while (ch == 1);
    cout << "Thanks for using the application" << endl;
    return 0;
}