#include <iostream>

using namespace std;

const int N = 10;

class list {
private:
	int Size;

	class Node {
	public:
		Node * next;
		char data[N];

		Node(char input[N], Node *next1 = NULL) {
			for (int i = 0; i < N; i++) {
				data[i] = input[i];
			}
			next = next1;
		}
	};

	Node *head;

public:
	list() {
		Size = 0;
		head = NULL;
	}

	~list() {
		while (Size) {
			Node *temp = head;
			head = head = head->next;
			delete temp;

			Size--;
		}
	}

	void push_back(char data[N]) {
		if (head == NULL) {
			head = new Node(data);
		}
		else {
			Node *current = head;
			while (current->next != NULL) {
				current = current->next;
			}
			current->next = new Node(data);
		}
		Size++;
	}

	void delet_elem(int index) {
		if (index == 0) {
			Node *temp = head;
			head = head->next;

			delete temp;
			Size--;
		}
		else {
			Node *previous = head;
			for (int i = 0; i < index - 1; i++) {
				previous = previous->next;
			}

			Node *toDelete = previous->next;
			previous->next = toDelete->next;

			delete toDelete;

			Size--;
		}
	}

	void show() {
		Node *current = head;

		while (current != NULL) {
			for (int i = 0; i < N; i++) {
				cout << current->data[i];
			}
			cout << endl;
			current = current->next;
		}
	}

	void search(char input[N]) {
		Node *current = head;
		int index = 0;
		
		bool flag = true;
		while (current != NULL) {
			for (int i = 0; i < N; i++) {
				if (current->data[i] != input[i]) {
					flag = false;
					break;
				}
			}
			if (flag) {
				delet_elem(index);
				break;
			}
			index++;
			flag = true;
			current = current->next;
		}
	}
};

int main() {
	setlocale(LC_ALL, "Russian");

	list lst;
	int flag = 0;
	char temp[N];
	
	while (flag != 4) {
		cout << "1 - Добавить строку" << endl;
		cout << "2 - Удалить строку" << endl;
		cout << "3 - Вывести список" << endl;
		cout << "4 - Выйти" << endl;
		cin >> flag;
		if (flag == 1) {
			cout << "Введите строку: ";
			for (int j = 0; j < N; j++) {
				cin >> temp[j];
			}
			lst.push_back(temp);
		}
		if (flag == 2) {
			cout << "Введите строку, которую нужно удалить: ";
			for (int j = 0; j < N; j++) {
				cin >> temp[j];
			}

			lst.search(temp);
		}
		if (flag == 3) {
			lst.show();
		}
		system("pause");
		system("cls");
	}

	return 0;
}