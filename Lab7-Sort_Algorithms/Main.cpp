#include "iostream"
#include "chrono"
#include "vector"

using namespace std;


void ShowPriceDetail(int* mas, int* n);
//int CheckIntValue(int* i);

/**
 * @brief Перевіряє коректне значення типу int, яке ввів користувач до системи
 * @param i Значення типу int введене з клавіатури
 * @return Повертає коректне значення для подальшої роботи системи
*/
int CheckIntValue(int* i) {

	cin.ignore(666, '\n');
	while (true) {
		if (cin.fail()) {
			cin.clear();
			cin.ignore(666, '\n');
			cout << "You enter wrong data! Please enter correct data: \n";
			cin >> *i;
			cin.ignore(666, '\n');
		}
		else {
			return *i;
		}
	}
}

/**
 * @brief Перевіряє мінімальну кількість замовлень
 * @param n Кількість замовлень введена користувачем з клавіатури
 * @return Повертає коректне значення кількості елементів замовлень
*/
int CheckMinMembersOfOrder(int* n) {

	if (*n <= 0) {
		cout << "You enter wrong data! Please enter correct data (min members - 1): \n";
		cin >> *n;
		*n = CheckIntValue(n);
	}
	return *n;
}

/**
 * @brief Шукає рандомне число
 * @param n Діапазон чисел від 0 до n-1
 * @return Повертає рандомне число
*/
int GetRandomNumber(int n) {
	int random;

	random = rand() % n;

	return random;
}

void BubbleSort(int* mas, int* n) {
	int buf;
	
	cout << "Bubble Sorting is in progress..." << endl;
	for (int i = 0; i < *n; i++) {
		for (int j = 0; j < *n - 1; j++) {
			if (mas[j] > mas[j + 1]) {
				buf = mas[j];
				mas[j] = mas[j + 1];
				mas[j + 1] = buf;
			}
		}
	}	
}

void BubbleSort(float* mas, int* n) {
	float buf;

	cout << "Bubble Sorting is in progress..." << endl;
	for (int i = 0; i < *n; i++) {
		for (int j = 0; j < *n - 1; j++) {
			if (mas[j] > mas[j + 1]) {
				buf = mas[j];
				mas[j] = mas[j + 1];
				mas[j + 1] = buf;
			}
		}
	}
}

void BubbleSort(char* mas, int* n) {
	char buf;

	cout << "Bubble Sorting is in progress..." << endl;
	for (int i = 0; i < *n; i++) {
		for (int j = 0; j < *n - 1; j++) {
			if ((int)mas[j] > (int)mas[j + 1]) {
				buf = mas[j];
				mas[j] = mas[j + 1];
				mas[j + 1] = buf;
			}
		}
	}
}

void ChoiceSort(int* mas, int* n) {
	int min = 10000000000;
	int index;
	bool find = false;

	cout << "Choice Sorting is in progress..." << endl;
	for (int i = 0; i < *n - 1; i++) {
		for (int j = i; j < *n; j++) {
			if (min > mas[j]) {
				min = mas[j];
				index = j;
				find = true;
			}
		}
		if (find) {
			mas[index] = mas[i];
			mas[i] = min;
			find = false;
			min = 10000000000;
		}		
	}
}

void CountingSort(int* mas, int* n) {
	int count = 0;
	int max_value = 110000;
	int* count_mas = new int[max_value + 1];

	cout << "Count Sorting is in progress..." << endl;
	for (int i = 0; i <= max_value; i++) {
		count_mas[i] = 0;
	}

	for (int i = 0; i < *n; i++) {
		count_mas[mas[i]] += 1;
	}
	for (int i = 0; i < *n; i++) {
		for (int j = count; j <= max_value; j++) {
			if (count_mas[j] > 0) {
				mas[i] = j;
				count_mas[j] -= 1;
				count = j;
				break;
			}
		}
	}

	delete[] count_mas;
}

