#include "Matrix.h"
#include <exception>
using namespace std;


Matrix::Matrix(int nrLine, int nrCols) {
    this->nrLine = nrLine;
    this->nrColum = nrCols;
    this->columns = new TElem[nrCols+1]{0};
    this->lines = new TElem[nrLine*nrCols];
    this->values = new TElem[nrLine*nrCols]{NULL_TELEM};
    this->capacity = CAPACITY;
    this->sizeLine = 0;
}


Matrix::~Matrix() {
    delete[] lines;
    delete[] columns;
    delete[] values;
}

///Theta(1)
int Matrix::nrLines() const {
    return this->nrLine;
}

/// Theta(1)
int Matrix::nrColumns() const {
    return this->nrColum;
}

/// best: Theta(1)  worst: Theta(log n)  average: Theta(log n)  Total complexity: O(log n)
int Matrix::binary_search(int left, int right, int poz, const TElem* vect) const
{
    while(left <= right) {
        int m = (left + right) / 2;
        if (vect[m] == poz)
            return m;
        else if(vect[m] < poz)
            left = m + 1;
        else right = m - 1;
    }
    return -(left+1);
}

/// Theta(size)
void Matrix::bigger(){
    int new_capacity = RESIZE * this->capacity;
    int* new_lines = new int[new_capacity];
    TElem* new_values = new TElem[new_capacity]{NULL_TELEM};
    for (int i = 0; i < this->sizeLine; ++i) {
        new_lines[i] = this->lines[i];
        new_values[i] = this->values[i];
    }
    delete[] this->lines;
    delete[] this->values;
    this->lines = new_lines;
    this->values = new_values;
    this->capacity = new_capacity;
}

/// best: Theta(1)  worst: Theta(min(size, new_capacity))  average: Theta(min(size, new_capacity))  Total Complexity: O(min(size, capacity))
void Matrix::smaller() {
    if (this->capacity <= CAPACITY)
        return;

    int new_capacity = this->capacity / RESIZE;
    int* new_lines = new int[new_capacity];
    TElem* new_values = new TElem[new_capacity];
    for (int i = 0; i < this->sizeLine && i < new_capacity; ++i) {
        new_lines[i] = this->lines[i];
        new_values[i] = this->values[i];
    }
    delete[] this->lines;
    delete[] this->values;
    this->lines = new_lines;
    this->values = new_values;
    this->capacity = this->capacity / RESIZE;
    if (this->sizeLine > this->capacity)
        this->sizeLine = this->capacity;
}

/// best: Theta(1)  worst: Theta(log n)  average: Theta(log n)  Total complexity: O(log n)
/// n = right - left + 1 (number of non-null elements of the line i)
TElem Matrix::element(int i, int j) const {
    if (i < 0 || i >= this->nrLine || this->nrColum <= j || 0 > j)
        throw exception();

    int index;
    int start = this->columns[j];
    int end = this->columns[j+1] - 1;
    index = binary_search(start, end, i, this->lines);
    if(index >= 0)
        return this->values[index];
    return NULL_TELEM;
}

/// best: Theta(1)  worst: Theta(nr_lines + size)  average: Theta(nr_lines + size)  Total complexity: O(nr_lines + size)
void Matrix::add_element(int poz, int i, int j, TElem e)
{
    if(this->sizeLine == this->capacity)
        bigger();

    for (int k = this->nrColum; k > j ; k--)
        this->columns[k]++;
    for (int k = this->sizeLine; k > poz; k--) {
        this->lines[k] = this->lines[k-1];
        this->values[k] = this->values[k-1];
    }
    this->lines[poz] = i;
    this->values[poz] = e;
    this->sizeLine++;
}

/// best: Theta(1)  worst: Theta(nr_lines + size) - maybe shrink  average: Theta(nr_lines + size)  Total complexity: O(nr_lines + size)
void Matrix::remove(int poz, int j){
    if(this->sizeLine == this->capacity/RESIZE)
        smaller();

    for(int k = this->nrColum; k > j ; k--)
        this->columns[k]--;

    for(int k = poz; k < this->sizeLine-1; k++)
    {
        this->lines[k] = this->lines[k+1];
        this->values[k] = this->values[k+1];
    }
    this->sizeLine--;
}

/// best: Theta(1)  worst: Theta(log n)  average: Theta(log n)  Total complexity: O(log n)
/// n = right - left + 1 (number of non-null elements of the line i)
TElem Matrix::modify(int i, int j, TElem e) {
    if (i < 0 || i >= this->nrLine || this->nrColum <= j || 0 > j)
        throw exception();

    int start = this->columns[j];
    int end = this->columns[j+1] - 1;
    int index = binary_search(start, end, i, this->lines);

    if(index >= 0){
        TElem prev = this->values[index];
        if(e != NULL_TELEM)
            this->values[index] = e;
        else
            remove(index, j);
        return prev;
    }
    if(e != NULL_TELEM)
        add_element(-index-1, i, j, e);
    return NULL_TELEM;
}

void Matrix::setElemsOnLine(int line, TElem elem)
{
    if (line < 0 || line >= this->nrLine)
        throw exception();

    for (int i = 0; i < this->sizeLine; i++)
        if(this->lines[i] == line)
            this->values[i] = elem;
}

