struct subvector {
    int* mas;
    unsigned int top;
    unsigned int capacity;
};

bool init(subvector* qv);
bool push_back(subvector* qv, int d);
int pop_back(subvector* qv);
bool resize(subvector* qv, unsigned int new_capacity);
void shrink_to_fit(subvector* qv);
void clear(subvector* qv);
void destructor(subvector* qv);

bool init(subvector* qv)
{
    (*qv).mas = 0;
    (*qv).top = 0;
    (*qv).capacity = 0;
    return true;
}

bool push_back(subvector* qv, int d)
{
    try {
        if (qv->top + 1 > qv->capacity) resize(qv, ((*qv).capacity + 1));
        *(qv->mas + qv->top) = d;
        qv->top++;
        return true;
    }
    catch (...)
    {
        throw;
        return false;
    }
}

int pop_back(subvector* qv)
{
    if (!(qv->top > 0)) return 0;
    qv->top--;
    int value = *(qv->mas + qv->top);
    return value;
}

bool resize(subvector* qv, unsigned int new_capacity)
{
    int* new_subvector = new int[new_capacity];
    if (qv->top > new_capacity) qv->top = new_capacity;
    unsigned int new_top = qv->top;
    for (unsigned int i = 0; i < (*qv).top; i++)
    {
        new_subvector[i] = *((*qv).mas + i);
    }
    if (qv->mas) delete[](*qv).mas;
    (*qv).mas = new_subvector;
    (*qv).top = new_top;
    (*qv).capacity = new_capacity;
    return true;
}

void shrink_to_fit(subvector* qv)
{
    resize(qv, qv->top);
}

void clear(subvector* qv)
{
    qv->top = 0;
}

void destructor(subvector* qv)
{
    delete[] qv->mas;
    init(qv);
}