void Merge(int* mas, int low_index, int middle_index, int high_index) {
	int left = low_index;
	int right = middle_index + 1;

	int* buf_mas = new int[high_index - low_index + 1];
	for (int i = 0; i < (high_index - low_index + 1); i++) {
		buf_mas[i] = 0;
	}

	int index = 0;

	while ((left <= middle_index) && (right <= high_index)) {
		if (mas[left] < mas[right]) {
			buf_mas[index] = mas[left];
			left++;
		}
		else {
			buf_mas[index] = mas[right];
			right++;
		}
		index++;
	}
	for (int i = left; i <= middle_index; i++) {
		buf_mas[index] = mas[i];
		index++;
	}
	for (int i = right; i <= high_index; i++) {
		buf_mas[index] = mas[i];
		index++;
	}
	
	for (int i = 0; i < (high_index - low_index + 1); i++) {
		mas[low_index + i] = buf_mas[i];
	}

	delete[] buf_mas;

}

void MergeSort(int* mas, int low_index, int high_index) {
	
	if (high_index - low_index < 1) {
		return;
	}
	int middle_index = (low_index + high_index) / 2;
	if (high_index - low_index > 1) {
		
		
		MergeSort(mas, low_index, middle_index);
		MergeSort(mas, middle_index + 1, high_index);
		
		
		
	}
	Merge(mas, low_index, middle_index, high_index);
}

void InsertSort(int* mas, int n) {
	int buf;

	cout << "Insert Sorting is in progress..." << endl;
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j <= i; j++) {
			if (mas[i + 1 - j] < mas[i - j]) {
				buf = mas[i + 1 - j];
				mas[i + 1 - j] = mas[i - j];
				mas[i - j] = buf;
			}
		}
	}
}

void ShellSort(int* mas, int* n) {
	int buf;

	cout << "Shell Sorting is in progress..." << endl;
	for (int step = *n / 2; step > 0; step /= 2) {
		for (int i = step; i < *n; i++) {
			int k = 0;
			for (int j = i; j >= step; j -= step) {
				if (mas[i - k] < mas[j - step]) {
					buf = mas[i - k];
					mas[i - k] = mas[j - step];
					mas[j - step] = buf;
					//cout << " ------Work----------" << step << endl;
					//ShowPriceDetail(mas, n);
					k++;
				}
			}
		}
	}	
}

void ShellSort(float* mas, int* n) {
	float buf;

	cout << "Shell Sorting is in progress..." << endl;
	for (int step = *n / 2; step > 0; step /= 2) {
		for (int i = step; i < *n; i++) {
			int k = 0;
			for (int j = i; j >= step; j -= step) {
				if (mas[i - k] < mas[j - step]) {
					buf = mas[i - k];
					mas[i - k] = mas[j - step];
					mas[j - step] = buf;
					//cout << " ------Work----------" << step << endl;
					//ShowPriceDetail(mas, n);
					k++;
				}
			}
		}
	}
}

void ShellSort(char* mas, int* n) {
	char buf;

	cout << "Shell Sorting is in progress..." << endl;
	for (int step = *n / 2; step > 0; step /= 2) {
		for (int i = step; i < *n; i++) {
			int k = 0;
			for (int j = i; j >= step; j -= step) {
				if ((int)mas[i - k] < (int)mas[j - step]) {
					buf = mas[i - k];
					mas[i - k] = mas[j - step];
					mas[j - step] = buf;
					//cout << " ------Work----------" << step << endl;
					//ShowPriceDetail(mas, n);
					k++;
				}
			}
		}
	}
}


void ShowPriceDetail(int* mas, int* n) {

	for (int i = 0; i < *n; i++) {
		cout << *(mas + i) << "$| ";
	} cout << endl;
}

void ShowPriceDetail(float* mas, int* n) {
	for (int i = 0; i < *n; i++) {
		cout << *(mas + i) << "$| ";
	} cout << endl;
}

void ShowPriceDetail(char* mas, int* n) {
	for (int i = 0; i < *n; i++) {
		cout << *(mas + i) << " | ";
	} cout << endl;
}

