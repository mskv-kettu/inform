class subvector 
{
public:
    subvector()
    {
        this->mas = 0;
        this->top = 0;
        this->capacity = 0;
    }
    ~subvector()
    {
        this->top = 0;
        this->capacity = 0;
        delete[] this->mas;
    }

    bool push_back(int d)
    {
        try {
            if (this->top + 1 > this->capacity) resize(this->capacity + 1);
            *(this->mas + this->top) = d;
            this->top++;
            return true;
        }
        catch (...)
        {
            throw;
            return false;
        }
    }

    int pop_back()
    {
        if (!(this->top > 0)) return 0;
        this->top--;
        int value = *(this->mas + this->top);
        return value;
    }

    bool resize(unsigned int new_capacity)
    {
        int* new_subvector = new int[new_capacity];
        if (this->top > new_capacity) this->top = new_capacity;
        unsigned int new_top = this->top;
        for (unsigned int i = 0; i < this->top; i++)
        {
            new_subvector[i] = *(this->mas + i);
        }
        if (this->mas) delete[]this->mas;
        this->mas = new_subvector;
        this->top = new_top;
        this->capacity = new_capacity;
        return true;
    }

    void shrink_to_fit()
    {
        resize(this->top);
    }

    void clear()
    {
        this->top = 0;
    }

private:
    int* mas;
    unsigned int top;
    unsigned int capacity;
};
