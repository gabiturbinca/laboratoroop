
class Sort
{
    int *v;
    int n;
public:
    Sort(int nr,int mini,int maxi);
    Sort(int *v,int nr);
    Sort(int count, ...);
    Sort (char *c);
    void InsertSort(bool ascendent=false);
    void QuickSort(bool ascendent=false);
    void BubbleSort(bool ascendent=false);
    void Print();
    int  GetElementsCount();
    int  GetElementFromIndex(int index);
};

