
#include <iostream>

using namespace std;

void hanoi(int start, int end, int count) {
    if(count == 1 ) {
        cout<<"Ring number 1 from "<<start<<" to "<<end<<endl;
        return;
    }
    hanoi(start, 6-start-end, count-1);
    cout << "Ring number "<<count<<" from "<<start<<" to "<<end<<endl;
    hanoi(6-start-end, end , count-1);
}

int main(int argc, char const *argv[])
{
	hanoi(1, 3, 3);
	return 0;
}