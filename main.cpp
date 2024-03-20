#include <iostream>
using namespace std;

class Person {
    string name;
    int age;
    string phone;
protected:
    Person(string name = "", int age = 0, string phone = "") : name(name), phone(phone), age(age) {}

public:
    const string &getName() const {
        return name;
    }

    void setName(const string &name) {
        Person::name = name;
    }

    int getAge() const {
        return age;
    }

    void setAge(int age) {
        Person::age = age;
    }

    const string &getPhone() const {
        return phone;
    }

    void setPhone(const string &phone) {
        Person::phone = phone;
    }


    virtual void print() {
        cout << name << " " << age << " " << phone;
    }
};

class Resident : public Person {
    string occupation;
    float rent;
    static int rCount;
    int id;
public:
    Resident(string occupation = "", float rent = 0.0,string name = "", int age = 0, string phone = "") : rent(rent), occupation(occupation) {
        setName(name);
        setAge(age);
        setPhone(phone);
        Resident::rCount++;
        id = rCount;
    }

    const string &getOccupation() const {
        return occupation;
    }

    void setOccupation(const string &occupation) {
        Resident::occupation = occupation;
    }

    float getRent() const {
        return rent;
    }

    void setRent(float rent) {
        Resident::rent = rent;
    }

    static int getRCount() {
        return Resident::rCount;
    }

    int getId() const {
        return id;
    }


    void print() {
        cout << id << " ";
        Person::print();
        cout << " " << occupation << " " << rent;
    }
};

class Staff : public Person {
    int id;
    static int eCount;
    float salary;
    string role;

public:
    Staff(float salary = 0.0, string role = "",string name = "", int age = 0, string phone = "") : role(role), salary(salary) {
        Staff::eCount++;
        id = Staff::eCount;
        setName(name);
        setAge(age);
        setPhone(phone);
    }

    float getSalary() const {
        return salary;
    }

    void setSalary(float salary) {
        Staff::salary = salary;
    }

    const string &getRole() const {
        return role;
    }

    void setRole(const string &role) {
        Staff::role = role;
    }

    int getId() const {
        return id;
    }

    static int getECount() {
        return eCount;
    }

    void print() {
        cout << id << " ";
        Person::print();
        cout << " " << role << " " << salary;
    }
};

class Visitor : public Person {
    int cnic;
    Resident r;
    string date;
public:
    Visitor(int cnic = 0, string date = "",string name = "", int age = 0, string phone = "")
            : cnic(cnic), date(date) {
        setName(name);
        setAge(age);
        setPhone(phone);
    }

    void addResident(Resident &r) {
        this->r = r;
    }

    int getCnic() const {
        return cnic;
    }

    void setCnic(int cnic) {
        Visitor::cnic = cnic;
    }

    const string &getDate() const {
        return date;
    }

    void setDate(const string &date) {
        Visitor::date = date;
    }

    const Resident &getR() const {
        return r;
    }

    void setR(const Resident &r) {
        Visitor::r = r;
    }

    void print() {
        cout << cnic << " ";
        Person::print();
        cout << " " << r.getName() << " " << date;
    }
};

class Guardian: public Person{
    int cnic;
    static int gcount;
    int id;
    Resident r;
public:
    Guardian(string name="", int age=40, string phone="", int cnic=0 ){
        this->cnic=cnic;
        this->setName(name);
        this->setAge(age);
        this->setPhone(phone);
        Guardian::gcount++;
        id=gcount;
    }

    void setResident(Resident r){
        this->r=r;
    }

    Resident getResident(){
        return r;
    }

    int getCnic(){
        return cnic;
    }

    void setCnic(int cnic)  {
        this->cnic= cnic;
    }

    int getId(){
        return id;
    }

    static int getGcount(){
        return gcount;
    }

    void print(){
        cout<<id<<" ";
        Person::print();
        cout<<" "<<cnic<<" "<<r.getName();
    }
};

class Room{
    int id;
    Resident *r;
    int capacity;
    int rcount;

public:
    Room(int id=0, int capacity=0){
        this->id = id;
        this->capacity = capacity;
        r= new Resident[capacity];
    }

    int getId() const {
        return id;
    }

    void setId(int id) {
        Room::id = id;
    }

