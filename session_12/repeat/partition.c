typedef long long int ssize_t;

ssize_t partition(int *a,ssize_t p,ssize_t r)
{
    int pivot,temp;
    int i,j;
    pivot = a[r];
    j = p;
    i = p -1;
    for(j = p;j<r;j++)
    {
        if(a[j]<= pivot)
        {
            i = i + 1;
            temp = a[j];
            a[j] = a[i];
            a[i] = temp;
        }
    }
    i = i + 1;
     temp = a[i] ;
     a[i] = a[j];
     a[j] = temp;

     return i;
}

ssize_t partiton(int *a,ssize_t p,ssize_t r)
{
    int pivot,temp;
    int i,j;
    pivot = a[r];
    i  = p - 1 ;
    for(j = p;j<r;j++)
    {
        if(a[j]<=pivot)
        {
            i = i + 1;
            temp = a[i];
            a[i] = a[j];
            a[j] = temp ;
        }

    }
        i = i + 1;
        temp = a[i];
        a[i] = a[j];
        a[j] = temp ;
      return i;   
}

ssize_t partition(int *a,int p ,int r)
{
    int pivot,temp;
    int i,j;
    i = p - 1;
    pivot = a[r];
    for(j=p;j<r;j++)
    {
        if(a[j] <=pivot)
        {
            i = i + 1;
            temp = a[j];
            a[j] = a[i];
            a[i] = temp;
        }
    }
    i = i + 1;
    temp = a[j];
    a[j] = a[i];
    a[i] = temp ;
}

ssize_t partition(int *a,ssize_t p,ssize_t r)
{
    int i,j;
    int pivot,temp;
    pivot = a[r];

    i = p  - 1;
    for(j=p;j<r;j++)
    {
        if(a[j] <= pivot)
        {
            i = i + 1 ;
            temp = a[j];
            a[j] = a[i];
            a[i] = temp;

        }
    }
    i = i + 1 ;
    temp = a[j];
    a[j] = a[i];
    a[i] = temp ;
    return i;
}

ssize_t partition(int *a,ssize_t p,ssize_t r)
{
    int i,j;
    int pivot ,temp;
    pivot = a[r];
    i = p - 1;
    for(j=p;j<r;j++)
    {
        if(a[j]<=pivot)
        {
            i = i + 1 ;
            temp = a[i] ;
            a[i] = a[j];
            a[j] = temp;
        }
    }
    i = i + 1;
    temp = a[r];
    a[r] = a[i];
    a[i] = temp ;
    return i;

}