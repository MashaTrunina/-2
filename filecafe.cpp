#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
/* Так делать не стоит из-за конфликтов имен. Пусть у тебя есть функция с именем как у функции, 
 * которая орпеделена в стд. Тогда при вызове узнать, какая из эти двух функций на самом деле 
 * вызывается будет сложно. А вот если бы функцию из стд ты вызывал std::func(), то такой проблемы
 * возникнуть не может */
/* Если тебе это хочется для ввода-вывода только, то просто using std::cin и аналогично cout */
using namespace std;

class Character {
public:
    string name;

public:
    Character(string _name) : name(_name) {}

    Character() : name(" ") {}

    ~Character() {}

    void displayInfo() {
        cout << "Ïåðñîíàæ: " << name << endl;
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
/* Меню не содержит никаких данных и функций, непонятно, зачем тогда он нужен. */
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
    /* Можно заметить, что у тебя для всех классов конкретной еды есть эти методы. Тогда 
     * они должны быть в общем интерфейсе, который они наследуют от какого-то предка и 
     * переопределяют, чтобы затем это поведение можно было вызывать через указатель на предка.
     * Так что их нужно сделать виртуальными функциями в одном из классов предков. А вообще, 
     * структура твоих классов не совсем позволяет это удобно сделать, потому что Drink наследуется
     * от Food, но не является напрямую servable, а вот Pie является. Тогда выходит, что при помещении
     * этого интерфейса в класс Food, в классе Drink придется переопределять функции, которые ему не нужны.
     * Не то чтобы это страшно, но есть еще один вариант: можно сделать интерфейс (абстарктный класс), в
     * в котором будут виртуальные функции prepare и serve. А потом делать наследование от него для всех
     * конкретных классов еды. */
    void prepare() {
        cout << "Ïðèãîòîâëåíèå ïèðîãà" << endl;
    }

    void serve() {
        cout << "Ïîäà÷à ïèðîãà" << endl;
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
        cout << "Ïðèãîòîâëåíèå ÷àÿ" << endl;
    }

    void serve() {
        cout << "Ïîäà÷à ÷àÿ" << endl;
    }
};

class Coffee : public Drink {
public:
    Coffee(string _name) : name(_name) {}

    Coffee() : name("") {}

    ~Coffee() {}

    string name;

    void prepare() {
        cout << "Ïðèãîòîâëåíèå êîôå" << endl;
    }

    void serve() {
        cout << "Ïîäà÷à êîôå" << endl;
    }
};

/* Немного не ясно назначение этого класса. Судя по методам, это не
 * деньги персонажа. Тогда для чего он используется? Кажется, что 
 * можно было бы сделать какое-то количество денег персонажа и 
 * заведения полями. Тогда трансфер мог бы переводить эти деньги между
 * этими сущностями */
class Money {
private:
    int amount;

public:
    Money() {}

    void transfer() {
        cout << " Âàø áàëàíñ: " << amount << endl;
    }