    int getCapacity() const {
        return capacity;
    }

    void setCapacity(int capacity) {
        Room::capacity = capacity;
    }

    Resident *getR() const {
        return r;
    }

    int availableSeats(){
        return (capacity-rcount);
    }

    bool availability(){
        return (availableSeats()>=1);
    }

    bool isFull(){
        return rcount==capacity;
    }

    void addResident(Resident a){
        if(!isFull()){
            r[rcount]=a;
            rcount++;
        }
        else{
            throw "Room is already full";
        }
    }

    bool Exists(int id){
        for(int i=0; i<rcount; i++){
            if(r->getId()==id){
                return true;
            }
        }
        return false;
    }

    int getIndex(int id){
        for(int i=0; i<rcount; i++){
            if(r[i].getId()==id){
                return i;
            }
        }
    }

    Resident searchByid (int id){
        if(Exists(id)){
            return r[getIndex(id)];
        }
    }

    Resident searcyhByName(string name){
        for(int i=0; i<rcount; i++){
            if(r[i].getName()==name){
                return r[i];
            }
        }
    }

    void removeResident(int id){
        if(Exists(id)){
            r[getIndex(id)] = r[rcount-1];
            rcount--;
        }
    }

    void print(){
        cout<<id<<" "<<capacity<<" "<<availableSeats()<<" ";
        for(int i=0; i<rcount; i++){
            cout<<r[i].getName()<<" ";
        }
        cout<<endl;
    }

    ~Room(){
        delete []r;
    }

};


int Guardian::gcount=0;
int Resident::rCount = 0;
int Staff::eCount = 0;

int main() {
    Resident *r1 = new Resident("Student", 102000, "Daniyal", 20);
    Resident *r2 = new Resident("Student", 102000, "Abdullah", 21);
    Resident *r3 = new Resident("Student", 102000, "Hizra", 25);

    Staff *s1 = new Staff(35000.0, "Day Warden", "Hamid Ibrar", 45);
    Staff *s2 = new Staff(30000,"Night Warden","03333333333",35);
    Staff *s3 = new Staff(35000.0, "House keeping", "Mushtaq", 40);


    Visitor *v1 = new Visitor(1234567892222, "10-jan-2024", "Subhan", 20);

    Guardian *g = new Guardian("Dkait", 60, "03301234567", 030);
    Resident r("student", 102000, "Bux");
    g->setResident(r);

    Person *p[8] = {r1, r2, r3, s1, s2,s3, v1, g};

    Resident *res[50] = {r1, r2, r2};
    int rcount = 3;

    Room room(307, 2);
    Resident R("student", 102000, "Hassan fayyaz");
    room.addResident(R);


    int x = 1;
    int choice;

    while(x!=6){
        cout<<endl;
        cout << "--------------------------------------------------------------------------" << endl;
        cout << "-----------------------Hostel Management System---------------------------" << endl << endl;

        cout << "1. See all initial members: "<<endl;
        cout << "2. see all residents: "<<endl;
        cout << "3. see rooms: "<<endl;
        cout << "4. check room availability: "<<endl;
        cout << "5. Add resident: "<<endl;
        cout << "6. quit: "<<endl;
        cin >> choice;

        if (choice == 1) {
            for (int i = 0; i < 8; i++) {
                p[i]->print();
                cout << endl;
            }
        } else if (choice == 2) {
            for (int i = 0; i < rcount; i++) {
                res[i]->print();
                cout<<endl;
            }
        } else if (choice == 3) {
            room.print();
        } else if (choice == 4) {
                cout << "Room id: " << room.getId() << "  Seats:" << room.availableSeats() << endl;
        } else if (choice == 5) {
            string name;
            int age;
            string occupation;
            float rent;
            cout << "Add name: ";
            cin >> name;

            cout << "Add age: ";
            cin >> age;

            cout << "Add occupation: ";
            cin >> occupation;

            cout << "Add rent: ";
            cin >> rent;

            res[rcount] = new Resident(occupation, rent, name, age);
            rcount++;
        } else if (choice == 6) {
            x = 6;
        } else {
            cout << "Enter a valid value: ";
            cin >> choice;
        }

    }


    return 0;
}