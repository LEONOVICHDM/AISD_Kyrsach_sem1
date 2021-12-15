#include <iostream>
#include<cmath>
using namespace std;

template <class T>
class Stack
{
private:
	class elem
	{
	public:
		elem(T data, elem* next = NULL) :data(data), next(next) {}
		~elem() = default;
		void setNext(elem* newnext) { next = newnext; }
		elem* getNext() { return next; }
		T getData() { return data; }
	private:
		T data;
		elem* next;
	};

	elem* head;
public:
	Stack() {
		head = NULL;
	};

	~Stack() {
		while (!empty())
		{
			pop();
		}
	};

	void pop() {//delete
		if (empty())
		{
			throw out_of_range("No more elements");
		}
		else
		{
			elem* tmp = head;
			head = head->getNext();
			delete tmp;
		}
	};

	void push(T data) {//add
		elem* tmp = new elem(data);
		elem* cur = head;
		head = tmp;
		head->setNext(cur);

	};

	bool empty() {
		return head == nullptr;
	};

	T top() {//first element
		if (empty())
		{
			throw out_of_range("Empty");
		}
		else
		{
			return head->getData();
		}

	};
};

string reverse(string str) {
	char temp;

	for (int i = 0; i < str.length() / 2; i++) {
		temp = str[str.length() - i - 1];
		str[str.length() - i - 1] = str[i];
		str[i] = temp;
	}

	for (int i = 0; i < str.length(); i++) {
		if (str[i] == ')') {
			str[i] = '(';
			continue;
		}
		if (str[i] == '(') str[i] = ')';
	};

	return str;
}

bool whoareyou(char symbol) {
	if (symbol == ')' || symbol == '(' || symbol == '+' || symbol == '-' || symbol == '*' || symbol == '/' || symbol == '^') return true;
	return false;
}

string InfixToPrefix(string str, Stack<char> PolskaHardBass) {
		str = reverse(str);
		PolskaHardBass.push('(');
		str += ")";

		char operators[7] = {'(',')','+','-','*','/','^'};
		int operatorsPriority[7] = { 0,0,1,1,2,2,3 };
		int index1=0;
		int index2=0;
		int stacksize = 1;

		string prefix = "";

		for (int i = 0; i < str.length(); i++) {
			if (str[i] == '(') {
				PolskaHardBass.push('(');
				stacksize++;
			}
			else if (str[i] == ')') {
				while (PolskaHardBass.top() != '(') {
					prefix += PolskaHardBass.top() + ' ';
					PolskaHardBass.pop();
					stacksize--;
				}
				PolskaHardBass.pop();
				stacksize--;
			}
			else if (whoareyou(str[i])) {
				for (int j = 0; j < 7; j++) {
					if (PolskaHardBass.top() == operators[j]) index1 = operatorsPriority[j];
					if (str[i] == operators[j]) index2 = operatorsPriority[j];
				}
				while (index1 >= index2) {
					prefix += PolskaHardBass.top() + ' ';
					PolskaHardBass.pop();
					stacksize--;
					for (int j = 0; j < 7; j++) {
						if (PolskaHardBass.top() == operators[j]) index1 = operatorsPriority[j];
						if (str[i] == operators[j]) index2 = operatorsPriority[j];
					}
				}

				PolskaHardBass.push(str[i]);
				stacksize++;
			}
			else if (isdigit(str[i]) || str[i] == '.') {
				prefix += str[i];

				try {
					if (isdigit(str[i + 1]) || str[i + 1] == '.') continue;
					prefix += ' ';
				}
				catch (exception e) {}
			}
		}

		for (int i = 0; i < stacksize; i++) {
			prefix += PolskaHardBass.top() + ' ';
			PolskaHardBass.pop();
		
		}

		for (int i = 0; i < prefix.length(); i++) {
			if (prefix[i] == 'K') {
				prefix[i] = '+';
			}
			if (prefix[i] == 'M') {
				prefix[i] = '-';
			}
			if (prefix[i] == 'J') {
				prefix[i] = '*';
			}
			if (prefix[i] == 'O') {
				prefix[i] = '/';
			}
			if (prefix[i] == '~') {
				prefix[i] = '^';
			}
		}

		return reverse(prefix);
}



double calculator(string prefix, Stack<double> CalculatedPolskaHardBass) {
	string doubleStr = "";
	int i = prefix.length() - 1;
	int stacksize=0;
	double op1, op2;

	while (i >= 0) {
		if (isdigit(prefix[i])) {
			while (prefix[i] != ' ') {
				doubleStr += prefix[i];
				i--;
			}
			doubleStr = reverse(doubleStr);
			CalculatedPolskaHardBass.push(atof(doubleStr.c_str()));
			stacksize++;
			doubleStr = "";

		}
		else if (whoareyou(prefix[i])) {
			if (stacksize >= 2) {
				op1 = CalculatedPolskaHardBass.top();
				CalculatedPolskaHardBass.pop();
				op2 = CalculatedPolskaHardBass.top();
				CalculatedPolskaHardBass.pop();
				stacksize -= 2;
				if (prefix[i] == '-') CalculatedPolskaHardBass.push(op1 - op2);
				else if (prefix[i] == '+') CalculatedPolskaHardBass.push(op1 + op2);
				else if (prefix[i] == '*') CalculatedPolskaHardBass.push(op1 * op2);
				else if (prefix[i] == '/') CalculatedPolskaHardBass.push(op1 / op2);
				else if (prefix[i] == '^') CalculatedPolskaHardBass.push(pow(op1, op2));
				stacksize++;
			}

			i--;
		}

		while (i >= 0 && prefix[i] == ' ') i--;
	}

	return CalculatedPolskaHardBass.top();
}

double pow(double base, double power) {
	if (power == 0.0) return 1;

	double result = 1;
	for (int i = 0; i < abs((int)power); i++) {
		result *= base;
	}

	if (power < 0) result = 1 / result;

	return result;
}

int main() {
	
	Stack<char> PolskaHardBass;
	Stack<double> CalculatedPolskaHardBass;
	string formula = "(2 + 22) - 16 * 0.5";
	double resulte;

	formula = InfixToPrefix(formula, PolskaHardBass);
	cout <<"Polska hard prefex bass: "<< formula << "\n";

	resulte = calculator(formula, CalculatedPolskaHardBass);
	cout << "Polska hard prefex bass calculated resulte: " << resulte << "\n";
	return 0;
}


//input : (2 + 22) - 16 * 0.5
//output : -+ 2 22* 16 0.5 
//output :16

//input : 15^2/15^3
//output : /^ 15 2^ 15 3
//output : 0.0666667