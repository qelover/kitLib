/*
 * @brief: get median value by quick sort style
 */

template <typename T>
T median (T a[], int s, int e, const int mid)
{
    if (s>=e)
        return NULL;
        
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
    
    if (i == mid)
        return temp;
    else if (i < mid)
        return median<T>(a, i+1, e, mid);
    else
        return median<T>(a, s, i-1, mid);
}
