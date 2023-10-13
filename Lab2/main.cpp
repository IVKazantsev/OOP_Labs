#include <iostream>
#include <vector>

#include "include/Array3d.h"
#include "src/templates.cpp"

using namespace Data;

int main() {
    // Примеры массивов
    Array3d<int> arrayOfInt(3, 3, 3);
    Array3d<std::string> arrayOfString(3, 3, 3);
    // Заполним массивы какими-либо значениями
    arrayOfInt.ones();
    arrayOfString.fill("Vacuum");

    // Выведем их
    arrayOfInt.arrayPrint();
    arrayOfString.arrayPrint();

    // Использование перегрузки оператора ()
    std::cout << arrayOfInt(1, 1, 1) << std::endl << std::endl;

    // Метод изменения двумерного массива в нашем основном
    std::vector<std::vector<int>> inputData = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    arrayOfInt.SetValues2d(0, 1, inputData);

    // Метод извлечения двумерного массива-среза из нашего основного
    std::vector<int> extractData = arrayOfInt.GetValues2d(2, 1);
    for (int i = 1; i <= extractData.size(); i++) {
        std::cout << extractData[i - 1] << " ";
        if(i % 3 == 0) std::cout << std::endl;
    }

    std::cout << std::endl;

    // Метод изменения одномерного массива в нашем основном

    std::vector<std::string> inputStrings = {"First", "Second", "Third"};
    arrayOfString.SetValues1d(0, 2, 1, 1, inputStrings);

    // Метод извлечения одномерного массива-среза из нашего основного

    std::vector<std::string> extractStrings = arrayOfString.GetValues1d(0, 2, 1, 1);
    for (int i = 0; i < extractStrings.size(); i++) std::cout << extractStrings[i] << " ";
    return 0;
}
