#include <stdio.h>
#include<stdlib.h>

int  idkp0[2][3*10],idkp1[2][3*100];

// 读数据，将读到的数据保存到数组中 
int getData()
{
	FILE *fpRead = fopen("idkp1-10.txt","r");
	
	if(fpRead == NULL) 
	{
		return 0;
	}
	
	// 读取第一组数据
	for(int i=0;i<3*10;i++) 
		fscanf(fpRead,"%d,",&idkp0[0][i]);
	for(int i=0;i<3*10;i++) 
		fscanf(fpRead,"%d,",&idkp0[1][i]);

	// 读取第二组数据
	for(int i=0;i<3*100;i++) 
		fscanf(fpRead,"%d,",&idkp1[0][i]);
	for(int i=0;i<3*100;i++) 
		fscanf(fpRead,"%d,",&idkp1[1][i]);
}

// 按项集第三项的价值/重量比进行非递增排序 
void Bubble_sort(int len)
{
    int tmp1 = 0,tmp2 = 0,tmp3 = 0,tmp4 = 0,tmp5 = 0,tmp6 = 0;  // 做交换操作的中间容器
    bool swap = false;    // 加判断条件  减少比较次数
    for(int i=0;i<len-1;i++) 
	{
        for(int j=0;j<len-1-i;j++)
        {
            if((j+1)%3 == 0 && ((idkp0[0][j]/idkp0[1][j]) < (idkp0[0][j+3]/idkp0[1][j+3])))
            {
                tmp1 = idkp0[0][j];
                idkp0[0][j] = idkp0[0][j+3];
                idkp0[0][j+3] = tmp1;  // 交换
                
                tmp2 = idkp0[0][j-1];
                idkp0[0][j-1] = idkp0[0][j+2];
                idkp0[0][j+2] = tmp2;  // 交换
                
                tmp3 = idkp0[0][j-2];
                idkp0[0][j-2] = idkp0[0][j+1];
                idkp0[0][j+1] = tmp3;  // 交换
                
                tmp4 = idkp0[1][j];
                idkp0[1][j] = idkp0[1][j+3];
                idkp0[1][j+3] = tmp4;  // 交换
                
                tmp5 = idkp0[1][j-1];
                idkp0[1][j-1] = idkp0[1][j+2];
                idkp0[1][j+2] = tmp5;  // 交换
                
                tmp6 = idkp0[1][j-2];
                idkp0[1][j-2] = idkp0[1][j+1];
                idkp0[1][j+1] = tmp6;  // 交换
                
                swap = true;
            }
        }
        if (!swap)
		{
            return;
        }
    }
}

int V[100][100];   // 前i个物品装入容量为j的背包中获得的最大价值

int max(int a,int b){
   if(a>=b)
       return a;
   else return b;
}

// 动态规划法求解01背包问题
void Baggage(int level,int n,int temp_weight,int temp_value,int weight[],int value[])
{
	if(level>=n+1)
	{
		if(temp_value>max_value)
		{
			max_value = temp_value;
		}
	}
	else
	{
		if(temp_weight>=weight[level+1])
		{
			temp_weight = temp_weight - weight[level+1];
			temp_value = temp_value + value[level+1];
			Baggage(level+1,n,temp_weight,temp_value,weight,value);
			temp_weight = temp_weight + weight[level+1];
			temp_value = temp_value - value[level+1];
		}
		Baggage(level+1,n,temp_weight,temp_value,weight,value);
	}
}

int main() 
{
	getData();  // 从文件中读取数据
	
	// 打印出读取到的物品价值
	printf("价值:\n");
	for(int i=0;i<3*10;i++)
	{
		if((i+1)%3 == 0)
			printf("%d] ",idkp0[0][i]);
		else if((i+3)%3 == 0)
			printf("[%d,",idkp0[0][i]);
		else
			printf("%d,",idkp0[0][i]);
	}
	// 打印出读取到的物品重量
	printf("\n重量:\n");
	for(int i=0;i<3*10;i++)
	{
		if((i+1)%3 == 0)
			printf("%d] ",idkp0[1][i]);
		else if((i+3)%3 == 0)
			printf("[%d,",idkp0[1][i]);
		else
			printf("%d,",idkp0[1][i]);
	}
	printf("\n");
	
	// 按项集第三项的价值/重量比进行非递增排序
	Bubble_sort(3*10);
	
	// 输出排序后的结果
	printf("\n排序后：\n\n");
	printf("价值:\n");
	for(int i=0;i<3*10;i++)
	{
		if((i+1)%3 == 0)
			printf("%d] ",idkp0[0][i]);
		else if((i+3)%3 == 0)
			printf("[%d,",idkp0[0][i]);
		else
			printf("%d,",idkp0[0][i]);
	}
	printf("\n重量:\n");
	for(int i=0;i<3*10;i++)
	{
		if((i+1)%3 == 0)
			printf("%d] ",idkp0[1][i]);
		else if((i+3)%3 == 0)
			printf("[%d,",idkp0[1][i]);
		else
			printf("%d,",idkp0[1][i]);
	}
	printf("\n");
	
} 
