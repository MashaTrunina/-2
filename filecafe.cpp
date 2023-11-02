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
        cout << "Персонаж: " << name << endl;
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
        cout << "Приготовление пирога" << endl;
    }

    void serve() {
        cout << "Подача пирога" << endl;
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
        cout << "Приготовление чая" << endl;
    }

    void serve() {
        cout << "Подача чая" << endl;
    }
};

class Coffee : public Drink {
public:
    Coffee(string _name) : name(_name) {}

    Coffee() : name("") {}

    ~Coffee() {}

    string name;

    void prepare() {
        cout << "Приготовление кофе" << endl;
    }

    void serve() {
        cout << "Подача кофе" << endl;
    }
};

class Money {
private:
    int amount;

public:
    Money() {}

    void transfer() {
        cout << " Ваш баланс: " << amount << endl;
    }

    void generateMoney() {
        srand(static_cast<unsigned>(time(0)));
        amount = rand() % 151 + 50; // Генерация случайного числа от 50 до 200
    }
};

int main() {
    setlocale(LC_ALL, "RU");

    Character character;
    cout << "Введите имя персонажа: ";
    cin >> character.name;
    character.displayInfo();

    int cafeChoice;
    cout << "Выберите кафе: 1.TEA или 2.COFFEE" << endl;
    cin >> cafeChoice;

    Money money;
    money.generateMoney();
    money.transfer();

    if (cafeChoice == 1) { // Выбор кафе

        Cafe tea("TEA");
        tea.get_info();

        int baristaChoice;
        cout << "Выберите бариста: 1.Ivan или 2.Kate" << endl;
        cin >> baristaChoice;

        cout << "Добрый день, что будете заказывать? На выбор есть: 1.зеленый чай(10@), 2.черный чай(30@), 3.ягодный пирог(50@), 4.яблочный пирог(60@). " << endl;

        if (baristaChoice == 1) {
            Staff number1("Ivan", "Хорошо делает зеленый чай и ягодный пирог");
            number1.take_info();

            int drinkChoice, foodChoice;
            cout << "Выберите напиток: ";
            cin >> drinkChoice;
            cout << "Выберите блюдо: ";
            cin >> foodChoice;

            if ((drinkChoice == 1 && foodChoice == 3) || (drinkChoice == 1 && foodChoice == 4))  {
                Tea Greentea("Зеленый");
                Greentea.prepare();
                Greentea.serve();

                Pie pie1("ягоодный пирог");
                pie1.prepare();
                pie1.serve();

                cout << "Ivan приготовил вкусный чай и пирог, вы остались довольны" << endl;
            }
            else {
                cout << "Ivan не смог приготовить вкусный заказ, вы остались недовольны" << endl;
                cout << "Game over" << endl;
            }
        }
        else if (baristaChoice == 2) {
            Staff number2("Kate", "Хорошо делает черный чай и яблочный пирог");
            number2.take_info();

            int drinkChoice, foodChoice;
            cout << "Выберите напиток: ";
            cin >> drinkChoice;
            cout << "Выберите блюдо: ";
            cin >> foodChoice;

            if ((drinkChoice == 2 && foodChoice == 3) || (drinkChoice == 2 && foodChoice == 3)) {
                Tea Blacktea("Черный");
                Blacktea.prepare();
                Blacktea.serve();

                Pie pie2("яблочный пирог");
                pie2.prepare();
                pie2.serve();

                cout << "Kate приготовила вкусный чай, вы остались довольны" << endl;
            }
            else {
                cout << "Kate не смогла приготовить вкусный заказ, вы остались недовольны" << endl;
            }
        }
    }
    else if (cafeChoice == 2) {
        Cafe coffee("COFFEE");
        coffee.get_info();

        int baristaChoice;
        cout << "Выберите бариста: 1.Mary или 2.Anastasia" << endl;
        cin >> baristaChoice;

        cout << "Добрый день, что будете заказывать? На выбор есть: 1.капучино(10@), 2.латте(30@), 3.булочка с корицей(50@), 4.булочка с творогом(60@). " << endl;

        if (baristaChoice == 1) {
            Staff number1("Mary", "Варит прекрасный кофе и делает вкусные булочки с корицей");
            number1.take_info();

            int drinkChoice, foodChoice;
            cout << "Выберите напиток: ";
            cin >> drinkChoice;
            cout << "Выберите блюдо: ";
            cin >> foodChoice;

            if ((drinkChoice == 1 && foodChoice == 3) || (drinkChoice == 1 && foodChoice == 4)) {
                Coffee Cappuccino("Капучино");
                Cappuccino.prepare();
                Cappuccino.serve();

                Pie bun1("булочка с корицей");
                bun1.prepare();
                bun1.serve();

                cout << "Mary приготовила вкусный кофе, вы остались довольны" << endl;
            }
            else {
                cout << "Mary не смогла приготовить вкусный заказ, вы остались недовольны" << endl;
            }
        }
        else if (baristaChoice == 2) {
            Staff number2("Anastasia", "Хорошо делает Латте и готовит вкусную булочку с творогом");
            number2.take_info();

            int drinkChoice, foodChoice;
            cout << "Выберите напиток: ";
            cin >> drinkChoice;
            cout << "Выберите блюдо: ";
            cin >> foodChoice;

            if ((drinkChoice == 2 && foodChoice == 3) || (drinkChoice == 2 && foodChoice == 4)) {
                Coffee Latte("Латте");
                Latte.prepare();
                Latte.serve();

                Pie bun2("булочка с творогом");
                bun2.prepare();
                bun2.serve();

                cout << "Anastasia приготовила вкусный кофе и булочку, вы остались довольны" << endl;
            }
            else {
                cout << "Anastasia не смогла приготовить вкусный заказ, вы остались недовольны" << endl;
            }
        }
    }

    return 0;
}
