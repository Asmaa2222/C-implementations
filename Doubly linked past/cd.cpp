#include <iostream>
#include "LL.h"
#include <vector>
using namespace std;
int main()
{

    cout << "Enter numberof elements: ";
    int n;
    cin >> n;
    vector<int> v;
    for (int i = 0; i < n; ++i)
    {
        cout << "Enter the element " << i + 1 << " in the list: ";
        int x; cin>>x; v.push_back(x); 
    }   


      for (int i = 0; i < n-1; i++)    //bubble sort 
         for (int j = 0; j < n-i-1; j++){
        if (v[j] > v[j+1])
            swap(v[j], v[j+1]);
}
  LinkedList l;

        for(int i=0; i<n ; ++i)
        {
            if(v[i+1]>v[i])
            l.addLast(v[i]); 
            else 
            l.addFirst(v[i]); 
        }
        cout<<"Heloooooooooooooooooooooooo\n"; 

//  LinkedList l;

//         for(int i=0; i<n ; ++i)
//         {
//            l.insert(v[i]); 
//         }
l.printList(); 
cout<<"The first element in the list is: "<<l.first()<<endl; 
cout<<"The last element in the list is: "<<l.last()<<endl; 
l.Reverse(); 
cout<<"The first element in the list is: "<<l.first()<<endl; 
cout<<"The last element in the list is: "<<l.last()<<endl; 
l.printList(); 
cout<<"The first element in the list is: "<<l.first()<<endl; 
cout<<"The last element in the list is: "<<l.last()<<endl; 
l.remove(9); 

//l.remove(5); 
cout<<"The first element in the list is: "<<l.first()<<endl; 
cout<<"The last element in the list is: "<<l.last()<<endl; 
//l.reverse(); 
//l.printList(); 




 

    return 0;
}