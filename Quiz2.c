#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// 좌수법 우수법은 벽이있거나 배열의 공간을 넘어가면 front방향을 바꾸면서
// 이동하는 메커니즘인 듯 dfs가 효율적인것 같아서 dfs로 풀었음. 아마 센싱 하면서
// 할때는 좌수법 우수법 사용하면 될 듯하다. c는 약간 츤데레 느낌의 언어 같다.
//  미로의 크기를 정의

#define ROWS 5
#define COLS 5

// 미로를 나타내는 2차원 배열
// 2 by 2좌표는 막혀서 못감 ㅎ
int maze[ROWS][COLS] = {{1, 0, 1, 1, 1},
                        {1, 0, 0, 0, 1},
                        {1, 0, 0, 0, 1},
                        {1, 0, 0, 0, 1},
                        {1, 1, 1, 1, 1}};

// 방문한 지점을 표시하기 위한 배열임
int visited[ROWS][COLS] = {0};

// 좌표를 나타내는 구조체
typedef struct {
  int x;
  int y;
} Point;

// 스택을 나타내는 구조체
typedef struct {
  Point* array;  //
  int top;
  int capacity;
} Stack;

// 스택 초기화
Stack* createStack(int capacity) {
  Stack* stack = (Stack*)malloc(sizeof(
      Stack));  // 초기 stack 동적 할당으로 정의 why 메모리 해제 하기 위해서
  // stack 메모리 공간 vs heap메모리 공간
  stack->capacity = capacity;  //
  stack->top = -1;
  stack->array = (Point*)malloc(
      capacity *
      sizeof(Point));  // 동적 배열로 정의 부족하면 heap메모리의 크기를 키우고
                       // 이전 값을  새로운 배열에 복사한다. 링크드리스트가
                       // 추가삭제시 용이 배열은 탐색에 용이하다
  return stack;
}

// 스택에 요소 추가
void push(Stack* stack, Point item) {
  if (stack->top == stack->capacity - 1) {
    // 스택이 가득 찬 경우
    return;
  }
  stack->array[++stack->top] = item;
}

// 스택에서 요소 제거
Point pop(Stack* stack) {
  Point emptyPoint = {-1, -1};  // 스택이 비어있는 경우 반환할 값
  if (stack->top == -1) {
    return emptyPoint;
  }
  return stack->array[stack->top--];  //
}

// 미로 경로 찾기 (DFS)
bool findPathDFS() {
  Stack* stack = createStack(ROWS * COLS);
  Point start = {0, 0};
  Point end = {2, 2};

  // 시작 지점을 스택에 추가
  push(stack, start);
  visited[start.x][start.y] = 1;  // 시작 지점 방문 표시

  while (stack->top != -1) {
    Point current = pop(stack);

    // 도착 지점에 도달하면 종료
    if (current.x == end.x && current.y == end.y) {
      free(stack);
      return true;
    }

    // 현재 지점의 상하좌우 탐색
    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};

    for (int i = 0; i < 4; i++) {
      int newX = current.x + dx[i];
      int newY = current.y + dy[i];

      // 미로 범위를 벗어나거나 벽이면 무시
      if (newX < 0 || newX >= ROWS || newY < 0 || newY >= COLS ||
          maze[newX][newY] == 0 || visited[newX][newY] == 1) {
        continue;
      }

      // 다음 지점을 스택에 추가하고 방문 표시
      Point next = {newX, newY};
      push(stack, next);
      visited[newX][newY] = 1;
    }
  }

  free(stack);  // 메모리 해제
  return false;
}

int main() {
  if (findPathDFS()) {
    printf("미로 경로를 찾았습니다!\n");
  } else {
    printf("미로 경로를 찾을 수 없습니다.\n");
  }

  return 0;
}
