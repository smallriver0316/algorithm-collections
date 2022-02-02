#include <iostream>
#include <string>
#include <regex>
#include <string.h>
using namespace std;

#define N 1000

enum pet
{
  Dog,
  Cat
};

struct Animal
{
  string name;
  int time;
};

class Queue
{
  int start, end, num;
  Animal buffer[N];

public:
  Queue()
  {
    start = 0;
    end = 0;
  }

  bool isEmpty()
  {
    return start == end;
  }

  void enqueue(Animal a)
  {
    if (abs(end - start) >= N - 1)
    {
      cout << "[ERROR] Queue is full" << endl;
      throw "[ERROR] Queue is full";
    }

    buffer[end] = a;
    if (++end >= N)
    {
      end = 0;
    }
  }

  Animal dequeue()
  {
    if (isEmpty())
    {
      cout << "[ERROR] Queue is empty" << endl;
      throw "[ERROR] Queue is empty";
    }
    Animal a = buffer[start];
    if (++start >= N)
    {
      start = 0;
    }
    return a;
  }

  Animal peek()
  {
    if (isEmpty())
    {
      cout << "[ERROR] Queue is empty" << endl;
      throw "[ERROR] Queue is empty";
    }
    return buffer[start];
  }
};

class AnimalShelter
{
  Queue dogs, cats;

public:
  void enqueue(Animal a, int type)
  {
    switch (type)
    {
    case Dog:
      dogs.enqueue(a);
      break;
    case Cat:
      cats.enqueue(a);
      break;
    default:
      cout << "[ERROR] Commit only dogs or cats" << endl;
      throw "[ERROR] Commit only dogs or cats";
    }
  }

  Animal dequeueDog()
  {
    return dogs.dequeue();
  }

  Animal dequeueCat()
  {
    return cats.dequeue();
  }

  Animal dequeueAny()
  {
    if (dogs.isEmpty())
    {
      return cats.dequeue();
    }
    else if (cats.isEmpty())
    {
      return dogs.dequeue();
    }
    else
    {
      Animal dog = dogs.peek();
      Animal cat = cats.peek();
      return dog.time < cat.time ? dogs.dequeue() : cats.dequeue();
    }
  }
};

int spec2type(char *spec)
{
  if (strcmp(spec, "cat") == 0)
  {
    return Cat;
  }
  else if (strcmp(spec, "dog") == 0)
  {
    return Dog;
  }
  else
  {
    cout << "[ERROR] Specify dog or cat, but " << spec << endl;
    throw "[ERROR] Specify dog or cat";
  }
}

int main()
{
  int n;
  /*
    com: command, enqueue or dequeue
    spec: species, cat, dog, or any
    name: name of animal, such as pochi, tama, and so on
  */
  char com[8], spec[4], name[10];
  AnimalShelter shelter;

  try
  {
    regex re_enqueue("enqueue");
    regex re_dequeue("dequeue");

    scanf("%d", &n);
    (void)getchar();

    for (int i = 0; i < n; i++)
    {
      scanf("%7s %3s", com, spec);
      if (regex_match(com, re_enqueue))
      {
        scanf("%s", name);
        Animal a = {name, i};
        shelter.enqueue(a, spec2type(spec));
      }
      else if (regex_match(com, re_dequeue))
      {
        Animal a;
        if (strcmp(spec, "dog") == 0)
        {
          a = shelter.dequeueDog();
        }
        else if (strcmp(spec, "cat") == 0)
        {
          a = shelter.dequeueCat();
        }
        else if (strcmp(spec, "any") == 0)
        {
          a = shelter.dequeueAny();
        }
        else
        {
          cout << "[ERROR] Specify dog, cat, or any" << endl;
          throw "[ERROR] Specify dog, cat, or any";
        }
        cout << a.name << endl;
        (void)getchar();
      }
      else
      {
        cout << "[ERROR] Invalid command! " << com << endl;
        throw "[ERROR] Invalid command!";
      }
    }
  }
  catch (const std::exception &e)
  {
    std::cerr << e.what() << '\n';
  }

  return 0;
}
