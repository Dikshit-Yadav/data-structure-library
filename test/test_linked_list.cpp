#include <iostream>
#include <string>
#include "Linked_List.h"

int main()
{
    std::cout << " Default Constructor \n";

    LinkedList<int> list1;

    std::cout << "Size : " << list1.size() << '\n';
    std::cout << "Empty: " << std::boolalpha << list1.empty() << "\n\n";


    std::cout << " Copy Constructor \n";

    LinkedList<int> list2(list1);

    std::cout << "Original Size : " << list1.size() << '\n';
    std::cout << "Copied Size   : " << list2.size() << '\n';
    std::cout << "Copied Empty  : " << list2.empty() << "\n\n";


    std::cout << "Copy Assignment\n";

    LinkedList<int> list3;

    list3 = list1;

    std::cout <<"Assigned Size: " << list3.size() << '\n';
    std::cout <<"Assigned Empty: " << list3.empty() << "\n\n";


    std::cout << "Self Assignment\n";

    list3 = list3;

    std::cout << "Self Assignment Successful\n";
    std::cout << "Size : " << list3.size() << '\n';
    std::cout << "Empty: " << list3.empty() << "\n\n";


    std::cout << " Destructor \n";
    std::cout << "Objects will be destroyed automatically at program exit.\n";

    return 0;
}