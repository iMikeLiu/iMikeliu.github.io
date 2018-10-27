void inv(long long n,long long p,long long *result[])
{
	inv[1]=1;
    for(long long i=2;i<=n;i++)
	{
        inv[i]=(int)(p-p/i)*result[p%i]%p;
    }
}
//求模1-p意义下n的逆元，存于数组result[]里面 