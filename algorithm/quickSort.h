/*
 * @brief: quick sort
 * @param: input array is a[0:9] with length 10; 
 *         value range of s and e is both [0:9]
 */
 
 
template <typename T>
void quickSort(T a[], int s, int e)
{
    if (s>=e)
        return;

    int i = s;
    int j = e;
    T temp = a[s];

    while (i<j)
    {
        while (i<j && a[j]>temp)
            --j;
        a[i] = a[j];

        while (i<j && a[i]<=temp)
            ++i;
        a[j] = a[i];
    }
    a[i] = temp;

    quickSort<T>(a, s, i-1);
    quickSort<T>(a, i+1, e); 
}

/*
 * if value range of e is [0:10], code will be changed as follows:
 *

while (i<j)
{
    do{
        --j;
    }while (i<j && a[j]>temp);
    a[i] = a[j];
    do{
        ++i;
    }while (i<j && a[i]<=temp);
    a[j] = a[i];
}

*/
