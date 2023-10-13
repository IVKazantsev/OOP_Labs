//
// Created by Honor on 05.10.2023.
//

#include "../src/Array3d.cpp"
#include "../include/Array3d.h"

using namespace Data;
//template<>
//void Array3d<int>::SetValues2d(int dim, int i, std::vector<std::vector<int>> data) {
//    if(dim < 0 || dim > 2 || i < 0) throw std::out_of_range("Index was out of range");
//    int size1{0}, size2{0};
//    switch (dim) {
//        case 0:
//            size1 = mDim1;
//            size2 = mDim2;
//            if (data.size() != mDim1 * mDim2) throw "Вы ввели неверный массив";
//            break;
//        case 1:
//            size1 = mDim0;
//            size2 = mDim2;
//            if(data.size() != mDim0 * mDim2) throw "Вы ввели неверный массив";
//            break;
//        case 2:
//            size1 = mDim0;
//            size2 = mDim1;
//            if(data.size() != mDim0 * mDim1) throw "Вы ввели неверный массив";
//            break;
//        default:
//            break;
//    }
//    switch (dim) {
//        case 0:
//            for (int j = 0; j < size1; j++)
//                for (int k = 0; k < size2; k++)
//                    mData[i + j * mDim0 + k * mDim0 * mDim1] = data[j][k];
//            break;
//        case 1:
//            for (int j = 0; j < size1; j++)
//                for (int k = 0; k < size2; k++)
//                    mData[j + i * mDim0 + k * mDim0 * mDim1] = data[j][k];
//            break;
//        case 2:
//            for (int j = 0; j < size1; j++)
//                for (int k = 0; k < size2; k++)
//                    mData[j + k * mDim0 + i * mDim0 * mDim1] = data[j][k];
//            break;
//        default:
//            break;
//    }
//}