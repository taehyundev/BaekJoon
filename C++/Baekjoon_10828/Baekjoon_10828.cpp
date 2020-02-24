#include <iostream>
using namespace std;
class Stack {
private:
	//Required Variable (Size, Top) << This Integer
	int Size;
	int Top = -1;
	int data[10000];

public:
	int pop();
	void push(int val);
	bool empty();
	int sizeF();
	int topF();

	Stack();
	//~Stack();
};

//Constructor
Stack::Stack() :Top(-1), Size(0) {}

//push Function (push x).
void Stack::push(int val) {
	Size++;
	Top++;
	data[Top] = val;
}

//pop Function
int Stack::pop() {
	if (Top >= 0)	{Size--; }
	return Top < 0 ? -1: data[Top--];
}
//Top Display
int Stack::topF() {
	return Top < 0 ? -1:data[Top];
}
//Empty True : 1 | False:0
bool Stack::empty() {
	return Size > 0 ? true : false;
}
//Size Integer's number
int Stack::sizeF() {
	return Size;
}
int main() {
	//1 ~ 10000 action(n)
	Stack s;
	
	int n; //최대 입력받는 요솟수
	cin >> n;
	int val;

	int i = 0;
	do {
		string txt;
		cin >> txt;
		if (txt == "push") {
			cin >> val;
			s.push(val);
		}
		else if (txt =="pop") {
			 val =s.pop();
			cout << val << endl;
		}
		else if (txt == "top") {
			val = s.topF();
			cout << val << endl;
		}
		else if (txt == "size") {
			val = s.sizeF();
			cout << val << endl;
		}
		else if (txt == "empty") {
			if (s.empty() == true) {
				cout << 0 << endl;
			}
			else {
				cout << 1 << endl;
			}
		}
		i++;
	} while(i<n);
	
}