struct Test{
    int operator()(int x, int y, int z){
        return x? y:z;
    }
};