void FindMiddlePriceOfCars(int* car_price, int* n) {
	float middle_price = 0;
	int* insert_mas = new int[*n];
	int* choice_mas = new int[*n];
	int* counting_mas = new int[*n];
	int* merge_mas = new int[*n];
	int* shell_mas = new int[*n];

	for (int i = 0; i < *n; i++) {
		car_price[i] = 10000 + GetRandomNumber(100000);
		/*Test double
		car_price[i] = GetRandomNumber(10);
		if (i == 2 || i == 3){
			car_price[i] = 10;
		}//*/
		middle_price += car_price[i];
	} cout << endl;
	//ShowPriceDetail(car_price, n);

	copy(car_price, car_price + *n, insert_mas);
	copy(car_price, car_price + *n, choice_mas);
	copy(car_price, car_price + *n, counting_mas);
	copy(car_price, car_price + *n, merge_mas);
	copy(car_price, car_price + *n, shell_mas);
	

	auto start_bubble = chrono::high_resolution_clock::now();
	BubbleSort(car_price, n);
	auto stop_bubble = chrono::high_resolution_clock::now();
	auto dur_bubble = chrono::duration_cast<chrono::milliseconds>(stop_bubble - start_bubble);

	auto start_insert = chrono::high_resolution_clock::now();
	InsertSort(insert_mas, *n);
	auto stop_insert = chrono::high_resolution_clock::now();
	auto dur_insert = chrono::duration_cast<chrono::milliseconds>(stop_insert - start_insert);

	auto start_choice = chrono::high_resolution_clock::now();
	ChoiceSort(choice_mas, n);
	auto stop_choice = chrono::high_resolution_clock::now();
	auto dur_choice = chrono::duration_cast<chrono::milliseconds>(stop_choice - start_choice);

	auto start_counting = chrono::high_resolution_clock::now();
	CountingSort(counting_mas, n);
	auto stop_counting = chrono::high_resolution_clock::now();
	auto dur_counting = chrono::duration_cast<chrono::milliseconds>(stop_counting - start_counting);

	auto start_merge = chrono::high_resolution_clock::now();
	MergeSort(merge_mas, 0, *n - 1);
	auto stop_merge = chrono::high_resolution_clock::now();
	auto dur_merge = chrono::duration_cast<chrono::milliseconds>(stop_merge - start_merge);

	auto start_shell = chrono::high_resolution_clock::now();
	ShellSort(shell_mas, n);
	auto stop_shell = chrono::high_resolution_clock::now();
	auto dur_shell = chrono::duration_cast<chrono::milliseconds>(stop_shell - start_shell);

	cout << "-------------Sort MAS---------------" << endl;
	//ShowPriceDetail(car_price, n);
	//ShowPriceDetail(insert_mas, n);
	//ShowPriceDetail(test_mas, n);
	//ShowPriceDetail(choice_mas, n);
	//ShowPriceDetail(counting_mas, n);
	//ShowPriceDetail(merge_mas, n);
	//ShowPriceDetail(shell_mas, n);
	cout << "\nAmount: " << middle_price << endl;
	cout << "\nMiddle Price of Cars: " << middle_price / *n << "$\n";
	cout << "Middle Price of Cars by bubble sort: " << car_price[*n / 2 - 1] << "$ sort speed: " << (float)dur_bubble.count() / 1000 << " seconds " << endl;
	cout << "Middle Price of Cars by insert sort: " << insert_mas[*n / 2 - 1] << "$ sort speed: " << (float)dur_insert.count() / 1000 << " seconds " << endl;
	cout << "Middle Price of Cars by choice sort: " << choice_mas[*n / 2 - 1] << "$ sort speed: " << (float)dur_choice.count() / 1000 << " seconds " << endl;
	cout << "Middle Price of Cars by counting sort: " << counting_mas[*n / 2 - 1] << "$ sort speed: " << (float)dur_counting.count() / 1000 << " seconds " << endl;
	cout << "Middle Price of Cars by merge sort: " << merge_mas[*n / 2 - 1] << "$ sort speed: " << (float)dur_merge.count() / 1000 << " seconds " << endl;
	cout << "Middle Price of Cars by shell sort: " << shell_mas[*n / 2 - 1] << "$ sort speed: " << (float)dur_shell.count() / 1000 << " seconds " << endl;
	cout << "The dif btw the average cost cars and the cost of the cars by sorting: " << abs((middle_price / *n) - car_price[*n / 2 - 1]) << "$\n";
	
	delete[] insert_mas;
	delete[] choice_mas;
	delete[] counting_mas;
	delete[] merge_mas;
	delete[] shell_mas;
}