    void generateMoney() {
        srand(static_cast<unsigned>(time(0)));
        amount = rand() % 151 + 50; // Ãåíåðàöèÿ ñëó÷àéíîãî ÷èñëà îò 50 äî 200
    }
};

int main() {
    setlocale(LC_ALL, "RU");

    Character character;
    cout << "Ââåäèòå èìÿ ïåðñîíàæà: ";
    cin >> character.name;
    character.displayInfo();

    int cafeChoice;
    cout << "Âûáåðèòå êàôå: 1.TEA èëè 2.COFFEE" << endl;
    cin >> cafeChoice;

    Money money;
    money.generateMoney();
    money.transfer();

    if (cafeChoice == 1) { // Âûáîð êàôå

        Cafe tea("TEA");
        tea.get_info();

        int baristaChoice;
        cout << "Âûáåðèòå áàðèñòà: 1.Ivan èëè 2.Kate" << endl;
        cin >> baristaChoice;

        cout << "Äîáðûé äåíü, ÷òî áóäåòå çàêàçûâàòü? Íà âûáîð åñòü: 1.çåëåíûé ÷àé(10@), 2.÷åðíûé ÷àé(30@), 3.ÿãîäíûé ïèðîã(50@), 4.ÿáëî÷íûé ïèðîã(60@). " << endl;

        if (baristaChoice == 1) {
            Staff number1("Ivan", "Õîðîøî äåëàåò çåëåíûé ÷àé è ÿãîäíûé ïèðîã");
            number1.take_info();

            int drinkChoice, foodChoice;
            cout << "Âûáåðèòå íàïèòîê: ";
            cin >> drinkChoice;
            cout << "Âûáåðèòå áëþäî: ";
            cin >> foodChoice;

            if ((drinkChoice == 1 && foodChoice == 3) || (drinkChoice == 1 && foodChoice == 4))  {
                Tea Greentea("Çåëåíûé");
                Greentea.prepare();
                Greentea.serve();

                Pie pie1("ÿãîîäíûé ïèðîã");
                pie1.prepare();
                pie1.serve();
                /* Кажется, что этот вывод можно генерировать из класса Баристы. Он сам будет подставлять
                 * свое имя в начало, еще будет получать указатель на ту еду, что он подает, оттуда извлекать
                 * её название и тоже подставлять в строку вывода. Потому что если я заставлю тебя написать
                 * сценарии с еще 10 работниками, ты умрешь. */
                cout << "Ivan ïðèãîòîâèë âêóñíûé ÷àé è ïèðîã, âû îñòàëèñü äîâîëüíû" << endl;
            }
            else {
                cout << "Ivan íå ñìîã ïðèãîòîâèòü âêóñíûé çàêàç, âû îñòàëèñü íåäîâîëüíû" << endl;
                cout << "Game over" << endl;
            }
        }
        else if (baristaChoice == 2) {
            Staff number2("Kate", "Õîðîøî äåëàåò ÷åðíûé ÷àé è ÿáëî÷íûé ïèðîã");
            number2.take_info();

            int drinkChoice, foodChoice;
            cout << "Âûáåðèòå íàïèòîê: ";
            cin >> drinkChoice;
            cout << "Âûáåðèòå áëþäî: ";
            cin >> foodChoice;

            if ((drinkChoice == 2 && foodChoice == 3) || (drinkChoice == 2 && foodChoice == 3)) {
                Tea Blacktea("×åðíûé");
                Blacktea.prepare();
                Blacktea.serve();

                Pie pie2("ÿáëî÷íûé ïèðîã");
                pie2.prepare();
                pie2.serve();

                cout << "Kate ïðèãîòîâèëà âêóñíûé ÷àé, âû îñòàëèñü äîâîëüíû" << endl;
            }
            else {
                cout << "Kate íå ñìîãëà ïðèãîòîâèòü âêóñíûé çàêàç, âû îñòàëèñü íåäîâîëüíû" << endl;
            }
        }
    }
    else if (cafeChoice == 2) {
        Cafe coffee("COFFEE");
        coffee.get_info();

        int baristaChoice;
        cout << "Âûáåðèòå áàðèñòà: 1.Mary èëè 2.Anastasia" << endl;
        cin >> baristaChoice;

        cout << "Äîáðûé äåíü, ÷òî áóäåòå çàêàçûâàòü? Íà âûáîð åñòü: 1.êàïó÷èíî(10@), 2.ëàòòå(30@), 3.áóëî÷êà ñ êîðèöåé(50@), 4.áóëî÷êà ñ òâîðîãîì(60@). " << endl;

        if (baristaChoice == 1) {
            Staff number1("Mary", "Âàðèò ïðåêðàñíûé êîôå è äåëàåò âêóñíûå áóëî÷êè ñ êîðèöåé");
            number1.take_info();

            int drinkChoice, foodChoice;
            cout << "Âûáåðèòå íàïèòîê: ";
            cin >> drinkChoice;
            cout << "Âûáåðèòå áëþäî: ";
            cin >> foodChoice;

            if ((drinkChoice == 1 && foodChoice == 3) || (drinkChoice == 1 && foodChoice == 4)) {
                Coffee Cappuccino("Êàïó÷èíî");
                Cappuccino.prepare();
                Cappuccino.serve();

                Pie bun1("áóëî÷êà ñ êîðèöåé");
                bun1.prepare();
                bun1.serve();

                cout << "Mary ïðèãîòîâèëà âêóñíûé êîôå, âû îñòàëèñü äîâîëüíû" << endl;
            }
            else {
                cout << "Mary íå ñìîãëà ïðèãîòîâèòü âêóñíûé çàêàç, âû îñòàëèñü íåäîâîëüíû" << endl;
            }
        }
        else if (baristaChoice == 2) {
            Staff number2("Anastasia", "Õîðîøî äåëàåò Ëàòòå è ãîòîâèò âêóñíóþ áóëî÷êó ñ òâîðîãîì");
            number2.take_info();

            int drinkChoice, foodChoice;
            cout << "Âûáåðèòå íàïèòîê: ";
            cin >> drinkChoice;
            cout << "Âûáåðèòå áëþäî: ";
            cin >> foodChoice;

            if ((drinkChoice == 2 && foodChoice == 3) || (drinkChoice == 2 && foodChoice == 4)) {
                Coffee Latte("Ëàòòå");
                Latte.prepare();
                Latte.serve();

                Pie bun2("áóëî÷êà ñ òâîðîãîì");
                bun2.prepare();
                bun2.serve();

                cout << "Anastasia ïðèãîòîâèëà âêóñíûé êîôå è áóëî÷êó, âû îñòàëèñü äîâîëüíû" << endl;
            }
            else {
                cout << "Anastasia íå ñìîãëà ïðèãîòîâèòü âêóñíûé çàêàç, âû îñòàëèñü íåäîâîëüíû" << endl;
            }
        }
    }

    return 0;
}
