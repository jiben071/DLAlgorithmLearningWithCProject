//
//  main.c
//  DLAlgorithmLearningWithCProject
//
//  Created by denglong on 2018/5/24.
//  Copyright © 2018 ubtrobot. All rights reserved.
//

#define LOCAL
#define INF 1000000000

#include <stdio.h>
#include <math.h>
#include <time.h>
#include <string.h>

//计算浮点数
void calculateFloatNumber(){
    printf("%.1f\n",8.0/5.0);//%.1f————保留小数点后一位
}

//复杂表达式
void complexExpression(){
    printf("%.8f\n",1 + 2*sqrt(3)/(5-0.1));
}

//带输入表达式
void inputNumberToCalculate(){
    int a,b;
    scanf("%d%d",&a,&b);
    printf("%d\n",a+b);
}

//计算圆柱体表面积
void calculateCylinderSuperFicialArea(){
//    acos() 函数返回一个以弧度表示的反余弦值
//    【参数】x 为余弦值，范围为 -1 到 1 之间，超出此范围将会导致错误，并设置 errno 的值为 EDOM.
//    【返回值】返回 0 至 π 之间的计算结果，单位为弧度，在函数库中角度均以弧度来表示。
    //反余弦函数求得PI值
    const double pi = acos(-1.0);
    double radius,height,bottomS,sideS,totalS;
    scanf("%lf%lf",&radius,&height);
    bottomS = pi * radius * radius;//底面积
    sideS = 2 * pi * radius * height;
    totalS = bottomS * 2 + sideS;
    printf("Area = %.3lf\n",totalS);
}

//三位数反转
void reverse(int number){
    int a,b,c,m;
    a = number / 100;
    c = number % 10;
    b = (number / 10) % 10;
    m = c * 100 + b * 10 + a;
    printf("%d\n", m);
    printf("%03d\n",m);
}

void exchangeNumber(int a,int b){
    int c;
    c = a;
    a = b;
    b = c;
    printf("%d %d",a,b);
}

/*
 “已知鸡和兔的总数量为n，总腿数为m。输入n和m，依次输出鸡的数目和兔的数目。如果无解，则输出No answer。”
 */
void chickRobbit(int totalObjects,int totalLegs){
    int chickNumber,rabbitNumber;
    chickNumber = (4 * totalObjects - totalLegs) / 2;
    rabbitNumber = totalObjects - chickNumber;
    if (totalLegs % 2 == 1 || chickNumber < 0 || rabbitNumber < 0) {
        printf("NO answer\n");
    }else{
        printf("%d %d\n",chickNumber,rabbitNumber);
    }
}


void testInputOut(){
    printf("%lf \n", 111111.0 * 111111.0);
    printf("%f \n", sqrt(-10));
    printf("%d \n",1/0);
    
}

void convertTemperature(float f){
    float temp;
    temp = 5 * (f - 32) / 9.0;
    printf("%.3f",temp);
}


void circleTest(){
    for (int i = 0; i <= 100; i++) {
        printf("%d \n",i);
    }
}

void factorialCalculate(int number){
    const int MOD = 1000000;
    int S = 0;
    for (int i = 1; i <= number; i++) {
        int factorial = 1;
        for (int j = 1; j <= i; j++) {
            factorial = (factorial * j % MOD);
            S = (S + factorial) % MOD;
        }
    }
    printf("%d\n",S);
    //获取程序运行时间
    printf("Time used = %.2f\n",(double)clock() / CLOCKS_PER_SEC);
}

//数据统计（重定向版）
void reDirectInOrOut(){
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
#ifdef LOCAL
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    int x,n = 0,min = INF,max = -INF,s = 0;
    while (scanf("%d",&x) == 1) {
        s += x;
        if (x < min) {
            min = x;
        }
        if (x > max) {
            max = x;
        }
        n++;
    }
    printf("%d %d %.3f\n",min,max,(double)s/n);
}

//数据统计（fopen版）
//在算法竞赛中，如果不允许使用重定向方式读写数据，应使用fopen和fscanf/fprint进行输入输出。
void reDirectInOrOut2(){
    FILE *fin,*fout;
    fin = fopen("data.in", "rb");
    fout = fopen("data.out", "wb");
    int x,n = 0,min = INF,max = -INF,s = 0;
    while (fscanf(fin, "%d",&x) == 1) {
        s += x;
        if (x < min) {
            min = x;
        }
        
        if (x > max) {
            max = x;
        }
        n++;
    }
    fprintf(fout, "%d %d %.3f\n",min,max,(double)s/n);
    fclose(fin);
    fclose(fout);
}

//数据统计  分组
void dataStatics(){
    int x,n = 0,min = INF,max = -INF,s = 0,kase = 0;
    while (scanf("%d",&n) == 1 && n) {
        s = 0;
        min = INF;
        max = -INF;
        for (int i = 0; i < n; i++) {
            scanf("%d",&x);
            s += x;
            if (x < min) {
                min = x;
            }
            if (x > max) {
                max = x;
            }
        }
        if (kase) {
            printf("\n");
        }
        printf("Case %d: %d %d %.3f\n",++kase,min,max,(double)s/n);
    }
}

