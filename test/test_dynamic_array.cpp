#include <iostream>
#include <string>
#include "DynamicArray.h"

using std::cout;
using std::endl;
using std::string;

template <typename T>
void printArray(const DynamicArray<T>& arr, const string& name)
{
    cout << "\n" << name << " (size=" << arr.size()
         << ", capacity=" << arr.capacity() << "): ";

    for (int i = 0; i < arr.size(); i++)
        cout << arr.get(i) << " ";

    cout << endl;
}

int main()
{


    DynamicArray<int> intArr;

    intArr.append(10);
    intArr.append(20);
    intArr.append(30);
    intArr.insert(1, 999);
    intArr.remove(2);

    printArray(intArr, "INT ARRAY");


    DynamicArray<char> charArr;

    charArr.append('A');
    charArr.append('B');
    charArr.append('C');
    charArr.insert(1, 'X');

    printArray(charArr, "CHAR ARRAY");

    DynamicArray<double> doubleArr;

    doubleArr.append(1.1);
    doubleArr.append(2.2);
    doubleArr.append(3.3);
    doubleArr.insert(2, 9.9);

    printArray(doubleArr, "DOUBLE ARRAY");


    DynamicArray<string> stringArr;

    stringArr.append("hello");
    stringArr.append("world");
    stringArr.append("dynamic");
    stringArr.insert(1, "C++");

    printArray(stringArr, "STRING ARRAY");

    DynamicArray<string> copyArr(stringArr);
    printArray(copyArr, "STRING COPY");

    DynamicArray<string> assignArr;
    assignArr.append("temp");
    assignArr = stringArr;
    printArray(assignArr, "STRING ASSIGNMENT");

    cout << "TEST COMPLETE \n";

    return 0;
}