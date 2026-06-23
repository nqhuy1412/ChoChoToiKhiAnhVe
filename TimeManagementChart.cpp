#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

#define MAX_TASKS 100
#define MAX_LEN 100

typedef struct {
    char name[MAX_LEN];
    int important;   // 1 = Quan trọng, 0 = Không quan trọng
    int urgent;      // 1 = Khẩn cấp, 0 = Không khẩn cấp
} Task;

Task tasks[MAX_TASKS];
int taskCount = 0;

void addTask(char* name, int important, int urgent) {
    if (taskCount >= MAX_TASKS) {
        printf("Khong the them cong viec, danh sach da day.\n");
        return;
    }

    strcpy(tasks[taskCount].name, name);
    tasks[taskCount].important = important;
    tasks[taskCount].urgent = urgent;
    taskCount++;
}

void showTasksByCategory() {
    printf("\n== Danh sach theo Ma tran Eisenhower ==\n");

    printf("\n1. Quan trong và Khan cap (Lam ngay):\n");
    for (int i = 0; i < taskCount; i++) {
        if (tasks[i].important && tasks[i].urgent) {
            printf("- %s\n", tasks[i].name);
        }
    }

    printf("\n2. Quan trong nhung Khong khan cap (Lap ke hoach):\n");
    for (int i = 0; i < taskCount; i++) {
        if (tasks[i].important && !tasks[i].urgent) {
            printf("- %s\n", tasks[i].name);
        }
    }

    printf("\n3. Khong quan trong nhung Khan cap (Giao viec):\n");
    for (int i = 0; i < taskCount; i++) {
        if (!tasks[i].important && tasks[i].urgent) {
            printf("- %s\n", tasks[i].name);
        }
    }

    printf("\n4. Khong quan trong và Khong khan cap (Loai bo):\n");
    for (int i = 0; i < taskCount; i++) {
        if (!tasks[i].important && !tasks[i].urgent) {
            printf("- %s\n", tasks[i].name);
        }
    }
}

int main() {
    int choice;
    char name[MAX_LEN];
    int important, urgent;

    while (1) {
        printf("\n== Ma tran Eisenhower ==\n");
        printf("1. Them cong viec\n");
        printf("2. Hien thi cong viec\n");
        printf("3. Thoat\n");
        printf("Chon mot tuy chon: ");
        scanf("%d", &choice);
        getchar(); // Xóa ký tự newline sau khi nhập số

        switch (choice) {
        case 1:
            printf("Nhap ten cong viec: ");
            fgets(name, sizeof(name), stdin);
            name[strcspn(name, "\n")] = 0; // Xóa newline trong chuỗi

            printf("Cong viec này co quan trong khong? (1 = Co, 0 = Khong): ");
            scanf("%d", &important);
            printf("Cong viec nay co khan cap khong? (1 = Co, 0 = Khong): ");
            scanf("%d", &urgent);

            addTask(name, important, urgent);
            break;

        case 2:
            showTasksByCategory();
            break;

        case 3:
            printf("Thoat chuong trinh.\n");
            return 0;

        default:
            printf("Lua chon khong hop le. Vui long thu lai.\n");
        }
    }

    return 0;
}
