#include <iostream>
using namespace std;

class Queues {
	int FRONT, REAR, max = 5;
	int queue_array[5];

public:
	Queues() {
		FRONT = -1;
		REAR = -1;
	}

	void insert() {
		int num;
		cout << "enter a number : ";
		cin >> num;
		cout << endl;

		//cek apakah antrian penuh
		if ((FRONT == 0 && REAR == max - 1) || (FRONT == REAR + 1)) {
			cout << "\nQueue overflow\n";
			return;
		}

		//cek apakah antrian kosong
		if (FRONT == -1) {
			FRONT = 0;
			REAR = 0;
		}
		else {
			//jika rear beradaa di posisi terakhir array, kembali ke awal array
			if (REAR == max - 1)
				REAR = 0;
			else
				REAR = REAR + 1;
		}
		queue_array[REAR] = num;
	}
	void remove() {
		//apaakah antrian kosong
		if (FRONT == -1) {
			cout << "Queue underflow\n";
			return;
		}
		cout << "\n the element deleted from the queue is: " << queue_array[FRONT] << "\n";

		//cek jika antrian hanya di miliki satu element
		if (FRONT == REAR) {
			FRONT = -1;
			REAR = -1;
		}
		else {
			//jika elemen yang di hapus berada di posisi terakhir arrat, kembali ke awal array
			if (FRONT == max - 1)
				FRONT = 0;
			else
				FRONT = FRONT + 1;
		}
	}
	void display() {
		int FRONT_position = FRONT;
		int REAR_position = REAR;

		//cek apakah antrian ksosong
		if (FRONT == -1) {
			cout << "Queue is empty\n";
			return;
		}
		cout << "\nelement in the queue are ...\n";

		//jika FRONT_pistion <= REAR_pisition, iterasi dari FRONT hingga REAR
		if (FRONT_position <= REAR_position) {
			while (FRONT_position <= REAR_position) {
				cout << queue_array[FRONT_position] << " ";
				FRONT_position++;
			}
			cout << endl;
		}
		else {
			//jika FRONT_position > REAR_position, ietrasi dari FRONT hinggga akhir array
			while (FRONT_position <= max - 1) {
				cout << queue_array[FRONT_position] << " ";
				FRONT_position++;
			}
			FRONT_position = 0;

			//iterasi dari awal hingga REAR
			while (FRONT_position <= REAR_position) {
				cout << queue_array[FRONT_position] << " ";
				FRONT_position++;
			}
			cout << endl;
		}
	}
};

int main() {
	Queues q;
	char ch;

	while (true) {
		try {
			cout << "menu" << endl;
			cout << "1. impelement insert operation" << endl;
			cout << "2. impelement delete operation" << endl;
			cout << "3. display values" << endl;
			cout << "4. exit" << endl;
			cout << "enter your choice (1-4)" << endl;
			cin >> ch;
			cout << endl;

			switch (ch) {
			case '1': {

				q.insert();
				break;
			}
			case '2': {
				q.remove();
				break;
			}
			case '3': {
				q.display();
				break;
			}
			case '4': {
				return 0;
			}
			default: {
				cout << "invalid option!!" << endl;
				break;
			}
			}
		}
		catch (exception& e) {
			cout << "check for the values entered." << endl;
		}
	}
	return 0;
}
