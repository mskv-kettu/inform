#include <iostream>

struct subset_node {
    int key;
    subset_node* left;
    subset_node* right;
};

// инициализация пустого дерева (аналогично списку, пустое дерево это указатель на NULL)
bool init(subset_node** sn); 
// добавление элемента в дерево, дубли игнорировать (ничего не добавлять в дерево, если там уже есть элемент с таким же key) и возвращать false
bool insert(subset_node** sn, int k); 
// удаление элемента из дерева (если элемента не нашлось, то ничего не удалять и вернуть false)
bool remove(subset_node** sn, int k); 
// поиск элемента в дереве, нужно вернуть указатель на элемент с тем же key или, если такого элемента не нашлось, то NULL
subset_node* find(subset_node* sn, int k); 
// количество элементов в дереве
unsigned int size(subset_node* sn); 
// высота дерева
unsigned int height(subset_node* sn); 
// очистить всю используемую память
void destructor(subset_node** sn); 
//обход в глубину, возвращает указатель на массив
int* DFS(subset_node* sn); 
int DFS_assistance(subset_node* sn, int* result);

bool init(subset_node** sn)
{
    *sn = NULL;
    return true;
}

bool insert(subset_node** sn, int k)
{
    if (*sn == NULL)
    {
        *sn = new subset_node;
        (*sn)->key = k;
        (*sn)->left = NULL;
        (*sn)->right = NULL;
        return true;
    }

    // Поиск места для нового элемента
    subset_node* sn_parent = NULL;
    subset_node* sn_current = *sn;
    while (sn_current != NULL)
    {
        if (k < sn_current->key)
        {
            sn_parent = sn_current;
            sn_current = sn_current->right;
            continue;
        }
        if (k > sn_current->key)
        {
            sn_parent = sn_current;
            sn_current = sn_current->left;
            continue;
        }
        if (k == sn_current->key)
        {
            return false;
        }
    }
    // Созднание нового узла
    if (k < sn_parent->key)
    {
        sn_parent->right = new subset_node;
        subset_node* temp = sn_parent->right;
        temp->key = k;
        temp->left = NULL;
        temp->right = NULL;
        return true;
    }
    if (k > sn_parent->key)
    {
        sn_parent->left = new subset_node;
        subset_node* temp = sn_parent->left;
        temp->key = k;
        temp->left = NULL;
        temp->right = NULL;
        return true;
    }
    std::cout << "error\n";
    return false;
}

bool remove(subset_node** sn, int k)
{
    if (*sn == NULL) return false;
    subset_node* sn_parent = NULL;
    subset_node* sn_current = *sn;
    while (sn_current != NULL)
    {
        if (k < sn_current->key)
        {
            sn_parent = sn_current;
            sn_current = sn_current->right;
            continue;
        }
        if (k > sn_current->key)
        {
            sn_parent = sn_current;
            sn_current = sn_current->left;
            continue;
        }
        if (k == sn_current->key)
        {
            delete sn_current;
            (k < sn_current->key) ? sn_parent->right = NULL : sn_parent->left = NULL;
            return true;
        }
    }
    return false;
}

subset_node* find(subset_node* sn, int k) 
{
    if (sn == NULL) return NULL;
    subset_node* sn_parent = NULL;
    subset_node* sn_current = sn;
    while (sn_current != NULL)
    {
        if (k < sn_current->key)
        {
            sn_parent = sn_current;
            sn_current = sn_current->right;
            continue;
        }
        if (k > sn_current->key)
        {
            sn_parent = sn_current;
            sn_current = sn_current->left;
            continue;
        }
        if (k == sn_current->key)
        {
            delete sn_current;
            return (k < sn_current->key) ?  sn_parent->right : sn_parent->left;
        }
    }
    return NULL;
}

unsigned int size(subset_node* sn)
{
    if (sn == NULL) return 0;
    return 1 + size(sn->left) + size(sn->right);
}

unsigned int height(subset_node* sn)
{
    if (sn == NULL) return 0;
    if (height(sn->left) >= height(sn->right)) return (1 + height(sn->left));
    else return (1 + height(sn->right));
    return -1;
}

void destructor(subset_node** sn)
{
    if (*sn == NULL) return;
    destructor(&((*sn)->left));
    destructor(&((*sn)->right));
    delete* sn;
}

int* DFS(subset_node* sn)
{
    //int* dfs = new int[size(sn)];
}

int DFS_assistance(subset_node* sn, int* result)
{
    
}
