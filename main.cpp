#include<stdio.h>
#include<Windows.h>
#include<thread>

void thread_1() {
	printf("Thread1\n");
}
void thread_2() {
	printf("Thread2\n");

}
void thread_3() {
	printf("Thread3\n");
}

int main() {
	// Create three threads and run them concurrently
	std::thread t1(thread_1);
	t1.join();
	std::thread t2(thread_2);
	t2.join();
	std::thread t3(thread_3);
	t3.join();
	return 0;
}