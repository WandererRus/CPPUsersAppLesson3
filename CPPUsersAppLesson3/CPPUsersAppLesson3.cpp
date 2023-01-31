// CPPUsersAppLesson3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include<string>
/*Есть некоторый текст.Используя стандартные
строковые функции :
Посчитайте количество вхождений слово, заданного пользователем;
Посчитайте количество предложений в тексте;
Количество точек и запятых;
Переверните весь текст целиком;
Переверните каждое предложение в тексте.*/
int countsubstr(const char* text, const char* substr)
{
    const char* findsubstr = nullptr;
    int counter = 0;
    do {
        findsubstr = strstr(text, substr);
        if (findsubstr != nullptr)
        {
            counter++;
            text = findsubstr + strlen(substr);
        }
        else
        {
            break;
        }
    } while (strstr(text, substr));
    return counter;
}

int main()
{
    const char* text = "this is, some; words. for, testing? in this... app and... this text! contains, some! words. more; than once";
    const char* substr = "this";
    std::cout << "\"" << substr << "\" exists in text " << countsubstr(text, substr) << " times \n";

    /*
    counter = 0;
    int massiveSize;
    while (strstr(text, "!") != nullptr || strstr(text, ".") != nullptr || strstr(text, "...") != nullptr || strstr(text, "?") != nullptr || strstr(text, ";") != nullptr)
    {

    }*/
    const char* substr2 = ".";
    const char* substr3 = ",";
    std::cout << "\"" << substr2 << "\" and \""<< substr3 <<"\"exists in text " << countsubstr(text, substr2) + countsubstr(text, substr3) << " times \n";
    int lenOfText = strlen(text);
    char* reversetext = new char[lenOfText];
    std::cout << text << "\n";
    for (int i = 0; i <= lenOfText; i++)
    {
        *(reversetext+i) = text[lenOfText - i-1];
    }
    std::cout << reversetext << "\n";
    std::string textString =  std::string(text);
    char* charArrayText = new char[lenOfText + 1];
    strcpy(charArrayText, textString.c_str());
    std::cout << strtok(charArrayText, "!");

    return 0;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