void permutation(){
    for (int i =  1; i < 10; i++) {
        
    }
}

//一维数组
void arrayTest1(){
    //数组不能进行赋值操作
    int a[10],b[20];
//    a = b;//报错
    
    //从数组a赋值5个整型元素到数组b
    memcpy(b,a,sizeof(int) * 5);

    //全部复制
    memcpy(b, a, sizeof(a));
}

#define maxn 1010
int a[maxn];
void turnLightOn(){
    int n,k,first = 1;
    memset(a, 0, sizeof(a));//把数组a清零
    scanf("%d%d",&n,&k);
    for (int i = 1; i <= k; i++) {//遍历人
        for (int j = 1; j <= n; j++) {//遍历灯
            if (j % i == 0) {//对应倍数的灯
                a[j] = !a[j];
            }
        }
    }
    
    //遍历数组还剩下的灯组
    for (int i = 1; i<=n; n++) {
        if (a[i]) {
            //打印空格
            if (first) {
                first = 0;
            }else{
                printf(" ");
            }
            
            printf("%d",i);//开灯的编号
        }
    }
    printf("\n");
}

//蛇形填数
#define maxn2 20
int snak[maxn2][maxn2];
void snakNumberFill(){
    int rowNumber;
    int x;//x下标
    int y;//y下标
    int total;//总共填满的格子数
    scanf("%d",&rowNumber);
    memset(snak, 0, sizeof(snak));//重置所有的格子里面的数字为0
    total = snak[x=0][y=rowNumber-1] = 1;//先填上第一个数
    
    //关键：找到循环的界限，第一圈、第二圈
    while (total < rowNumber * rowNumber) {//只要填上的格子数没有满，就继续遍历
        //往下走
        while (x+1 < rowNumber && !snak[x+1][y]) {
            snak[++x][y] = ++total;
        }
        
        //往左走
        while (y-1 > 0 && !snak[x][y-1]) {
            snak[x][--y] = ++total;
        }
        
        //往上走
        while (x-1 > 0 && !snak[x-1][y]) {
            snak[x--][y] = ++total;
        }
        
        //往右走
        while (y+1 < rowNumber && !snak[x][y+1]) {
            snak[y++][x] = ++total;
        }
    }
    
    //遍历输出
    for (x = 0; x < rowNumber; x++) {
        for (y = 0; y < rowNumber; y++) {
            printf("%3d",snak[x][y]);
        }
        printf("\n");
    }
    
}

//程序3-1 逆序输出
#define maxn3 105
int array[maxn3];//“比较大的数组应尽量声明在main函数外，否则程序可能无法运行。”
void inverseOutPrint(){
    int x,n = 0;
    while (scanf("%d",&x) == 1) {
        a[n++] = x;
    }
    for (int i = n-1; i >= 1; i--) {
        printf("%d",a[i]);
    }
    printf("%d\n",a[0]);
    
    int b[105];
    //数组复制
    memcpy(b, array, sizeof(array));
}



//KMP算法
//https://blog.csdn.net/ltyqljhwcm/article/details/51460713
void makeNext(const char StrArray[],int *MoveArray){
    int str_index,move_index;//str_index:模版字符串下标；move_index:最大前后缀长度
    int str_len = (int)strlen(StrArray);//模版字符串长度
    MoveArray[0] = 0;//模版字符串的第一个字符的最大相同前后缀长度为0
    
    //for循环，从第二个字符开始，依次计算每一个字符对应的move值
    for (str_index = 1,move_index = 0; str_index < str_len; ++str_index){
        //递归的求出StrArray[0]···P[str_index]的最大的相同的前后缀长度move_index
        //当移动的步骤大于0 同时 当前遍历的字符不等于可移动步骤的最大字符  就要持续循环
        while(move_index > 0 && StrArray[str_index] != StrArray[move_index]){//有几个前后缀相同的字符打基础，突然出现了一个不同的，要回溯一下，看少一个能不能还会有相同的
            move_index = MoveArray[move_index-1];//表示最后还能有多少个相同的后缀
        }
        
        //如果有相等的字母，那么最大相同前后缀长度加1
        if (StrArray[str_index] == StrArray[move_index]){
            move_index++;
        }
        
        MoveArray[str_index] = move_index;
        printf("MoveArray[%d]是  相同字符数：%d \n",str_index,MoveArray[str_index]);
    }
    
}

#define N 100005
int moveArray[N];
int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    printf("%d\n",1+2);
    calculateFloatNumber();
//    inputNumberToCalculate();
//    calculateCylinderSuperFicialArea();
//    reverse(520);
    chickRobbit(32, 21);
    testInputOut();
    convertTemperature(180);
    
    makeNext("aabcddcaafabcdaabd", moveArray);
    return 0;
}




