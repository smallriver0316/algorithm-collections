#include <iostream>
#include <string>
using namespace std;

struct Process
{
    string name;
    int time;
};

class Queue
{
public:
    int start, end, num;
    Process array[100000];

    Queue(int n)
    {
        start = 0;
        end = 0;
        num = n;
    }

    void enqueue(Process p)
    {
        array[end] = p;
        if (++end >= num)
        {
            end = 0;
        }
    }

    Process dequeue()
    {
        Process p = array[start];
        if (++start >= num)
        {
            start = 0;
        }
        return p;
    }
};

int main()
{
    int n, q;
    cout << "Input:" << endl;
    cin >> n;
    cin >> q;

    Queue queue(n);
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        Process p;
        cin >> p.name >> p.time;
        queue.enqueue(p);
    }

    cout << "Output:" << endl;
    do
    {
        Process p = queue.dequeue();
        if (p.time > q)
        {
            p.time -= q;
            cnt += q;
            queue.enqueue(p);
        }
        else
        {
            cnt += p.time;
            cout << p.name << " " << cnt << endl;
            n--;
        }
    } while (n > 0);

    return 0;
}
