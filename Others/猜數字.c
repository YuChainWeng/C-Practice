#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
void prepare(void);  //�ǳƤu�@�����
void ask(void);  //�q���ݤ����
void answer(void);  //�H�����Xa�Xb�����
void think(void);  //�q����Ҥ���ơ]���N�O�q���׮w���ư����i�઺���ס^
void menu(void);  //��椧���
int answerBase[5040][4];  /*���׮w�A�|�ˤJ�Ҧ����ƪ��|��ơA�q1234��9876
                            5040�O�]��10*9*8*7�A4�O�]���C�յ��׬O�@�ӥ|���*/
int isOver,restart;  //��@���L�ȡA�P�_�O�_�C�������H�άO�_�n�~��
int remain;  //���׮w�̭������׼�
int a,b;  //���Ӹ˨ϥΪ̦^�����Xa�Xb
int randNum;  //�˶üơA�H���q���׮w�̭�������
int main(void){
    while(1==1){
        prepare();
        while(!isOver){
            ask();
            answer();
            if(isOver) break;
            think();
            printf("------------------\n");
        }
        menu();
        if(!restart) break;
    }
    getchar();
    return 0;
}
/****** �ǳƤu�@����� ******/
void prepare(void){
    int i,tmp,unit_1,unit_10,unit_100,unit_1000;
    remain=5040;
    tmp=0;  //tmp�u�O�@�Ӯ��ӭp���ܼ�
    isOver=0;  //�P�_�����P�_
    for(i=0;i<10000;i++){  //�o��for���͵��׮w
        unit_1 = (i/1)%10;  //�H�U�|���|��Ʃ�|�ӦU��Ƥ��O�s��|���ܼ�
        unit_10 = (i/10)%10;
        unit_100 = (i/100)%10;
        unit_1000 = (i/1000)%10;
        if(unit_1!=unit_10 && unit_1!=unit_100 && unit_1!=unit_1000 && unit_10!=unit_100 && unit_10!=unit_1000 && unit_100!=unit_1000){
            answerBase[tmp][0] = unit_1000;
            answerBase[tmp][1] = unit_100;
            answerBase[tmp][2] = unit_10;
            answerBase[tmp][3] = unit_1;
            tmp++;
        }
    }
}
void ask(void){
    int i;
    printf("�аݬO");
    srand(time(0));
    while(1==1){
        randNum=0;
        for(i=0;i<4;i++){
            randNum *= 10;
            randNum += rand()%10;
        }
        if(randNum<remain) break;
    }
    for(i=0;i<4;i++) printf("%d",answerBase[randNum][i]);
    printf("?\n");
}
/****** �H��������� ******/
void answer(void){
    char input[500];
    int right=0;  //���L�ȡA�P�_�O�_���T����J
    do{  //���oa,b��
        do{  //���oa��
            printf("A:");
            fgets(input,sizeof(input),stdin);
            *(input+strlen(input)-1)='\0';
            if(strlen(input)==1 && *input-'0'<= 9 && *input-'0'>=0){
                a = *input-'0';
                right = 1;
            }else printf("��J���~\n\n");
        }while(!right);
        do{  //���ob��
            printf("B:");
            fgets(input,sizeof(input),stdin);
            *(input+strlen(input)-1)='\0';
            if(strlen(input)==1 && *input-'0'<= 9 && *input-'0'>=0){
                b = *input-'0';
                right = 1;
            }else printf("��J���~\n\n");
        }while(!right);

        if(a+b>4){  //�p�Ga�Mb�ۥ[�j��4��M�N���ա�
            printf("��J���~\n\n");
            right = 0;
        }
    }while(!right);
    if(a==4){
        printf("�j���ΡG�C�㵪��F�I\n");
        isOver=1;
    }else if(remain==1){  //�p�G���׮w�u�Ѥ@�ӵ��סA���O�o�����٬O�����A�N�O���a�@���I
        printf("�j���ΡG�A�@���I= =+\n");
        isOver=1;
    }
}
/****** �q����Ҥ���� ******/
void think(void){
     int i,j,k,aa,bb;
     int refer[4];
     for(i=0;i<4;i++){
         refer[i]=answerBase[randNum][i];
     }
     for(i=0;i<remain;i++){
         aa = bb = 0;  //���a�ȩMb�ȡA���n�ϧO�󤧫e���H����J��a��b��
         for(j=0;j<4;j++){  //�H�U���for�ΨӤ���i�ӵ��שM�üƨ������ת��O�Xa�Xb
             for(k=0;k<4;k++){
                 if(answerBase[i][j]==refer[k]){
                     if(j==k) aa++;
                     else bb++;
                 }
             }
         }
         if(!((aa==a)&&(bb==b))){  //��a��b�Ȭ۵������׫O�d�U��
             for(j=i;j<remain;j++){  //�}�l�h�B
                 for(k=0;k<4;k++){
                     answerBase[j][k]=answerBase[j+1][k];
                 }
             }
             remain--;
             i--;
         }
     }
     if(remain==0){  //�o�{�S�����ײŦX���a�Q���Ʀr�A�N�O���a�@���I
        printf("�j���ΡG�A�@���I= =+\n");
        isOver=1;
     }
}
/****** ��椧��� ******/
void menu(void){
    char input[500];
    int right = 0;
    do{
        printf("�j���ΡG�O�_���s�Hy/n");
        fgets(input,sizeof(input),stdin);
        *(input+strlen(input)-1)='\0';
        if(strlen(input)==1 && (*input == 'y' || *input == 'Y')){
            printf("\n------------------\n");
            restart = 1;
            right = 1;
        }else if(strlen(input)==1 && (*input == 'n' || *input == 'N')){
            printf("�j���ΡG�C�������A�������");
            restart = 0;
            right = 1;
        }else printf("��J���~\n\n");
    }while(!right);
}
