class Solution {
public:
    long long minimumPerimeter(long long neededApples) {
        long long res = 0, i = 0;
        while (res < neededApples) 
            res += 12 * pow(i++, 2);
        return (i-1) * 8;
    }
};