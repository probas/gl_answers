#include <iostream>
#include <vector>
#include <assert.h>

std::vector<int>::iterator insert(std::vector<int>& v, size_t pos, const int& val) {
    size_t size= v.size();
    size_t offset = size - pos;
    std::vector<int>::iterator it = v.end();
    std::vector<int>::iterator it1 = it - 1;
    
    if ( offset == 0 ) {
        v.push_back(val);
        return it;
    }

    v.push_back(*it1);
    for (int i = offset; i > 1; i--) {
        it1 -= 1;
        it -= 1;
        *it = *it1;
    }
    *it1 = val;
    
    return it1;
}

int main() {
    std::vector<int> v;
    std::vector<int>::iterator it;
    int elem = 777;
    size_t position = 0;

    for (int i = 1; i < 10; i++) {
        v.push_back(i);
    }
    
    it = insert(v, position, elem);
    std::cout << "\nInserted element: " <<*it;
    std::cout << " at position: " << position << " \n";
    it = v.begin();
    std::cout << "Vector: " << "[ " << *it;
    for (it=v.begin() + 1; it!= v.end(); it++) {
        std::cout << " " << *it;
    }
    std::cout << " ]" << std::endl;

    return 0;
}
