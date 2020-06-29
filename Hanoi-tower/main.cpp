#include <iostream>

using namespace std;

void render(int num, int tower[][3]){
    cout << endl;
    for (int i = num-1; i >=0; i--){
            printf("%5d\t%5d\t%5d\n", tower[i][0], tower[i][1], tower[i][2]);

    }
}

void move(int num, int towers[][3], int heights[3], int from, int to){
    if(heights[from]>0 && (heights[to]==0 || towers[heights[from]-1][from] < towers[heights[to]-1][to])){
        towers[heights[to]++][to] = towers[heights[from]-1][from];
        towers[--heights[from]][from] = 0;
    } else{
        cout<<"Error: can't put bigger brick on smaller one"<<endl;
    }


}

int main()
{
    int num, start, finish;
    cin>>num;
    int towers[num][3] = {0};
    int heights[3] = {num, 0, 0};

    for(int i=num-1; i>=0; i--){
        towers[i][0]=num-i;
    }
    render(num, towers);

    while(heights[1]<num && heights[2]<num){
        cin>>start>>finish;
        move(num, towers, heights, start-1, finish-1);
        render(num, towers);
    }
    return 0;
}
