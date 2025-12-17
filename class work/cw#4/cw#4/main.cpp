#include <iostream>
#include <string>
using namespace std;

// Структура дії
struct Action {
    string title;

    // Декілька зручних конструкторів
    Action() : title("") {}
    Action(const string& title) : title(title) {}
};

class MyStack
{
    // Нижня і верхня межі стека
    enum { EMPTY = -1, FULL = 20 };

    // Массив для зберігання дій
    Action st[FULL + 1];

    // Індекс вершини стека
    int top;

public:
    // Конструктор
    MyStack();

    // Додати дію
    void Push(const Action& a);

    // Витягнути дію
    Action Pop();

    // Очистити стек
    void Clear();

    // Перевірка: стек пустий?
    bool IsEmpty();

    // Перевірка: стек повний?
    bool IsFull();

    // Кількість елементів
    int GetCount();

    // Вивести всі дії
    void Output()
    {
        if (IsEmpty()) {
            cout << "[порожній стек]\n";
            return;
        }

        for (int i = 0; i < top + 1; i++)
        {
            cout << i << ": " << st[i].title << endl;
        }
        cout << endl;
    }
    ../ ∆∆∆


MyStack::MyStack()
{
    top = EMPTY;
}

void MyStack::Clear()
{
    top = EMPTY;
}

bool MyStack::IsEmpty()
{
    return top == EMPTY;
}

bool MyStack::IsFull()
{
    return top == FULL;
}

int MyStack::GetCount()
{
    return top + 1;
}

void MyStack::Push(const Action& a)
{
    if (!IsFull())
        st[++top] = a;
}

Action MyStack::Pop()
{
    if (!IsEmpty())
        return st[top--];
    // якщо пустий — повертаємо "порожню" дію
    return Action();
}

int main()
{
    MyStack actions;

    actions.Push(Action("Відкрити файл"));
    actions.Push(Action("Зберегти файл"));
    actions.Push(Action("Скасувати останню дію"));
    actions.Push(Action("Закрити програму"));

    cout << "Стек дій зараз:\n";
    actions.Output();

    // Знімаємо верхні дві дії
    Action a1 = actions.Pop();
    Action a2 = actions.Pop();

    cout << "Зняли зверху:\n";
    cout << "1) " << a1.title << endl;
    cout << "2) " << a2.title << endl << endl;

    cout << "Стек після Pop:\n";
    actions.Output();

    return 0;
}

