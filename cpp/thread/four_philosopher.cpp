#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define num 4
#pragma comment(lib, "pthreadVC2.lib")


pthread_mutex_t chopstick[5] = { PTHREAD_MUTEX_INITIALIZER ,PTHREAD_MUTEX_INITIALIZER ,PTHREAD_MUTEX_INITIALIZER
                                 ,PTHREAD_MUTEX_INITIALIZER, PTHREAD_MUTEX_INITIALIZER };

//????????
void getChop(int i);
void layChop(int i);
void *philosophe(void *i);

int count =0;

int main()
{
	pthread_t thread1,t1,t2,t3,t4,t5;
/*	for (int i = 0; i < 5; i++) {
		pthread_create(&thread1, NULL, philosophe, (void*)(i+1));
		pthread_join(thread1, NULL);
	}*/
	pthread_create(&t1, NULL, philosophe, (void*)1);
	pthread_create(&t2, NULL, philosophe, (void*)2);
	pthread_create(&t3, NULL, philosophe, (void*)3);
	pthread_create(&t4, NULL, philosophe, (void*)4);
	pthread_create(&t5, NULL, philosophe, (void*)5);
	pthread_join(t1, NULL);
	pthread_join(t2, NULL);
	pthread_join(t3, NULL);
	pthread_join(t4, NULL);
	pthread_join(t5, NULL);
	system("pause");
	return 0;
}

/*
?????????????????????
*/
void *philosophe(void *i) {
	int index = (int)i;
	getChop(index);
	printf("?????%d????????\n", index);
	layChop(index);
	return NULL;
}
/*
????????????????
*/
void getChop(int i) {
	//??????????ж?????????????????????
	while (count<4) {
		int ret_trylock1 = pthread_mutex_lock(&chopstick[i-1]);
		//????????????????????????????????????????????
		if (!ret_trylock1) {
			count++;
		}
		int ret_trylock2 = pthread_mutex_lock(&chopstick[i%5]);
		
		if (!ret_trylock1 && !ret_trylock2) {
			break;
		}
	}
}

//??????????????
void layChop(int i)
{
	//???????????????????????????????????????????????м??????????????????????
	printf("?????%d?????????????????\n", i);
	
	pthread_mutex_unlock(&chopstick[i - 1]);
	pthread_mutex_unlock(&chopstick[i % 5]);
                //?????????????????count-1,???????????????????λ
	count--;
}




