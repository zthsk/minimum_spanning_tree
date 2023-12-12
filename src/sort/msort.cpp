#include <sort.hpp>
#include <graph.hpp> 

//extern
std::string sortAlgName = "Merge Sort";

template<class T>
void sort(std::vector<T> &array, int l, int r) {
    if (l >= r)
        return;
    int m = (l + r) >> 1;
    sort(array, l, m);
    sort(array, m + 1, r);
    std::vector<T> tmp;
    tmp.clear();
    int i = l;
    int j = m + 1;
    while (i <= m || j<= r) {
        if (i <= m && (j > r || array[i] < array[j])) {
            tmp.push_back(array[i]);
            ++i;
        }
        else {
            tmp.push_back(array[j]);
            ++j;
        }
    }
    for (int i = 0; i < tmp.size(); ++i)
        array[l+i] = tmp[i];
}

template void sort(std::vector<Edge> &array,  int l, int r);
template void sort(std::vector<int> &array,  int l, int r);
