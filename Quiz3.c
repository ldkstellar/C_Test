#include <stdio.h>
#define SIZE 5

int maze[SIZE][SIZE] = {
    //0,0
    {0, 1, 1, 1, 0},
    {0, 1, 0, 0, 0},
    {0, 1, 0, 1, 0},
    {0, 0, 0, 1, 0},
    {1, 1, 1, 1, 0}
};

int maxPath = 0;// 가장 많이 갈 수 있는 칸 수
int maxDir = 0; // 가장 많이 갈 수 있는 방향
int myY;
int myx;

int max[4]={0};// 상 하 좌 우
void sortmax(){
    int myMax = max[0];
    int myIndex = 0;

    for (int i = 0; i < 4; i++) {
        if (max[i] > myMax) {
            myMax = max[i];
            myIndex = i;
        }
    }

    switch (myIndex){
        case 0:
            printf("하");
            printf("\n");
            break;

        case 1:
            printf("상");
            printf("\n");
            break;

        case 2:
            printf("우");
            printf("\n");
            break;
        
        case 3:
            printf("좌");
            printf("\n");
            break;
    }

    for (int i = 0; i < 4; i++) {
        
        if (max[i] == max[myIndex] && myIndex !=i) {
            
            
        switch (i){
            case 0:
                printf("하");
                printf("\n");
                break;

            case 1:
                printf("상");
                printf("\n");
                break;

            case 2:
                printf("우");
                printf("\n");
                break;
            
            case 3:
                printf("좌");
                break;    
            }
            printf("%d",i);
        }
    }

    return;

}
void findxy(int myx ,int myY){
    
    // 벽확인
    if (maze[myY][myx] ==1)
    {
        printf("벽입니다.");
        return;
        /* code */
    }
    

    //하으로 이동

    for (int i = myY+1 ; i < 5; i++){

        if (maze[i][myx] != 1){
             max[0]+=1;
        }

        else if(maze[i][myx] == 1){
            break;   
        }
    }

   
    
    //상로 이동
    for (int i = myY-1 ; i >= 0; i--){

        if (maze[i][myx] != 1){
             max[1]+=1;
        }
        else if(maze[i][myx] == 1){
             break;
        }
          
    }


    //우로 이동
    for (int i = myx+1;i< 5;i++){

        if ( maze[myY][i] != 1){
             max[2]+=1;
        }
        else if (maze[myY][i] == 1){
             break;  
        }
        
          
    }

   

    //좌로 이동
    for (int i = myx-1; i >=0 ;i--)
   
        if ( maze[myY][i] != 1){
             max[3]+=1;
             }

        else if(maze[myY][i] == 1){
            break;
            }
    for (int i = 0; i < 4; i++)
    {
        printf("%d\n",max[i]);
    }
    

    sortmax();      
}
    
    


int main() {
    printf("좌표를 입력하세요:");
    scanf("%d %d", &myx,&myY);
    findxy(myx,myY);
   

    return 0;
}
