/* The functions which
builds the segment tree */
int buildseg(int i,int l,int r,int arr[],int seg[])
{
    if(l==r)
    {   seg[i]=arr[l];//IMP ...I FORGOT TO WRITE THIS LINE TOI INTILAISE THE LEAF NODES !!
        return arr[l];}
    if(l>r)
    {return 1e9;}
    int mid=l+(r-l)/2;
    int le=buildseg(2*i+1,l,mid,arr,seg);
    int ri=buildseg(2*i+2,mid+1,r,arr,seg);
    seg[i]=min(le,ri);
    return min(le,ri);
}
int *constructST(int arr[], int n) {
    // Your code here
    
    int *seg=new int[4*n];
    int a=buildseg(0,0,n-1,arr,seg);
    return seg;
}

/* The functions returns the
 min element in the range
 from a and b */
int f(int st[],int lq,int rq,int l,int r,int i)
{
    if(lq>r || l>rq)
    {return 1e9;}
    if(l>=lq && rq>=r)
    {return st[i];}
    int mid=l+(r-l)/2;
    int le=f(st,lq,rq,l,mid,2*i+1);
    int ri=f(st,lq,rq,mid+1,r,2*i+2);
    return min(le,ri);
}
int RMQ(int st[], int n, int a, int b) {
    
    // Your code here
    return f(st,a,b,0,n-1,0);
    
}