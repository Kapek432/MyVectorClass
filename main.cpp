#include <iostream>
#include "MyVector.h"
#include <limits>

int main() {
    MyVector<int> vec1;

    vec1.pushBack(10);
    vec1.pushBack(20);
    vec1.pushBack(30);
    vec1.pushFront(5);

    std::cout << "vec1 after pushBack and pushFront: " << vec1 << std::endl;


    std::cout << "First element: " << vec1[0] << std::endl;
    std::cout << "Size of vec1: " << vec1.getSize() << std::endl;

    vec1.pop_back();
    std::cout << "vec1 after pop_back: " << vec1 << std::endl;

    vec1.pop_front();
    std::cout << "vec1 after pop_front: " << vec1 << std::endl;

    vec1.insert(1, 25);  // Insert 25 at index 1
    std::cout << "vec1 after insert at index 1: " << vec1 << std::endl;

    vec1.erase(0);  // Erase element at index 0
    std::cout << "vec1 after erase at index 0: " << vec1 << std::endl;

    vec1.clear();
    std::cout << "vec1 after clear: " << vec1 << std::endl;

    vec1.reserve(5);
    vec1.pushBack(100);
    vec1.pushBack(200);
    std::cout << "vec1 after reserve and pushBack: " << vec1 << std::endl;

    vec1.resize(1);  // Resize to 1 element
    std::cout << "vec1 after resize to size 1: " << vec1 << std::endl;

    vec1.pushBack(300);
    vec1.pushBack(400);
    vec1.reverse();
    std::cout << "vec1 after reverse: " << vec1 << std::endl;

    vec1.sort();
    std::cout << "vec1 after sort: " << vec1 << std::endl;

    MyVector<int> vec2 = vec1;
    std::cout << "vec2 after copy assignment: " << vec2 << std::endl;

    std::cout << "vec1 and vec2 are equal: " << (vec1 == vec2 ? "True" : "False") << std::endl;

    MyVector<int> vec3;
    vec3.pushBack(500);
    vec3.pushBack(600);
    vec3.pushBack(700);
    MyVector<int> vec4 = vec1 + vec3;
    std::cout << "vec4 (vec1 + vec3): " << vec4 << std::endl;
    vec1 += vec3;
    std::cout << "vec1 after vec1 += vec3: " << vec1 << std::endl;

    MyVector<int> vec5 = vec1 - vec3;
    std::cout << "vec5 (vec1 - vec3): " << vec5 << std::endl;
    vec1 -= vec3;
    std::cout << "vec1 after vec1 -= vec3: " << vec1 << std::endl;

    MyVector<int> vec6 = vec1 * vec3;
    std::cout << "vec6 (vec1 * vec3): " << vec6 << std::endl;
    vec1 *= vec3;
    std::cout << "vec1 after vec1 *= vec3: " << vec1 << std::endl;

    MyVector<int> vec7 = vec1 / vec3;
    std::cout << "vec7 (vec1 / vec3): " << vec7 << std::endl;
    vec1 /= vec3;
    std::cout << "vec1 after vec1 /= vec3: " << vec1 << std::endl;

    std::cout << "Enter 3 numbers for vec8: ";
    MyVector<int> vec8(3);
    vec8.resize(3);
    std::cin >> vec8;
    std::cout << "vec8 after input: " << vec8 << std::endl;

    return 0;
}
