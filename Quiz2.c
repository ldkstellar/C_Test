#include <stdio.h>
#include <string.h>
void quiz(){

}

void main(){
    int matrix[5][5] ={{1,2,3,4,5},{1,2,3,4,5},{1,2,3,4,5},{1,2,3,4,5},{1,2,3,4,5}};
    
    
   
    int x =1;
    int maxsize;

    char answer[10] ="";
   

    printf("방법을 입력하세요\n");
    scanf("%s",&answer);
  
    if (strcmp(answer,"우수법")){// reverse colcok wise
       while (1)
       {
        if (left == 1)break;
     
       
        for (int i = 0; i < 5; i++)
        {
            printf("%d",0);
            printf(",");
            printf("%d",matrix[0][i]);
            printf("->");
            
        }
    
        for (int i = 0; i < 5; i++)
        {
            printf(" %d",1+i);
            printf(",");
            printf("%d",matrix[i][temp]);
            printf("->");
        }

        for (int i = 4; i >=0 ; i--)
        {
            
            printf(" %d",5);
            printf(",");
            printf("%d",matrix[4][i]);
            printf("->");
            /* code */
        }
        temp =2;

         for (int i = 4; i >=0 ; i--)
        {
            
            printf(" %d",5);
            printf(",");
            printf("%d",matrix[4][i]);
            printf("->");
            /* code */
        }
        
        
        
        return;
    }

    
    
}