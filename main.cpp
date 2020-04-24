#include <iostream>
#include "llist.h"
#include "list.cpp"
using namespace std;
   
void dump(const LList& l){
	for(size_t i = 0; i < l.size(); ++i, cout << " ") cout << l[i];
}   

int main(){
	//with move

	//LList l;
	//for(int i = 0;i < 3000;i++)
	//	l.push_back(i);
	//LList a(move(l));

	//with copy

        //LList m;
        //for(int i = 0;i < 3000;i++)
        //	m.push_back(i);
        //LList b(m);

	return 0;
}