void SortingDataMassive(int* n) {
	float* float_data = new float[*n];
	float* float_data_copy = new float[*n];
	char* char_data = new char[*n];	
	char* char_data_copy = new char[*n];

	for (int i = 0; i < *n; i++) {
		float_data[i] = (float)GetRandomNumber(101) + (float)GetRandomNumber(100) / 10.0 + (float)GetRandomNumber(100) / 100.0;
		do {
			char_data[i] = (char)(GetRandomNumber(94) + 33);
		} while ((int)char_data[i] == 124);		
	}
	//ShowPriceDetail(float_data, n);
	//ShowPriceDetail(char_data, n);

	copy(float_data, float_data + *n, float_data_copy);
	copy(char_data, char_data + *n, char_data_copy);

	auto start_fbubble = chrono::high_resolution_clock::now();
	BubbleSort(float_data, n);
	auto end_fbubble = chrono::high_resolution_clock::now();
	auto dir_fbubble = chrono::duration_cast<chrono::milliseconds>(end_fbubble - start_fbubble);

	auto start_fshell = chrono::high_resolution_clock::now();
	ShellSort(float_data_copy, n);
	auto end_fshell = chrono::high_resolution_clock::now();
	auto dir_fshell = chrono::duration_cast<chrono::milliseconds>(end_fshell - start_fshell);

	auto start_cbubble = chrono::high_resolution_clock::now();
	BubbleSort(char_data, n);
	auto end_cbubble = chrono::high_resolution_clock::now();
	auto dir_cbubble = chrono::duration_cast<chrono::milliseconds>(end_cbubble - start_cbubble);

	auto start_cshell = chrono::high_resolution_clock::now();
	ShellSort(char_data_copy, n);
	auto end_cshell = chrono::high_resolution_clock::now();
	auto dir_cshell = chrono::duration_cast<chrono::milliseconds>(end_cshell - start_cshell);

	cout << "-------------Sort MAS---------------" << endl;
	/*/ShowPriceDetail(float_data, n);
	ShowPriceDetail(float_data_copy, n);
	ShowPriceDetail(char_data, n);
	ShowPriceDetail(char_data_copy, n);*/
	cout << "Sorting: " << *n << " float data by bubble sort takes -> " << (float)dir_fbubble.count() / 1000 << " seconds" << endl;
	cout << "Sorting: " << *n << " float data by shell sort takes -> " << (float)dir_fshell.count() / 1000 << " seconds" << endl;
	cout << "Sorting: " << *n << " char data by bubble sort takes -> " << (float)dir_cbubble.count() / 1000 << " seconds" << endl;
	cout << "Sorting: " << *n << " char data by shell sort takes -> " << (float)dir_cshell.count() / 1000 << " seconds" << endl;

	delete[] float_data;
	delete[] float_data_copy;
	delete[] char_data;
	delete[] char_data_copy;
}

/**
 * @brief Інтерфейс який дає змогу користувачу працювати з додатком
 * @param q Вибір виконуваного завдання, яке задається користувачем з клавіатури
*/
void MenuOfSolution(int* q) {
	int n;
	int* car_price;

	srand(time(0));
	switch (*q) {
	case 1:
		cout << "\n__Task A__\n";
		cout << "Enter n amount of Cars: ";
		cin >> n;
		n = CheckIntValue(&n);
		n = CheckMinMembersOfOrder(&n);
		car_price = new int[n];
		FindMiddlePriceOfCars(car_price, &n);
		delete[] car_price;
		break;
	case 2:
		cout << "\n__Task C__\n";
		cout << "Enter n amount of data: ";
		cin >> n;
		n = CheckIntValue(&n);
		n = CheckMinMembersOfOrder(&n);
		SortingDataMassive(&n);
		break;
	default:
		cout << "\n__You don't enter any task for execution__\n";
		break;
	}
	if (*q == 1 || *q == 2) {
		MenuOfSolution(q);
	}
}

int main() {
	int q;

	cout << "\nCreated by Vladislav Samoilov / KNT - 223\n";
	cout << "--------Select task:--------\n";
	cout << "Task A) Find Middle Price Of Cars - Enter 1\n";
	cout << "Task C) Sorting massive data - Enter 2\n";
	cout << "------------------------------------------------------------\n";
	cin >> q;
	q = CheckIntValue(&q);
	MenuOfSolution(&q);

	return main();
}