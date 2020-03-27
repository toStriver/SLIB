#include <iostream>
#include "Object.h"
#include "SmartPointer.hpp"
#include "Exception.h"
#include "List.hpp"
#include "SeqList.hpp"
#include "StaticList.hpp"
#include "DynamicList.hpp"
#include "StaticArray.hpp"
#include "DynamicArray.hpp"
#include "LinkList.hpp"

using namespace std;
using namespace SLIB;


int main()
{
   LinkList<int> sa;

   for(int i = 0; i < 5; i++)
   {
       sa.insert(i, 10+i);
   }

   for(int i = 0; i < sa.length(); i++)
   {
       cout << sa.get(i) << "  ";
   }

   cout << endl;

   sa.insert(3, 100);

   for(int i = 0; i < sa.length(); i++)
   {
       cout << sa.get(i) << "  ";
   }
   cout << endl;

   sa.remove(3);
   sa.clear();
   for(int i = 0; i < 5; i++)
   {
       sa.insert(0, 100+i);
   }

   for(int i = 0; i < sa.length(); i++)
   {
       cout << sa.get(i) << "  ";
   }
    cout << endl;

    return 0;
}
