#include <iostream>
using namespace std;

struct Array
{
    unsigned int n;
    float *ptr;
};

void linspace(Array *&destination, float start, float stop, unsigned int npoints)
{
    destination->n = npoints;
    destination->ptr = new float[npoints];
    if (npoints == 1)
    {
        destination->ptr[0] = start;
    }
    else
    {
        float step = (stop - start) / (npoints - 1);
        for (unsigned idx = 0; idx < npoints; idx++)
        {
            destination->ptr[idx] = start + step * idx;
        }
    }
    return;
}

int main()
{
    float start, stop;
    unsigned int npoints;
    cin >> start >> stop >> npoints;

    Array *data = new Array;
    linspace(data, start, stop, npoints);
    for (unsigned idx = 0; idx < data->n; ++idx)
    {
        cout << data->ptr[idx];
        if (idx != data->n - 1)
            cout << " ";
    }
    cout << endl;

    delete[] data->ptr;
    delete data;
    return 0;
}

