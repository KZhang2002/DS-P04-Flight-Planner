#include "catch.hpp"
#include "DSString.h"
#include "DSVector.h"
#include "DSLinkedList.h"
#include "DSStack.h"
#include <iostream>
#include <fstream>
#include <algorithm>

//Namespace declarations
using std::cout;
using std::endl;
using std::ifstream;
using std::ofstream;
using std::fstream;

/*
TEST_CASE( "DSString Class Functions", "[DSString]" ) {

    DSString str1;
    char const *test = "test";
    char const *alph = "abcdefghijklmnopqrstuvwxyz";
    char const *empty = "";

    SECTION("Constructor Testing") {
        DSString str2(test);
        REQUIRE(strcmp(str2.c_str(), test) == 0); //Should Pass

        DSString str3(str2);
        REQUIRE(strcmp(str3.c_str(), str2.c_str()) == 0); //Should Pass

        DSString null;
        REQUIRE(null.c_str() == nullptr);
    }

    SECTION("Assignment Operator Testing") {
        DSString str2;
        DSString str3;

        str2 = test;
        REQUIRE(strcmp(str2.c_str(), test) == 0); //Should Pass

        str1 = str2;
        REQUIRE(strcmp(str1.c_str(), str2.c_str()) == 0); //Should Pass

        str3 = alph;
        REQUIRE(strcmp(str3.c_str(), alph) == 0);
    }

    SECTION("Concat Operator Testing") {
        DSString str2 = test;
        str1 = test;
        DSString str3;
        str3 = str1 + str2;
        str1 = test;
        char testtest[9] = "testtest";
        REQUIRE(strcmp(str1.c_str(), test) == 0);
        REQUIRE(strcmp(str2.c_str(), test) == 0);
        REQUIRE(strcmp(str3.c_str(), testtest) == 0); //Should pass
    }

    SECTION("Relational Operator Testing") {
        str1 = "a";
        DSString str2("b");
        REQUIRE((strcmp(str1.c_str(), str2.c_str()) < 0) == str1 < str2); //Should pass
        REQUIRE((strcmp(str2.c_str(), str1.c_str()) < 0) == str1 > str2); //Should pass
        REQUIRE((strcmp(str2.c_str(), str1.c_str()) < 0) != str1 < str2); //Should pass
    }

    SECTION("Subscript Operator Testing") {
        str1 = test;
        REQUIRE(str1[0] == 't'); //Should pass
        REQUIRE(str1[1] != 't'); //Should pass
        REQUIRE(str1[2] == 's'); //Should pass
    }

    SECTION("Get Function Testing") {
        str1 = test;
        DSString str2(alph);

        //getLength() test
        REQUIRE(str1.getLength() == strlen(test)); //Should pass

        //substring() tests
        char temp1[5] = "abcd";
        DSString str3 = str2.substring(0, 4);
        REQUIRE(strcmp(str3.c_str(), temp1) == 0); //Should pass

        char temp2[4] = "xyz";
        str3 = str2.substring(23, 3);
        REQUIRE(strcmp(str3.c_str(), temp2) == 0); //Should pass

        //c_str() test
        REQUIRE(strcmp(str1.c_str(), test) == 0); //Should pass
    }

    SECTION("Stream Insertion Operator Testing") {
        DSString message("Stream Insertion Operator Works");
        cout << message << endl;
    }

    SECTION("Clean Function Testing") {
        DSString emptyStr("");
        DSString nonalph1("!@#$%^");
        DSString nonalph2("!test");
        DSString nonalph3("test!");
        DSString nonalph4("!te!st!");
        DSString nonalph5("!te!!!st!");
        DSString testStr(test);

        REQUIRE(strcmp(nonalph2.clean().c_str(), testStr.c_str()) == 0);
        REQUIRE(strcmp(nonalph3.clean().c_str(), testStr.c_str()) == 0);
        REQUIRE(strcmp(nonalph4.clean().c_str(), testStr.c_str()) == 0);
        REQUIRE(strcmp(nonalph4.clean().c_str(), testStr.c_str()) == 0);
    }

    SECTION("lowerStr() Function Testing") {
        DSString capitalStr("Test");
        DSString capitalStr2("tesT");
        DSString capitalStr3("TesT");
        DSString capitalStr4("TEST");
        DSString testStr(test);

        REQUIRE(strcmp(capitalStr.lowerStr().c_str(), testStr.c_str()) == 0);
        REQUIRE(strcmp(capitalStr2.lowerStr().c_str(), testStr.c_str()) == 0);
        REQUIRE(strcmp(capitalStr3.lowerStr().c_str(), testStr.c_str()) == 0);
        REQUIRE(strcmp(capitalStr4.lowerStr().c_str(), testStr.c_str()) == 0);
    }

    SECTION("Find Function Testing") {
        DSString findWordTest("a test aa test aa");
        DSString findTest("aatestaaaatestaaa");
        DSString testStr("test");

        REQUIRE(findWordTest.findWord(testStr) == 2);
        REQUIRE(findWordTest[findWordTest.findWord(testStr)] == 't');

        REQUIRE(findWordTest.find(testStr, 6) == 10);
        REQUIRE(findWordTest[findWordTest.findWord(testStr)] == 't');

        REQUIRE(findTest.find(testStr) == 2);
        REQUIRE(findTest[findTest.find(testStr)] == 't');

        REQUIRE(findTest.find(testStr, 6) == 10);
        REQUIRE(findTest[findTest.find(testStr)] == 't');
    }
}
*/
/*
TEST_CASE( "DSVector Class Functions", "[DSVector]") {
    SECTION("Constructor Testing") {
        //Default Constructor
            DSVector<int> defCon;
            REQUIRE(defCon.getSize() == 0);
            REQUIRE(defCon.getCapacity() == 10);

        //Constructor (size, capacity, data)
            int *arr = new int[4]{1, 2, 3, 4};
            DSVector<int> nums(4, 4, arr);

            REQUIRE(nums.getData() == arr);
            REQUIRE(nums.getSize() == 4);
            REQUIRE(nums.getCapacity() == 4);

            nums.print();

        //Constructor (size, val)
            int arr2[4] = {1, 1, 1, 1};
            DSVector<int> nums2(4, 1);

            REQUIRE(nums2.compare(arr2, 4));
            REQUIRE(nums2.getSize() == 4);
            REQUIRE(nums2.getCapacity() == 14);

        //Copy Constructor
            int arr3[4] = {1, 2, 1, 2};
            REQUIRE(!nums2.compare(arr3, 4));

            DSVector<int> nums3(nums2);
            REQUIRE(nums2.compare(nums3));
            REQUIRE(nums2.getCapacity() == nums3.getCapacity());
            REQUIRE(nums2.getSize() == nums3.getSize());
    }

    SECTION("Storage Testing") {
        DSVector<int> nums(4, 4);
        for (int i = 1; i <= 100; i++) {
            nums.push_back(i);
        }

        REQUIRE(nums.getSize() == 104);
        REQUIRE(nums.getCapacity() == 112);

        REQUIRE(nums[1] == 4);
        REQUIRE(nums[4] == 1);
        REQUIRE(nums[53] == 50);
        REQUIRE(nums[103] == 100);
    }

    SECTION("Operator Testing") {
        int *arr = new int[4]{1, 2, 3, 4};
        DSVector<int> nums(4, 4, arr);

        REQUIRE(nums[0] == 1);
        REQUIRE(nums[1] == 2);
        REQUIRE(nums[2] == 3);
        REQUIRE(nums[3] == 4);

        DSVector<int> nums2;
        nums2 = nums;

        REQUIRE(nums.compare(nums2));

        cout << nums << endl;
        cout << nums2 << endl;
    }

    SECTION("Vector Element Modifiers Test") {
        DSVector<int> nums;
        DSVector<int> nums2(30, 1);

        for (int i = 0; i < 30; i++) {
            nums.push_back(1);
        }
        REQUIRE(nums.compare(nums2));

        DSVector<int> nums3;
        for (int i = 0; i < 100; i++) {
            nums3.push_back(i);
        }

        nums3.pop(0);
        REQUIRE(nums3[0] == 1);

        nums3.pop(50);
        REQUIRE(nums3[50] == 52);
    }

    SECTION("Iterator Function Tests") {
        int *arr = new int[4]{1, 2, 3, 4};
        DSVector<int> nums(4, 4, arr);

        REQUIRE(*nums.begin() == 1);
        REQUIRE(*(nums.end() - 1) == 4);

        nums.increment_iterator();
        REQUIRE(*nums.get_iterator() == 2);

    }
}
*/
/*TEST_CASE( "DSLinkedList Class Functions", "[DSLinkedList]") {
    SECTION("Constructor Testing") {
        //Default Constructor
        DSLinkedList<int> empty;
        REQUIRE(empty.getHead() == nullptr);
        REQUIRE(empty.getTail() == nullptr);
        REQUIRE(empty.getIterator() == nullptr);
        REQUIRE(empty.getNumMembers() == 0);

        //Constructor (array)
        int arr[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
        DSLinkedList<int> arrayList(arr, 10);
        arrayList.printAll();

        for(int i = 0; i < 10; i++) {
            if (i != 0) { REQUIRE(arrayList.getIterator()->getPrev()->getData() == arr[i-1]); }
            REQUIRE(arrayList.getIterator()->getData() == arr[i]);
            if (i != 9) { REQUIRE(arrayList.getIterator()->getNext()->getData() == arr[i+1]); }

            if (i != 9) {
                arrayList.incrementIterator();
            }
        }

        for(int i = 9; i >= 0; i--) {
            if (i != 0) { REQUIRE(arrayList.getIterator()->getPrev()->getData() == arr[i-1]); }
            REQUIRE(arrayList.getIterator()->getData() == arr[i]);
            if (i != 9) { REQUIRE(arrayList.getIterator()->getNext()->getData() == arr[i+1]); }

            if (i != 0) {
                arrayList.decrementIterator();
            }
        }

        arrayList.resetIterator();

        //Copy Constructor
        DSLinkedList<int> copy(arrayList);
        copy.resetIterator();
        copy.printAll();

        for(int i = 0; i < 10; i++) {
            if (i != 0) { REQUIRE(copy.getIterator()->getPrev()->getData() == arr[i-1]); }
            REQUIRE(copy.getIterator()->getData() == arr[i]);
            if (i != 9) { REQUIRE(copy.getIterator()->getNext()->getData() == arr[i+1]); }

            if (i != 9) {
                copy.incrementIterator();
            }
        }

        for(int i = 9; i >= 0; i--) {
            if (i != 0) { REQUIRE(copy.getIterator()->getPrev()->getData() == arr[i-1]); }
            REQUIRE(copy.getIterator()->getData() == arr[i]);
            if (i != 9) { REQUIRE(copy.getIterator()->getNext()->getData() == arr[i+1]); }

            if (i != 0) {
                copy.decrementIterator();
            }
        }
    }

    SECTION("Operator Overloading Testing") {
        //Comparison Operator and Brackets
        int arr[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
        DSLinkedList<int> arrayList(arr, 10);
        arrayList.resetIterator();

        for (int i  = 0; i < arrayList.getNumMembers(); i++) {
            cout << arrayList[i] << " == " << arrayList.getIterator() << endl;

            REQUIRE(arrayList[i] == arrayList.getIterator());
            arrayList.incrementIterator();

            REQUIRE(arrayList[i].getData() == arr[i]);
            if (i != 0) { REQUIRE(arrayList[i].getPrev()->getData() == arr[i-1]); }
            if (i != 9) { REQUIRE(arrayList[i].getNext()->getData() == arr[i+1]); }
        }

        //Assignment Operator
        DSLinkedList<int> copy;
        copy = arrayList;

        for (int i = 0; i < copy.getNumMembers(); i++) {
            REQUIRE(copy[i].getData() == arrayList[i]->getData());
            if (i != 0) { REQUIRE(copy[i]->getPrev()->getData() == arrayList[i-1]->getPrev()->getData()); }
            if (i != 9) { REQUIRE(copy[i]->getNext()->getData() == arrayList[i+1]->getNext()->getData()); }
        }
    }

    SECTION("List Modifiers") {
        int arr[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
        DSLinkedList<int> arrayList(arr, 10);
        arrayList.printAll();

        //Push_Back
        arrayList.push_back(10);
        cout << "Element pushed back" << endl;
        arrayList.printAll();
        REQUIRE(arrayList[10]->getData() == 10);
        REQUIRE(arrayList.getNumMembers() == 11);
        REQUIRE(arrayList.getTail()->getData() == 10);

        for (int i = 0; i < 11; i++) {
            REQUIRE(arrayList[i]->getData() == i);
            if (i != 0) { REQUIRE(arrayList[i]->getPrev()->getData() == i - 1); }
            if (i != 10) { REQUIRE(arrayList[i]->getNext()->getData() == i + 1); }
        }

        //Push_Front
        arrayList.push_front(-1);
        cout << "Element pushed front" << endl;
        arrayList.printAll();

        REQUIRE(arrayList.getNumMembers() == 12);
        REQUIRE(arrayList.getTail()->getData() == 10);

        for (int i = -1; i < 11; i++) {
            REQUIRE(arrayList[i + 1]->getData() == i);
            if (i != -1) { REQUIRE(arrayList[i + 1]->getPrev()->getData() == i - 1); }
            if (i != 10) { REQUIRE(arrayList[i + 1]->getNext()->getData() == i + 1); }
        }

        //Pop_Back
        REQUIRE(arrayList.pop_back() == 10);
        cout << "Element popped back" << endl;
        arrayList.printAll();

        for (int i = 0; i < 11; i++) {
            REQUIRE(arrayList[i]->getData() == i - 1);
            if (i != 0) { REQUIRE(arrayList[i]->getPrev()->getData() == i - 2); }
            if (i != 10) { REQUIRE(arrayList[i]->getNext()->getData() == i); }
        }

        //Pop_Front
        REQUIRE(arrayList.pop_front() == -1);
        cout << "Element popped front" << endl;
        arrayList.printAll();

        for (int i = 0; i < 10; i++) {
            REQUIRE(arrayList[i]->getData() == i);
            if (i != 0) { REQUIRE(arrayList[i]->getPrev()->getData() == i - 1); }
            if (i != 9) { REQUIRE(arrayList[i]->getNext()->getData() == i + 1); }
        }

        //Pop_At
        REQUIRE(arrayList.pop_at(2) == 2);
        cout << "Element popped at 2" << endl;
        arrayList.printAll();
        int arr2[9] = {0, 1, 3, 4, 5, 6, 7, 8, 9};

        for (int i = 0; i < 9; i++) {
            REQUIRE(arrayList[i]->getData() == arr2[i]);
            if (i != 0) { REQUIRE(arrayList[i]->getPrev()->getData() == arr2[i-1]); }
            if (i != 8) { REQUIRE(arrayList[i]->getNext()->getData() == arr2[i+1]); }
        }

        //Push_At
        cout << "Element (2) pushed at 3" << endl;
        arrayList.push_at(2, 2);
        arrayList.printAll();

        for (int i = 0; i < 10; i++) {
            REQUIRE(arrayList[i]->getData() == i);
            if (i != 0) { REQUIRE(arrayList[i]->getPrev()->getData() == i - 1); }
            if (i != 9) { REQUIRE(arrayList[i]->getNext()->getData() == i + 1); }
        }
    }
}*/
TEST_CASE( "DSStack Class Functions", "[DSStack]") {
    ///Constructor Tests
    //Default Constructor
    DSStack<int> empty;
    REQUIRE(empty.checkEmpty() == true);
    REQUIRE(empty.getSize() == 0);
    REQUIRE(empty.getStack().getHead() == nullptr);

    ///Stack Modifier Tests
    //Push + Top Testing
    for (int i = 0; i < 10; i++) {
        cout << empty.getSize() << " ";
        cout << empty.checkEmpty() << endl;
        empty.push(i);
        REQUIRE(empty.top() == i);
        REQUIRE(empty.getSize() == i + 1);
    }

    cout << endl;

    //Pop Testing
    for (int i = 10; i > 0; i--) {
        cout << empty.getSize() << " ";
        cout << empty.checkEmpty() << " ";
        REQUIRE(empty.getSize() == i);
        REQUIRE(empty.top() == i - 1);
        empty.pop();
        cout << empty.getSize() << endl;
    }

    cout << empty.getSize() << endl;
    //CheckEmpty testing
    REQUIRE(empty.checkEmpty() == true);

    //Clear Testing
    for (int i = 0; i < 100; i++) {
        empty.push(i);
        REQUIRE(empty.top() == i);
    }

    empty.clear();
    REQUIRE(empty.checkEmpty() == true);
}
