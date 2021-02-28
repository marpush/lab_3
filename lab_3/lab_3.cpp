#include <iostream>
#include <ctime>
#include <cmath>

using namespace std;
#define COUNT_COLS 2
#define COUNT_ROWS 2

void scan_array(int array[][COUNT_COLS]);
int scan_number_in_range(const double left_border, const double right_border);
int scan_integer_number(const double border);
void print_array(int array[][COUNT_COLS]);
void find_eigenvalues(int array[][COUNT_COLS]);


int main()
{
    setlocale(LC_ALL,"Russian");
    int array[COUNT_ROWS][COUNT_COLS];
    scan_array(array);
    print_array(array);
    find_eigenvalues(array);
}

void find_eigenvalues(int array[][COUNT_COLS])
{
    int eigenvalues_1 = 0, eigenvalues_2 = 0;
    int discriminant = pow((array[0][0] + array[1][1]),2) - 4 * ((array[0][0] * array[1][1]) - (array[0][1] * array[1][0]));
    if (discriminant = 0) {
        eigenvalues_1 = -(array[0][0] + array[1][1]) / 2;
        cout << "Матрица имеет одно собственное число равное" << eigenvalues_1;
    }else {
        if (discriminant > 0) {
            cout << "Матрица не имеет собственных чисел";
        }
        else {
            eigenvalues_1 = (-(array[0][0] + array[1][1]) / 2) + sqrt(pow(array[0][0] + array[1][1], 2) - (array[0][0] * array[1][1]) - (array[0][1] * array[1][0]));
            eigenvalues_2 = (-(array[0][0] + array[1][1]) / 2) - sqrt(pow(array[0][0] + array[1][1], 2) - (array[0][0] * array[1][1]) - (array[0][1] * array[1][0]));
            cout << "Матрица имеет два собственных числа равных " << eigenvalues_1 << " и " << eigenvalues_2;
        }
    }
}

void scan_array(int array[][COUNT_COLS])
{
    cout << "Если вы хотите заполнить массив самостоятельно, введите 1.\n" <<
        "Если вы хотите заполнить масств рандомными числами, введите 0.\n";
    int answer = 0;
    cout << "Ответ: ";
    answer = scan_number_in_range(0, 1);

    if (answer == 1) {
        for (int i = 0; i < COUNT_ROWS; ++i) {
            for (int j = 0; j < COUNT_COLS; ++j) {
                cout << "a[" << i << "][" << j << "]=";
                array[i][j] = scan_integer_number(array[i][j]);
            }
        }
    }
    else {
        for (int i = 0; i < COUNT_ROWS; ++i) {
            for (int j = 0; j < COUNT_COLS; ++j) {
                array[i][j] = rand();
            }
        }
    }
}

int scan_number_in_range(const double left_border, const double right_border)
{
    while (true) {
        int number = 0;
        cin >> number;

        if (cin.fail()) {
            cout << "Введено не число.\n";
            cin.clear();
            std::cin.ignore(32767, '\n');
        }
        else {
            if ((number >= left_border) && (number <= right_border)) {
                return number;
            }
            else {
                if (number < left_border) {
                    cout << "Введенное число меньше " << left_border << "\n";
                    cin.clear();
                }

                if (number > right_border) {
                    cout << "Введенное число больше " << right_border << "\n";
                    cin.clear();
                }
            }
        }

    }
}

int scan_integer_number(const double border)
{
    while (true) {
        int number = 0;
        cin >> number;

        if (cin.fail()) {
            cout << "Введенный символ не целое число. Введите ещё раз: \n";
            cin.clear();
            std::cin.ignore(32767, '\n');
        }
        else {
              return number;
        }
    }
}

void print_array(int array[][COUNT_COLS])
{
    for (int i = 0; i < COUNT_ROWS; i++) {
        for (int j = 0; j < COUNT_COLS; j++) {
            cout << array[i][j] << " ";
        }
        cout << "\n";
    }
}