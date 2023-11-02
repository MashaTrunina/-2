#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

class Character {
public:
    string name;

public:
    Character(string _name) : name(_name) {}

    Character() : name(" ") {}

    ~Character() {}

    void displayInfo() {
        cout << "��������: " << name << endl;
    }
};

class Cafe {
public:
    string name;

public:
    Cafe(string _name) : name(_name) {}

    Cafe() : name(" ") {}

    ~Cafe() {}

    void get_info() {
        cout << "Name: " << name << endl;
    }
};

class Staff {
public:
    string Name;
    string skill;

public:
    Staff(string _name, string _skill) : Name(_name), skill(_skill) {}

    Staff() : Name(" "), skill(" ") {}

    ~Staff() {}

    void take_info() {
        cout << "Name: " << Name << endl;
        cout << "Skills: " << skill << endl;
    }
};

class Menu {
public:
    Menu() {}

    virtual ~Menu() {}
};

class Food : public Menu {
private:
    string name;

public:
    Food(string _name) : name(_name) {}

    Food() : name("") {}

    ~Food() {}

    void display() {
        cout << "Food: " << name << endl;
    }
};

class Pie : public Food {
public:
    string type;

public:
    Pie(string _type) : type(_type) {}

    Pie() : type("") {}

    ~Pie() {}

    void prepare() {
        cout << "������������� ������" << endl;
    }

    void serve() {
        cout << "������ ������" << endl;
    }
};

class Drink : public Food {
public:
    string name;

    Drink(string _name) : Food(_name) {}

    Drink() : Food() {}

    ~Drink() {}

    void display() {
        cout << "Drink: " << name << endl;
    }
};

class Tea : public Drink {
public:
    string type;

    Tea(string _type) : type(_type) {}

    Tea() : type("") {}

    ~Tea() {}

    void prepare() {
        cout << "������������� ���" << endl;
    }

    void serve() {
        cout << "������ ���" << endl;
    }
};

class Coffee : public Drink {
public:
    Coffee(string _name) : name(_name) {}

    Coffee() : name("") {}

    ~Coffee() {}

    string name;

    void prepare() {
        cout << "������������� ����" << endl;
    }

    void serve() {
        cout << "������ ����" << endl;
    }
};

class Money {
private:
    int amount;

public:
    Money() {}

    void transfer() {
        cout << " ��� ������: " << amount << endl;
    }

    void generateMoney() {
        srand(static_cast<unsigned>(time(0)));
        amount = rand() % 151 + 50; // ��������� ���������� ����� �� 50 �� 200
    }
};

int main() {
    setlocale(LC_ALL, "RU");

    Character character;
    cout << "������� ��� ���������: ";
    cin >> character.name;
    character.displayInfo();

    int cafeChoice;
    cout << "�������� ����: 1.TEA ��� 2.COFFEE" << endl;
    cin >> cafeChoice;

    Money money;
    money.generateMoney();
    money.transfer();

    if (cafeChoice == 1) { // ����� ����

        Cafe tea("TEA");
        tea.get_info();

        int baristaChoice;
        cout << "�������� �������: 1.Ivan ��� 2.Kate" << endl;
        cin >> baristaChoice;

        cout << "������ ����, ��� ������ ����������? �� ����� ����: 1.������� ���(10@), 2.������ ���(30@), 3.������� �����(50@), 4.�������� �����(60@). " << endl;

        if (baristaChoice == 1) {
            Staff number1("Ivan", "������ ������ ������� ��� � ������� �����");
            number1.take_info();

            int drinkChoice, foodChoice;
            cout << "�������� �������: ";
            cin >> drinkChoice;
            cout << "�������� �����: ";
            cin >> foodChoice;

            if ((drinkChoice == 1 && foodChoice == 3) || (drinkChoice == 1 && foodChoice == 4))  {
                Tea Greentea("�������");
                Greentea.prepare();
                Greentea.serve();

                Pie pie1("�������� �����");
                pie1.prepare();
                pie1.serve();

                cout << "Ivan ���������� ������� ��� � �����, �� �������� ��������" << endl;
            }
            else {
                cout << "Ivan �� ���� ����������� ������� �����, �� �������� ����������" << endl;
                cout << "Game over" << endl;
            }
        }
        else if (baristaChoice == 2) {
            Staff number2("Kate", "������ ������ ������ ��� � �������� �����");
            number2.take_info();

            int drinkChoice, foodChoice;
            cout << "�������� �������: ";
            cin >> drinkChoice;
            cout << "�������� �����: ";
            cin >> foodChoice;

            if ((drinkChoice == 2 && foodChoice == 3) || (drinkChoice == 2 && foodChoice == 3)) {
                Tea Blacktea("������");
                Blacktea.prepare();
                Blacktea.serve();

                Pie pie2("�������� �����");
                pie2.prepare();
                pie2.serve();

                cout << "Kate ����������� ������� ���, �� �������� ��������" << endl;
            }
            else {
                cout << "Kate �� ������ ����������� ������� �����, �� �������� ����������" << endl;
            }
        }
    }
    else if (cafeChoice == 2) {
        Cafe coffee("COFFEE");
        coffee.get_info();

        int baristaChoice;
        cout << "�������� �������: 1.Mary ��� 2.Anastasia" << endl;
        cin >> baristaChoice;

        cout << "������ ����, ��� ������ ����������? �� ����� ����: 1.��������(10@), 2.�����(30@), 3.������� � �������(50@), 4.������� � ��������(60@). " << endl;

        if (baristaChoice == 1) {
            Staff number1("Mary", "����� ���������� ���� � ������ ������� ������� � �������");
            number1.take_info();

            int drinkChoice, foodChoice;
            cout << "�������� �������: ";
            cin >> drinkChoice;
            cout << "�������� �����: ";
            cin >> foodChoice;

            if ((drinkChoice == 1 && foodChoice == 3) || (drinkChoice == 1 && foodChoice == 4)) {
                Coffee Cappuccino("��������");
                Cappuccino.prepare();
                Cappuccino.serve();

                Pie bun1("������� � �������");
                bun1.prepare();
                bun1.serve();

                cout << "Mary ����������� ������� ����, �� �������� ��������" << endl;
            }
            else {
                cout << "Mary �� ������ ����������� ������� �����, �� �������� ����������" << endl;
            }
        }
        else if (baristaChoice == 2) {
            Staff number2("Anastasia", "������ ������ ����� � ������� ������� ������� � ��������");
            number2.take_info();

            int drinkChoice, foodChoice;
            cout << "�������� �������: ";
            cin >> drinkChoice;
            cout << "�������� �����: ";
            cin >> foodChoice;

            if ((drinkChoice == 2 && foodChoice == 3) || (drinkChoice == 2 && foodChoice == 4)) {
                Coffee Latte("�����");
                Latte.prepare();
                Latte.serve();

                Pie bun2("������� � ��������");
                bun2.prepare();
                bun2.serve();

                cout << "Anastasia ����������� ������� ���� � �������, �� �������� ��������" << endl;
            }
            else {
                cout << "Anastasia �� ������ ����������� ������� �����, �� �������� ����������" << endl;
            }
        }
    }

    return 0;
}
