long long sumAndMultiply(int n) {
    int place = 1;
    long long x=0;
    long long sum =0;
    while(n>0){
        if(n%10 !=0){
            x = x + (n%10)*place;
            place *= 10;
        }
        sum += (n%10);

        n/=10;
    }
    return (x*sum);
}