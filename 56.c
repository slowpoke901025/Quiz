#include<stdio.h>


int format1(char*s)//�O�_���e�A�� 
{
	if(*s=='{'||*s=='['||*s=='(')
	{
		return 1;
	}
	return 0;
}

int format2(char*s)//�O�_����A�� 
{
	if(*s=='}'||*s==']'||*s==')')
	{
		return 1;
	}
	return 0;
}



int function(char*s)//�P�_���G�禡 
{
	
	char *start = s;//���V���� 
	char *left = NULL;//���V�ثe�̾a�k�����A�� ���k�A����P��t�� 
	
	while(*s != '\0')
	{
		if(format1(s))//���A�� 
		{
			left = s;//���V���A�� 
		}
		
		else if(format2(s))//�J��̥��䪺�k�A�� 
		{
			if(left==NULL)//left�ثe�L���V 
			{
				left = s;//�q�ثe��m���e�� 
				while(!format1(--left))//��쥪�A������ 
				{
					if(left==start)//�w�g��쭺�����S�� 
					{
						return 0;//���ŦX 
					}
				}
			}
			
			if(*s-*left>0 && *s-*left<=2)//�P�_�����A���P�k�A���O�_���� 
			{
				*s = 0;		//���k�s 
				*left = 0; //���k�s
				left = NULL; //���мȮɫ��V�� 
			}
			else
			{
				return 0;//������,���ŦX 
			}
		}
		
		else//�D�A���� 
		{
			return 0;
		}
		s++;
	}
	
	
	if(left==NULL)//�Ҧ��A���Ҧ��� 
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
	
	
int main(int argc, char *argv[])
{
	char s[100]={};
	printf("Enter:");
	scanf("%s",s);
	
	if(function(s))
	{
		printf("GOOD!");
	}
	else
	{
		printf("BAD:(");
	}
}
