int countStudents(int* students, int studentsSize, int* sandwiches, int sandwichesSize) {
    int front = 0, rear = studentsSize - 1, top = 0;
    int remain = studentsSize;
    int unsuccess = 0;

    while (unsuccess < remain) {
        if (students[front] == sandwiches[top]) {
            top++;
            front = (front + 1) % studentsSize;
            unsuccess = 0;
            remain--;
        } else {
             rear = (rear + 1) % studentsSize;
            students[rear] = students[front];
            front = (front + 1) % studentsSize;
            unsuccess++;

        }
    }

    return remain;
}