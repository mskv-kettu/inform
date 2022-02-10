class subforwardlist
{
private:
    // Структура в области видимости класса
    struct subForwardListStruct; 

public:
    subforwardlist()
    {
        sfls = NULL;
    }
    ~subforwardlist()
    {
        unsigned int N = this->size();
        subForwardListStruct** ToDo = new subForwardListStruct * [N];
        subForwardListStruct* pointer = sfls;
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
        sfls = NULL;
    }
    
    //добавление элемента в конец недосписка
    bool push_back(int d) 
    {
        subForwardListStruct* new_elem = new subForwardListStruct;
        new_elem->data = d;
        new_elem->next = NULL;
        if (!sfls)
        {
            sfls = new_elem;
            return true;
        }
        subForwardListStruct* temp = sfls;
        while (temp->next)
        {
            temp = temp->next;
        }
        temp->next = new_elem;
        return true;
    }

    //удаление элемента с конца недосписка
    int pop_back()
    {
        if (!sfls) return 0;
        subForwardListStruct* temp = sfls;
        int result = temp->data;
        if (!temp->next) { result = temp->data; delete temp; sfls = NULL; return  result; } // для 1 элемента
        subForwardListStruct* prev = sfls;
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

    //добавление элемента в начало недосписка
    bool push_forward(int d) //добавление элемента в начало недосписка
    {
        subForwardListStruct* new_elem = new subForwardListStruct;
        new_elem->data = d;
        new_elem->next = sfls;
        sfls = new_elem;
        return true;
    }

    //удаление элемента из начала недосписка
    int pop_forward() //удаление элемента из начала недосписка
    {
        subForwardListStruct* temp = NULL;
        if (sfls) { temp = sfls->next; }
        else return 0;
        int result = sfls->data;
        delete sfls;
        sfls = temp;
        return result;
    }

    //добавление элемента с порядковым номером where
    bool push_where(unsigned int where, int d)
    {
        if (!where) { push_forward(d); return true; }
        subForwardListStruct* cur = sfls;
        subForwardListStruct* cur_prev = NULL;
        for (unsigned int i = 0; i < where; i++)
        {
            if (!(cur->next)) push_back(NULL); // проверка where больше длины списка
            cur_prev = cur;
            cur = cur->next;
        }
        subForwardListStruct* new_elem = new subForwardListStruct;
        new_elem->data = d;
        new_elem->next = cur;
        cur_prev->next = new_elem;
        return true;
    }

    //удаление элемента с порядковым номером where
    bool erase_where(unsigned int where)
    {
        subForwardListStruct* cur = sfls;
        subForwardListStruct* cur_prev = NULL;
        for (unsigned int i = 0; i < where; i++)
        {
            cur_prev = cur;
            cur = cur->next;
        }
        if (cur_prev) cur_prev->next = cur->next;
        else sfls = cur->next;
        delete cur;
        return true;
    }

    //определить размер недосписка
    unsigned int size()
    {
        unsigned int size = 0;
        subForwardListStruct* temp = sfls;
        while (temp)
        {
            temp = temp->next;
            size++;
        }
        return size;
    }

    subForwardListStruct* sfls;

    bool clear()
    {
        this->~subforwardlist();
        return true;
    }

private:
    struct subForwardListStruct
    {
        int data;
        subForwardListStruct* next;
    };
};
