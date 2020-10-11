#include "HPriorityQueue.hpp"

int main(void) {
	HPriorityQueue queue(5);

	queue.Enqueue(13, "공부");
	queue.Enqueue(1, "운동");
	queue.Enqueue(2, "프로틴 섭취");
	queue.Enqueue(21, "농구");
	queue.Enqueue(81, "근무");
	queue.Enqueue(12, "블로그 글쓰기");
	queue.Enqueue(3, "전역");
	queue.Enqueue(51, "이발");
	queue.Enqueue(68, "잠자기");
	queue.Enqueue(7, "노래듣기");

	queue.PrintQueue();

	for(int i=0;i<12;i++) {
		printf("Phase: %d\n", i);
		queue.Dequeue();
		queue.PrintQueue();
	}

	queue.DestroyQueue();

	return 0;
}
