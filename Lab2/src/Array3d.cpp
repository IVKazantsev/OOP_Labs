
 //Created by Honor on 05.10.2023.


#include "../include/Array3d.h"
#include <iostream>

using namespace Data;

template <typename T>
Array3d<T>::Array3d(int dim0, int dim1, int dim2)
 : mDim0{dim0}, mDim1{dim1}, mDim2{dim2} {
    mData.resize(mDim0 * mDim1 * mDim2);
}

 template <typename T>
 T& Array3d<T>::operator()(int i, int j, int k) {
     return mData[i + j * mDim0 + k * mDim0 * mDim1];
 }

template <typename T>
std::vector<T> Array3d<T>::GetValues2d(int dim, int i) const {
    if(dim < 0 || dim > 2 || i < 0) throw std::out_of_range("Index was out of range");
    std::vector<T> result;
    switch (dim) {
        case 0:
            for (int j = 0; j < mDim1; j++)
                for (int k = 0; k < mDim2; k++)
                    result.push_back(mData[i + j * mDim0 + k * mDim0 * mDim1]);
            break;
        case 1:
            for (int j = 0; j < mDim0; j++)
                for (int k = 0; k < mDim2; k++)
                    result.push_back(mData[j + i * mDim0 + k * mDim0 * mDim1]);
            break;
        case 2:
            for (int j = 0; j < mDim0; j++)
                for (int k = 0; k < mDim1; k++)
                    result.push_back(mData[j + k * mDim0 + i * mDim0 * mDim1]);
            break;
        default:
            break;
    }
    return result;
}

template <typename T>
void Array3d<T>::SetValues2d(int dim, int i, std::vector<std::vector<T>>& data) {
    if(dim < 0 || dim > 2 || i < 0) throw std::out_of_range("Index was out of range");
    switch (dim) {
        case 0:
            for (int j = 0; j < mDim1; j++)
                for (int k = 0; k < mDim2; k++)
                    mData[i + j * mDim0 + k * mDim0 * mDim1] = data[j][k];
            break;
        case 1:
            for (int j = 0; j < mDim0; j++)
                for (int k = 0; k < mDim2; k++)
                    mData[j + i * mDim0 + k * mDim0 * mDim1] = data[j][k];
            break;
        case 2:
            for (int j = 0; j < mDim0; j++)
                for (int k = 0; k < mDim1; k++)
                    mData[j + k * mDim0 + i * mDim0 * mDim1] = data[j][k];
            break;
        default:
            break;
    }
}

template<typename T>
std::vector<T> Array3d<T>::GetValues1d(int dim1, int dim2, int i, int j) const {
    if(dim1 < 0 || dim1 > 2 || i < 0 || dim2 < 0 || dim2 > 2 || j < 0)
        throw std::out_of_range("Index was out of range");

    std::vector<T> result;
    if((dim1 == 0 && dim2 == 1) || (dim1 == 1 && dim2 == 0))
        for (int k = 0; k < mDim2; k++)
            result.push_back(mData[i + j * mDim0 + k * mDim0 * mDim1]);
    else if((dim1 == 0 && dim2 == 2) || (dim1 == 2 && dim2 == 0))
        for (int k = 0; k < mDim1; k++)
            result.push_back(mData[i + j * mDim0 + k * mDim0 * mDim1]);
    else if((dim1 == 1 && dim2 == 2) || (dim1 == 2 && dim2 == 1))
        for (int k = 0; k < mDim0; k++)
            result.push_back(mData[i + j * mDim0 + k * mDim0 * mDim1]);
    return result;
}

template<typename T>
void Array3d<T>::SetValues1d(int dim1, int dim2, int i, int j, std::vector<T>& data) {
    if(dim1 < 0 || dim1 > 2 || i < 0 || dim2 < 0 || dim2 > 2 || j < 0)
        throw std::out_of_range("Index was out of range");

    std::vector<int> result;
    if((dim1 == 0 && dim2 == 1) || (dim1 == 1 && dim2 == 0))
        for (int k = 0; k < mDim2; k++)
            mData[i + j * mDim0 + k * mDim0 * mDim1] = data[k];
    else if((dim1 == 0 && dim2 == 2) || (dim1 == 2 && dim2 == 0))
        for (int k = 0; k < mDim1; k++)
            mData[i + j * mDim0 + k * mDim0 * mDim1] = data[k];
    else if((dim1 == 1 && dim2 == 2) || (dim1 == 2 && dim2 == 1))
        for (int k = 0; k < mDim0; k++)
            mData[i + j * mDim0 + k * mDim0 * mDim1] = data[k];
}

template<typename T>
void Array3d<T>::zerosFill() {
    for(int i = 0; i < mDim0 * mDim1 * mDim2; i++)
        mData[i] = 0;
}

template<typename T>
void Array3d<T>::ones() {
    for(int i = 0; i < mDim0 * mDim1 * mDim2; i++)
        mData[i] = 1;
}

 template<typename T>
 void Array3d<T>::fill(T value) {
     for(int i = 0; i < mDim0 * mDim1 * mDim2; i++)
         mData[i] = value;
 }

 template<typename T>
 void Array3d<T>::arrayPrint() {
     for (int i = 0; i < 3; i++) {
         for (int j = 0; j < 3; j++) {
             for (int k = 0; k < 3; k++)
                 std::cout << this->operator()(i, j, k) << " ";
             std::cout << std::endl;
         }
         std::cout << std::endl;
     }
 }