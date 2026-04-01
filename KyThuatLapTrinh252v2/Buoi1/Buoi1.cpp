// Buoi1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
using namespace std;

void main()
{
    int a = 5;
    int* p = &a;
    a = 8;
    *p = 10;
    cout << a << "\t" << *p;



}


void bai1()
{
    //Tao mang dong luu diem
    vector <float> diem;

    //Them diem cua 5 nguoi
    diem.push_back(6);
    diem.push_back(7.5);
    diem.push_back(4.2);
    diem.push_back(6.4);
    diem.push_back(5.9);

    //Xoa diem cua 1 nguoi cuoi cung
    diem.pop_back();

    //Duyet qua mang diem va in ra man hinh
    for (int i = 0; i < diem.size(); i++)
    {
        cout << diem[i] << endl;
    }
}















// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
