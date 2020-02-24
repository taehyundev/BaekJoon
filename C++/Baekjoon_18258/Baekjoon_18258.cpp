#include <iostream>
using namespace std;

class Queue {
private:
	//Main variables
	int data[10000000];
	int size;
	int back;
	int front;
public:
	void push(int n);
	int pop();
	int frontF();
	int backF();
	int sizeF();
	bool Empty();
	Queue();

};
Queue::Queue() :size(0), back(-1), front(-1) {}

//push Func /NOT values = -1
void Queue::push(int n) {
	if (front == -1) {
		front++;
	}
	back++;
	data[back] = n;
	size++;

}

//pop Func /NOT values = -1
int Queue::pop() {
	if (size == 0) {
		return -1;
	}
	return size-- > 0 ? data[front++] : -1;
}

//front Func
int Queue::frontF() {
	return size > 0 ? data[front] : -1;
}

//back Func
int Queue::backF() {
	return size > 0 ? data[back] : -1;
}

//size F
int Queue::sizeF() {
	return size < 0 ? size = 0 : size;
}

//Empty true = 1 false = 0
bool Queue::Empty() {
	return size < 1 ? true : false;
}

int main() {
	cin.tie(0);
	cin.sync_with_stdio(false);
	int n, val;
	Queue q;
	cin >> n;
	int i = 0;
	do {
		string txt;
		cin >> txt;
		if (txt == "push") {
			int x;
			cin >> x;
			q.push(x);
		}
		else if (txt == "pop") {
			val = q.pop();
			cout << val << "\n";
		}
		else if (txt == "front") {
			val = q.frontF();
			cout << val << "\n";
		}
		else if (txt == "back") {
			val = q.backF();
			cout << val << "\n";
		}
		else if (txt == "size") {
			val = q.sizeF();
			cout << val << "\n";
		}
		else if (txt == "empty") {
			if (q.Empty() == true) {
				cout << 1 << "\n";
			}
			else {
				cout << 0 << "\n";
			}
		}
		i++;
	} while (n > i);
}