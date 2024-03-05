/*Approach 1*/
class Solution {
public:
    int fib(int n) {
      if(n <= 1)
         return n;
      return fib(n-1) + fib(n-2);
}




/*Approach 2 : Optimized */
class Solution {
public:
    int fib(int n) {
        if(n<2)
            return n;
        if(n%2 == 0)
            return (2*fib(n/2-1) + fib(n/2)) * fib(n/2);
        else
            return (fib((n+1)/2-1)*fib((n+1)/2-1) + fib((n+1)/2)*fib((n+1)/2));
    }
};
