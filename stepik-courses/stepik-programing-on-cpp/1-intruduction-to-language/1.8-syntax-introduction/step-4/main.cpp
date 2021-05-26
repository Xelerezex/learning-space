int power(int x, unsigned p) {
    int answer = 1;
    for(unsigned i = 1; i <= p; ++i){
        answer *= x;
    }
    return (p == 0) ? 1 : answer;
}
