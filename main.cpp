#include <iostream>
#include <cmath>
#include <fstream>

using namespace std;

class abiba {
    public:
        static void to_string(){
            cout << endl << "вот ты и попался C#-пер!";
        }
    static void fileAction(int source, bool write){
        if (write) {
            ofstream out;
            out.open("/home/michail/CLionProjects/untitled/1.txt", ios::app);
            if (out.is_open()) {
                out << source << endl;
                out.close();
            }
        } else {
            ifstream out("/home/michail/CLionProjects/untitled/1.txt");
            string txt;
            cout << "Числа: " << endl;
            while (getline(out, txt)){
                cout << txt << endl;
            }
        }
    }

    static int toDec(int source){
        int dec = 0, i = 0, rem;
        while (source!=0) {
            rem = source % 10;
            source /= 10;
            dec += rem * pow(2, i);
            ++i;
        }
        cout << dec;
        fileAction(dec, true);
    }

    static int toBin(int source){
        int bin = 0;
        int rem, i = 1;

        while (source != 0) {
            rem = source % 2;
            source /= 2;
            bin += rem * i;
            i *= 10;
        }
        cout << bin;
        fileAction(bin, true);
    }
};



int main() {
    int select;
    cout << "Добро пожаловать\n\nВыберите задание из списка:\n1) Всё кроме четвёртого\n2) Четвёртое\n\nВведите номер задания: ";
    cin >> select;
    if (select == 1){
        int source;
        int lenghtOfValid = 0;
        cout << "Введите число: ";
        cin >> source;
        for (int i = 0; i < to_string(source).length(); i++){
            char str[to_string(source).length()];
            str[i] = to_string(source)[i];
            if (atoi(&str[i]) == 1 || atoi(&str[i]) == 0) lenghtOfValid++;
        }
        if (lenghtOfValid == to_string(source).length()){
            abiba::toDec(source);
        } else {
            abiba::toBin(source);
        }
        abiba::to_string();
        abiba::fileAction(NULL, false);
        return 0;
    } else if (select == 2) {
        int count;
        cout << "Введите количество вводимых чисел: ";
        cin >> count;
        double sum = 0;
        double some[count];
        for (int i = 0; i < count; i++){
            cout << endl << "Введите " << i+1 << " число: ";
            cin >> some[i];
            sum += some[i];
        }
        cout << endl << "Средняя температура: " << sum / count << endl;
        ofstream out;
        out.open("/home/michail/CLionProjects/untitled/2.txt", ios::app);
        if (out.is_open()) {
            out << sum / count << endl;
            out.close();
        }
        return 0;
    } else {
        cout << "Такого задания не существует, удаляю System32";
        return 0;
    }
}