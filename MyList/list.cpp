/*
Вокруг считающего стоит N человек, из которых выделен первый, а остальные занумерованы по часовой стрелке числами от 2 до N. 
Считающий, начиная с кого-то, ведет счет до M. Человек на котором остановился счет, выходит из круга. 
Счет продолжается со следующего человека и так до тех пор, пока не останется один человек.
Определить:
a) номер оставшегося человека, если известно M и то, что счет начинался с первого человека;
b) номер человека c которого начинался счет, если известно M и номер оставшегося человека L.
*/
#include "listcl.h"

using namespace std;
using namespace chrono;

// Функция для определения номера оставшегося человека
int findRemainingPerson(int N, int M) {
    list<int> people;
    for (int i = 1; i <= N; ++i) {
        people.push_back(i);
    }
    for(auto el : people) cout<<el<<" ";
    cout<<endl;
    auto current = people.begin();
    while (people.size() > 1) {
        for (int count = 1; count < M; ++count) {
            ++current;
            if (current == people.end()) {
                current = people.begin();
            }
        }
        current = people.erase(current);
        if (current == people.end()) {
            current = people.begin();
        }
        for(auto el : people) cout<<el<<" ";
        cout<<endl;
    }
    return people.front();
}

// Функция для определения номера человека, с которого начинался счет
int findStartingPerson(int N, int M, int L) {
    list<int> people;
    for (int i = 1; i <= N; ++i) {
        people.push_back(i);
    }
    for(auto el : people) cout<<el<<" ";
        cout<<endl;
    auto current = people.begin();
    while (people.size() > 1) {
        for (int count = 1; count < M; ++count) {
            ++current;
            if (current == people.end()) {
                current = people.begin();
            }
        }
        current = people.erase(current);
        if (current == people.end()) {
            current = people.begin();
        }
    }
    // Находим оставшегося человека
    int remainingPerson = people.front();
    // Теперь находим, с какого человека начинался счет
    int startingPerson = (L - M + remainingPerson - 1 + N) % N + 1;
    return startingPerson;
}
    

int main() {
    FILE* m;
    try {
        if((m = fopen("inp.txt","r")) == nullptr) throw Exception("inp.txt");
    } catch (const Exception& ex) {
        cout<<"Не существует такого файла, как "<<ex.getMessage()<<endl;
        return -1;
    }
    int N, M, L;
    double c;
    Slist<int> A;
    Node<int>* temp;
    try {
        if(fscanf(m, "%d %d %d", &N, &M, &L) != 3) throw Exception{"inp.txt"};
    } catch (const Exception& ex) {
        cout<<"Некорректные данные в файле "<<ex.getMessage()<<endl;
        return -1;
    }
    if(N < 1) {
        cout<<"Количество N человек < 1";
        return 0;
    }
    auto start = high_resolution_clock::now();
    // Создание односвязного списка
    for (int i = 1; i <= N; i++) {
        A.Add(i);
    }
    A.Show();
    Node<int>* last = A[0];
    // Цикл по обходу списка
    for (int i = 1; i < N; i++) {
        // Цикл для перехода на M-й элемент вперед
        for (int j = 1; j < M; j++) {
            last = last->next;
        }
        // Обновление указателей для удаления текущего элемента
        temp = last;
        last = last->next;
        cout<<"Выбыл "<<temp->x<<"-й человек    ";
        A.remove(temp);
        A.Show();
    }
    cout<<"a)Считалочка остановилась на "<<last->x<<"-м человеке :) \n";
    //printf("a)Считалочка остановилась на %d-м человеке :) \n", last->x);
    int beg = (L - M + last->x - 1 + N) % N + 1; 
    cout<<"b)Считалочка начиналась с "<<beg<<"-ого человека :) \n";
    //printf("b)Считалочка начиналась с %d-ого человека :)\n", begin);
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<nanoseconds>(end - start);
    c = duration.count();
    cout<<"Время выполнения: "<<c<<" наносекунд"<<endl; 
    start = high_resolution_clock::now();
    //STL:
    // a) Номер оставшегося человека
    int remainingPerson = findRemainingPerson(N, M);
    cout<<"a) Номер оставшегося человека: "<<remainingPerson<<endl;

    // b) Номер человека, с которого начинался счет
    int startingPerson = findStartingPerson(N, M, L);
    cout<<"b) Номер человека, с которого начинался счет: "<<startingPerson<<endl;
    end = high_resolution_clock::now();
    duration = duration_cast<nanoseconds>(end - start);
    c = duration.count();
    cout<<"Время выполнения: "<<c<<" наносекунд"<<endl;
    //проверка оператора копирования на списке, элементы которого - целочисленные массивы 
    int* arr1 = new int[10];
    int* arr2 = new int[10];
    int* arr3 = new int[10];
    for(int i = 0; i < 10; i++) {
        arr1[i] = i + 1;
        arr2[i] = 2*(i + 1);
        arr3[i] = 3*(i + 1);
    }
    cout<<"list:\n";
    Slist<int*> list;
    list.Add(arr1);
    list.Add(arr2);
    list.Add(arr3);
    Slist<int*>::iterator it4 = list.begin();

    do {
        int* A = *it4;
        for(int i = 0; i < 10; i++) std::cout << A[i] << " ";
        std::cout << "\n";
        it4++;
    } while (it4 != list.begin());
    cout<<"copylist:\n";
    Slist<int*> copylist = list;
    Slist<int*>::iterator it3 = copylist.begin();
    
    do {
        int* A = *it3;
        for(int i = 0; i < 10; i++) std::cout << A[i] << " ";
        std::cout << "\n";
        it3++;
    } while (it3 != copylist.begin());
    return 0; 
}