
class Solution{
    public:
    
    long long fastExp(long long A, long long K, long long mod){
        long long ans = 1;
        while(K > 0){
            if(K&1){
                //odd
                ans = (ans*A)%(mod);
            }
            A = (A*A)%mod;
            K>>=1; //k = k/2;
        }
        return ans;
    }
    
    long long evaluateA(long long A, long long K)
    {
        if(K == 0){
            return 1;
        }
        long long mod = 1000000007;
        long long numerator = fastExp(A, K + 1, mod) - 1;
        long long denominator = A - 1;
        return (numerator * fastExp(denominator, mod - 2, mod)) % mod;
        
        //Fermat's Little Theorem
        //fastExp(denominator, mod - 2, mod) gives the inverse of denominator but only works 
        //if mod is prime and denominator is not divisible by mod
    }
};
