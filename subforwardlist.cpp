#include <iostream>
struct subforwardlist {

    int data;

    subforwardlist* next;

};

bool init(subforwardlist** sfl); //инициализация пустого недосписка
bool push_back(subforwardlist** sfl, int d); //добавление элемента в конец недосписка
int pop_back(subforwardlist** sfl); //удаление элемента с конца недосписка
bool push_forward(subforwardlist** sfl, int d); //добавление элемента в начало недосписка
int pop_forward(subforwardlist** sfl); //удаление элемента из начала недосписка
bool push_where(subforwardlist** sfl, unsigned int where, int d); //добавление элемента с порядковым номером where
bool erase_where(subforwardlist** sfl, unsigned int where); //удаление элемента с порядковым номером where
unsigned int size(subforwardlist** sfl); //определить размер недосписка
void clear(subforwardlist** sfl); //очистить содержимое недосписка

bool init(subforwardlist** sfl) //инициализация пустого недосписка
{
    *sfl = NULL;
    return true;
}

bool push_back(subforwardlist** sfl, int d) //добавление элемента в конец недосписка
{
    subforwardlist* new_elem = new subforwardlist;
    new_elem->data = d;
    new_elem->next = NULL;
    if (!*sfl)
    {
        *sfl = new_elem;
        return true;
    }
    subforwardlist* temp = *sfl;
    while (temp->next)
    {
        temp = temp->next;
    }
    temp->next = new_elem;
    return true;
}

int pop_back(subforwardlist** sfl) //удаление элемента с конца недосписка
{
    if (!(*sfl)) return 0;
    subforwardlist* temp = *sfl;
    int result = temp->data;
    if (!temp->next) { result = temp->data; delete temp; *sfl = NULL; return  result; }
    subforwardlist* prev = *sfl;
    while (temp->next)
    {
        prev = temp;
        temp = temp->next;
    }
    result = temp->data;
    delete temp;
    prev->next = NULL;
    return  result;
}

bool push_forward(subforwardlist** sfl, int d) //добавление элемента в начало недосписка
{
    subforwardlist* new_elem = new subforwardlist;
    new_elem->data = d;
    new_elem->next = *sfl;
    *sfl = new_elem;
    return true;
}

int pop_forward(subforwardlist** sfl) //удаление элемента из начала недосписка
{
    subforwardlist* temp = NULL;
    if (*sfl) { temp = (*sfl)->next; }
    else return 0;
    int result = (*sfl)->data;
    delete* sfl;
    *sfl = temp;
    return result;
}

bool push_where(subforwardlist** sfl, unsigned int where, int d) //добавление элемента с порядковым номером where
{
    if (!where) { push_forward(sfl, d); return true; }
    subforwardlist* cur = *sfl;
    subforwardlist* cur_prev = NULL;
    for (unsigned int i = 0; i < where; i++)
    {
        //if (!(cur->next)) push_back(sfl, NULL);
        cur_prev = cur;
        cur = cur->next;
    }
    subforwardlist* new_elem = new subforwardlist;
    new_elem->data = d;
    new_elem->next = NULL;
    new_elem->next = cur;
    cur_prev->next = new_elem;
}

bool erase_where(subforwardlist** sfl, unsigned int where) //удаление элемента с порядковым номером where
{
    subforwardlist* cur = *sfl;
    subforwardlist* cur_prev = NULL;
    for (unsigned int i = 0; i < where; i++)
    {
        cur_prev = cur;
        cur = cur->next;
    }
    if (cur_prev) cur_prev->next = cur->next;
    else *sfl = cur->next;
    delete cur;
    return true;
}

unsigned int size(subforwardlist** sfl) //определить размер недосписка
{
    unsigned int size = 0;
    subforwardlist* temp = *sfl;
    while (temp)
    {
        temp = temp->next;
        size++;
    }
    return size;
}

void clear(subforwardlist** sfl) //очистить содержимое недосписка
{
    unsigned int N = size(sfl);
    subforwardlist** ToDo = new subforwardlist * [N];
    subforwardlist* pointer = *sfl;
    for (unsigned int i = 0; i < N; i++)
    {
        ToDo[i] = pointer;
        pointer = pointer->next;
    }
    for (unsigned int i = 0; i < N; i++)
    {
        delete ToDo[i];
    }
    delete[] ToDo;
    *sfl = NULL;
}