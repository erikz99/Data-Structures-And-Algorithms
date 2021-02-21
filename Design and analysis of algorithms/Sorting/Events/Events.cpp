#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

struct Event {
    char hour[9];
    char date[11];
    int index;

    bool operator<(const Event& ev) {
        int thisYear = (date[6] - '0') * 1000 + (date[7] - '0') * 100 + (date[8] - '0') * 10 + (date[9] - '0');
        int evYear = (ev.date[6] - '0') * 1000 + (ev.date[7] - '0') * 100 + (ev.date[8] - '0') * 10 + (ev.date[9] - '0');
        if (thisYear < evYear) {
            return true;
        }
        else if (thisYear > evYear) {
            return false;
        }
        int thisMonth = (date[3] - '0') * 10 + (date[4] - '0');
        int evMonth = (ev.date[3] - '0') * 10 + (ev.date[4] - '0');
        if (thisMonth < evMonth) {
            return true;
        }
        else if (thisMonth > evMonth) {
            return false;
        }
        int thisDay = (date[0] - '0') * 10 + (date[1] - '0');
        int evDay = (ev.date[0] - '0') * 10 + (ev.date[1] - '0');
        if (thisDay < evDay) {
            return true;
        }
        else if (thisDay > evDay) {
            return false;
        }
        double thisHour = (hour[0] - '0') * 10 + (hour[1] - '0') + (hour[3] - '0') * (1.0 / 6) + (hour[4] - '0') * (1.0 / 60) + (hour[6] - '0') * (1.0 / 360) + (hour[7] - '0') * (1.0 / 3600);
        double evHour = (ev.hour[0] - '0') * 10 + (ev.hour[1] - '0') + (ev.hour[3] - '0') * (1.0 / 6) + (ev.hour[4] - '0') * (1.0 / 60) + (ev.hour[6] - '0') * (1.0 / 360) + (ev.hour[7] - '0') * (1.0 / 3600);
        if (thisHour < evHour) {
            return true;
        }
        else if (thisHour > evHour) {
            return false;
        }
        return index < ev.index;
    }
};

Event arr[200000];
int numberOfElements;

void siftUp(int ind) {
    if (ind == 0)return;

    int parent = (ind - 1) / 2;

    if (arr[ind] < arr[parent]) {
        swap(arr[ind], arr[parent]);
        siftUp(parent);
    }
}

void siftDown(int ind) {
    int left = ind * 2 + 1, right = ind * 2 + 2;

    if (left >= numberOfElements)return;

    if (arr[right] < arr[left] && arr[right] < arr[ind]) {
        swap(arr[right], arr[ind]);
        siftDown(right);
    }
    else if (arr[left] < arr[ind]) {
        swap(arr[left], arr[ind]);
        siftDown(left);
    }
}

void addElement(Event& element) {
    arr[numberOfElements] = element;
    siftUp(numberOfElements++);
}

void removeElement() {
    arr[0] = arr[--numberOfElements];
    siftDown(0);
}

int top() {
    if (numberOfElements > 0) {
        return arr[0].index;
    }
    return -1;
}

void solve() {
        int numOfEvents;
    scanf("%d", &numOfEvents);
    char hour[9];
    char date[11];
    Event event;
    for (int i = 0; i < numOfEvents; i++) {
        scanf("%s", hour);
        scanf("%s", date);
        strcpy(event.hour, hour);
        strcpy(event.date, date);
        event.index = i + 1;
        addElement(event);
    }
    for (int i = 0; i < numOfEvents; i++) {
        printf("%d\n", top());
        removeElement();
    }
}

int main() {
    solve();
}