//
// Created by Honor on 05.10.2023.
//

#ifndef LAB2_ARRAY3D_H
#define LAB2_ARRAY3D_H

#include <iostream>
#include <vector>

namespace Data {
    template<typename T> class Array3d {
    private:
        int mDim0;
        int mDim1;
        int mDim2;
        std::vector<T> mData;

    public:
        Array3d(int dim0, int dim1, int dim2);
        T& operator()(int i, int j, int k);

        std::vector<T> GetValues2d(int dim, int i) const;
        std::vector<T> GetValues1d(int dim1, int dim2, int i, int j) const;
        void SetValues2d(int dim, int i, std::vector<std::vector<T>>& data);
        void SetValues1d(int dim1, int dim2, int i, int j, std::vector<T>& data);

        void ones();
        void zerosFill();
        void fill(T value);

        void arrayPrint();
    };
};


#endif //LAB2_ARRAY3D_H
